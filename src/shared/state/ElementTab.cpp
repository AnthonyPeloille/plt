
#include "ElementTab.h"

state::ElementTab::ElementTab(size_t width, size_t height) {
    this->width = width;
    this->height = height;
    element_list.resize(height);
    for (auto &h_list : element_list){
        h_list.resize(width);
    }
}

size_t state::ElementTab::getWidth() const{
    return width;
}

size_t state::ElementTab::getHeight() const{
    return height;
}

void state::ElementTab::resize(size_t width, size_t height) {
    this->width = width;
    this->height = height;
    element_list.resize(height);
    for (auto &h_list : element_list){
        h_list.resize(width);
    }
}

state::Element *const state::ElementTab::get(int i, int j) {
    return element_list[i][j].get();
}

void state::ElementTab::set(int i, int j, Element *e) {
    element_list[i][j].reset(e->clone());
}

/*
const state::Element &state::ElementTab::operator()(int i, int j) {
    return <#initializer#>;
}
*/
