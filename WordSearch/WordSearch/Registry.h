#ifndef REGISTRY_H
#define REGISTRY_H

#include "globalHeader.h"

class Registry{
public:
	Registry();
	~Registry();
	ws::vector positions;
	void registerPositions(ws::vector poses);
	void findCollisions();

};

#endif // REGISTRY_H
