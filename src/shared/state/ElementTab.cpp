
#include "ElementTab.h"

state::ElementTab::ElementTab(size_t width, size_t height) {

}

const size_t state::ElementTab::getWidth() {
    return width;
}

const size_t state::ElementTab::getHeight() {
    return height;
}

size_t state::ElementTab::add(Element *e) {
    return 0;
}

void state::ElementTab::resize(size_t width, size_t height) {

}

state::Element *const state::ElementTab::get(int i, int j) {
    return nullptr;
}

void state::ElementTab::set(int i, int j, Element *e) {

}

/*
const state::Element &state::ElementTab::operator()(int i, int j) {
    return <#initializer#>;
}
*/