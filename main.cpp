#include <iostream>
#include <limits>
#include <queue>
#include "utils.h"
#include "image2d.h"
#include "box2d_iterator.h"
#include "partial_box2d_iterator.h"
#include "neighb2d_iterator.h"

using bool_t = unsigned ;

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
            if (D.has(n) and dmap(n) > dmap(p))
            {
                utils::print_image(std::cout, dmap);
                std::cout<<std::endl;
                dmap(n) = dmap(p) + 1;
                q.push(n);
            }
    }
    return dmap;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::vector<unsigned> v{2, 1, 1, 1, 0,
                                    0, 0, 0, 1, 0,
                                    0, 1, 1, 1, 0,
                                    0, 1, 0, 1, 0,
                                    1, 1, 0, 0, 0,
                                    0, 1, 1, 1, 3};

    image2d<unsigned> ima = image2d<unsigned>(6,5,v);
    partial_box2d box = partial_box2d(ima);
    partial_box2d_iterator it = partial_box2d_iterator(box);


    box2d D = ima.domain();
    const unsigned max = std::numeric_limits<unsigned>::max();
    image2d<unsigned>dmap(D);
    for (it.start(); it.is_valid(); it.next())
        dmap(it.value()) = max;

    std::cout<<"Image de base"<<std::endl;
    utils::print_image(std::cout, ima);
    auto d = compute_dmap__SPECIFIC(ima);
    std::cout<<"Image modifiée"<<std::endl;
    utils::print_image(std::cout, dmap);
    return 0;
}
