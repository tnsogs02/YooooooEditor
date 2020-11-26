#include "image_cons_bri.h"

void adjust_contrast(cv::Mat image, int contrast)
{
	//滑桿值控制contrast值
	//對比度調整，建議contrast範圍:0 ~ 100，負數為負片效果(很好玩呦)
	//contrast=-100時，圖片會變成一片灰(因為整張圖完全失去對比了)
	cv::Mat imageRGB[3];
	cv::split(image, imageRGB);
	double _contrast = contrast;
	double contrast_factor = 1 + _contrast / 100;
	double aver = (mean(imageRGB[0])[0] + mean(imageRGB[1])[0] + mean(imageRGB[2])[0]) / 3;
	imageRGB[0] = contrast_factor * (imageRGB[0] - aver) + aver;
	imageRGB[1] = contrast_factor * (imageRGB[1] - aver) + aver;
	imageRGB[2] = contrast_factor * (imageRGB[2] - aver) + aver;

	merge(imageRGB, 3, image);
}

void adjust_brightness(cv::Mat image, int brightness, double arguments)
{
	//滑桿值控制brightness值
	//亮部調整，建議brightness範圍:-50 ~ +50
	//arguments之值須大於1，測試時以1.5做測試，看似可行
	//亮部之判定:以整張圖之平均亮度乘上arguments之值為閥值，亮度超過該值之pixel則判定為亮部
	cv::Mat imageRGB[3];
	cv::split(image, imageRGB);
	if (arguments < 1)arguments = 1;
	double _arguments = arguments, _brightness = brightness;
	double aver = (mean(imageRGB[0])[0] + mean(imageRGB[1])[0] + mean(imageRGB[2])[0]) / 3.0;
	aver *= _arguments;
	double x;
	for (int i = 0; i < image.rows; i++) 
	{
		for (int j = 0; j < image.cols; j++) 
		{
			x = 0;
			for (int k = 0; k < 3; k++) 
			{
				x += image.at<cv::Vec3b>(i, j)[k];
			}
			if (x >= aver)
			{
				for (int k = 0; k < 3; k++) 
				{
					image.at<cv::Vec3b>(i, j)[k] = cv::saturate_cast<uchar>((image.at<cv::Vec3b>(i, j)[k]) + _brightness);
				}
			}
		}
	}
}