#ifndef REGISTRY_H
#define REGISTRY_H

#include "globalHeader.h"

class Registry{
public:
	Registry();
	~Registry();
	std::vector<std::tuple<int , int>> positions;
	void registerPositions(std::vector<std::tuple<int, int>> poses);
	void findOverLaps();

};

#endif // REGISTRY_H
