#pragma once
#include "Cmdheader.h"
#include "Header.h"
#include "Gerenatedata.h"

void copyAndGenerateData(int*& src_arr, int& size, int dataType);
void deleteData(int*& ptr);

bool readfile(const char* filename, int *&arr, int &size);
void savefile(const char* filename, int *arr, int size); 