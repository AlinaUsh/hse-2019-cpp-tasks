#ifndef MY_VECTOR_IMPL_H_
#define MY_VECTOR_IMPL_H_

#include "my_vector.h"
#include <memory>
#include <cstdlib>

namespace my_vector {

    std::size_t two_pow(std::size_t n) {
        std::size_t x = 1;
        while (x < n)
            x <<= 1;
        return x;
    }

    template<typename T>
    my_vector<T>::my_vector() : capacity_(1), size_(0),
                array_(static_cast<T*>(aligned_alloc(alignof(T), sizeof(T)))){}

    template<typename T>
    my_vector<T>::my_vector(std::size_t n) : capacity_(two_pow(n)), size_(n),
                array_(static_cast<T*>(aligned_alloc(alignof(T), sizeof(T) * two_pow(n)))) {
        for (std::size_t i = 0; i < capacity_; i++) {
            try {
                new (array_ + i) T();
            } catch (...) {
                for (; i > 0; i--)
                    array_[i - 1].~T();
                std::free(array_);
                throw;
            }
        }
    }

    template<typename T>
    my_vector<T>::my_vector(const my_vector& other) : capacity_(other.capacity_), size_(other.size()),
                array_(static_cast<T*>(aligned_alloc(alignof(T), sizeof(T) * other.capacity_))) {
        for (std::size_t i = 0; i < size_; i++) {
            try {
                new(array_ + i) T(other.array_[i]);
            } catch (...) {
                for (; i > 0; i--) {
                    array_[i - 1].~T();
                }
                std::free(array_);
                throw;
            }
        }
    }

    template<typename T>
    my_vector<T>::my_vector(my_vector &&v) noexcept : capacity_(std::move(v.capacity_)),
                size_(std::move(v.size_)), array_(std::move(v.array_)) {
        v.capacity_ = 0;
        v.size_ = 0;
        v.array_ = nullptr;
    }

    template<typename T>
    void my_vector<T>::swap(my_vector<T> &other) noexcept {
        std::swap(capacity_, other.capacity_);
        std::swap(size_, other.size_);
        std::swap(array_, other.array_);
    }

    template<typename T>
    my_vector<T> &my_vector<T>::operator=(my_vector other) {
        this->swap(other);
        return *this;
    }

    template<typename T>
    my_vector<T> &my_vector<T>::operator=(my_vector &&v) noexcept {
        if (&v == this)
            return *this;
        for (; size_ > 0; size_--)
            array_[size_ - 1].~T();
        std::free(array_);
        size_ = std::move(v.size_);
        capacity_ = std::move(v.capacity_);
        array_ = std::move(v.array_);
        v.capacity_ = 0;
        v.size() = 0;
        v.array_ = nullptr;
        return *this;
    }

    template<typename T>
    my_vector<T>::~my_vector<T>() noexcept {
        for (; size_ > 0; size_--)
            array_[size_ - 1].~T();
        std::free(array_);
    }

    template<typename T>
    void my_vector<T>::reserve(std::size_t n) {
        if (capacity_ >= n) {
            return;
        }
        capacity_ = two_pow(n);
        T *v = static_cast<T *>(aligned_alloc(alignof(T), sizeof(T) * capacity_));
        if (v == nullptr) {
            throw std::bad_alloc();
        }
        for (std::size_t i = 0; i < size_; i++) {
            try {
                new(v + i) T(array_[i]);
            } catch (...) {
                for (; i > 0; i--)
                    v[i - 1].~T();
                std::free(v);
                throw;
            }
        }
        std::swap(v, array_);
        for (std::size_t i = 0; i < size_; i++) {
            v[i].~T();
        }
        std::free(v);
    }

    template<typename T>
    void my_vector<T>::resize(std::size_t n) {
        reserve(n);
        if (n < size_) {
            for (size_t i = n; i < size_; i++) {
                array_[i].~T();
            }
            size_ = n;
        }
        if (n >= size_) {
            for (; size_ < n; size_++) {
                try {
                    new(array_ + size_) T();
                } catch (...) {
                    size_--;
                    for (; size_ > 0; size_--) {
                        array_[size_ - 1].~T();
                    }
                    std::free(array_);
                    throw;
                }
            }
        }
    }

    template<typename T>
    size_t my_vector<T>::size() const noexcept {
        return size_;
    }

    template<typename T>
    size_t my_vector<T>::capacity() const noexcept {
        return capacity_;
    }

    template<typename T>
    bool my_vector<T>::empty() const noexcept {
        return size_ == 0;
    }

    template<typename T>
    T& my_vector<T>::operator[](std::size_t index) const noexcept {
        return array_[index];
    }

    template<typename T>
    void my_vector<T>::push_back(T t) {
        if (size_ == capacity_) {
            reserve(2 * capacity_);
        }
        new(array_ + size_) T(t);
        size_++;
    }

    template<typename T>
    void my_vector<T>::pop_back() noexcept {
        if (size_ > 0) {
            size_--;
            array_[size_].~T();
        }
    }

    template<typename T>
    void my_vector<T>::clear() {
        resize(0);
    }
}

#endif //MY_VECTOR_IMPL_H_
