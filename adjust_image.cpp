#include"adjust_image.h"
Mat adjust(cv::Mat image, int temperature) {
	/*色溫調整，temperature在0~10000*/
	double R = 0,B = 0;
	std::vector<cv::Mat>imageRGB;
	split(image, imageRGB);
	B = mean(imageRGB[0])[0]+1;
	R = mean(imageRGB[2])[0]+1;
	double R_B = R / B;
	/*R/B/256乘10000+5000為色溫*/
	double a = R_B / 256 * 10000 + 5000;
	if (R>128) {
		imageRGB[2] /= R_B * ((double)(temperature/a));
	}
	else {
		imageRGB[0] /= R_B * ((double)(temperature/a));
	}
	merge(imageRGB, image);
	return image;
}
cv::Mat average(cv::Mat image, int adjust) {
	float a = 1.5, b = 10;
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
