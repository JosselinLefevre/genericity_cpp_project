//
// Created by valentin on 08/11/2019.
//

#pragma once

#include "point2d.h"
#include "image2d.h"

class partial_box2d_iterator;
class neighb2d_iterator;

class partial_box2d {
public:
    using point_type = point2d;
    using p_iterator_type = partial_box2d_iterator;
    using n_iterator_type = neighb2d_iterator;
    explicit partial_box2d(image2d<unsigned> &ima);
    partial_box2d();
    ~partial_box2d();
    partial_box2d& operator=(const partial_box2d& b);
    bool has(const point_type &p) const;
    int rows() const;
    int cols() const;
    image2d<unsigned> ima_;
private:
};

