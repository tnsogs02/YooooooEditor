#pragma once
#include <iostream>
#include <iomanip>
#include <cassert>

#include "exiv2/exiv2.hpp"
#include "libraw/libraw.h"

#define YORECORDNAME "Iptc.0x0019.0x0000"

extern "C" class __declspec(dllimport) rawIO {
public:
	int _stdcall tiffExport(char* inPath, char* outPath);
	int _stdcall iptcWrite(char* filePath, char* iptcValue);
	int _stdcall iptcRead(char* filePath, char* iptcValue);
	int _stdcall exifRead(char* inPath, char* exifValue);
};