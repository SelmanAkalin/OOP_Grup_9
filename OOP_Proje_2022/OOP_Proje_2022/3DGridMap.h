#pragma once
/**
* @Author	: Ali Yalnýz
* @date		: 24.12.2022
* @file		: 3DGridMap.h
*/
#include"PointCloud.h"
#include<fstream>
//! class GridMap
class GridMap{
private:
	bool map[75][75][75];
	float gridSize;
	int depth;
public:
	GridMap();
	GridMap(float, int);
	void setgridSize(float);
	float getgridSize()const;
	int getdepth()const;
	void insertPointCloud(PointCloud&);
	void insertPoint(Point&);
	bool getGrid(int, int, int)const;
	bool loadMap(string);
	bool saveMap(string);
};