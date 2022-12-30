/**
* @Author	: Resulberdi Akyyev
* @date		: 24.12.2022
* @file		: Transform_PointCloudRecorder_DepthCamera_TEST.cpp
*/
#include"DepthCamera.h"
#include"PointCloudRecorder.h"
#include"Transform.h"
#include<iomanip>
/**
* @brief	: Testing classes if getting file doing transform and saving PointCloud to a file.
*/
void Transform_PointCloudRecorder_DepthCamera_TEST() {

	double rotat0[3][3] = { -0.7076050, 0.0065031, -0.7065783,
						 0.7066082, 0.0065134, -0.7075750,
						 0.0000008, -0.9999576, -0.0092041 };
	double rotat1[3][3] = { -0.6638364, -0.0068830, 0.7478462,
							-0.7478778, 0.0061099, -0.6638082,
							-0.0000002, -0.9999576, -0.0092036 };
	double rotat2[3][3] = { 0.8762180, 0.0044351, -0.4818945,
							0.4819149, -0.0080638, 0.8761809,
							0.0000001, -0.9999577, -0.0092030 };
	double rotat3[3][3] = { 0.3597052, -0.0085871, 0.9330265,
							-0.9330660, -0.0033108, 0.3596900,
							0.0000003, -0.9999576, -0.0092033 };
	double trans0[3] = { 1.95704, 1.93000, 1.05707 };
	double trans1[3] = { -1.91288, 1.94412, 1.05465 };
	double trans2[3] = { 1.96978, -1.94622, 1.05264 };
	double trans3[3] = { -1.87445, -1.95027, 1.06432 };

	DepthCamera DC0("cam.txt");
	DepthCamera DC1("cam1.txt");
	DepthCamera DC2("cam2.txt");
	DepthCamera DC3("cam3.txt");

	PointCloud PC0 = DC0.capture();
	PointCloud PC1 = DC1.capture();
	PointCloud PC2 = DC2.capture();
	PointCloud PC3 = DC3.capture();

	Transform T0(&rotat0[0][0], &trans0[0]);
	Transform T1(&rotat1[0][0], &trans1[0]);
	Transform T2(&rotat2[0][0], &trans2[0]);
	Transform T3(&rotat3[0][0], &trans3[0]);

	PC0 = T0.doTransform(PC0);
	PC1 = T1.doTransform(PC1);
	PC2 = T2.doTransform(PC2);
	PC3 = T3.doTransform(PC3);

	PointCloudRecorder PCR0("cam0_cýktý.txt");
	PointCloudRecorder PCR1("cam1_cýktý.txt");
	PointCloudRecorder PCR2("cam2_cýktý.txt");
	PointCloudRecorder PCR3("cam3_cýktý.txt");

	PCR0.save(PC0);
	PCR1.save(PC1);
	PCR2.save(PC2);
	PCR3.save(PC3);
}
int main() {

	Transform_PointCloudRecorder_DepthCamera_TEST();

	system("pause");

	return 0;
}