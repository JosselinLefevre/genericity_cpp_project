//
// Created by Valentin on 08/11/2019.
//

#pragma once
#include <vector>
#include "partial_box2d.h"
#include <cassert>

template <typename T>
class partial_image2d {
public :
    using value_type = T;
    using domain_type = partial_box2d;
    using point_type = typename domain_type::point_type;
    using p_iterator_type = typename domain_type::p_iterator_type;
    using n_iterator_type = typename domain_type::n_iterator_type;

    partial_image2d();
    explicit partial_image2d(const domain_type& d);
    partial_image2d(unsigned nrows, unsigned ncols);
    partial_image2d(unsigned nrows, unsigned ncols, std::vector<T>& v);

    const domain_type& domain() const;
    box2d bounding_box() const;
    void setDomain(const domain_type& d);

    T& operator()(const point_type& p);
    T operator()(const point_type& p) const;

private:
    unsigned ncols_;
    unsigned nrows_;
    domain_type dom_;
    std::vector<T> data_;
};

template<typename T>
partial_image2d<T>::partial_image2d(const partial_image2d::domain_type &d) :dom_{d}, nrows_{static_cast<unsigned int>(d.rows())}, ncols_{static_cast<unsigned int>(d.cols())}{
    data_ = std::vector<T>(ncols_*nrows_);
}

template<typename T>
partial_image2d<T>::partial_image2d(unsigned nrows, unsigned ncols) : nrows_{nrows}, ncols_{ncols} {}

template<typename T>
partial_image2d<T>::partial_image2d() : nrows_{0}, ncols_{0} {}

template<typename T>
partial_image2d<T>::partial_image2d(unsigned nrows, unsigned ncols, std::vector<T> &v) : nrows_{nrows}, ncols_{ncols}{
    assert(v.size() == ncols*nrows);
    image2d<T> i = image2d<T>(nrows, ncols, v);
    dom_ = domain_type(i);
    data_ = v;
}


template<typename T>
auto partial_image2d<T>::domain() const -> const domain_type& {
    return dom_;
}

template<typename T>
void partial_image2d<T>::setDomain(const domain_type& d) {
    dom_ = d;
}

template<typename T>
box2d partial_image2d<T>::bounding_box() const { return dom_.ima_.domain();}

template<typename T>
T &partial_image2d<T>::operator()(const partial_image2d::point_type &p){
    unsigned nc = dom_.cols();
    return data_[p.row * nc + p.col];
}

template<typename T>
T partial_image2d<T>::operator()(const partial_image2d::point_type &p) const {
    unsigned nc = dom_.cols();
    return data_[p.row * nc + p.col];
}
