//
// Created by josselin on 21/10/2019.
//

#pragma once


#include <vector>
#include "point2d.h"

class neighb2d_iterator {
public:
    neighb2d_iterator();
    void center_at(point2d& p);
    void start();
    bool is_valid();
    void next();
    point2d value();

private:
    std::vector<point2d> delta_;
    unsigned i_;
    point2d p_ = point2d(0, 0);
};