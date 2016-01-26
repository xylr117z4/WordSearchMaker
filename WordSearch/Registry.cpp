#include "Registry.h"

Registry::Registry(){
	wordCount = 0;
}

void Registry::registerWord(ws::vector poses, int dir){
	for(unsigned int i = 0; i < poses.size(); ++i){
		wordData.push_back(std::make_tuple(std::get<0>(poses[i]), std::get<1>(poses[i]), wordCount, dir));
	}
	++wordCount;
}

std::vector<int> Registry::findCollisions(){
	std::sort(wordData.begin(), wordData.end());
	std::tuple<int, int> temp;
	std::vector<int> needToBeMoved;
	for(unsigned int i = 0; i < wordData.size(); ++i){
		
		temp = std::make_tuple(std::get<0>(wordData[i]), std::get<1>(wordData[i]));
		
		for(unsigned int c = 0; c < wordData.size(); ++c){
			std::tuple<int, int> workingTemp = std::make_tuple(std::get<0>(wordData[c]), std::get<1>(wordData[c]));
			if(c != i){
				if(std::get<0>(temp) == std::get<0>(workingTemp) && std::get<1>(temp) == std::get<1>(workingTemp)){
					if(!alreadyBeingMoved(needToBeMoved, std::get<2>(wordData[i]))){
						needToBeMoved.push_back(std::get<2>(wordData[i])); //add first word id to vector
					}
				}
			}			
		}
	}
	return needToBeMoved;
}

bool Registry::alreadyBeingMoved(std::vector<int> moving, int id){
	for(unsigned int i = 0; i < moving.size(); ++i){
		if(moving[i] == id){
			return true;
		}
	}
	return false;
}

Registry::~Registry(){
}

