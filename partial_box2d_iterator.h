//
// Created by valentin on 08/11/2019.
//

#pragma once
#include "partial_box2d.h"

class partial_box2d_iterator {
private:
    point2d curr_p;
    partial_box2d dom_;
public:
    explicit partial_box2d_iterator(const partial_box2d& box);

    void start();
    bool is_valid();
    void next();
    point2d& value();
};

