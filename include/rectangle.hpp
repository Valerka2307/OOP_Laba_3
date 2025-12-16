#include "array.hpp"
#include "figure.hpp"


class Rectangle: public Figure {
  public:
    Rectangle();
    Rectangle(Array<std::pair<double, double>> lst);
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;

    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;

    friend std::ostream& operator<<(std::ostream& output, const Rectangle& square);
    friend std::istream& operator>>(std::istream& input, Rectangle& square);

    virtual double square() const override;
    virtual std::pair<double, double> geom_center() const override;

    virtual ~Rectangle() = default;

    bool compare_rectangles(const Rectangle& other) const;

  private:
    Array<std::pair<double, double>> coord_;
};

bool operator==(const Rectangle& left, const Rectangle& right);