//
// Created by josselin on 16/10/2019.
//
#pragma once

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

    image2d();
    explicit image2d(const domain_type& d);
    image2d(int nrows, int ncols);
    image2d(int nrows, int ncols, std::vector<T>& v);

    const domain_type& domain() const;
    box2d bounding_box() const;

    std::vector<T> getData();

    T& operator()(const point_type& p);
    T operator()(const point_type& p) const;


private:
    int ncols_;
    int nrows_;
    std::vector<T> data_;
    domain_type dom_;
};

template<typename T>
image2d<T>::image2d(const image2d::domain_type &d) :dom_{d}, nrows_{d.rows()}, ncols_{d.cols()}{
    data_ = std::vector<T>(ncols_*nrows_);
}
template<typename T>
image2d<T>::image2d(int nrows, int ncols) : nrows_{nrows}, ncols_{ncols} {

}
template<typename T>
image2d<T>::image2d() : nrows_{0}, ncols_{0} {

}

template<typename T>
image2d<T>::image2d(int nrows, int ncols, std::vector<T> &v) : nrows_{nrows}, ncols_{ncols}, dom_{domain_type(point2d(), point2d(nrows - 1, ncols - 1))}{
    assert(v.size() == ncols*nrows);
    data_ = v;
}

template<typename T>
auto image2d<T>::domain() const -> const domain_type& {
    return dom_;
}

template<typename T>
std::vector<T> image2d<T>::getData(){
    return data_;
}

template<typename T>
box2d image2d<T>::bounding_box() const { return dom_; }

template<typename T>
T &image2d<T>::operator()(const image2d::point_type &p){
    unsigned nc = dom_.cols();
    return data_[p.row * nc + p.col];
}

template<typename T>
T image2d<T>::operator()(const image2d::point_type &p) const {
    unsigned nc = dom_.cols();
    return data_[p.row * nc + p.col];
}