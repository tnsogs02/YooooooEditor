#pragma once
#include <iostream>
#include ".\libraw\libraw.h"
#pragma comment(lib,"libraw.lib")

int tiffExport(char* inPath, char* outPath);