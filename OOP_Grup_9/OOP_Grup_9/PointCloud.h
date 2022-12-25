/**
* @Author	: Selman Akalýn
* @date		: 23.12.2022
* @file		: PointCloud.h
*/
#pragma once
#include"Point.h"
//! class PointCloud
class PointCloud {
private:
	friend PointCloud& operator+(const PointCloud&, const PointCloud&);
	Point* points;
	int pointNumber;
public:
	PointCloud();
	PointCloud(int);
	PointCloud(const PointCloud&);
	~PointCloud();
	void setPoints(Point*);
	Point* getPoints();
	int getpointNumber()const;
	PointCloud& operator+(const PointCloud&);
	PointCloud& operator=(const PointCloud&);
};