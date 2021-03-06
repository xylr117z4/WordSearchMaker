#include "Registry.h"

Registry::Registry(){
}

void Registry::registerWord(ws::vector poses){
	int startSize = ids.size();
	for(unsigned int i = 0; i < poses.size(); ++i){
		positions.push_back(poses[i]);
		ids.push_back(startSize+1);
	}
}

void Registry::findCollisions(){
	std::sort(positions.begin(), positions.end());
	std::tuple<int, int> temp;
	for(unsigned int i = 0; i < positions.size(); ++i){
		
		temp = std::make_tuple(std::get<0>(positions[i]), std::get<1>(positions[i]));
		
		for(unsigned int c = 0; c < positions.size(); ++c){
			std::tuple<int, int> workingTemp = std::make_tuple(std::get<0>(positions[c]), std::get<1>(positions[c]));
			if(c != i){
				if(temp == workingTemp){
					printf("probably a collision:\nID1: %d X1: %d Y1: %d\nID2: %d X2: %d Y2: %d\n\n", ids[i], std::get<0>(temp), std::get<1>(temp), ids[c], std::get<0>(workingTemp), std::get<1>(workingTemp));
				}
			}			
		}
	}
}

Registry::~Registry(){
}

