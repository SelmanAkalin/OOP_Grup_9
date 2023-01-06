#include"PointCloudGenerator.h"

//PointCloudGenerator::PointCloudGenerator(string _FN, Transform _TR) :fileName(_FN), transform(_TR) {}
//void PointCloudGenerator::settransform(Transform _TR) {
//	transform = _TR;
//}
//Transform& PointCloudGenerator::gettransform() {
//	return transform;
//}
//void PointCloudGenerator::setfileName(string _FN) {
//	fileName = _FN;
//}
//string PointCloudGenerator::getfileName() const{
//	return fileName;
//}
PointCloud PointCloudGenerator::capture(){
	//fstream file(fileName, ios::in);

	//if (!file) return false;

	//file.ignore(256, '\n');

	//int sizePC;

	//file >> sizePC;

	//PointCloud turnPC(sizePC);

	//list<Point> tempP;

	//while (!file.eof()) {

	//	double X, Y, Z;
	//	Point pP;
	//	file >> X >> Y >> Z;
	//	pP.setX(X);
	//	pP.setY(Y);
	//	pP.setZ(Z);
	//	tempP.push_back(pP);
	//	file.ignore(256, '\n');
	//			
	//}

	//turnPC.setPoints(tempP);

	//file.close();

	//return turnPC;
}
PointCloud PointCloudGenerator::captureFor() {
	/*fstream file(fileName, ios::in);

	if (!file) return false;

	file.ignore(256, '\n');

	int sizePC;

	file >> sizePC;

	PointCloud turnPC(sizePC);

	list<Point> tempP = turnPC.getPoints();

	while (!file.eof()) {

		double X, Y, Z;
		Point pP;
		file >> X >> Y >> Z;
		pP.setX(X);
		pP.setY(Y);
		pP.setZ(Z);
		tempP.push_back(pP);
		file.ignore(256, '\n');

	}

	turnPC.setPoints(tempP);

	transform.doTransform(turnPC);

	file.close();

	return turnPC;*/
}