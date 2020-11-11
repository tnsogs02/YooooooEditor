#include "rawopen.h"

LibRaw rawProcessor;

using namespace std;

int tiffExport(char* inPath, char* outPath) {
	int errCode = rawProcessor.open_file(inPath);
	if (errCode == 0) {
		rawProcessor.imgdata.params.output_tiff = 1;
		rawProcessor.imgdata.params.output_bps = 16;
		rawProcessor.imgdata.params.no_auto_bright = 1;
		rawProcessor.imgdata.params.use_auto_wb = 0;
		rawProcessor.imgdata.params.use_camera_wb = 1;
		rawProcessor.imgdata.params.use_camera_matrix = 1;
		rawProcessor.imgdata.params.user_flip = 0;
		rawProcessor.imgdata.params.user_qual = 2;
		rawProcessor.unpack();
		rawProcessor.dcraw_process();
		rawProcessor.dcraw_ppm_tiff_writer(outPath);
	}
	else {
		cout << "Can't open " << inPath << endl;
		return 1;
	}
	return 0;
}