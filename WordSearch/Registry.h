#ifndef REGISTRY_H
#define REGISTRY_H

#include "globalHeader.h"

class Registry{
public:
	Registry();
	~Registry();
	std::vector<std::tuple<int,int, int,int>> wordData;
	int wordCount;
	void registerWord(ws::vector poses, int dir);
	std::vector<int> findCollisions();
	bool spread(ws::vector& positions, int& dir);
	bool alreadyBeingMoved(std::vector<int> moving, int id);
};

#endif // REGISTRY_H
