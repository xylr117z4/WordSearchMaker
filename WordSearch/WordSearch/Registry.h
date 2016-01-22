#ifndef REGISTRY_H
#define REGISTRY_H

#include "globalHeader.h"

class Registry{
public:
	Registry();
	~Registry();
	ws::vector positions;
	std::vector<int> ids;
	void registerWord(ws::vector poses);
	void findCollisions();

};

#endif // REGISTRY_H
