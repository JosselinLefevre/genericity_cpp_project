#include <iostream>
#include <limits>
#include <queue>
#include "utils.h"
#include "image_through.h"
#include "image2d.h"
#include "box2d_iterator.h"
#include "neighb2d_iterator.h"

using bool_t = unsigned;

template<typename I>
image2d<unsigned> compute_dmap(const I &input) {
// these 4 new lines below express that some types depends on I
// and on domain_type (that is, I::domain_type)
    using point_type = typename I::point_type;
    using domain_type = typename I::domain_type;
    using p_iterator_type = typename domain_type::p_iterator_type;
    using n_iterator_type = typename domain_type::n_iterator_type;
    const domain_type &D = input.domain();
// instead of: box2d D = input.domain();
    const unsigned max = unsigned(-1);
    image2d<unsigned> dmap(input.bounding_box());
// instead of: image2d<unsigned> dmap(D);
    p_iterator_type p(D);
// instead of: box2d_iterator p(D);
    for (p.start(); p.is_valid(); p.next())
        dmap(p.value()) = max;
    std::queue<point_type> q;
    n_iterator_type n(D.rows(), D.cols());
// instead of: std::queue<point2d> q;
// neighb2d_iterator n;
    for (p.start(); p.is_valid(); p.next())
        if (input(p.value()) == true) {
            dmap(p.value()) = 0;
            n.center_at(p.value());
            for (n.start(); n.is_valid(); n.next())
                if (D.has(n) and input(n) == false) {
                    q.push(p.value());
                    break;
                }
        }
    while (not q.empty()) {
        point2d p = q.front();
        q.pop();
        n.center_at(p);
        for (n.start(); n.is_valid(); n.next())
            if (D.has(n) and dmap(n) == max) {
                dmap(n) = dmap(p) + 1;
                q.push(n);
            }
    }
    return dmap;
}

image2d<unsigned> compute_dmap__SPECIFIC(const image2d<bool_t>& input)
{
    box2d D = input.domain();
    const unsigned max = std::numeric_limits<unsigned>::max();
    image2d<unsigned> dmap(D);
    box2d_iterator p(D);
    for (p.start(); p.is_valid(); p.next())
        dmap(p.value()) = max;
    std::queue<point2d> q;
    neighb2d_iterator n(D.rows(), D.cols());
    for (p.start(); p.is_valid(); p.next())
        if (input(p.value()) != 0)
        {
            dmap(p.value()) = 0;
            n.center_at(p.value());
            for (n.start(); n.is_valid(); n.next())
                if (D.has(n) and input(n.value()) == 0)
                {
                    q.push(p.value());
                    break;
                }
        }
    while (not q.empty())
    {
        point2d p = q.front();
        q.pop();
        n.center_at(p);
        for (n.start(); n.is_valid(); n.next())
            //if (D.has(n) and dmap(n) > dmap(p))
            if (D.has(n) and dmap(n) == max)
            {
                //utils::print_image(std::cout, dmap);
                //std::cout<<std::endl;
                dmap(n) = dmap(p) + 1;
                q.push(n);
            }
    }
    return dmap;
}

int main() {
    /*std::vector<bool_t> v{0, 0, 1, 0,
                          1, 0, 0, 1,
                          0, 0, 0, 0,
                          0, 1, 0, 0};


    image2d<bool_t> a = image2d<bool_t>(4, 4, v);

    std::cout << "Image de base" << std::endl;
    utils::print_image(std::cout, a);
    auto d = compute_dmap(a);
    std::cout << "Image modifiée" << std::endl;
    utils::print_image(std::cout, d);*/

    //box2d D{2, 3};
    // TODO : ask for the meaning of the line above
    image2d<unsigned> ima(5,5);
    std::vector<bool_t>  v{ 0, 0, 0, 0, 0,
                   0, 0, 0, 1, 0,
                   0, 0, 1, 1, 0,
                   0, 0, 0, 0, 0,
                   2, 0, 0, 3, 0,
                   0, 0, 0, 0, 0 };

    ima.fill_with(v);
    std::cout << "Image de base" << std::endl;
    utils::print_image(std::cout, ima);

    auto ima_ell = through(ima, utils::fun_sqr{});
    std::cout << "Image ell" << std::endl;
    utils::print_image(std::cout, ima_ell);

    auto ima_bin = through(ima, utils::fun_equal{2});
    std::cout << "Image bin" << std::endl;
    utils::print_image(std::cout, ima_ell);

    return 0;
}
