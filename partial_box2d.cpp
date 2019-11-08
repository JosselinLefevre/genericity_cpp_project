//
// Created by josselin on 06/11/2019.
//

#include <iostream>
#include "box2d.h"

box2d::box2d(const box2d::point_type &fp, const box2d::point_type &lp) : lp_{lp}, fp_{fp}, nrows{lp.row-fp.row+1}, ncols{lp.col-fp.col+1}{
}

box2d::box2d() : box2d(point2d(), point2d()){
}

box2d::~box2d() {
    //std::cout<<"destroy box"<<std::endl;
}

bool box2d::has(const box2d::point_type &p) const {
    return (p.col >= fp_.col && p.col <= lp_.col && p.row >= fp_.row && p.row <= lp_.row);
}
//box2d& box2d::operator=(const box2d &b) = default;

int box2d::rows() const{
    return nrows;
}

int box2d::cols() const{
    return ncols;
}

box2d &box2d::operator=(const box2d &b) {
    nrows = b.lp_.row-b.fp_.row+1;
    ncols = b.lp_.col-b.fp_.col+1;
    lp_ = b.lp_;
    fp_ = b.fp_;
    return *this;
}