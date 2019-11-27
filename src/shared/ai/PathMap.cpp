
#include "PathMap.h"

int const ai::PathMap::getWeight(const Point &p) {
    return 0;
}

void ai::PathMap::setWeight(const Point &p) {

}

const int *const ai::PathMap::getWeights() {
    return nullptr;
}

void ai::PathMap::init(const state::ElementTab &grid, std::vector<std::shared_ptr<state::MobileElement>> chars) {
    this->weights.push_back(0);
    this->weights.push_back(1);
    this->weights.push_back(2);
    this->weights.push_back(3);

}

void ai::PathMap::addSink(ai::Point p) {

}

void ai::PathMap::update(const state::ElementTab &grid, std::vector<std::shared_ptr<state::MobileElement>> chars) {

}
