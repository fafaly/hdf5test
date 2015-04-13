#pragma once
#include "H5Cpp.h"
#ifdef OLD_HEADER_FILENAME
#include <iostream.h>
#else
#include <iostream>
#endif
#include <string>
#include "msgdata.h"

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
typedef struct Market_Data
{
	int32 dte;
	int32 tme;
	int32 pclse;//
	int32 opn;//
	int32 high;
	int32 low;
	int32 lastPx;
	int64 volume;
	int64 value;
	int32 tcount;

	int32 ask[10];
	//ask size
	uint32 asize[10];

	int32 bid[10];
	//bid size
	uint32 bsize[10];
}Market_Data;


const H5std_string  MEMBER1 = "dte";
const H5std_string  MEMBER2 = "tme";
const H5std_string  MEMBER3 = "pclse";
const H5std_string  MEMBER4 = "opn";
const H5std_string  MEMBER5 = "high;";
const H5std_string  MEMBER6 = "low;";
const H5std_string  MEMBER7 = "lastPx";
const H5std_string  MEMBER8 = "volume";
const H5std_string  MEMBER9 = "value;";
const H5std_string  MEMBER10 = "tcount";
const H5std_string  MEMBER11 = "ask1";
const H5std_string  MEMBER12 = "ask2";
const H5std_string  MEMBER13 = "ask3";
const H5std_string  MEMBER14 = "ask4";
const H5std_string  MEMBER15 = "ask5";
const H5std_string  MEMBER16 = "ask6";
const H5std_string  MEMBER17 = "ask7";
const H5std_string  MEMBER18 = "ask8";
const H5std_string  MEMBER19 = "ask9";
const H5std_string  MEMBER20 = "ask10";
const H5std_string  MEMBER21 = "asize1";
const H5std_string  MEMBER22 = "asize2";
const H5std_string  MEMBER23 = "asize3";
const H5std_string  MEMBER24 = "asize4";
const H5std_string  MEMBER25 = "asize5";
const H5std_string  MEMBER26 = "asize6";
const H5std_string  MEMBER27 = "asize7";
const H5std_string  MEMBER28 = "asize8";
const H5std_string  MEMBER29 = "asize9";
const H5std_string  MEMBER30 = "asize10";
const H5std_string  MEMBER31 = "bid1";
const H5std_string  MEMBER32 = "bid2";
const H5std_string  MEMBER33 = "bid3";
const H5std_string  MEMBER34 = "bid4";
const H5std_string  MEMBER35 = "bid5";
const H5std_string  MEMBER36 = "bid6";
const H5std_string  MEMBER37 = "bid7";
const H5std_string  MEMBER38 = "bid8";
const H5std_string  MEMBER39 = "bid9";
const H5std_string  MEMBER40 = "bid10";
const H5std_string  MEMBER41 = "bsize1";
const H5std_string  MEMBER42 = "bsize2";
const H5std_string  MEMBER43 = "bsize3";
const H5std_string  MEMBER44 = "bsize4";
const H5std_string  MEMBER45 = "bsize5";
const H5std_string  MEMBER46 = "bsize6";
const H5std_string  MEMBER47 = "bsize7";
const H5std_string  MEMBER48 = "bsize8";
const H5std_string  MEMBER49 = "bsize9";
const H5std_string  MEMBER50 = "bsize10";
















































