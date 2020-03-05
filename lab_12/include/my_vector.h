#ifndef MY_VECTOR_H_
#define MY_VECTOR_H_

#include <ostream>
#include <cstddef>

namespace my_vector {

    template<typename T>
    class my_vector {
    public:
        my_vector();
        explicit my_vector(std::size_t n);
        my_vector(const my_vector &other);
        my_vector(my_vector &&v) noexcept;
        ~my_vector() noexcept;
        my_vector &operator=(my_vector other);
        my_vector &operator=(my_vector &&v) noexcept;

        std::size_t size() const noexcept;
        std::size_t capacity() const noexcept;
        bool empty() const noexcept;

        void resize(std::size_t n);
        void reserve(std::size_t n);

        T &operator[](std::size_t index) const noexcept;
        friend std::ostream &operator<<(std::ostream &out, const my_vector<T> &v) {
            if (v.size() == 0) {
                return out;
            }
            out << v[0];
            for (std::size_t i = 1; i < v.size(); i++) {
                out << ' ' << v[i];
            }
            return out;
        }

        void swap(my_vector<T> &other) noexcept;

        void push_back(T t);
        void pop_back() noexcept;
        void clear();

    private:
        size_t capacity_ = 0;
        size_t size_ = 0;
        T* array_ = nullptr;
    };

}

#include "my_vector_impl.h"

#endif  // MY_VECTOR_H_