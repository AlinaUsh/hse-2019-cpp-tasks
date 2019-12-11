#include "Rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(int id, int x, int y, int width, int height) : Figure(id, x, y) {
    this->height = height;
    this->width = width;
}

Rectangle::~Rectangle() {}

void Rectangle::print() const {
    std::cout << "Rectangle " << id << ": x = " << x << " y = " << y
              << " width  = " << width << " height  = " << height << '\n';
}

bool Rectangle::is_inside(int x, int y) const {
    return (2 * abs(this->x - x) <= this->width) && (2 * abs(this->y - y) <= this->height);
}

void Rectangle::zoom(int factor) {
    this->height *= factor;
    this->width *= factor;
}
