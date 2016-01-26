#include "Registry.h"

Registry::Registry(){
	wordCount = 0;
}

void Registry::registerWord(ws::vector poses){
	for(unsigned int i = 0; i < poses.size(); ++i){
		positions.push_back(std::make_tuple(std::get<0>(poses[i]), std::get<1>(poses[i]), wordCount));
	}
	++wordCount;
}

void Registry::findCollisions(){
	std::sort(positions.begin(), positions.end());
	std::tuple<int, int> temp;
	for(unsigned int i = 0; i < positions.size(); ++i){
		
		temp = std::make_tuple(std::get<0>(positions[i]), std::get<1>(positions[i]));
		
		for(unsigned int c = 0; c < positions.size(); ++c){
			std::tuple<int, int> workingTemp = std::make_tuple(std::get<0>(positions[c]), std::get<1>(positions[c]));
			if(c != i){
				if(std::get<0>(temp) == std::get<0>(workingTemp) && std::get<1>(temp) == std::get<1>(workingTemp)){
					printf("id1: %d X: %d Y: %d \nid2: %d X: %d Y: %d\n\n", std::get<2>(positions[i]), std::get<0>(positions[i]), std::get<1>(positions[i]), std::get<2>(positions[c]), std::get<0>(positions[c]), std::get<1>(positions[c]));
				}
			}			
		}
	}
}

Registry::~Registry(){
}

