#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::Texture texture;
    texture.loadFromFile("../res/DungeonTiles/0x72_DungeonTilesetII_v1.3.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(16, 16, 16, 16));
    //sprite.setColor(sf::Color(255, 255, 255, 200));
    sprite.setPosition(100, 25);
    window.draw(sprite);
    while (window.isOpen())
    {
        // Event processing
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Request for closing the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear the whole window before rendering a new frame
        window.clear();
        // Draw some graphical entities
        window.draw(sprite);
        // End the current frame and display its contents on screen
        window.display();
    }
}

// Fin test SFML

#include <state.h>

using namespace std;
using namespace state;

int main(int argc,char* argv[])
{
    testSFML();
    //Exemple exemple;
    //exemple.setX(53);
    //state::Door door {};
    //cout << door.getTypeId() << endl;
    
    if(argc > 1){
        if(argv[1] == std::string("hello")){	
            cout << "Bonjour le monde !" << endl;
        }
    }

    return 0;
}
