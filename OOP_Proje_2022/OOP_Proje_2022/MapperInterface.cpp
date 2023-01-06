#include"MapperInterface.h"




void MapperInterface::addGenerator(PointCloudGenerator* _PCG) {
	generators.push_back(_PCG);
}
void MapperInterface::setRecorder(PointCloudRecorder* _PCR) {
	recorder = _PCR;
}
bool MapperInterface::generate() {

	if (generators.size() == 0)return 0;

	list<Point> temp;

	for (int i = 0; i < generators.size(); i++) {
		patch = generators.at(i)->captureFor();
		temp.merge(patch.getPoints());
	}

	pointCloud.setPoints(temp);

	return 1;
}
bool MapperInterface::recordPointCloud() {
	map->insertPointCloud(pointCloud);
	map->saveMap("recordPointCloud");
}
bool MapperInterface::recordMap() {
	map->saveMap("recordMap");
}
bool MapperInterface::insertMap() {
	map->insertPointCloud(pointCloud);
}