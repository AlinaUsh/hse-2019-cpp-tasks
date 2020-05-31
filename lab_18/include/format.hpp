#ifndef LAB_18_FORMAT_HPP
#define LAB_18_FORMAT_HPP

#include <cstddef>  // std::size_t
#include <string>  // std::string
#include <charconv>

#if __cplusplus < 201703L
#error At least C++17 is required
#endif

namespace format {
    template<typename T, typename Enable = void>
    struct FormatHelper {
        static constexpr bool hasValue = false;
    };

    template<typename T, typename std::enable_if_t<FormatHelper<T>::hasValue> * = nullptr>
    std::string make_string(const T &value) {
        FormatHelper<T> helper(value);  // Explicit!
        std::string formatted;
        formatted.reserve(helper.estimate_size());
        helper.append_to(formatted);
        formatted.shrink_to_fit();
        return formatted;
    }

    template<>
    struct FormatHelper<bool> {
        explicit FormatHelper(bool value) : value_{value} {}
        std::size_t estimate_size() const {
            return value_ ? 4 : 5;
        }
        void append_to(std::string &s) const {
            s += value_ ? "true" : "false";
        }
        static constexpr bool hasValue = true;
    private:
        bool value_;
    };

    template<typename T>
    struct FormatHelper<T, std::enable_if_t<std::is_integral_v<T>>> {
        explicit FormatHelper(T value) : value_{value} { }
        std::size_t estimate_size() const {
            return std::numeric_limits<T>::digits10 + 5;
        }
        void append_to(std::string &s) const {
            char buffer[estimate_size()] = {};
            auto[p, ec] = std::to_chars(std::begin(buffer), std::end(buffer), value_);
            s += std::string_view(buffer, p - buffer);
        }
        static constexpr bool hasValue = true;
    private:
        T value_;
    };

    template<typename T>
    struct FormatHelper<T, typename std::enable_if_t<std::is_same_v<std::string, decltype(std::declval<T>().format())>>> {
        explicit FormatHelper(const T& value) : value{value} {}
        static constexpr std::size_t estimate_size() {
            return 10;
        }
        void append_to(std::string& s) const {
            s += value.format();
        }
        static constexpr bool hasValue = true;
    private:
        const T& value;
    };

}  // namespace format

#endif //LAB_18_FORMAT_HPP
