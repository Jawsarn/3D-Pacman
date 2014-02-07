// Testing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MapLoader.h"


int _tmain(int argc, _TCHAR* argv[])
{
	MapLoader test = MapLoader();

	test.LoadMap("test.raw",256,256);
	return 0;
}

