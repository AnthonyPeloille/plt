
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
    ids[11] = TOPLEFT;
    ids[12] = TOPRIGHT;
    ids[13] = BOTTOMRIGHT;
    ids[14] = BOTTOMLEFT;
    ids[15] = HORI;
    ids[16] = VERT;
    ids[21] = EMPTY;
    ids[41] = PowerBoost;
    std::map<int, std::string> type;
    type[1] = "Wall";
    type[2] = "Space";
    type[3] = "Door";
    type[4] = "Chest";

    if(file){
        while(getline(file,line)){
            std::stringstream stream(line);
            j = 0;
            while(getline(stream,id,',')){
                ide = std::stoi(id);
                if(type[ide/10] == "Space"){
                    Space e{(SpaceTypeId)ids[ide]};
                    this->grid.set(i,j,&e);
                }else if(type[ide/10] == "Wall"){
                    Wall e{(WallTypeId)ids[ide]};
                    this->grid.set(i,j,&e);
                }else if(type[ide/10] == "Door"){
                    Door e{};
                    this->grid.set(i,j,&e);
                }else if(type[ide/10] == "Chest"){
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

