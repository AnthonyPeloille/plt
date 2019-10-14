
#include "ElementTab.h"

state::ElementTab::ElementTab(size_t width, size_t height) {
    this->width = width;
    this->height = height;
    element_list.resize(height);
    for (auto &h_list : element_list){
        h_list.resize(width);
    }
}

const size_t state::ElementTab::getWidth() {
    return width;
}

const size_t state::ElementTab::getHeight() {
    return height;
}

/*size_t state::ElementTab::add(Element *e) {
    return 0;
}*/

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
    element_list[i][j] = std::move(std::unique_ptr<Element> (e));
}

/*
const state::Element &state::ElementTab::operator()(int i, int j) {
    return <#initializer#>;
}
*/
