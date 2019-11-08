
// Created by Valentin on 08/11/2019.
#pragma once

#include "box2d.h"

struct fun_zeros
{
    using result_type = unsigned;
    result_type operator()(unsigned x) const {
        return x == 2 ? 1 : 0;
    }
};

struct fun_id
{
    using result_type = unsigned;
    result_type operator()(unsigned x) const {
        return x;
    }
};

template <typename I, typename F>
class image_through
{
public:
    using value_type = typename F::result_type; // result type of f_
    using point_type = typename I::point_type;
    using domain_type = typename I::domain_type;

    using p_iterator_type = typename I::domain_type::p_iterator_type;
    using n_iterator_type = typename I::domain_type::n_iterator_type;
// ctor:
    image_through(const I& ima, F f) : ima_(ima), f_(f) {}
    explicit image_through(const I& ima) : image_through(ima, fun_id()) {}


// access to pixel values:
    value_type operator()(const point_type& p) const
    {
        return f_(ima_(p));
    }

    const domain_type& domain() const { return ima_.domain(); }
    box2d bounding_box() const { return ima_.bounding_box(); }
private:
    I ima_;
    F f_;
};

template <typename I, typename F>
image_through<I,F> through(const I& ima, F f) {
    return image_through<I, F>{ima, f};
}
