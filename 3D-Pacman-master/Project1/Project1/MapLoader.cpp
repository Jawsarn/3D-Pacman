#include "MapLoader.h"
#include <fstream>

using namespace std;

MapLoader::MapLoader(void)
{
}


MapLoader::~MapLoader(void)
{
}

std::vector<std::vector<int>> MapLoader::LoadMap(const char* mapName, int width, int height)
{
	ifstream fileStream;
	fileStream.open(mapName, ios_base::binary);
	vector<unsigned char> temp_mapInfo(width*height);
	vector<vector<int>> returnMap(width);

	if (!fileStream)
	{
		return returnMap;
	}

	fileStream.read((char*) &temp_mapInfo[0],(streamsize)temp_mapInfo.size());
	fileStream.close();

	vector<int> temp;
	int index = 0;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			returnMap[i].push_back((int)temp_mapInfo[index++]);
		}
	}

	return returnMap;
}