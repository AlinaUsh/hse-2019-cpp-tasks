#include "../include/my_vector.h"
#include "../include/my_vector_impl.h"

#include <iostream>
#include <string>
#include <cstring>
#include <cassert>

namespace product {

    class Product {
    public:
        Product() : quantity_(0), price_(0) {
            name_ = new char[1]{0};
        }
        Product(const char* name, int quantity, double price) : quantity_(quantity), price_(price) {
            name_ = new char[std::strlen(name) + 1];
            std::strcpy(name_, name);
        }
        Product(const Product &p) : Product(p.name_, p.quantity_, p.price_) {}
        Product(Product &&p) noexcept : name_(p.name_), quantity_(p.quantity_), price_(p.price_) {
            p.name_ = nullptr;
            p.quantity_ = 0;
            p.price_ = 0;
        }
        ~Product() {
            delete [] name_;
        }
        friend std::ostream &operator<<(std::ostream &out, Product &p) {
            out << static_cast<std::string>(p.name_) << " " << p.quantity_ << " " << p.price_;
            return out;
        }
        Product &operator=(Product p) {
            std::swap(name_, p.name_);
            std::swap(quantity_, p.quantity_);
            std::swap(price_, p.price_);
            return *this;
        }
        Product &operator=(Product &&p) noexcept {
            this->~Product();
            name_ = p.name_;
            quantity_ = p.quantity_;
            price_ = p.price_;
            p.name_ = nullptr;
            p.quantity_ = 0;
            p.price_ = 0;
            return *this;
        }
        bool operator==(const Product& p) const {
            return (strcmp(name_, p.name_) == 0 && quantity_ == p.quantity_ && price_ == p.price_);
        }

    private:
        char *name_ = nullptr;  // Указатель владеет C-style строкой, на которую указывает.
        int quantity_ = 0;
        double price_ = 0;
    };

    void print(const my_vector::my_vector <Product> &v) {
        std::cout << v << std::endl;
    }

}  // namespace product

template<typename T>
void test_my_vector(T a, T b) {
    my_vector::my_vector <T> v;
    assert(v.capacity() == 1);
    assert(v.size() == 0);
    assert(v.empty());
    v.push_back(a);
    assert(v.size() == 1);
    assert(v[0] == a);
    assert(!v.empty());
    v.pop_back();
    assert(v.size() == 0);
    v.push_back(b);
    assert(v.size() == 1);
    v[0] = a;
    assert(v[0] == a);
    v.clear();
    assert(v.empty());
    v.push_back(a);
    assert(v.size() == 1);
    v.push_back(b);
    assert(v.size() == 2);
    assert(v.capacity() == 2);
    v.push_back(a);
    assert(v.size() == 3);
    assert(v.capacity() == 4);
    v.pop_back();
    assert(v.size() == 2);
    v[1] = b;
    assert(v[1] == b);
    v.reserve(10);
    assert(v.capacity() >= 16);


    my_vector::my_vector <T> u1;
    my_vector::my_vector <T> u2(u1);
    assert(u2.empty());
    u1.push_back(a);
    assert(u1.size() == 1);
    u2 = u1;
    assert(u2.size() == 1);
    assert(u2.capacity() == u1.capacity());
    assert(u2[0] == u1[0]);
    u2.push_back(a);
    u2.push_back(a);
    my_vector::my_vector <T> u3(u2);
    assert(u2[0] == u3[0]);
    assert(u2[1] == u3[1]);
    assert(u2[2] == u3[2]);
    assert(u2.size() == u3.size());
    assert(u2.capacity() == u3.capacity());
    u2[0] = a;
    assert(u2[0] == a);
}

template<typename T>
void test_my_vector_default_constructible(T a, T b) {
    my_vector::my_vector <T> v1;
    assert(v1.empty());
    assert(v1.capacity() == 1);
    v1.push_back(b);
    v1.push_back(b);
    v1[0] = a;
    assert(v1[0] == a);
    assert(v1.size() == 2);
    assert(v1[0] == a);
    assert(v1[1] == b);
    v1.pop_back();
    assert(v1.size() == 1);
    my_vector::my_vector <T> v2(v1);
    assert(v1[0] == v2[0]);
    assert(v1.size() == v2.size());
    assert(v1.capacity() == v2.capacity());
    v1.clear();
    v1.push_back(a);
    my_vector::my_vector <T> v3;
    v3 = v1;
    assert(v3[0] == v1[0]);
    assert(v3.size() == v1.size());
    assert(v3.capacity() == v1.capacity());
}

int main() {
    test_my_vector<int>(5, 10);
    test_my_vector<product::Product>(product::Product("asdf", 4, 12.0),
                                     product::Product("qwe", -1, 7.5));
    test_my_vector_default_constructible(1, 2);
    return 0;
}
