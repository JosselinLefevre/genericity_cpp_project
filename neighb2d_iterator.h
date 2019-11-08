//
// Created by josselin on 21/10/2019.
//

#ifndef PROJET1_NEIGHB2D_ITERATOR_H
#define PROJET1_NEIGHB2D_ITERATOR_H


#include <vector>
#include "point2d.h"

class neighb2d_iterator {
public:
    explicit neighb2d_iterator(unsigned nrows, unsigned ncols);
    void center_at(point2d& p);
    void start();
    bool is_valid();
    void next();
    static point2d value();

    operator point2d() const {
        point2d n;
        n.row = p_.row + delta_[i_].row;
        n.col = p_.col + delta_[i_].col;
        return n;
    }

private:
    unsigned nrows_, ncols_;
    std::vector<point2d> delta_;
    unsigned i_;
    point2d p_ = point2d(0, 0);
};


#endif //PROJET1_NEIGHB2D_ITERATOR_H
