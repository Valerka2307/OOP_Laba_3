#include "array.hpp"
#include "figure.hpp"


class Trapezoid: public Figure {
  public:
    Trapezoid();
    Trapezoid(Array<std::pair<double, double>> lst);
    Trapezoid(const Trapezoid& other);
    Trapezoid(Trapezoid&& other) noexcept;

    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other) noexcept;

    friend std::ostream& operator<<(std::ostream& output, const Trapezoid& trapezoid);
    friend std::istream& operator>>(std::istream& input, Trapezoid& square);

    virtual double square() const override;
    virtual std::pair<double, double> geom_center() const override;

    virtual ~Trapezoid() = default;

    bool compare_trapezoids(const Trapezoid& other) const;

  private:
    Array<std::pair<double, double>> coord_;
};

bool operator==(const Trapezoid& left, const Trapezoid& right);
