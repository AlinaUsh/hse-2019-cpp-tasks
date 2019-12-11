#include "Circle.hpp"
#include <cstring>
#include <iostream>

Circle::Circle(int id, int x, int y, int radius, const char *label) : Figure(id, x, y) {
    this->radius = radius;
    this->label = new char[strlen(label) + 1];
    strcpy(this->label, label);
}

Circle::~Circle() {
    delete[] label;
}

void Circle::print() const {
    std::cout << "Circle " << id << ": x = " << x << " y = " << y
              << " radius = " << radius << " label = " << label << '\n';
}

bool Circle::is_inside(int x, int y) const {
    return (this->x - x) * (this->x - x) + (this->y - y) * (this->y - y) <= this->radius * this->radius;
}

void Circle::zoom(int factor) {
    this->radius *= factor;
}
