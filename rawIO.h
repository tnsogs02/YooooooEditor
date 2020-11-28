#pragma once
#include <iostream>
#include <iomanip>
#include <cassert>

#include "exiv2/exiv2.hpp"
#include "libraw/libraw.h"

#define YORECORDNAME "Iptc.0x0019.0x0000"

int tiffExport(char* inPath, char* outPath);
int iptcWrite(std::string filePath, std::string& iptcValue);
int iptcRead(std::string filePath, std::string& iptcValue);
