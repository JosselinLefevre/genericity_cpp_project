#include <iostream>
#include <limits>
#include <queue>
#include "utils.h"
#include "image2d.h"
#include "box2d_iterator.h"
#include "neighb2d_iterator.h"

using bool_t = int;

image2d<unsigned> compute_dmap__SPECIFIC(const image2d<bool_t>& input){

    box2d D = input.domain();
    const unsigned max = std::numeric_limits<unsigned>::max();
    image2d<unsigned> dmap(D);
    box2d_iterator p(D);
    for (p.start(); p.is_valid(); p.next()) {
        dmap(p.value()) = max;
        std::cout<<dmap(p.value())<<std::endl;
    }
    std::cout<<"lolz"<<std::endl;
    std::queue<point2d> q;
    neighb2d_iterator n;
    for (p.start(); p.is_valid(); p.next())
        if (input(p.value()))
        {
            dmap(p.value()) = 0;
            n.center_at(p.value());
            for (n.start(); n.is_valid(); n.next())
                if (D.has(n.value()) and !input(n.value()))
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
            if (D.has(n.value()) and dmap(n.value()) == max)
            {
                dmap(n.value()) = dmap(p) + 1;
                q.push(n.value());
            }
    }
    return dmap;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<bool_t> v{0,0,1,0,
                       1,0,0,1,
                       0,0,1,0,
                       0,1,1,0};



    image2d<bool_t> a = image2d<bool_t>(4,4,v);
    box2d D = a.domain();
    int w = D.fp_.row;
    box2d_iterator p(D);
    for (p.start(); p.is_valid(); p.next()) {
        std::cout<<a(p.value())<<std::endl;
    }
    std::cout<<"lolz"<<std::endl;

    utils::print_image(std::cout, a);
    auto d = compute_dmap__SPECIFIC(a);
    utils::print_image(std::cout, d);
    return 0;
}
