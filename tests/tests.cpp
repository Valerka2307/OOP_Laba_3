#include "gtest/gtest.h"
#include "square.hpp"
#include "rectangle.hpp"
#include "trapezoid.hpp"
#include <cmath>
#include <utility>

// Тест конструктора по умолчанию
TEST(SquareTest, DefaultConstructor) {
    Rectangle s;
    auto coords = s.geom_center();
    // Координаты центра должны быть (0,0)
    EXPECT_DOUBLE_EQ(coords.first, 0.0);
    EXPECT_DOUBLE_EQ(coords.second, 0.0);
    // Площадь должна быть 0 (все вершины в точке (0,0))
    EXPECT_DOUBLE_EQ(s.square(), 0.0);
}

// Тест конструктора с координатами
TEST(SquareTest, ConstructorWithCoordinates) {
    Array<std::pair<double, double>> coords;
    coords.Push({0.0, 0.0});
    coords.Push({1.0, 0.0});
    coords.Push({1.0, 1.0});
    coords.Push({0.0, 1.0});

    Rectangle s(coords);

    EXPECT_DOUBLE_EQ(s.square(), 1.0); // длина стороны 1, площадь = 1
    auto center = s.geom_center();
    EXPECT_DOUBLE_EQ(center.first, 0.5);
    EXPECT_DOUBLE_EQ(center.second, 0.5);
}

// Тест оператора сравнения
TEST(SquareTest, CompareSquares) {
    Array<std::pair<double, double>> coords1;
    coords1.Push({0.0, 0.0});
    coords1.Push({1.0, 0.0});
    coords1.Push({1.0, 1.0});
    coords1.Push({0.0, 1.0});

    Array<std::pair<double, double>> coords2 = coords1;

    Rectangle s1(coords1);
    Rectangle s2(coords2);

    EXPECT_TRUE(s1 == s2);

    // Изменим одну вершину
    coords2[0] = {0.1, 0.0};
    Rectangle s3(coords2);
    EXPECT_FALSE(s1 == s3);
}

// Тест конструктора копирования и перемещения
TEST(SquareTest, CopyAndMoveConstructor) {
    Array<std::pair<double, double>> coords;
    coords.Push({0,0}); coords.Push({1,0});
    coords.Push({1,1}); coords.Push({0,1});

    Rectangle s1(coords);
    Rectangle s2(s1); // copy
    EXPECT_TRUE(s1 == s2);

    Rectangle s3(std::move(s1)); // move
    EXPECT_TRUE(s2 == s3);
}

// Тест оператора присваивания
TEST(SquareTest, AssignmentOperators) {
    Array<std::pair<double,double>> coords;
    coords.Push({0,0}); coords.Push({1,0});
    coords.Push({1,1}); coords.Push({0,1});

    Rectangle s1(coords);
    Rectangle s2;
    s2 = s1; // copy assign
    EXPECT_TRUE(s1 == s2);

    Rectangle s3;
    s3 = std::move(s1); // move assign
    EXPECT_TRUE(s3 == s2);
}

TEST(RectangleTests, DefaultConstructor) {
    Rectangle r;
    EXPECT_DOUBLE_EQ(r.square(), 0.0);
}

TEST(RectangleTests, SquareCalculation) {
    Array<std::pair<double,double>> pts;
    pts.Push({0,0});
    pts.Push({3,0});
    pts.Push({3,4});
    pts.Push({0,4});

    Rectangle r(pts);

    EXPECT_DOUBLE_EQ(r.square(), 12.0);
}

TEST(RectangleTests, CenterCalculation) {
    Array<std::pair<double,double>> pts;
    pts.Push({0,0});
    pts.Push({4,0});
    pts.Push({4,6});
    pts.Push({0,6});

    Rectangle r(pts);

    auto c = r.geom_center();
    EXPECT_DOUBLE_EQ(c.first, 2.0);
    EXPECT_DOUBLE_EQ(c.second, 3.0);
}

TEST(RectangleTests, Equality) {
    Array<std::pair<double,double>> pts1;
    pts1.Push({0,0});
    pts1.Push({2,0});
    pts1.Push({2,2});
    pts1.Push({0,2});

    Array<std::pair<double,double>> pts2 = pts1;

    Rectangle r1(pts1);
    Rectangle r2(pts2);

    EXPECT_TRUE(r1 == r2);
}

// --- Trapezoid Tests ---
TEST(TrapezoidTest, AreaAndCenter) {
    Array<std::pair<double,double>> coords;
    coords.Push({0,0});
    coords.Push({4,0});
    coords.Push({3,2});
    coords.Push({1,2});

    Trapezoid tr(coords);
    double area = tr.square();
    EXPECT_NEAR(area, 6.0, 1e-6); // площадь равнобедренной трапеции

    auto center = tr.geom_center();
    EXPECT_NEAR(center.first, 2.0, 1e-6);
    EXPECT_NEAR(center.second, 16.0 / 18.0, 1e-6);
}

TEST(TrapezoidTest, CompareTrapezoids) {
    Array<std::pair<double,double>> coords;
    coords.Push({0,0});
    coords.Push({4,0});
    coords.Push({3,2});
    coords.Push({1,2});

    Trapezoid t1(coords);
    Trapezoid t2(coords);

    EXPECT_TRUE(t1 == t2);
}
