#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include "render.h"
#include "engine.h"
#include "ai.h"

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
    engine->init("../res/map.txt","../res/wall.txt");
    auto* scene = new render::Scene(engine->getState(),window);
    auto* pos = new state::Coords(10,20);
    auto* move = new engine::MoveCommand(dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get()),pos);
    engine->getState().getChars()[0]->setDirection(state::NORTH);
    engine->addCommand(1,move);
    auto* attack = new engine::AttackCommand(dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get()));
    engine->addCommand(0,attack);
    bool start = true;
    bool moving = false;
    sf::Vector2i position = sf::Mouse::getPosition();
    auto* path = new engine::PathCommand(new state::Coords());
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
                    if(scene->getMoveBounds().contains(window.mapPixelToCoords(position))){
                        pos = new state::Coords(engine->getState().getChars()[0]->getPosition());
                        path = new engine::PathCommand(pos);
                        engine->addCommand(2, path);
                        moving = true;
                    }else if(scene->getAttackBounds().contains(window.mapPixelToCoords(position))) {
                        attack = new engine::AttackCommand(dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get()));
                        engine->addCommand(0,attack);
                    }else {
                        if(moving) {
                            //std::cout << window.getSize().x << '-' << scene->getWidth() << std::endl;
                            //std::cout << window.getSize().y << '-' << scene->getHeight() << std::endl;
                            //std::cout << position.x/16.f << std::endl;
                            //std::cout << (int) (position.y / (16*((float) window.getSize().y) / (float) scene->getHeight())) << std::endl;
                            pos->setX((int) (position.x*1.f/16.f));
                            pos->setY((int) (position.y*1.f/16.f));
                            move = new engine::MoveCommand(
                                    dynamic_cast<state::MainCharacter *>(engine->getState().getChars()[0].get()), pos);
                            engine->getState().getChars()[0]->setDirection(state::NORTH);
                            engine->addCommand(1, move);
                            moving = false;
                        }
                    }
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
        sf::sleep(sf::milliseconds(100));
        engine->update();
    }
}

void testAI() {
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
    engine->init("../res/map.txt","../res/wall.txt");
    auto* scene = new render::Scene(engine->getState(),window);
    auto* r_ai = new ai::RandomAI(engine->getState(), time(0));
    bool start = true;
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

                default:
                    break;
            }
        }
        r_ai->run(*engine, *dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get()));
        // Clear the whole window before rendering a new frame
        window.clear();
        // Draw some graphical entities
        //window.draw(*surface);
        if(start){
            scene->draw();
            start = false;
        }
        // End the current frame and display its contents on screen
        sf::sleep(sf::milliseconds(100));
        engine->update();
    }
}

void testHeuristicAI() {
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
    engine->init("../res/map.txt","../res/wall.txt");
    auto* scene = new render::Scene(engine->getState(),window);
    auto* r_ai = new ai::HeuristicAI(engine->getState(), time(0));
    bool start = true;
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

                default:
                    break;
            }
        }
        r_ai->run(*engine, *dynamic_cast<state::MainCharacter*>(engine->getState().getChars()[0].get()));
        // Clear the whole window before rendering a new frame
        window.clear();
        // Draw some graphical entities
        //window.draw(*surface);
        if(start){
            scene->draw();
            start = false;
        }
        // End the current frame and display its contents on screen
        sf::sleep(sf::milliseconds(100));
        engine->update();
    }
}

// Fin test SFML

#include <state.h>

using namespace std;
using namespace state;

int main(int argc,char* argv[])
{
    //testSFML();
    //testAI();
    testHeuristicAI();
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
