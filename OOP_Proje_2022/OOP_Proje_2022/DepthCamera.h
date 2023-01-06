/**
* @Author	: Resulberdi Akyyev
* @date		: 24.12.2022
* @file		: DepthCamera.h
*/
#pragma once
#include"PointCloudGenerator.h"
//! class DepthCamera
class DepthCamera :public PointCloudGenerator {
private:
	string fileName;
public:
	DepthCamera(string);
	void setfileName(string);
	string getfileName()const;
	PointCloud capture();
	PointCloud captureFor();
};