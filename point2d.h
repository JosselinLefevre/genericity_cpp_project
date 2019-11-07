//
// Created by josselin on 16/10/2019.
//

#ifndef PROJET1_POINT2D_H
#define PROJET1_POINT2D_H

#include <iostream>

struct point2d{
    int row;
    int col;
    point2d(int row, int col) {
        this->row = row;
        this->col = col;
    }
    point2d() {
        this->row = 0;
        this->col = 0;
    }
    point2d operator+(point2d& p) {
        point2d out;
        out.row = p.row + this->row;
        out.col = p.col + this->col;
        return out;
    }

    point2d& operator=(const point2d& p) = default;


};


#endif //PROJET1_POINT2D_H
