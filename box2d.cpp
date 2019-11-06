//
// Created by josselin on 06/11/2019.
//

#include <iostream>
#include "box2d.h"

bool box2d::has(const box2d::point_type &p) const {
    return (p.col >= fp_.col && p.col <= lp_.col && p.row >= fp_.row && p.row <= lp_.row);
}

box2d::box2d(const box2d::point_type &fp, const box2d::point_type &lp) : lp_{lp}, fp_{fp}, nrows{lp.row-fp.row}, ncols{lp.col-fp.col}{

}

box2d::~box2d() {
    std::cout<<"destroy box"<<std::endl;
}

const box2d& box2d::operator=(box2d &) const {
    return *this;
}

int box2d::rows() const{
    return nrows;
}

int box2d::cols() const{
    return ncols;
}