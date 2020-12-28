#pragma once
#include <iostream>
#include <iomanip>
#include <cassert>

#include "exiv2/exiv2.hpp"
#include "libraw/libraw.h"

#define YORECORDNAME "Iptc.0x0019.0x0000"

extern "C" __declspec(dllexport) int CStiffExport(char* inPath, char* outPath) {
	rawIO raw;
	return raw.tiffExport(inPath, outPath);
}
extern "C" __declspec(dllexport) int CSiptcWrite(char* filePath, char* iptcValue) {
	rawIO raw;
	return raw.iptcWrite(filePath, iptcValue);
}
extern "C" __declspec(dllexport) int CSiptcRead(char* filePath, char* iptcValue) {
	rawIO raw;
	return raw.iptcRead(filePath, iptcValue);
}
extern "C" __declspec(dllexport) int CSexifRead(char* inPath, char* exifValue) {
	rawIO raw;
	return raw.exifRead(inPath, exifValue);
}
