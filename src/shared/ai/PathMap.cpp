
#include <state/MainCharacter.h>
#include <state/Monster.h>
#include "PathMap.h"

int const ai::PathMap::getWeight(const Point &p) {
    return 0;
}

void ai::PathMap::setWeight(const Point &p) {

}

const int *const ai::PathMap::getWeights() {
    return nullptr;
}

void ai::PathMap::init(const state::ElementTab &grid, std::vector<std::shared_ptr<state::MobileElement>> chars, state::MainCharacter& mc, const state::Coords& exit) {
    this->weights.push_back(0);
    this->weights.push_back(1);
    this->weights.push_back(2);
    this->weights.push_back(3);
    this->queue = std::priority_queue<Point, std::vector<Point>, PointCompareWeight>();
    int tmp = 10000;
    state::Monster* m;
    state::Coords m_coords;
    state::Coords mc_coords = mc.getPosition();
    for(auto monster : chars) {
        if(std::abs(monster->getPosition().getX() - mc.getPosition().getX()) +
                 std::abs(monster->getPosition().getY() - mc.getPosition().getY())<tmp) {
            tmp = std::abs(monster->getPosition().getX() - mc.getPosition().getX()) +
                  std::abs(monster->getPosition().getY() - mc.getPosition().getY());
            m_coords = state::Coords(monster->getPosition().getX(),monster->getPosition().getY());
        }
    }


    state::Coords *tmp_coord = new state::Coords(mc_coords.getX(),mc_coords.getY());

    if(m_coords.getY() == 0 && m_coords.getX() == 0){
        m_coords.setX(exit.getX());
        m_coords.setY(exit.getY());
    }

    if(m_coords.getY() < mc_coords.getY()){
        if(grid.get(mc_coords.getX(),mc_coords.getY()-1) == NULL) {
            this->queue.push(Point(state::Coords(mc_coords.getX(), mc_coords.getY() - 1), 2));
            this->queue.push(Point(state::Coords(mc_coords.getX(), mc_coords.getY() + 1), 0));
        }else{
            this->queue.push(Point(state::Coords(mc_coords.getX(), mc_coords.getY() - 1), 0));
            this->queue.push(Point(state::Coords(mc_coords.getX(), mc_coords.getY() + 1), 1));
        }
    }else if(m_coords.getY() > mc_coords.getY()){
        if(grid.get(mc_coords.getX(),mc_coords.getY()+1) == NULL) {
            this->queue.push(Point(state::Coords(mc_coords.getX(), mc_coords.getY() - 1), 0));
            this->queue.push(Point(state::Coords(mc_coords.getX(), mc_coords.getY() + 1), 2));
        }else{
            this->queue.push(Point(state::Coords(mc_coords.getX(), mc_coords.getY() - 1), 1));
            this->queue.push(Point(state::Coords(mc_coords.getX(), mc_coords.getY() + 1), 0));
        }
    }

    if(m_coords.getX() < mc_coords.getX()){
        if(grid.get(mc_coords.getX()-1,mc_coords.getY()) == NULL){
            this->queue.push(Point(state::Coords(mc_coords.getX()-1,mc_coords.getY()),2));
            this->queue.push(Point(state::Coords(mc_coords.getX()+1,mc_coords.getY()),0));
        }else{
            this->queue.push(Point(state::Coords(mc_coords.getX()-1,mc_coords.getY()),0));
            this->queue.push(Point(state::Coords(mc_coords.getX()+1,mc_coords.getY()),1));
        }
    }else if(m_coords.getX() > mc_coords.getX()){
        if(grid.get(mc_coords.getX()+1,mc_coords.getY()) == NULL){
            this->queue.push(Point(state::Coords(mc_coords.getX()+1,mc_coords.getY()),2));
            this->queue.push(Point(state::Coords(mc_coords.getX()-1,mc_coords.getY()),0));
        }else{
            this->queue.push(Point(state::Coords(mc_coords.getX()+1,mc_coords.getY()),0));
            this->queue.push(Point(state::Coords(mc_coords.getX()-1,mc_coords.getY()),1));
        }
    }

}

void ai::PathMap::addSink(ai::Point p) {

}

void ai::PathMap::update(const state::ElementTab &grid, std::vector<std::shared_ptr<state::MobileElement>> chars, state::MainCharacter& mc) {

}

const std::priority_queue<ai::Point, std::vector<ai::Point>, ai::PointCompareWeight> ai::PathMap::getQueue() const {
    return queue;
}
