/**
* @Author	: Resulberdi Akyyev
* @date		: 24.12.2022
* @file		: PointCloudRecorder.h
*/
#pragma once
#include"PointCloud.h"
#include<fstream>
//! class PointCloudRecorder
class PointCloudRecorder {
private:
	string fileName;
public:
	PointCloudRecorder(string);
	void setfileName(string);
	string getfileName()const;
	bool save(const PointCloud&)const;
};