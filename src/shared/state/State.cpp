
#include "State.h"
#include "Space.h"
#include "Wall.h"
#include "Door.h"
#include "Chest.h"
#include "MainCharacter.h"
#include "Monster.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int state::State::getEpoch() const {
    return epoch;
}

void state::State::setEpoch(int epoch) {
    this->epoch = epoch;
}

int state::State::getEpochRate() const {
    return epochRate;
}

void state::State::setEpochRate(int epochRate) {
    this->epochRate = epochRate;
}

const state::ElementTab &state::State::getFloor() const {
    return floor;
}

const state::ElementTab &state::State::getWall() const {
    return wall;
}


const std::vector<std::shared_ptr<state::MobileElement>> &state::State::getChars() const {
    return chars;
}

void state::State::initFloor(std::string map, int width, int height) {
    this->floor.resize(width,height);

    std::ifstream file(map, ios::in);
    std::string id, line;
    int i = 0;
    int j = 0;
    int ide = 0, id_type = 0;

    std::map<int, int> ids;
    ids[00] = 0;
    ids[11] = TOPLEFT;
    ids[12] = TOPRIGHT;
    ids[13] = BOTTOMRIGHT;
    ids[14] = BOTTOMLEFT;
    ids[15] = HORI;
    ids[16] = VERT_LEFT;
    ids[17] = VERT_RIGHT;
    ids[18] = TOP;
    ids[19] = CORNERLEFT;
    ids[110] = CORNERRIGHT;
    ids[111] = CORNERFRONTLEFT;
    ids[112] = CORNERFRONTRIGHT;
    ids[113] = INNERCORNER_L_TL;
    ids[114] = INNERCORNER_L_TR;
    ids[115] = INNERCORNER_ML;
    ids[116] = INNERCORNER_MR;
    ids[117] = INNERCORNER_T_TL;
    ids[118] = INNERCORNER_T_TR;
    ids[21] = EMPTY;
    ids[62] = PowerBoost;
    std::map<int, std::string> type;
    type[0] = "Empty";
    type[1] = "Wall";
    type[2] = "Space";
    type[3] = "Door";
    type[6] = "Chest";

    if(file){
        while(getline(file,line)){
            std::stringstream stream(line);
            j = 0;
            while(getline(stream,id,',')){
                ide = std::stoi(id);
                if(ide >= 100){
                    id_type = ide/100;
                }else{
                    id_type = ide/10;
                }
                if(type[id_type] == "Space"){
                    Space e{(SpaceTypeId)ids[ide]};
                    this->floor.set(i,j,&e);
                }else if(type[id_type] == "Wall"){
                    Wall e{(WallTypeId)ids[ide]};
                    this->floor.set(i,j,&e);
                }else if(type[id_type] == "Door"){
                    Door e{};
                    this->floor.set(i,j,&e);
                }else if(type[id_type] == "Chest"){
                    Chest e{(ChestContentId)ids[ide]};
                    this->floor.set(i,j,&e);
                }else{

                }
                j++;
            }
            i++;
        }
    }

}

void state::State::initWall(std::string map, int width, int height) {
    this->wall.resize(width,height);

    std::ifstream file(map, ios::in);
    std::string id, line;
    int i = 0;
    int j = 0;
    int ide = 0, id_type = 0;

    std::map<int, int> ids;
    ids[00] = 0;
    ids[11] = TOPLEFT;
    ids[12] = TOPRIGHT;
    ids[13] = BOTTOMRIGHT;
    ids[14] = BOTTOMLEFT;
    ids[15] = HORI;
    ids[16] = VERT_LEFT;
    ids[17] = VERT_RIGHT;
    ids[18] = TOP;
    ids[19] = CORNERLEFT;
    ids[110] = CORNERRIGHT;
    ids[111] = CORNERFRONTLEFT;
    ids[112] = CORNERFRONTRIGHT;
    ids[113] = INNERCORNER_L_TL;
    ids[114] = INNERCORNER_L_TR;
    ids[115] = INNERCORNER_ML;
    ids[116] = INNERCORNER_MR;
    ids[117] = INNERCORNER_T_TL;
    ids[118] = INNERCORNER_T_TR;
    ids[21] = EMPTY;
    ids[22] = START;
    ids[62] = PowerBoost;
    std::map<int, std::string> type;
    type[0] = "Empty";
    type[1] = "Wall";
    type[2] = "Space";
    type[3] = "Door";
    type[6] = "Chest";

    if(file){
        while(getline(file,line)){
            std::stringstream stream(line);
            j = 0;
            while(getline(stream,id,',')){
                ide = std::stoi(id);
                if(ide >= 100){
                    id_type = ide/100;
                }else{
                    id_type = ide/10;
                }
                if(type[id_type] == "Space"){
                    Space e{(SpaceTypeId)ids[ide]};
                    this->wall.set(i,j,&e);
                }else if(type[id_type] == "Wall"){
                    Wall e{(WallTypeId)ids[ide]};
                    this->wall.set(i,j,&e);
                }else if(type[id_type] == "Door"){
                    Door e{};
                    this->wall.set(i,j,&e);
                }else if(type[id_type] == "Chest"){
                    Chest e{(ChestContentId)ids[ide]};
                    this->wall.set(i,j,&e);
                }else{

                }
                j++;
            }
            i++;
        }
    }

}

void state::State::initChars (std::string map, int width, int height){

    std::ifstream file(map, ios::in);
    std::string id, line;
    int i = 0;
    int j = 0;
    int ide = 0, id_type = 0;

    std::map<int, int> ids;
    ids[00] = 0;
    ids[22] = START;
    std::map<int, std::string> type;
    type[0] = "Empty";
    type[1] = "Wall";
    type[2] = "Space";
    type[3] = "MC";
    type[3] = "Door";
    type[6] = "Chest";

    if(file){
        while(getline(file,line)){
            std::stringstream stream(line);
            j = 0;
            while(getline(stream,id,',')){
                ide = std::stoi(id);
                if(ide >= 100){
                    id_type = ide/100;
                }else{
                    id_type = ide/10;
                }
                if(ide==22) {
                    MainCharacter e{};
                    e.setPosition(state::Coords(j,i));
                    this->chars.push_back(std::make_shared<MainCharacter>(e));
                }else{

                }
                if(ide==41) {
                    Monster m{state::GHOST};
                    m.setPosition(state::Coords(j,i));
                    this->monsters.push_back(std::make_shared<Monster>(m));
                }else{

                }
                j++;
            }
            i++;
        }
    }

}

const std::vector<std::shared_ptr<state::MobileElement>> &state::State::getMonsters() const {
    return this->monsters;
}
