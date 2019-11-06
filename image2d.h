//
// Created by josselin on 16/10/2019.
//

#ifndef PROJET1_IMAGE2D_H
#define PROJET1_IMAGE2D_H

#include <vector>
#include "box2d.h"
#include <cassert>

template <typename T>
class image2d {
public :
    using value_type = T;
    using domain_type = box2d;
    using point_type = typename domain_type::point_type;
    using p_iterator_type = typename domain_type::p_iterator_type;
    using n_iterator_type = typename domain_type::n_iterator_type;

    explicit image2d(const domain_type& d);
    image2d(unsigned nrows, unsigned ncols);
    image2d(unsigned nrows, unsigned ncols, std::vector<T>& v);

    const domain_type& domain() const;
    T& operator()(const point_type& p);
    T operator()(const point_type& p) const;

private:
    domain_type d_;
    std::vector<T> data_;
};

template<typename T>
image2d<T>::image2d(const image2d::domain_type &d) :d_{d}{

}
template<typename T>
image2d<T>::image2d(unsigned nrows, unsigned ncols) {

}

template<typename T>
image2d<T>::image2d(unsigned nrows, unsigned ncols, std::vector<T> &v) :d_{domain_type(point2d(), point2d(ncols-1, nrows-1))}{
    assert(v.size() == ncols*nrows);
    data_ = v;
}

template<typename T>
auto image2d<T>::domain() const -> const domain_type& {
    return d_;
}

template<typename T>
T &image2d<T>::operator()(const image2d::point_type &p){
    unsigned nc = d_.lp_.row - d_.fp_.row;

    return data_[p.col * nc + p.row];
}

template<typename T>
T image2d<T>::operator()(const image2d::point_type &p) const {
    unsigned nc = d_.lp_.row - d_.fp_.row;

    return data_[p.col * nc + p.row];
}

#endif //PROJET1_IMAGE2D_H
