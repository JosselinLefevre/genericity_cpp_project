//
// Created by Valentin on 08/11/2019.
//

#include <iostream>
#include "partial_box2d.h"

partial_box2d::partial_box2d(image2d<unsigned> &ima) : ima_{ima}{
}

partial_box2d::partial_box2d() = default;

partial_box2d::~partial_box2d() = default;

bool partial_box2d::has(const partial_box2d::point_type &p) const {
    return (p.col >= ima_.domain().fp_.col && p.col <= ima_.domain().lp_.col && p.row >= ima_.domain().fp_.row && p.row <= ima_.domain().lp_.row && ima_(p)!=0);
}

int partial_box2d::rows() const{
    return ima_.domain().rows();
}

int partial_box2d::cols() const{
    return ima_.domain().cols();
}

partial_box2d &partial_box2d::operator=(const partial_box2d &b) {
    ima_ = b.ima_;
    return *this;
}