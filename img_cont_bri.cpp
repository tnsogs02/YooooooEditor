#include "imgconv.h"

cv::Mat adjust_contrast(cv::Mat image, int contrast)
{
	cv::Mat newimage;
	image.copyTo(newimage);
	cv::Mat imageRGB[3];
	cv::split(newimage, imageRGB);
	double _contrast = contrast;
	double contrast_factor = 1 + _contrast / 100;
	double aver = (mean(imageRGB[0])[0] + mean(imageRGB[1])[0] + mean(imageRGB[2])[0]) / 3;
	imageRGB[0] = contrast_factor * (imageRGB[0] - aver) + aver;
	imageRGB[1] = contrast_factor * (imageRGB[1] - aver) + aver;
	imageRGB[2] = contrast_factor * (imageRGB[2] - aver) + aver;

	merge(imageRGB, 3, newimage);

	return newimage;
}

cv::Mat adjust_brightness(cv::Mat image, int brightness)
{
	return adjust_brightness(image, brightness,1.2);
}

cv::Mat adjust_brightness(cv::Mat image, int brightness, double arguments)
{
	cv::Mat newimage;
	image.copyTo(newimage);
	cv::Mat imageRGB[3];
	cv::split(newimage, imageRGB);
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