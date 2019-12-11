#include<iostream>
#include "Scheme.hpp"

Scheme::Scheme(int capacity) {
    this->figures_ = new Figure*[capacity];
    this->number_of_figures = 0;
}

Scheme::~Scheme() {
    for (int i = 0; i < number_of_figures; i++)
        delete figures_[i];
    delete [] figures_;
}

void Scheme::push_back_figure(Figure* fg) {
    figures_[number_of_figures] = fg;
    number_of_figures++;
}

int Scheme::find_fig(int id) {
    for (int i = 0; i < number_of_figures; i++) {
        if (figures_[i]->get_id() == id)
            return i;
    }
    return -1;
}

void Scheme::remove_figure(int id) {
    int pos = find_fig(id);
    if (pos == -1) {
        std::cout << "No such figure\n";
        return;
    }
    delete figures_[pos];
    for (int i = pos; i < number_of_figures; i++) {
        figures_[i] = figures_[i + 1];
    }
    number_of_figures--;
}

void Scheme::print_all_figures() {
    for (int i = 0; i < number_of_figures; i++)
        figures_[i]->print();
}

void Scheme::zoom_figure(int id, int factor) {
    int pos = find_fig(id);
    if (pos != -1) {
        return;
    }
    figures_[pos]->zoom(factor);
}

Figure* Scheme::is_inside_figure(int x, int y) {
    for (int i = 0; i < number_of_figures; i++) {
        if (figures_[i]->is_inside(x, y))
            return figures_[i];
    }
    std::cout << "No such figure\n";
    return nullptr;
}

void Scheme::move(int id, int new_x, int new_y) {
    int pos = find_fig(id);
    if (pos != -1) {
        return;
    }
    figures_[pos]->move(new_x, new_y);
}
