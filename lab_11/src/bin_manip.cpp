#include "bin_manip.h"

#include <iostream>
#include <fstream>

write_le_int32::write_le_int32(const int32_t &num) : num(num) {}

std::ostream &write_le_int32::operator()(std::ostream &ostr) const {
    ostr.write((char *) &num, sizeof(num));
    return ostr;
}

std::ostream &operator<<(std::ostream &ostr, write_le_int32 wlei_val) {
    return wlei_val(ostr);
}

read_le_int32::read_le_int32(int32_t &num) : num(num) {}

std::istream &read_le_int32::operator()(std::istream &istr) const {
    istr.read((char *)&num, sizeof(num));
    return istr;
}

std::istream &operator>>(std::istream &istr, const read_le_int32 rlei_val) {
    return rlei_val(istr);
}

write_bool::write_bool(const bool &val) : val(val) {}

std::ostream &write_bool::operator()(std::ostream &ostr) const {
    ostr.write((char *) &val, sizeof(val));
    return ostr;
}

std::ostream &operator<<(std::ostream &ostr, write_bool wb_val) {
    return wb_val(ostr);
}

read_bool::read_bool(bool &val) : val(val) {}

std::istream &read_bool::operator()(std::istream &istr) const {
    istr.read((char *)&val, sizeof(val));
    return istr;
}

std::istream &operator>>(std::istream &istr, const read_bool rb_val) {
    return rb_val(istr);
}

write_c_str::write_c_str(char * const str) : _str(str) {}

std::ostream &write_c_str::operator()(std::ostream &ostr) const {
    int32_t cur_pos = 0;
    while (_str[cur_pos] != '\0') {
        ostr.write((char *) &_str[cur_pos], sizeof(char));
        cur_pos++;
    }
    ostr.write((char *) &_str[cur_pos], sizeof(char));
    return ostr;
}

std::ostream &operator<<(std::ostream &ostr, const write_c_str &w_str) {
    return w_str(ostr);
}

read_c_str::read_c_str(char *&str, int32_t size) : str(str), size(size) {}

std::istream &read_c_str::operator()(std::istream &istr) const {
    int32_t cur_pos = 0;
    char last = 'a';
    while (last != '\0' && cur_pos < size) {
        istr.read((char *)&last, sizeof(char));
        str[cur_pos] = last;
        cur_pos++;
    }
    if (last != '\0' && cur_pos == size) {
        istr.setstate(std::ios::failbit);
    }
    return istr;
}

std::istream &operator>>(std::istream &istr, const read_c_str r_str) {
    return r_str(istr);
}

