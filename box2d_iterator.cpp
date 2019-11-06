//
// Created by josselin on 16/10/2019.
//


#include "box2d_iterator.h"
#include <iostream>

box2d_iterator::box2d_iterator(box2d box): dom_(box), curr_p(box.fp_.row, box.fp_.col){
}
void box2d_iterator::start() {
    this->curr_p = this->dom_.fp_;
}

bool box2d_iterator::is_valid() {
    return curr_p.col < dom_.lp_.col + 1;
}

void box2d_iterator::next() {
    if(is_valid()){
        this->curr_p.col = curr_p.row == dom_.lp_.row ? this->curr_p.col + 1 : this->curr_p.col;
        this->curr_p.row = curr_p.row == dom_.lp_.row ? 0 : this->curr_p.row + 1;
    }
}

point2d &box2d_iterator::value() {
    std::cout << "(" << curr_p.row << ", " << curr_p.col << ")" << std::endl;
    return this->curr_p;
}



