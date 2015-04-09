#pragma once
#include "H5Cpp.h"
#include <string>
#include <iostream>

#ifndef H5_NO_NAMESPACE
using namespace H5;
using namespace std;
#ifndef H5_NO_STD
using std::cout;
using std::endl;
#endif  // H5_NO_STD
#endif

//create a dataset
int CreateDataSet(const char *FILE_NAME, const char* DATASET_NAME);
//creat group
int CreateGroup(const char * FILE_NAME, const char* groupname);
//Create groups in a file using absolute and relative paths
int CreateGroupPar();
//write data
int WriteData(const char* FILE_NAME, const char*	DATASET_NAME);
//create a attribute
int CreateAttribute();
//Create a file and dataset and select/read a subset from the dataset
int SubSet();
//Create a chunked and compressed dataset
int CreateExtend();
//Create a chunked and compressed dataset
int CreateChunk();