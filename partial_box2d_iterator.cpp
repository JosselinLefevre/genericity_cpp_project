//
// Created by valentin on 08/11/2019.
//

#include "partial_box2d_iterator.h"
#include <iostream>

partial_box2d_iterator::partial_box2d_iterator(const partial_box2d& box) {
    dom_ = box;
    curr_p = point2d();
}

void partial_box2d_iterator::start() {
    this->curr_p = this->dom_.ima_.domain().fp_;
}

bool partial_box2d_iterator::is_valid() {
    return dom_.has(curr_p);
}

void partial_box2d_iterator::next() {
    this->curr_p.row = curr_p.col == dom_.ima_.domain().lp_.col ? this->curr_p.row + 1 : this->curr_p.row;
    this->curr_p.col = curr_p.col == dom_.ima_.domain().lp_.col ? 0 : this->curr_p.col + 1;
    if(is_valid() && dom_.ima_(curr_p)==0){
        next();
    }
}

point2d &partial_box2d_iterator::value() {
    return this->curr_p;
}



