/**
* @Author	: Resulberdi Akyyev
* @date		: 24.12.2022
* @file		: PointCloudRecorder.cpp
*/
#include"PointCloudRecorder.h"
/**
* @brief	: Constructor with parameter.
* @param	: _fileName is a parameter for accessing a file.
*/
PointCloudRecorder::PointCloudRecorder(string _fileName) :fileName(_fileName) {}
/**
* @brief	: setfileName is a function for setting fileName.
* @param	: _fileName is a parameter for setting fileName.
*/
void PointCloudRecorder::setfileName(string _fileName) {
	fileName = _fileName;
}
/**
* @brief	: getfileName is a function for returning fileName.
*/
string PointCloudRecorder::getfileName()const {
	return fileName;
}
/**
* @brief	: save is a function for saving PointCloud to a file.
* @param	: _PC is a parameter for saving PointCloud to a file.
*/
bool PointCloudRecorder::save(const PointCloud& _PC)const {

	fstream file;

	file.open(fileName, ios::out);

	if (!file)return 0;

	PointCloud retPC(_PC);

	Point* now = retPC.getPoints();

	file << "//X Y Z\n" << retPC.getpointNumber() << endl;

	for (int i = 0; i < _PC.getpointNumber(); i++) {

		file << (*now).getX() << " " << (*now).getY() << " " << (*now).getZ() << endl;

		now++;
	}
	
	file.close();

	return 1;
}