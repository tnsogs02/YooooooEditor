#include"pch.h"
#include"Header.h"

int ret(unsigned char* imageBuffer, int width, int height, int ch) {
	Mat img(Size(width, height), CV_8UC3, imageBuffer, Mat::AUTO_STEP);

	Mat r = Colorfulness(img, ch);

	r.copyTo(img);

	return 0;

}