#include"pch.h"
#include"Header.h"

Mat Colorfulness(Mat img, int i) {
	Mat fimg;
	img.convertTo(fimg, 21, 1.0 / 255.0, 0);
	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_RGB2HSV);

	for (int r = 0; r < imgHSV.rows; r++) {
		uchar* p = imgHSV.ptr(r);
		for (int c = 0; c < imgHSV.cols; c++) {
			int q = *(p + c * 3 + 1);
			if (q + i >= 255)
				*(p + c * 3 + 1) = 255;
			else if (q + i <= 0)
				*(p + c * 3 + 1) = 0;
			else
				*(p + c * 3 + 1) += i;
		}
	}

	cvtColor(imgHSV, fimg, COLOR_HSV2RGB);

	return fimg;
}

Mat Dark_Adjust(Mat img, int i) {
	float threshold = 40;
	Mat fimg=img;
	//img.convertTo(fimg, 21, 1.0 / 255.0, 0);
	Mat HLSimg;
	cvtColor(fimg, HLSimg, COLOR_RGB2HLS);

	for (int r = 0; r < HLSimg.rows; r++) {
		uchar* p = HLSimg.ptr(r);
		for (int c = 0; c < HLSimg.cols; c++) {
			int q = *(p + c * 3 + 1);
			if (q < threshold) {
				if (q + i >= 255)
					*(p + c * 3 + 1) = 255;
				else if (q + i <= 0)
					*(p + c * 3 + 1) = 0;
				else
					*(p + c * 3 + 1) += i;
			}
		}
	}

	cvtColor(HLSimg, fimg, COLOR_HLS2RGB);

	return fimg;
}


//=================================================================================================
int temperature(Mat image, int temperature) {
	/*色溫計算，基本上每次圖片進來都call一次，如果想省時間請直接把搖桿初始值設為5000*/
	double R = 0, B = 0;
	vector<Mat>imageRGB;
	split(image, imageRGB);
	B = mean(imageRGB[0])[0] + 1;
	R = mean(imageRGB[2])[0] + 1;
	double R_B = R / B;
	/*R/B/256乘10000+5000為色溫*/
	double a = R_B / 256 * 10000 + 5000;
	return (int)a;

Mat adjust(Mat image, int temperature) {
	/*色溫調整，temperature在0~10000*/
	double R = 0, B = 0;
	vector<Mat>imageRGB;
	split(image, imageRGB);
	B = mean(imageRGB[0])[0] + 1;
	R = mean(imageRGB[2])[0] + 1;
	double R_B = R / B;
	/*R/B/256乘10000+5000為色溫*/
	double a = R_B / 256 * 10000 + 5000;
	if (R > 128) {
		imageRGB[2] /= R_B * ((double)(temperature / a));
	}
	else {
		imageRGB[0] /= R_B * ((double)(temperature / a));
	}
	merge(imageRGB, image);
	return image;
}
Mat average(cv::Mat image, int adjust) {
	if(adjust==0){
		return image;
	}
	float a = 1.2, b = 10;
	cv::Mat imageRGB[3];
	cv::split(image, imageRGB);
	double aver = (mean(imageRGB[0])[0] + mean(imageRGB[1])[0] + mean(imageRGB[2])[0]) / 3;
	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {
			double all = image.at<cv::Vec3b>(i, j)[0] + image.at<cv::Vec3b>(i, j)[1] + image.at<cv::Vec3b>(i, j)[2];
			if (all<aver &&adjust>0) {
				for (int k = 0; k < 3; k++) {
					image.at<cv::Vec3b>(i, j)[k] = cv::saturate_cast<uchar>(a * (image.at<cv::Vec3b>(i, j)[k]) + b);
				}
			}
			if (all > aver && adjust<0) {
				for (int k = 0; k < 3; k++) {
					image.at<cv::Vec3b>(i, j)[k] = cv::saturate_cast<uchar>( (image.at<cv::Vec3b>(i, j)[k])/a - b);
				}
			}
		}
	}
	/*曝光調整*/
	return image;
}


//=================================================================================================
Mat adjust_contrast(Mat image, int contrast)
{
	Mat newimage;
	image.copyTo(newimage);
	Mat imageRGB[3];
	split(newimage, imageRGB);
	double _contrast = contrast;
	double contrast_factor = 1 + _contrast / 100;
	double aver = (mean(imageRGB[0])[0] + mean(imageRGB[1])[0] + mean(imageRGB[2])[0]) / 3;
	imageRGB[0] = contrast_factor * (imageRGB[0] - aver) + aver;
	imageRGB[1] = contrast_factor * (imageRGB[1] - aver) + aver;
	imageRGB[2] = contrast_factor * (imageRGB[2] - aver) + aver;

	merge(imageRGB, 3, newimage);

	return newimage;
}


Mat adjust_brightness(Mat image, int brightness, double arguments)//double arguments 請傳入1.2
{
	Mat newimage;
	image.copyTo(newimage);
	Mat imageRGB[3];
	split(newimage, imageRGB);
	if (arguments < 1)arguments = 1;
	double _arguments = arguments, _brightness = brightness;
	double aver = (mean(imageRGB[0])[0] + mean(imageRGB[1])[0] + mean(imageRGB[2])[0]) / 3.0;
	aver *= _arguments;
	double x;
	for (int i = 0; i < newimage.rows; i++)
	{
		for (int j = 0; j < newimage.cols; j++)
		{
			x = 0;
			for (int k = 0; k < 3; k++)
			{
				x += newimage.at<cv::Vec3b>(i, j)[k];
			}
			if (x >= aver)
			{
				for (int k = 0; k < 3; k++)
				{
					newimage.at<cv::Vec3b>(i, j)[k] = cv::saturate_cast<uchar>((newimage.at<cv::Vec3b>(i, j)[k]) + _brightness);
				}
			}
		}
	}
	return newimage;
}


//=================================================================================================
//Color Seperate
Mat BGRch(Mat img, int B, int G, int R) {
	Mat fimg;
	img.copyTo(fimg);
	for (int r = 0; r < fimg.rows; r++) {
		uchar* p = fimg.ptr(r);
		for (int c = 0; c < fimg.cols; c++) {
			int q = *(p + c * 3);
			if (q + B >= 255)
				*(p + c * 3) = 255;
			else if (q + B <= 0)
				*(p + c * 3) = 0;
			else
				*(p + c * 3) += B;

			q = *(p + c * 3 + 1);
			if (q + G >= 255)
				*(p + c * 3 + 1) = 255;
			else if (q + G <= 0)
				*(p + c * 3 + 1) = 0;
			else
				*(p + c * 3 + 1) += G;

			q = *(p + c * 3 + 2);
			if (q + R >= 255)
				*(p + c * 3 + 2) = 255;
			else if (q + R <= 0)
				*(p + c * 3 + 2) = 0;
			else
				*(p + c * 3 + 2) += R;
		}
	}
	return fimg;
}
