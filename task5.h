#include <iostream>
#include <stdexcept>
#include <string>

/*
* \brief Именованная константа "количество секунд в часе"
*/
#define SECONDS_IN_HOUR 3600

/*
* \brief Именованная константа "количество секунд в минуте"
*/
#define SECONDS_IN_MINUTES 60

/*
* \brief пустой класс
*/
class except1 {};

/**
* \brief независимый класс с полями-параметрами функции
*/
class except2 {
    std::string msg;
public:
    except2(const std::string& s) : msg(s) {}
    const char* message() const { return msg.c_str(); }
};

/*
* \brief Класс наследник от стандартного исключения с полем
*/
class except3 : public std::invalid_argument {
    double num;
public:
    except3(const std::string msg, double n) : invalid_argument(msg), num(n) {}
    double arg() const { return num; }
};

/**
* \brief без спецификации исключений
*/
int root1(int hours, int minutes);

/**
* \brief со спецификацией throw()
*/
int root2(int hours, int minutes) throw();
/**
* \brief с конкретной спецификацией с подходящим стандартным исключением
*/
int root3(int hours, int minutes) throw(std::invalid_argument);

/**
* \brief Спецификация с собственным реализованным исключением
*/
int root4_1(int hours, int minutes) throw(except1);

/**
* \brief Спецификация с собственным реализованным исключением
*/
int root4_2(int hours, int minutes) throw(except2);

/**
* \brief Спецификация с собственным реализованным исключением
*/
int root4_3(int hours, int minutes) throw(except3);

void helper(int (*func)(int, int));
