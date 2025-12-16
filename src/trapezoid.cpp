#include "../include/trapezoid.hpp"
#include <cmath>


const double zero = 0.0;

Trapezoid::Trapezoid() {
    for (int i = 0; i < count_of_angles; ++i) {
        coord_.Push(std::make_pair(zero, zero));
    }
}

Trapezoid::Trapezoid(Array<std::pair<double, double>> lst) {
    coord_ = std::move(lst);
}

Trapezoid::Trapezoid(const Trapezoid& other) {
    coord_ = other.coord_;
}

Trapezoid::Trapezoid(Trapezoid&& other) noexcept {
    std::swap(coord_, other.coord_);
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    coord_ =  other.coord_;
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    std::swap(coord_, other.coord_);
    return *this;
}

std::istream& operator>>(std::istream& input, Trapezoid& trapezoid) {
    for (int i = 0; i < count_of_angles; ++i) {
        std::cout << "Input " << i + 1 << "-th coordinate:\n";
        std::cout << "x: ";
        input >> trapezoid.coord_[i].first;
        std::cout << "\ny: ";
        input >> trapezoid.coord_[i].second;
    }
    return input;
}

std::ostream& operator<<(std::ostream& output, const Trapezoid& trapezoid) {
    for (int i = 0; i < count_of_angles; ++i) {
        output << i + 1 << " coordinate\n";
        output << "x: " << trapezoid.coord_[i].first << "; y: " << trapezoid.coord_[i].second;
    }
    return output;
}

double Trapezoid::square() const {
    double down_length = std::sqrt((coord_[0].first - coord_[1].first) * (coord_[0].first - coord_[1].first) +
                         (coord_[0].second - coord_[1].second) * (coord_[0].second - coord_[1].second));
    
    double top_length = std::sqrt((coord_[2].first - coord_[3].first) * (coord_[2].first - coord_[3].first) +
                         (coord_[2].second - coord_[3].second) * (coord_[2].second - coord_[3].second));

    double side_length = std::sqrt((coord_[0].first - coord_[3].first) * (coord_[0].first - coord_[3].first) + 
                         (coord_[0].second - coord_[3].second) * (coord_[0].second - coord_[3].second));

    double height = std::sqrt(side_length * side_length - (top_length - down_length) * (top_length - down_length) / 4);

    return (top_length + down_length) * height / 2;
}

std::pair<double, double> Trapezoid::geom_center() const {
    double center_x = 0;
    for (int i = 0; i < count_of_angles; ++i) {
        center_x += (coord_[i].first + coord_[(i + 1) % count_of_angles].first) *
                    (coord_[i].first * coord_[(i + 1) % count_of_angles].second - coord_[(i + 1) % count_of_angles].first * coord_[i].second);
    }

    center_x /= (square() * 6);

    double center_y = 0;
    for (int i = 0; i < count_of_angles; ++i) {
        center_y += (coord_[i].second + coord_[(i + 1) % count_of_angles].second) *
                    (coord_[i].first * coord_[(i + 1) % count_of_angles].second - coord_[(i + 1) % count_of_angles].first * coord_[i].second);
    }
    center_y /= (square() * 6);

    return std::make_pair(center_x, center_y);
}

bool Trapezoid::compare_trapezoids(const Trapezoid& other) const {
    for (int i = 0; i < count_of_angles; ++i) {
        if (coord_[i] != other.coord_[i]) {
            return false;
        }
    }

    return true;
}

bool operator==(const Trapezoid& left, const Trapezoid& right) {
  return left.compare_trapezoids(right);
}
