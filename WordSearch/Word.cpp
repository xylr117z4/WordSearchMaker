#include "Word.h"

Word::Word()
{
}

void Word::addChar(char character){
	characters.push_back(character);
	int x = 0;
	int y = 0;
	if(startPositions.size() > 0){
		x = std::get<0>(startPositions.back())+1;
		y = std::get<1>(startPositions.back());
	}
	startPositions.push_back(std::make_tuple(x, y));
	positions.push_back(std::make_tuple(x, y));
}

void Word::setWord(std::string word){
	for(unsigned int i = 0; i < word.length(); ++i){
		addChar(word[i]);
	}
	setPosition(0, 0);
}

void Word::setPosition(int x, int y){
	for(unsigned int i = 0; i < startPositions.size(); ++i){
		startPositions[i] = std::make_tuple(x+i, y);
		positions[i] = std::make_tuple(x+i, y);
	}
}

void Word::slide(int x, int y, int dir){
	setPosition(x, y);
	rotate(dir);
}

void Word::rotate(int dir){
	direction = dir;
	int x = 0;
	int y = 0;
	int startX = std::get<0>(startPositions[0]);
	for(unsigned int i = 0; i < startPositions.size(); ++i){
		
		x = std::get<0>(startPositions[i]);
		y = std::get<1>(startPositions[i]);
		switch(dir){
			case 0: //right
				break;
			case 1: //down right
				y += i;
				break;
			case 2: //down
				x = startX;
				y += i;
				break;
			case 3: //down left
				x = startX-i;
				y += i;
				break;
			case 4: //left
				x = startX-i;
				break;
			case 5: //up left
				x = startX-i;
				y -= i;
				break;
			case 6: //up
				x = startX;
				y -= i;
				break;
			case 7: //up right
				y -= i;
				break;
		}
		positions[i] = std::make_tuple(x, y);
	}
}

void Word::draw(sf::RenderWindow &window){
	sf::Font font;
	font.loadFromFile("LiberationSans-Regular.ttf");
	for(unsigned int i = 0; i < characters.size(); ++i){
		sf::Text temp;
		temp.setFont(font);
		temp.setString(characters[i]);
		temp.setPosition(std::get<0>(positions[i])*24, std::get<1>(positions[i])*24);
		window.draw(temp);
	}
}

Word::~Word()
{
}

