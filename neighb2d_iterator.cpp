//
// Created by josselin on 21/10/2019.
//

#include <iostream>
#include "neighb2d_iterator.h"

neighb2d_iterator::neighb2d_iterator() : i_{0} {
    delta_.emplace_back(-1, 0);
    delta_.emplace_back(0, -1);
    delta_.emplace_back(1, 0);
    delta_.emplace_back(0, 1);
}

void neighb2d_iterator::center_at(point2d &p) {
    p_ = p;
}

void neighb2d_iterator::start() {
    i_ = 0;
}

bool neighb2d_iterator::is_valid() {
    return i_<5;
}

void neighb2d_iterator::next() {
    i_++;
}

point2d neighb2d_iterator::value() {
    point2d n;
    n.row = p_.row + delta_[i_].row;
    n.col = p_.col + delta_[i_].col;
    return n;
}



