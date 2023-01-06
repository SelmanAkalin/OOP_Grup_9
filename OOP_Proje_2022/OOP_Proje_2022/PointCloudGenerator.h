#pragma once
#include"PointCloud.h"
#include"Transform.h"
#include<fstream>

class PointCloudGenerator {
//private:
//	string fileName;
protected:
	Transform transform;
public:
	//PointCloudGenerator(string, Transform);
	//void settransform(Transform);
	//Transform& gettransform();
	//void setfileName(string);
	//string getfileName() const;
	virtual PointCloud capture() = 0;
	virtual PointCloud captureFor() = 0;
};