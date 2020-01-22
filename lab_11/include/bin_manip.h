#ifndef LAB_11_BIN_MANIP_H
#define LAB_11_BIN_MANIP_H

#include <iosfwd>
#include <string.h>
#include <iostream>

class write_le_int32 {
public:
    explicit write_le_int32(const int32_t &num);
    std::ostream &operator()(std::ostream &ostr) const;

private:
    int32_t num;
};

std::ostream &operator<<(std::ostream &ostr, write_le_int32 wlei_val);

class read_le_int32 {
public:
    explicit read_le_int32(int32_t &num);
    std::istream &operator()(std::istream &istr) const;

private:
    int32_t &num;
};

std::istream &operator>>(std::istream &istr, const read_le_int32 wlei_val);

class write_bool {
public:
    explicit write_bool(const bool &val);
    std::ostream &operator()(std::ostream &ostr) const;

private:
    bool val;
};

std::ostream &operator<<(std::ostream &ostr, write_bool wb_val);

class read_bool {
public:
    explicit read_bool(bool &val);
    std::istream &operator()(std::istream &istr) const;

private:
    bool &val;
};

std::istream &operator>>(std::istream &istr, const read_bool rb_val);

class write_c_str {
public:
    explicit write_c_str(char * const str);
    std::ostream &operator()(std::ostream &ostr) const;

private:
    char * _str;
};

std::ostream &operator<<(std::ostream &ostr, const write_c_str &w_str);

class read_c_str {
public:
    explicit read_c_str(char *&str, int32_t size);
    std::istream &operator()(std::istream &istr) const;

private:
    char *&str;
    int32_t size;
};

std::istream &operator>>(std::istream &istr, const read_c_str r_str);

#endif //LAB_11_BIN_MANIP_H
