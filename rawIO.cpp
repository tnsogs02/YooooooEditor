#include "rawIO.h"

LibRaw rawProcessor;

using namespace std;

int tiffExport(char* inPath, char* outPath) {
	int errCode = rawProcessor.open_file(inPath);
	if (errCode == 0) {
		Exiv2::Image::AutoPtr imageIn = Exiv2::ImageFactory::open(inPath);
		assert(imageIn.get() != 0);
		imageIn->readMetadata();
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
		Exiv2::Image::AutoPtr imageOut = Exiv2::ImageFactory::open(outPath);
		assert(imageOut.get() != 0);
		imageOut->setIptcData(imageIn->iptcData());
		imageOut->setExifData(imageIn->exifData());
		imageOut->writeMetadata();
	}
	else {
		cout << "Can't open " << inPath << endl;
		return 1;
	}
	return 0;
}

int iptcWrite(string filePath, string& iptcValue) try {
	Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(filePath);
	assert(image.get() != 0);
	image->readMetadata();
	Exiv2::IptcData iptcData = image->iptcData();
	Exiv2::IptcKey key(YORECORDNAME);
	Exiv2::IptcData::iterator iter = iptcData.findKey(key);
	while (iter != iptcData.end()) {
		iptcData.erase(iter);
		iter = iptcData.findKey(key);
	}
	iptcData[YORECORDNAME] = iptcValue;
	cout << "write!" << endl;
	image->setIptcData(iptcData);
	image->writeMetadata();
	cout << "write!!" << endl;
	return 0;
}

catch (Exiv2::AnyError& err) {
	std::cout << "Caught Exiv2 exception when Writing '" << err << "'\n";
	return 1;
}

int iptcRead(string filePath, string& iptcValue) try {
	Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(filePath);
	assert(image.get() != 0);
	image->readMetadata();
	Exiv2::IptcData& iptcData = image->iptcData();
	assert(!iptcData.empty());
	cout << iptcData[YORECORDNAME] << endl;
	return 0;
}

catch (Exiv2::AnyError& err) {
	std::cout << "Caught Exiv2 exception when reading '" << err << "'\n";
	return 1;
}