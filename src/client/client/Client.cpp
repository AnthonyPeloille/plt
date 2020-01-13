
#include "Client.h"
#include "../render/Scene.h"
#include <iostream>
#include <unistd.h>
#include <thread>
#include <pthread.h>
#include <ai/HeuristicAI.h>
#include <state/MainCharacter.h>
#include <SFML/Graphics.hpp>
#include <SFML/System/Sleep.hpp>

bool v1 = false;
bool v2 = true;
void thread_engine(void* ptr){
    auto* ptr_engine = (engine::Engine*) ptr;
    while(v2){
        usleep(1000);
        if(v1){
            ptr_engine->update();
            v1 = false;
        }
    }
}

client::Client::Client() {
    engine.init("../res/map.txt","../res/wall.txt");
    engine.registerObserver(this);
    character_ai = std::unique_ptr<ai::HeuristicAI>(new ai::HeuristicAI(engine.getState(), time(0)));
}

void client::Client::engineUpdating() {
    v1=true;
    usleep(1000);
}

void client::Client::engineUpdated() {

}

void client::Client::run() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML window");
    sf::Texture texture;
    texture.loadFromFile("../res/DungeonTiles/0x72_DungeonTilesetII_v1.3.png");
    sf::RenderStates states;
    sf::Sprite sprite;
    sprite.setTexture(texture);
    bool start = true;
    bool menu = true;
    auto* scene = new render::Scene(engine.getState(),window);
    std::thread thread(thread_engine, &engine);
    while (window.isOpen())
    {
        if(menu){
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    return;
                if (event.type == sf::Event::KeyPressed)
                    menu = false;
            }
            window.clear();
            window.draw(sprite);
            window.display();
        }else {
            // Event processing
            sf::Event event;
            while (window.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::Closed:
                        window.close();
                        break;

                    default:
                        break;
                }
            }
            character_ai->run(this->engine,
                              *dynamic_cast<state::MainCharacter *>(engine.getState().getChars()[0].get()));
            // Clear the whole window before rendering a new frame
            window.clear();
            // Draw some graphical entities
            //window.draw(*surface);
            if (start) {
                scene->draw();
                start = false;
            }
            // End the current frame and display its contents on screen
            sf::sleep(sf::milliseconds(100));
            engine.update();
        }
    }
    v2=false;
    thread.join();
}
