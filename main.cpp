#include <iostream>
#include <limits>
#include <queue>
#include "utils.h"
#include "image2d.h"
#include "box2d_iterator.h"
#include "partial_box2d_iterator.h"
#include "neighb2d_iterator.h"
#include "partial_image2d.h"
#include "image_through.h"

using bool_t = unsigned ;

template <typename I>
image2d<unsigned> compute_dmap(const I& input)
{
    using point_type = typename I::point_type;
    using domain_type = typename I::domain_type;
    using p_iterator_type = typename domain_type::p_iterator_type;
    using n_iterator_type = typename domain_type::n_iterator_type;
    const domain_type& D = input.domain();

    auto max = unsigned(-1);
    image2d<unsigned> dmap(input.bounding_box());

    p_iterator_type p_it(D);

    for (p_it.start(); p_it.is_valid(); p_it.next())
        dmap(p_it.value()) = max;
    std::queue<point_type> q;
    n_iterator_type n;

    for (p_it.start(); p_it.is_valid(); p_it.next())
        if (input(p_it.value()) == true)
        {
            dmap(p_it.value()) = 0;
            n.center_at(p_it.value());
            for (n.start(); n.is_valid(); n.next()){
                if (D.has(n.value()) and input(n.value()) == false)
                {
                    q.push(p_it.value());
                    break;
                }
            }
        }
    while (not q.empty())
    {
        point2d p = q.front();
        q.pop();
        n.center_at(p);
        for (n.start(); n.is_valid(); n.next())
            if (D.has(n.value()) and dmap(n.value()) == max)
            {
                dmap(n.value()) = dmap(p) + 1;
                q.push(n.value());
            }
    }
    return dmap;
}



int main() {

    std::vector<unsigned> v{2, 1, 1, 1, 0,
                            0, 0, 0, 1, 0,
                            0, 1, 1, 1, 0,
                            0, 1, 0, 1, 0,
                            1, 1, 0, 0, 0,
                            0, 1, 1, 1, 3};

    partial_image2d<bool_t> part_ima = partial_image2d<bool_t>(6,5,v);
    auto im_t = through(part_ima, fun_zeros{});


    std::cout<<"Image de base"<<std::endl;
    utils::print_image(std::cout, part_ima);
    auto d = compute_dmap(im_t);

    auto data = d.getData();
    partial_image2d<unsigned> part_d = partial_image2d<unsigned>(6,5,data);
    part_d.setDomain(part_ima.domain());

    std::cout<<"Image modifiee"<<std::endl;
    utils::print_image(std::cout, part_d);
    return 0;
}
