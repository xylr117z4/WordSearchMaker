#include "globalHeader.h"
#include "classes.h"

void getFilesInDir(std::string dir){
	DIR *dirp;
	dirp = opendir(dir.c_str());
	
	struct dirent *dp;
	
	do{
		if((dp = readdir(dirp)) != NULL){
			printf("found %s\n", dp->d_name);
		}
		else{
			closedir(dirp);
		}
	} while(dp != NULL);
}

int main(){
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	srand(time(NULL));
	
	sf::Font font;
	font.loadFromFile("LiberationSans-Regular.ttf");
	sf::Text text;
	text.setFont(font);
	std::stringstream ss;
	
	std::string list[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	std::vector<Word> words;
	Registry reg;
	
	for(unsigned int i = 0; i < 10; ++i){
		Word temp;
		temp.setWord(list[i]);
		temp.slide((rand()%14)+6, (rand()%14)+6, rand()%8);
		reg.registerWord(temp.positions, temp.direction);
		words.push_back(temp);
	}
	
	std::vector<int> needToBeMoved = reg.findCollisions();
	for(unsigned int i = 0; i < needToBeMoved.size(); ++i){
		std::cout << needToBeMoved[i] << "\n\n";
	}
    
    while (window.isOpen()){
        // Process events
        sf::Event event;
        while (window.pollEvent(event)){
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
		
		ss.str("");
		ss << sf::Mouse::getPosition(window).x/24 << ", " << sf::Mouse::getPosition(window).y/24;
		text.setString(ss.str());
		
        // Clear screen
        window.clear();
		
		// Draw Mouse Pos
		window.draw(text);
		
		for(unsigned int i = 0; i < words.size(); ++i){
			words[i].draw(window);
		}
		
		// Display content
        window.display();
    }
    return EXIT_SUCCESS;
}
