#include "square.hpp"
#include "rectangle.hpp"
#include "trapezoid.hpp"
#include "array.hpp"
#include "figure.hpp"
#include <iostream>

int main() {
    Array<Figure*> figures;   // массив фигур (полиморфизм)

    // --- Создаём первый квадрат ---
    Array<std::pair<double,double>> coords1;
    coords1.Push({0,0});
    coords1.Push({2,0});
    coords1.Push({2,2});
    coords1.Push({0,2});
    figures.Push(new Square(coords1));

    // --- Второй квадрат ---
    Array<std::pair<double,double>> coords2;
    coords2.Push({0,0});
    coords2.Push({1,1});
    coords2.Push({0,2});
    coords2.Push({-1,1});
    figures.Push(new Square(coords2));

    // --- Третий квадрат ---
    Array<std::pair<double,double>> coords3;
    coords3.Push({-1,-1});
    coords3.Push({1,-1});
    coords3.Push({1,1});
    coords3.Push({-1,1});
    figures.Push(new Square(coords3));

    // --- Прямоугольник ---
    Array<std::pair<double,double>> coords4;
    coords4.Push({0,0});
    coords4.Push({3,0});
    coords4.Push({3,4});
    coords4.Push({0,4});
    figures.Push(new Rectangle(coords4));

     // --- равнобедренная трапеция ---
    Array<std::pair<double,double>> tr_coords;
    tr_coords.Push({0,0});
    tr_coords.Push({4,0});
    tr_coords.Push({3,2});
    tr_coords.Push({1,2});
    figures.Push(new Trapezoid(tr_coords));

    std::cout << "Array of Figures:\n\n";

    // --- Полиморфная обработка ---
    for (size_t i = 0; i < figures.Size(); ++i) {
        Figure* f = figures[i];

        std::cout << "Figure #" << i + 1 << "\n";

        double area = f->square();
        auto center = f->geom_center();

        std::cout << "Square: " << area << "\n";
        std::cout << "Center: (" << center.first << ", " << center.second << ")\n";
        std::cout << "--------------------------\n";
    }

    // --- Освобождение памяти ---
    for (size_t i = 0; i < figures.Size(); ++i) {
        delete figures[i];
    }

    return 0;
}