//
// Created by josselin on 21/10/2019.
//

#include <iostream>
#include "neighb2d_iterator.h"

neighb2d_iterator::neighb2d_iterator(unsigned nrows, unsigned ncols) : i_{0}, nrows_{nrows}, ncols_{ncols} {
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
    return point2d();
}



