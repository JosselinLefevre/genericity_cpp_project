//
// Created by josselin on 16/10/2019.
//


#pragma once
#include "box2d.h"

class box2d_iterator {
private:
    point2d curr_p;
    box2d dom_;
public:
    explicit box2d_iterator(const box2d& box);

    void start();
    bool is_valid();
    void next();
    point2d& value();
};

