#ifndef WORD_H
#define WORD_H

#include "globalHeader.h"

class Word{
public:
	Word();
	~Word();
	std::vector<char> characters;
	ws::vector startPositions;
	ws::vector positions;
	int direction;
	void addChar(char character);
	void setID(int id);
	void setWord(std::string word);
	void setPosition(int x, int y);
	void slide(int x, int y, int dir);
	void rotate(int dir);
	void draw(sf::RenderWindow &window);
};

#endif // WORD_H
