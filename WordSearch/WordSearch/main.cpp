#include "globalHeader.h"
#include "classes.h"

//github test

int main(){
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	srand(time(NULL));
	
	std::string list[10] = {"hello", "nope", "yep", "test", "no", "yes", "twenty", "thirty", "fourty", "fifty"};
	std::vector<Word> words;
	for(unsigned int i = 0; i < 10; ++i){
		Word temp;
		temp.setWord(list[i]);
		temp.slide((rand()%14)+6, (rand()%14)+6, rand()%8);
		words.push_back(temp);
	}
    
    while (window.isOpen()){
        // Process events
        sf::Event event;
        while (window.pollEvent(event)){
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
		
		for(unsigned int i = 0; i < words.size(); ++i){
			words[i].draw(window);
		}
		
		// Display content
        window.display();
    }
    return EXIT_SUCCESS;
}
