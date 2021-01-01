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

Mat adjust(Mat image, int temperature);/*temperature����ҭn�զ�ŭȡA�Y�Ʀr�V�j�A�h�Ϥ��V����*/
Mat average(Mat image, int adjust);/*adjust>0�իG�Ϥ��A�p��s�շt�Ϥ�*/

Mat adjust_contrast(Mat image, int contrast);//contrast: prefer 0 ~ 100
Mat adjust_brightness(Mat image, int brightness, double arguments);
//brightness: prefer -50 ~ +50 ; arguments: default 1.2

//Color Seperate
Mat Red(Mat img, int i);
Mat Green(Mat img, int i);
Mat Blue(Mat img, int i);