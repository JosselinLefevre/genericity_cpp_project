cmake_minimum_required(VERSION 3.14)
project(projet1)

set(CMAKE_CXX_STANDARD 14)

add_executable(projet1 main.cpp box2d.h point2d.h box2d_iterator.cpp box2d_iterator.h image2d.h neighb2d_iterator.cpp neighb2d_iterator.h utils.h box2d.cpp image_through.h)