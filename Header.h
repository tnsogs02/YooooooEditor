#pragma once

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

Mat Colorfulness(Mat img, int i);	//int i from -100 to 100
Mat Dark_Adjust(Mat img, int i);	//int i from 0 to 100

Mat adjust(Mat image, int temperature);/*temperature控制所要調色溫值，若數字越大，則圖片越偏藍*/
Mat average(Mat image, int adjust);/*adjust>0調亮圖片，小於零調暗圖片*/

Mat adjust_contrast(Mat image, int contrast);//contrast: prefer 0 ~ 100
Mat adjust_brightness(Mat image, int brightness);
Mat adjust_brightness(Mat image, int brightness, double arguments);
//brightness: prefer -50 ~ +50 ; arguments: default 1.2

//Color Seperate
Mat Red(Mat img, int i);
Mat Green(Mat img, int i);
Mat Blue(Mat img, int i);