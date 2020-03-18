#ifndef MY_ARRAY_H_
#define MY_ARRAY_H_

#include <cstddef>
#include <cstring>
#include <stdexcept>

namespace lab_13 {

    const uint32_t BYTE = 8;

    template<typename T, std::size_t N>
    class my_array {
    public:
        T& at(std::size_t index);
        const T& at(std::size_t index) const;
        T& operator[](std::size_t index);
        const T& operator[](std::size_t index) const;
        void fill(T val);
        bool empty() const {
            return false;
        }
        std::size_t size() const {
            return N;
        }
    private:
        T array_[N];
    };

    template<typename T, std::size_t N>
    T& my_array<T, N>::operator[](std::size_t index) {
        return array_[index];
    }

    template<typename T, std::size_t N>
    const T& my_array<T, N>::operator[](std::size_t index) const {
        return array_[index];
    }

    template<typename T, std::size_t N>
    T& my_array<T, N>::at(std::size_t index) {
        if (index >= N) {
            throw std::out_of_range("");
        }
        return array_[index];
    }

    template<typename T, std::size_t N>
    const T& my_array<T, N>::at(std::size_t index) const {
        if (index >= N) {
            throw std::out_of_range("");
        }
        return array_[index];
    }

    template<typename T, std::size_t N>
    void my_array<T, N>::fill(T val) {
        for (size_t i = 0; i < N; i++) {
            array_[i] = val;
        }
    }

    template <std::size_t N>
    class my_array<bool, N> {
    private:
        uint8_t array_[(N + BYTE - 1) / BYTE];
        class Proxy {
        public:
            Proxy(uint8_t &data, std::size_t bit) : data_(data), bit_(bit % BYTE) {};
            operator bool() const {
                return (data_ & (1 << bit_)) != 0;
            }
            Proxy& operator=(Proxy other);
            Proxy& operator=(bool x);

        private:
            std::size_t bit_;
            uint8_t &data_;
        };

    public:
        my_array() {
            this->fill(0);
        }
        bool operator[](std::size_t index) const {
            return (array_[index / BYTE] & (1 << (index % 8))) != 0;
        }
        Proxy operator[](std::size_t index) {
            return Proxy(array_[index / BYTE], index);
        }
        bool empty() const {
            return false;
        }
        std::size_t size() const {
            return N;
        }
        bool at(std::size_t index) const;
        Proxy at(std::size_t index);
        void fill(bool val);
    };

    template<std::size_t N>
    typename my_array<bool, N>::Proxy& my_array<bool, N>::Proxy::operator=(bool x) {
        data_ &= ~(1 << bit_);
        data_ |= ~(1 << bit_);
        return *this;
    }

    template<std::size_t N>
    typename my_array<bool, N>::Proxy& my_array<bool, N>::Proxy::operator=(Proxy other) {
        *this = bool(other);
        return *this;
    }

    template<std::size_t N>
    bool my_array<bool, N>::at(std::size_t index) const {
        if (index >= N) {
            throw std::out_of_range("");
        }
        return this->operator[](index);
    }

    template<std::size_t N>
    typename my_array<bool, N>::Proxy my_array<bool, N>::at(std::size_t index){
        if (index >= N) {
            throw std::out_of_range("");
        }
        return this->operator[](index);
    }

    template<std::size_t N>
    void my_array<bool, N>::fill(bool val) {
        if (val) {
            memset(array_, 0, (N + BYTE - 1) / BYTE);
            return;
        }
        memset(array_, (uint8_t)0 - 1, (N + BYTE - 1) / BYTE);
    }

}  // namespace lab_13

#endif  // MY_ARRAY_H_
