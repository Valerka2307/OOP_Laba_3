#include "../include/square.hpp"
#include <cmath>


const double zero = 0.0;

Square::Square() {
    for (int i = 0; i < count_of_angles; ++i) {
        coord_.Push(std::make_pair(zero, zero));
    }
}

Square::Square(Array<std::pair<double, double>> lst) {
    coord_ = std::move(lst);
}

Square::Square(const Square& other) {
    coord_ = other.coord_;
}

Square::Square(Square&& other) noexcept {
    std::swap(coord_, other.coord_);
}

Square& Square::operator=(const Square& other) {
    coord_ =  other.coord_;
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
    std::swap(coord_, other.coord_);
    return *this;
}

std::istream& operator>>(std::istream& input, Square& square) {
    for (int i = 0; i < count_of_angles; ++i) {
        std::cout << "Input " << i + 1 << "-th coordinate:\n";
        std::cout << "x: ";
        input >> square.coord_[i].first;
        std::cout << "\ny: ";
        input >> square.coord_[i].second;
    }
    return input;
}

std::ostream& operator<<(std::ostream& output, const Square& square) {
    for (int i = 0; i < count_of_angles; ++i) {
        output << i + 1 << " coordinate\n";
        output << "x: " << square.coord_[i].first << "; y: " << square.coord_[i].second;
    }
    return output;
}

double Square::square() const {
    double length = std::sqrt((coord_[0].first - coord_[1].first) * (coord_[0].first - coord_[1].first) + 
                    (coord_[0].second - coord_[1].second) * (coord_[0].second - coord_[1].second));
    return length * length;
}

std::pair<double, double> Square::geom_center() const {
    double center_x = (coord_[0].first + coord_[2].first) / 2;
    double center_y = (coord_[0].second + coord_[2].second) / 2;
    return std::make_pair(center_x, center_y);
}

bool Square::compare_squares(const Square& other) const {
    for (int i = 0; i < count_of_angles; ++i) {
        if (coord_[i] != other.coord_[i]) {
            return false;
        }
    }

    return true;
}

bool operator==(const Square& left, const Square& right) {
  return left.compare_squares(right);
}