#include "array.hpp"
#include "figure.hpp"


class Square: public Figure {
  public:
    Square();
    Square(Array<std::pair<double, double>> lst);
    Square(const Square& other);
    Square(Square&& other) noexcept;

    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;

    friend std::ostream& operator<<(std::ostream& output, const Square& square);
    friend std::istream& operator>>(std::istream& input, Square& square);

    virtual double square() const override;
    virtual std::pair<double, double> geom_center() const override;

    virtual ~Square() = default;

    bool compare_squares(const Square& other) const;

  private:
    Array<std::pair<double, double>> coord_;
};

bool operator==(const Square& left, const Square& right);
