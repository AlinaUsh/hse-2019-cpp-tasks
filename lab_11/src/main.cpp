#include "employees.h"
#include <iostream>
#include <cstdio>
#include <string>

int main() {
    std::string s, file;
    EmployeesArray workers_list;
    while (true) {
        std::cin >> s;
        if (s == "exit") {
            return 0;
        }
        if (s == "load") {
            std::cin >> file;
            std::ifstream istr;
            istr.open(file.c_str(), std::ios_base::binary);
            istr >> workers_list;
            istr.close();
        }
        if (s == "save") {
            std::cin >> file;
            std::ofstream ostr;
            ostr.open(file.c_str(), std::ios_base::binary);
            ostr << workers_list;
            ostr.close();
        }
        if (s == "add") {
            int type;
            std::cin >> type;
            if (type == DEVELOPER) {
                Developer *developer = new Developer;
                std::cin >> *developer;
                workers_list.add(developer);
            } else if (type == SALESMANAGER) {
                SalesManager *salesManager = new SalesManager;
                std::cin >> *salesManager;
                workers_list.add(salesManager);
            }
        }
        if (s == "list") {
            std::cout << workers_list;
        }
    }
    return 0;
}
