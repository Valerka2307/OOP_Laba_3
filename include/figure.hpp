#pragma once

#include "array.hpp"
#include <iostream>
#include <utility>

const size_t count_of_angles = 4;


class Figure {
  public:
    virtual double square() const = 0;
    virtual std::pair<double, double> geom_center() const = 0;
    virtual ~Figure() = default;
};