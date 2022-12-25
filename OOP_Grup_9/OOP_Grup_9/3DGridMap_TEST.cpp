/**
* @Author	: Ali Yalnýz
* @date		: 24.12.2022
* @file		: 3DGridMap_TEST.cpp
*/
#include"3DGridMap.h"
#include"DepthCamera.h"
#include"PointCloudRecorder.h"
#include"Transform.h"
#include<iomanip>
/**
* @brief	: GridMap_TEST is a function for testing GridMap.
*/
void GridMap_TEST() {
	double rotat0[3][3] = { -0.7076050, 0.0065031, -0.7065783,
					 0.7066082, 0.0065134, -0.7075750,
					 0.0000008, -0.9999576, -0.0092041 };

	double trans0[3] = { 1.95704, 1.93000, 1.05707 };

	GridMap gridMap;

	DepthCamera DC0("cam.txt");

	PointCloud PC0 = DC0.capture();

	Transform T0(&rotat0[0][0], &trans0[0]);

	PC0 = T0.doTransform(PC0);

	gridMap.insertPointCloud(PC0);

	cout << "GridMap gridSize is: " << gridMap.getgridSize() << endl;
	cout << "GridMap has " << gridMap.getdepth() << " depth." << endl;

	gridMap.saveMap("gridMap.txt");

	GridMap loaderMap;

	loaderMap.loadMap("gridMap.txt");


	cout << "loaderMap gridSize is: " << gridMap.getgridSize() << endl

		<< "loaderMap has " << gridMap.getdepth() << " depth." << endl;

}

int main() {

	GridMap_TEST();

	system("pause");

	return 0;
}