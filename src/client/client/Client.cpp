
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
    sf::Font font;
    font.loadFromFile("../res/Font/ThickThinPixel.ttf");
    std::vector<std::shared_ptr<sf::Drawable>> menu_choice;

    sf::Text LocalText;
    LocalText.setFont(font);
    LocalText.setString("JEU LOCAL");
    LocalText.setCharacterSize(23);
    LocalText.setFillColor(sf::Color::Black);
    LocalText.setPosition(sf::Vector2f(580.f,285.f));

    sf::Text NetworkText;
    NetworkText.setFont(font);
    NetworkText.setString("JEU EN RESEAU");
    NetworkText.setCharacterSize(23);
    NetworkText.setFillColor(sf::Color::Black);
    NetworkText.setPosition(sf::Vector2f(580.f,355.f));

    sf::RectangleShape LocalBox(sf::Vector2f(340.f, 60.f));
    LocalBox.setFillColor(sf::Color(250,250,250));
    LocalBox.setPosition(sf::Vector2f(500.f,270.f));

    sf::RectangleShape NetworkBox(sf::Vector2f(340.f, 60.f));
    NetworkBox.setFillColor(sf::Color(250,250,250));
    NetworkBox.setPosition(sf::Vector2f(500.f,340.f));

    menu_choice.push_back(std::make_shared<sf::RectangleShape>(LocalBox));
    menu_choice.push_back(std::make_shared<sf::RectangleShape>(NetworkBox));
    menu_choice.push_back(std::make_shared<sf::Text>(LocalText));
    menu_choice.push_back(std::make_shared<sf::Text>(NetworkText));

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
                    window.close();
                if (event.type == sf::Event::KeyPressed)
                    menu = false;
                if (event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i position = sf::Mouse::getPosition(window);
                    if (LocalBox.getGlobalBounds().contains(window.mapPixelToCoords(position))) {
                        menu = false;
                    }
                    if (NetworkBox.getGlobalBounds().contains(window.mapPixelToCoords(position))) {
                        //
                    }
                }
            }
            window.clear();
            for(auto drawable : menu_choice){
                window.draw(*drawable);
            }
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
