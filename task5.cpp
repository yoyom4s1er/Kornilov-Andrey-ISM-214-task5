#include <iostream>
#include <stdexcept>
#include <string>
#include "task5.h"

int root1(int hours, int minutes) {
    return hours * SECONDS_IN_HOUR + minutes * SECONDS_IN_MINUTES;
}

int root2(int hours, int minutes) throw() {
    return hours * SECONDS_IN_HOUR + minutes * SECONDS_IN_MINUTES;
}

int root3(int hours, int minutes) throw(std::invalid_argument) {
    if (hours < 0 or minutes < 0)
        throw std::invalid_argument("часы или минуты меньше нуля");
    return hours * SECONDS_IN_HOUR + minutes * SECONDS_IN_MINUTES;
}

int root4_1(int hours, int minutes) throw(except1) {
    if (hours < 0 or minutes < 0)
        throw except1();
    return hours * SECONDS_IN_HOUR + minutes * SECONDS_IN_MINUTES;
}

int root4_2(int hours, int minutes) throw(except2) {
    if (hours < 0 or minutes < 0)
        throw except2("часы или минуты меньше нуля");
    return hours * SECONDS_IN_HOUR + minutes * SECONDS_IN_MINUTES;
}

int root4_3(int hours, int minutes) throw(except3) {
    if (hours < 0)
        throw except3("Неверный аргумент(часы): ", hours);
    else if (minutes < 0)
        throw except3("Неверный аргумент(минуты): ", minutes);
    return hours * SECONDS_IN_HOUR + minutes * SECONDS_IN_MINUTES;
}

void helper(int (*func)(int, int)) {
    double hours, minutes;
    std::cout << "Введите часы ";
    std::cin >> hours;
    std::cout << "Введите минуты ";
    std::cin >> minutes;
    std::cout << "Полученные секунды: " << func(hours, minutes) << '\n';
}
