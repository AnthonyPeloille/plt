
#include "PointCompareWeight.h"

bool ai::PointCompareWeight::operator()(const Point &a, const Point &b) {
    if(a.getWeight() < b.getWeight()){
        return true;
    }else{
        return false;
    }
}
