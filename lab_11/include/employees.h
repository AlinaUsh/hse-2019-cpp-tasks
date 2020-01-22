#ifndef LAB11_EMPLOYEES_H_INCLUDED
#define LAB11_EMPLOYEES_H_INCLUDED

#include <stdint.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

enum worker_type {
    DEVELOPER = 1,
    SALESMANAGER = 2
};

class Employee {
public:
    Employee() = default;
    Employee(char *_name, int32_t _base_salary);
    virtual ~Employee();

    virtual int salary() const = 0;

    virtual std::ostream &print(std::ostream &out) const = 0;
    virtual std::ofstream &print(std::ofstream &out) const = 0;

    friend std::ostream &operator<<(std::ostream &out, Employee &e) {
        return e.print(out);
    }

    friend std::ofstream &operator<<(std::ofstream &out, Employee &e) {
        return e.print(out);
    }

private:
    Employee(Employee &other);
    Employee &operator=(Employee &other);

protected:
    char *_name = nullptr;
    int32_t _base_salary = 0;
};


class Developer : public Employee {
public:
    Developer() = default;
    Developer(char *_name, int32_t _base_salary, bool _has_bounus);

    int salary() const override;

    friend std::ostream &operator<<(std::ostream &os, const Developer &developer);
    friend std::istream &operator>>(std::istream &is, Developer &developer);
    friend std::ofstream &operator<<(std::ofstream &os, const Developer &developer);
    friend std::ifstream &operator>>(std::ifstream &is, Developer &developer);

    std::ostream &print(std::ostream &out) const;
    std::ofstream &print(std::ofstream &out) const;

private:
    Developer(Developer &other);
    Developer &operator=(Developer &other);

    bool _has_bonus = false;
};


class SalesManager : public Employee {
public:
    SalesManager() = default;
    SalesManager(char *_name, int32_t _base_salary, int32_t _sold_nm, int32_t _price);

    int salary() const override;

    friend std::istream &operator>>(std::istream &in, SalesManager &salesManager);
    friend std::ostream &operator<<(std::ostream &out, const SalesManager &salesManager);
    friend std::ifstream &operator>>(std::ifstream &in, SalesManager &salesManager);
    friend std::ofstream &operator<<(std::ofstream &out, const SalesManager &salesManager);

    std::ostream &print(std::ostream &out) const;
    std::ofstream &print(std::ofstream &out) const;

private:
    SalesManager(SalesManager &other);
    SalesManager &operator=(SalesManager &other);

    int32_t _sold_nm = 0, _price = 0;
};


class EmployeesArray {
public:
    ~EmployeesArray();
    EmployeesArray();

    void add(const Employee *e);
    int total_salary() const;

    friend std::ifstream &operator>>(std::ifstream &input, EmployeesArray &array);
    friend std::ostream &operator<<(std::ostream &print, const EmployeesArray &array);
    friend std::ofstream &operator<<(std::ofstream &ofstr, const EmployeesArray &array);

private:
    EmployeesArray(const EmployeesArray &array);
    EmployeesArray &operator=(EmployeesArray &array);

    Employee **_employees;
    int _employees_num = 0;
    int _array_size = 0;
};

#endif
