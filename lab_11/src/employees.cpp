#include "employees.h"
#include "bin_manip.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

Employee::~Employee() {
    delete[] this->_name;
this->_name = nullptr;
}

int Developer::salary() const {
    int salary = _base_salary;
    if (_has_bonus) { salary += 1000; }
    return salary;
}

int SalesManager::salary() const {
    return _base_salary + _sold_nm * _price * 0.01;
}

EmployeesArray::~EmployeesArray() {
    for (int i = 0; i < _employees_num; i++) {
        delete _employees[i];
    }
    delete[] _employees;
}

EmployeesArray::EmployeesArray() {
    _array_size = 10;
    _employees = new Employee *[_array_size];
}

int EmployeesArray::total_salary() const {
    int _total_salary = 0;
    for (int i = 0; i < _employees_num; i++)
        _total_salary += _employees[i]->salary();
    return _total_salary;
}

void EmployeesArray::add(const Employee *e) {
    if (_employees_num + 1 == _array_size) {
        Employee **_new_employees;
        _new_employees = new Employee *[2 * _array_size];
        memcpy(_new_employees, _employees, _employees_num * sizeof(Employee *));
        std::swap(_new_employees, _employees);
        delete[] _new_employees;
        _array_size *= 2;
    }
    _employees[_employees_num] = (Employee *) e;
    _employees_num++;
}

std::ostream &Developer::print(std::ostream &out) const {
    out << *this;
    return out;
}

std::ofstream &Developer::print(std::ofstream &out) const {
    out << *this;
    return out;
}

std::ostream &SalesManager::print(std::ostream &out) const {
    out << *this;
    return out;
}

std::ofstream &SalesManager::print(std::ofstream &out) const {
    out << *this;
    return out;
}

std::ostream &operator<<(std::ostream &ofstr, const Developer &developer) {
    ofstr << "Developer\n";
    ofstr << "Name: " << developer._name << '\n';
    ofstr << "Base Salary: " << developer._base_salary << '\n';
    ofstr << "Has bonus: ";
    if (developer._has_bonus) {
        ofstr << "+\n";
    } else {
        ofstr << "-\n";
    }
    return ofstr;
}

std::ostream &operator<<(std::ostream &ofstr, const SalesManager &salesManager) {
    ofstr << "Sales Manager\n";
    ofstr << "Name: " << salesManager._name << '\n';
    ofstr << "Base Salary: " << salesManager._base_salary << '\n';
    ofstr << "Sold items: " << salesManager._sold_nm << '\n';
    ofstr << "Item price: " << salesManager._price << '\n';
    return ofstr;
}

std::istream &operator>>(std::istream &istr, Developer &developer) {
    std::string name;
    istr >> name >> developer._base_salary >> developer._has_bonus;
    developer._name = new char[101];
    std::strcpy(developer._name, name.c_str());
    return istr;
}

std::istream &operator>>(std::istream &ostr, SalesManager &salesManager) {
    std::string name;
    ostr >> name >> salesManager._base_salary >> salesManager._sold_nm >> salesManager._price;
    salesManager._name = new char[101];
    std::strcpy(salesManager._name, name.c_str());
    return ostr;
}

std::ostream &operator<<(std::ostream &ostr, const EmployeesArray &array) {
    for (int i = 0; i < array._employees_num; i++)
        ostr << i + 1 << ". " << *(array._employees[i]);
    ostr << "== Total salary: " << array.total_salary() << '\n';
    return ostr;
}

std::ifstream &operator>>(std::ifstream &istr, EmployeesArray &array) {
    int32_t type, number_of_workers;
    istr >> read_le_int32(number_of_workers);
    for (int i = 0; i < number_of_workers; i++) {
        istr >> read_le_int32(type);
        switch (type) {
            case DEVELOPER: {
                auto *developer = new Developer();
                istr >> *developer;
                array.add(developer);
                break;
            }
            case SALESMANAGER: {
                auto *salesManager = new SalesManager();
                istr >> *salesManager;
                array.add(salesManager);
                break;
            }
        }
    }
    return istr;
}

std::ofstream &operator<<(std::ofstream &ofstr, const EmployeesArray &array) {
    ofstr << write_le_int32(array._employees_num);
    for (int i = 0; i < array._employees_num; i++)
        ofstr << *array._employees[i];
    return ofstr;
}

std::ifstream &operator>>(std::ifstream &in, Developer &developer) {
    developer._name = new char[101];
    in >> read_c_str(developer._name, 101) 
	>> read_le_int32(developer._base_salary)
        >> read_bool(developer._has_bonus);
    return in;
}

std::ofstream &operator<<(std::ofstream &ofstr, const Developer &developer) {
    ofstr << write_le_int32(DEVELOPER) << write_c_str(developer._name)
        << write_le_int32(developer._base_salary) << write_bool(developer._has_bonus);
    return ofstr;
}

std::ifstream &operator>>(std::ifstream &istr, SalesManager &salesManager) {
    salesManager._name = new char[101];
    istr >> read_c_str(salesManager._name, 101);
    istr >> read_le_int32(salesManager._base_salary)
       >> read_le_int32(salesManager._sold_nm) >> read_le_int32(salesManager._price);
    return istr;
}

std::ofstream &operator<<(std::ofstream &ofstr, const SalesManager &salesManager) {
    ofstr << write_le_int32(SALESMANAGER) << write_c_str(salesManager._name)
        << write_le_int32(salesManager._base_salary) << write_le_int32(salesManager._sold_nm) << write_le_int32(salesManager._price);
    return ofstr;
}
