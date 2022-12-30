/**
* @Author	: Resulberdi Akyyev
* @date		: 24.12.2022
* @file		: DepthCamera.h
*/
#pragma once
#include"PointCloud.h"
#include<fstream>
//! class DepthCamera
class DepthCamera {
private:
	string fileName;
public:
	DepthCamera(string);
	void setfileName(string);
	string getfileName()const;
	PointCloud capture();
};