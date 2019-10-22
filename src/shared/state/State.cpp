
#include "State.h"
#include "Space.h"
#include "Wall.h"
#include "Door.h"
#include "Chest.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

state::ElementTab &state::State::getGrid() {
    return grid;
}

state::ElementTab &state::State::getChars() {
    return chars;
}

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

const state::ElementTab &state::State::getGrid() const {
    return grid;
}

const state::ElementTab &state::State::getChars() const {
    return chars;
}

void state::State::initGrid(std::string map, int width, int height) {
    this->grid.resize(width,height);

    std::ifstream file(map, ios::in);
    std::string id, line;
    int i = 0;
    int j = 0;
    int ide = 0;

    std::map<int, int> ids;
    ids[0] = EMPTY;
    ids[1] = TOPLEFT;
    ids[2] = 0;
    ids[3] = PowerBoost;
    ids[4] = HORI;
    std::map<int, std::string> type;
    type[0] = "Space";
    type[1] = "Wall";
    type[2] = "Door";
    type[3] = "Chest";
    type[4] = "Wall";

    if(file){
        while(getline(file,line)){
            std::stringstream stream(line);
            j = 0;
            while(getline(stream,id,',')){
                ide = std::stoi(id);
                if(type[ide] == "Space"){
                    Space e{(SpaceTypeId)ids[ide]};
                    this->grid.set(i,j,&e);
                }else if(type[ide] == "Wall"){
                    Wall e{(WallTypeId)ids[ide]};
                    this->grid.set(i,j,&e);
                }else if(type[ide] == "Door"){
                    Door e{};
                    this->grid.set(i,j,&e);
                }else if(type[ide] == "Chest"){
                    Chest e{(ChestContentId)ids[ide]};
                    this->grid.set(i,j,&e);
                }else{

                }
                j++;
            }
            i++;
        }
    }

}

