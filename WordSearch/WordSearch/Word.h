#ifndef WORD_H
#define WORD_H

#include "globalHeader.h"

class Word{
public:
	Word();
	~Word();
	std::vector<char> characters;
	std::vector<std::tuple<int, int>> startPositions;
	std::vector<std::tuple<int, int>> positions;
	void addChar(char character);
	void setWord(std::string word);
	void setPosition(int x, int y);
	void slide(int x, int y, int dir);
	void rotate(int dir);
	void draw(sf::RenderWindow &window);
};

#endif // WORD_H
