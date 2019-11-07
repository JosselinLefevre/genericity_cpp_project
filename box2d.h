//
// Created by josselin on 16/10/2019.
//
#pragma once

#include "point2d.h"

class box2d_iterator;
class neighb2d_iterator;

class box2d {
public:
    using point_type = point2d;
    using p_iterator_type = box2d_iterator;
    using n_iterator_type = neighb2d_iterator;
    box2d(const point_type &fp, const point_type &lp);
    box2d();
    ~box2d();
    box2d& operator=(const box2d& b);

    point_type fp_;
    point_type lp_;
    bool has(const point_type &p) const;
    int rows() const;
    int cols() const;
private:
    int nrows, ncols;
};

