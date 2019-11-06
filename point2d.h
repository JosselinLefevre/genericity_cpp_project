//
// Created by josselin on 16/10/2019.
//

#ifndef PROJET1_POINT2D_H
#define PROJET1_POINT2D_H

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
    point2d &operator+(point2d& p) {
        p.row += this->row;
        p.col += this->col;
        return p;
    }
};


#endif //PROJET1_POINT2D_H
