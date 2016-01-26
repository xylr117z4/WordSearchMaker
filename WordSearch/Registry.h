#ifndef REGISTRY_H
#define REGISTRY_H

#include "globalHeader.h"

class Registry{
public:
	Registry();
	~Registry();
	std::vector<std::tuple<int,int,int>> positions;
	int wordCount;
	void registerWord(ws::vector poses);
	void findCollisions();

};

#endif // REGISTRY_H
