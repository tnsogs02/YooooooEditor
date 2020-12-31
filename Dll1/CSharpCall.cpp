#include"pch.h"
#include"Header.h"

int ret(unsigned char* imageBuffer, int width, int height, int a, int b, int c, int d, int e, int f, int g, int h, int i) {
	Mat img(Size(width, height), CV_8UC3, imageBuffer, Mat::AUTO_STEP);

	Mat r;
	cvtColor(img, r, COLOR_BGR2RGB);

	r = Colorfulness(img, a);
	r = Dark_Adjust(r, b);
	r = adjust(r, c);
	//r = average(r, d);
	r = adjust_contrast(r, e);
	//r = adjust_brightness(r, f);
	r = BGRch(r, g, h, i);

	r.copyTo(img);

	return 0;

}