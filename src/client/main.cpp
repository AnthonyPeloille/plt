#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include "render.h"
#include "engine.h"

void testSFML() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML window");
    sf::Texture texture;
    texture.loadFromFile("../res/DungeonTiles/0x72_DungeonTilesetII_v1.3.png");
    sf::RenderStates states;
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(16, 16, 16, 16));
    //sprite.setColor(sf::Color(255, 255, 255, 200));
    sprite.setPosition(100, 25);
    //window.draw(sprite);
    //state->getGrid().resize(10,10);
    auto* engine = new engine::Engine();
    auto* scene = new render::Scene(engine->getState(),window);
    auto* pos = new state::Coords(0,20);
    auto* move = new engine::MoveCommand(dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get()),pos);
    engine->getState().getChars()[0]->setDirection(state::NORTH);
    engine->addCommand(0,move);
    bool start = true;
    sf::Vector2i position = sf::Mouse::getPosition();
    while (window.isOpen())
    {
        // Event processing
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::Resized:
                    scene->draw();
                    break;

                case sf::Event::KeyPressed:

                    break;

                case sf::Event::MouseMoved:
                    //std::cout << engine->getState().getChars()[0]->getPosition().getX() << " - " << engine->getState().getChars()[0]->getPosition().getY() << std::endl;

                    break;

                case sf::Event::MouseButtonPressed:
                    position = sf::Mouse::getPosition(window);
                    std::cout << window.getSize().x << '-' << scene->getWidth() << std::endl;
                    pos->setX((int)(position.x/(((float)window.getSize().x)/(float)scene->getWidth()))/16);
                    pos->setY((int)(position.y/(((float)window.getSize().y)/(float)scene->getHeight()))/16);
                    move = new engine::MoveCommand(dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get()),pos);
                    engine->getState().getChars()[0]->setDirection(state::NORTH);
                    engine->addCommand(0,move);
                    break;

                default:
                    break;
            }
        }
        // Clear the whole window before rendering a new frame
        window.clear();
        // Draw some graphical entities
        //window.draw(*surface);
        if(start){
            scene->draw();
            start = false;
        }
        // End the current frame and display its contents on screen
        sf::sleep(sf::milliseconds(1000));
        engine->update();
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
