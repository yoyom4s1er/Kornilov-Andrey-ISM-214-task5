#include <iostream>
#include <string>
#include "task5.h"

int main() {
    setlocale(LC_ALL, "rus");
    std::cout << "Программа переводит часы и минуты в секунды \n";

    try {
        helper(root1);
    }
    catch (...) {
        std::cout << "Произошло исключение в функции root1" << std::endl;
    }

    try {
        helper(root2);
    }
    catch (...) {
        std::cout << "Произошло исключение в функции root2" << std::endl;
    }

    try {
        helper(root3);
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        helper(root4_1);
    }
    catch (except1) {
        std::cout << "Произошло исключение except1 в функции root4_1" << std::endl;
    }

    try {
        helper(root4_2);
    }
    catch (except2& e) {
        std::cout << e.message() << std::endl;
    }

    try {
        helper(root4_3);
    }
    catch (except3& e) {
        std::cout << e.what() << " " << e.arg() << std::endl;
    }
}
