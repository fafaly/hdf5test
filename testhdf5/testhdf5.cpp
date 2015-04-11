// testhdf5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "hdf5func.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//CreateGroup("dbL2.h5", "/SH_L2_market_data/");
	//CreateGroup("dbL2.h5", "/SH_L2_market_data/d20141101"); 
	//CreateDataSet("dbL2.h5","/SH_L2_market_data/d20141101/t600000");
	//WriteData("dbL2.h5", "/SH_L2_market_data/d20141101/t600000");
	//CreateDataSet("test.h5", "t600000");
	WriteData("dbL2.h5", "/SH_L2_market_data/d20141101/t600001");
	return 0;
}
