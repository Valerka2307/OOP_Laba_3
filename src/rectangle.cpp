#include "../include/rectangle.hpp"
#include <cmath>

const double zero = 0.0;

Rectangle::Rectangle() {
    for (int i = 0; i < count_of_angles; ++i) {
        coord_.Push(std::make_pair(zero, zero));
    }
}

Rectangle::Rectangle(Array<std::pair<double, double>> lst) {
    coord_ = std::move(lst);
}

Rectangle::Rectangle(const Rectangle& other) {
    coord_ = other.coord_;
}

Rectangle::Rectangle(Rectangle&& other) noexcept {
    std::swap(coord_, other.coord_);
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    coord_ =  other.coord_;
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    std::swap(coord_, other.coord_);
    return *this;
}

std::istream& operator>>(std::istream& input, Rectangle& rectangle) {
    for (int i = 0; i < count_of_angles; ++i) {
        std::cout << "Input " << i + 1 << "-th coordinate:\n";
        std::cout << "x: ";
        input >> rectangle.coord_[i].first;
        std::cout << "\ny: ";
        input >> rectangle.coord_[i].second;
    }
    return input;
}

std::ostream& operator<<(std::ostream& output, const Rectangle& square) {
    for (int i = 0; i < count_of_angles; ++i) {
        output << i + 1 << " coordinate\n";
        output << "x: " << square.coord_[i].first << "; y: " << square.coord_[i].second;
    }
    return output;
}

double Rectangle::square() const {
    double length = std::sqrt((coord_[0].first - coord_[1].first) * (coord_[0].first - coord_[1].first) + 
                    (coord_[0].second - coord_[1].second) * (coord_[0].second - coord_[1].second));

    double height = std::sqrt((coord_[1].first - coord_[2].first) * (coord_[1].first - coord_[2].first) + 
                    (coord_[1].second - coord_[2].second) * (coord_[1].second - coord_[2].second));

    return length * height;
}

std::pair<double, double> Rectangle::geom_center() const {
    double center_x = (coord_[0].first + coord_[2].first) / 2;
    double center_y = (coord_[0].second + coord_[2].second) / 2;
    return std::make_pair(center_x, center_y);
}

bool Rectangle::compare_rectangles(const Rectangle& other) const {
    for (int i = 0; i < count_of_angles; ++i) {
        if (coord_[i] != other.coord_[i]) {
            return false;
        }
    }

    return true;
}

bool operator==(const Rectangle& left, const Rectangle& right) {
  return left.compare_rectangles(right);
}