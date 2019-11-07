//
// Created by josselin on 16/10/2019.
//


#include "box2d_iterator.h"
#include <iostream>

box2d_iterator::box2d_iterator(const box2d& box) {
    dom_ = box;
    curr_p = point2d();
}

void box2d_iterator::start() {
    this->curr_p = this->dom_.fp_;
}

bool box2d_iterator::is_valid() {
    return curr_p.row < dom_.lp_.row + 1;
}

void box2d_iterator::next() {
    if(is_valid()){
        this->curr_p.row = curr_p.col == dom_.lp_.col ? this->curr_p.row + 1 : this->curr_p.row;
        this->curr_p.col = curr_p.col == dom_.lp_.col ? 0 : this->curr_p.col + 1;
    }
}

point2d &box2d_iterator::value() {
    return this->curr_p;
}



