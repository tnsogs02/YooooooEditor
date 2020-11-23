#pragma once
#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>>
void adjust(cv::Mat& image, int temperature);/*temperature控制所要調色溫值，若數字越大，則圖片越偏藍*/
void average(cv::Mat& image, int adjust);/*adjust>0調亮圖片，小於零調暗圖片*/
