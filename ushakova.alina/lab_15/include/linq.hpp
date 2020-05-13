#ifndef LINQ_H_
#define LINQ_H_

#include <utility>
#include <vector>

namespace linq {
    namespace impl {

        template<typename T, typename Iter>
        class range_enumerator;

        template<typename T>
        class drop_enumerator;

        template<typename T, typename U, typename F>
        class select_enumerator;

        template<typename T, typename F>
        class until_enumerator;

        template<typename T, typename P>
        class where_enumerator;

        template<typename T>
        class take_enumerator;

        template<typename T>
        class enumerator {
        public:
            virtual const T &operator*() = 0; // Получает текущий элемент.
            virtual enumerator<T> &operator++() = 0;  // Переход к следующему элементу
            virtual operator bool() const = 0;  // Возвращает true, если есть текущий элемент

            auto drop(int count) {
                return drop_enumerator<T>(*this, count);
            }

            template<typename U = T, typename F>
            auto select(F func) {
                return select_enumerator<U, T, F>(*this, std::move(func));
            }

            template<typename F>
            auto until(F func) {
                return until_enumerator<T, F>(*this, std::move(func));
            }

            template<typename Iter>
            void copy_to(Iter it) {
                while (*this) {
                    *it = **this;
                    ++it;
                    ++(*this);
                }
            }

            std::vector<T> to_vector() {
                std::vector<T> v;
                this->copy_to(std::back_inserter(v));
                return v;
            }

            auto until_eq(const T& val) {
                auto pred = [val](const T& x) {
                    return x == val;
                };
                return until(pred);
            }

            template <typename P>
            auto where(P pred) {
                return where_enumerator<T, P>(*this, std::move(pred));
            }

            auto where_neq(const T& val) {
                auto pred = [val](const T& x) {
                    return x !=val;
                };
                return where(pred);
            }

            auto take(int count) {
                return take_enumerator<T>(*this, count);
            }
        };

        template<typename T, typename Iter>
        class range_enumerator : public enumerator<T> {
        public:
            range_enumerator(Iter begin, Iter end) : begin_(begin), end_(end) { }
            const T& operator*() override { return *begin_; }
            explicit operator bool() const override { return begin_ != end_; }
            range_enumerator& operator++() override {
                begin_++;
                return *this;
            }

        private:
            Iter begin_, end_;
        };

        template<typename T>
        class drop_enumerator : public enumerator<T> {
        public:
            drop_enumerator(enumerator<T> &parent, int count) : parent_(parent) {
                while (parent && count > 0) {
                    ++parent;
                    count--;
                }
            }
            const T& operator*() override { return *parent_; }
            explicit operator bool() const override { return parent_; }
            drop_enumerator& operator++() override {
                ++parent_;
                return *this;
            };

        private:
            enumerator<T>& parent_;
        };

        template<typename T, typename U, typename F>
        class select_enumerator : public enumerator<T> {
        public:
            select_enumerator(enumerator<U> &parent, F func) : parent_(parent), func_(std::move(func)) { }
            const T&operator*() override {
                return last_ = func_(*parent_);
            }
            explicit operator bool() const override { return parent_; }
            select_enumerator& operator++() override {
                ++parent_;
                return *this;
            }

        private:
            T last_;
            enumerator<U>& parent_;
            F func_;
        };

        template<typename T, typename F>
        class until_enumerator : public enumerator<T> {
        public:
            until_enumerator(enumerator<T> &parent, F predicate) : parent_(parent), predicate_(std::move(predicate)) { }
            const T& operator*() override { return *parent_; }
            explicit operator bool() const override {
                return parent_ && !predicate_(*parent_);
            }
            until_enumerator& operator++() override {
                ++parent_;
                return *this;
            }

        private:
            enumerator<T>& parent_;
            F predicate_;
        };

        template<typename T, typename P>
        class where_enumerator : public enumerator<T> {
        public:
            where_enumerator(enumerator<T>& parent, P pred) : parent_(parent), predicate_(std::move(pred)) { }
            const T& operator*() override { return *parent_; }
            explicit operator bool() const override {
                bool cur_ = parent_ && predicate_(*parent_);
                while (parent_ && !cur_) {
                    ++parent_;
                    cur_ = parent_ && predicate_(*parent_);
                }
                return parent_;
            }
            where_enumerator& operator++() override {
                ++parent_;
                return *this;
            }

        private:
            enumerator<T>& parent_;
            P predicate_;
        };

        template<typename T>
        class take_enumerator : public enumerator<T> {
        public:
            take_enumerator(enumerator<T>& parent, int count) : parent_(parent), count_(count) { }
            const T& operator*() override { return *parent_; }
            explicit operator bool() const override {
                return parent_ && count_ > 0;
            }
            take_enumerator& operator++() override {
                ++parent_;
                --count_;
                return *this;
            }

        private:
            enumerator<T>& parent_;
            int count_;
        };

    } // namespace impl

    template<typename Iter>
    auto from(Iter begin, Iter end) {
        return impl::range_enumerator<typename std::iterator_traits<Iter>::value_type, Iter>(begin, end);
    }

} // namespace linq

#endif