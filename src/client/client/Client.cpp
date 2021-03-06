
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
#include <engine/PathCommand.h>
#include <engine/MoveCommand.h>
#include <engine/AttackCommand.h>
#include "NetworkClient.h"

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
    std::string url = "http://localhost";
    auto net = NetworkClient(url, 8888);
    auto info = net.getGameStatus();
    bool start = true;
    bool menu = true;
    bool lobby = false;
    auto* scene = new render::Scene(engine.getState(),window);

    auto* pos = new state::Coords(10,20);
    auto* move = new engine::MoveCommand(dynamic_cast<state::MainCharacter*>(engine.getState().getChars()[0].get()),pos);
    engine.getState().getChars()[0]->setDirection(state::NORTH);
    engine.addCommand(1,move);
    net.putCommand(std::unique_ptr<engine::MoveCommand>(new engine::MoveCommand(dynamic_cast<state::MainCharacter*>(engine.getState().getChars()[0].get()),pos)));
    auto* attack = new engine::AttackCommand(dynamic_cast<state::MainCharacter*>(engine.getState().getChars()[0].get()));
    engine.addCommand(0,attack);
    bool moving = false;
    sf::Vector2i position = sf::Mouse::getPosition();
    auto* path = new engine::PathCommand(new state::Coords());

    std::thread thread(thread_engine, &engine);
    while (window.isOpen())
    {
        if(menu){

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
                        menu = false;
                        lobby = true;
                    }
                }
            }
            window.clear();
            for(auto drawable : menu_choice){
                window.draw(*drawable);
            }
            window.display();
        }else if (lobby) {
            window.clear();

            //auto info = net.getGameStatus();

            Json::Value player;
            Json::Reader reader;
            reader.parse(info.c_str(), player);
            int height = 100;

            std::vector<std::shared_ptr<sf::Drawable>> lobbyInfo;
            for(int i = 0;i<player["players"].size();i++){
                sf::Text LobbyPlayer;
                LobbyPlayer.setFont(font);
                LobbyPlayer.setString(player["players"][0].asString());
                LobbyPlayer.setCharacterSize(26);
                LobbyPlayer.setFillColor(sf::Color::White);
                LobbyPlayer.setPosition(sf::Vector2f(580.f,height));
                height += 20;
                lobbyInfo.push_back(std::make_shared<sf::Text>(LobbyPlayer));
            }

            sf::RectangleShape StartBox(sf::Vector2f(340.f, 60.f));
            StartBox.setFillColor(sf::Color(250,250,250));
            StartBox.setPosition(sf::Vector2f(800.f,490.f));

            sf::Text StartText;
            StartText.setFont(font);
            StartText.setString("LANCER LE JEU");
            StartText.setCharacterSize(30);
            StartText.setFillColor(sf::Color::Black);
            StartText.setPosition(sf::Vector2f(830.f,500.f));

            lobbyInfo.push_back(std::make_shared<sf::RectangleShape>(StartBox));
            lobbyInfo.push_back(std::make_shared<sf::Text>(StartText));

            for(auto infos : lobbyInfo){
                window.draw(*infos);
            }
            window.display();
	        sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i position = sf::Mouse::getPosition(window);
                    if (StartBox.getGlobalBounds().contains(window.mapPixelToCoords(position)) &&
                        player["players"].size() >= 2) {
                        lobby = false;
                    }
                }
            }
            sf::sleep(sf::milliseconds(100));

        }else {
                // Event processing
                sf::Event event;
                while (window.pollEvent(event)) {
                    switch (event.type) {
                        case sf::Event::Closed:
                            window.close();
                            break;
                        case sf::Event::MouseButtonPressed:
                            position = sf::Mouse::getPosition(window);
                            if(scene->getMoveBounds().contains(window.mapPixelToCoords(position))){
                                pos = new state::Coords(engine.getState().getChars()[0]->getPosition());
                                path = new engine::PathCommand(pos);
                                engine.addCommand(2, path);
                                moving = true;
                            }else if(scene->getAttackBounds().contains(window.mapPixelToCoords(position))) {
                                attack = new engine::AttackCommand(dynamic_cast<state::MainCharacter*>(engine.getState().getChars()[0].get()));
                                engine.addCommand(0,attack);
                            }else {
                                if(moving) {
                                    //std::cout << window.getSize().x << '-' << scene->getWidth() << std::endl;
                                    //std::cout << window.getSize().y << '-' << scene->getHeight() << std::endl;
                                    //std::cout << position.x/16.f << std::endl;
                                    //std::cout << (int) (position.y / (16*((float) window.getSize().y) / (float) scene->getHeight())) << std::endl;
                                    pos->setX((int) (position.x*1.f/16.f));
                                    pos->setY((int) (position.y*1.f/16.f));
                                    move = new engine::MoveCommand(
                                            dynamic_cast<state::MainCharacter *>(engine.getState().getChars()[0].get()), pos);
                                    engine.getState().getChars()[0]->setDirection(state::NORTH);
                                    engine.addCommand(1, move);
                                    moving = false;
                                }
                            }
                            break;
                            default:
                                break;
                    }
                }/*
                character_ai->run(this->engine,
                        *dynamic_cast<state::MainCharacter *>(engine.getState().getChars()[0].get()));*/
                if(dynamic_cast<state::MainCharacter *>(engine.getState().getChars()[0].get())->getVictory()){

                    window.clear();

                    sf::Text VictoryText;
                    VictoryText.setFont(font);
                    VictoryText.setString("Victoire");
                    VictoryText.setCharacterSize(40);
                    VictoryText.setFillColor(sf::Color::White);
                    VictoryText.setPosition(sf::Vector2f(580.f,250.f));
                    window.draw(VictoryText);

                    window.display();
                    dynamic_cast<state::MainCharacter *>(engine.getState().getChars()[0].get())->setVictory(false);
                    sf::sleep(sf::milliseconds(5000));
                    menu = true;
                    lobby = false;
                    engine.init("../res/map.txt","../res/wall.txt");

                }
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
