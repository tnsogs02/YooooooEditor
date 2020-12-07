#pragma once
#include <iostream>

#define YORECORDNAME "Iptc.0x0019.0x0000"

class __declspec(dllimport) rawIO {
public:
	int tiffExport(char* inPath, char* outPath);
	int iptcWrite(std::string filePath, std::string& iptcValue);
	int iptcRead(std::string filePath, std::string& iptcValue);
private:
};