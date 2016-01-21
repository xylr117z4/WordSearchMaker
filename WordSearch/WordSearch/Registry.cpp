#include "Registry.h"

Registry::Registry(){
}

void Registry::registerPositions(std::vector<std::tuple<int, int>> poses){
	for(unsigned int i = 0; i < poses.size(); ++i){
		positions.push_back(poses[i]);
	}
}

void Registry::findOverLaps(){
	std::sort(positions.begin(), positions.end());
	int tempX = 0;
	int tempY = 0;
	for(unsigned int i = 0; i < positions.size(); ++i){
		std::cout << std::get<0>(positions[i]) << ", " << std::get<1>(positions[i]) << "\n\n";
	}
}

Registry::~Registry(){
}

