#pragma once
#include <string>
#include <vector>

enum class STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
private:
    int cash;
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES state;

public:
    Automata(); // Конструктор
    void on(); // Включение автомата
    void off(); // Выключение автомата
    void coin(int money); // Занесение денег на счёт
    void getMenu(); // Считывание меню
    STATES getState(); // Считывание текущего состояния
    void choice(unsigned int drinkNumber); // Выбор напитка
    bool check(unsigned int drinkNumber); // Проверка наличия необходимой суммы
    void cancel(); // Отмена сеанса
    void cook(unsigned int drinkNumber); // Имитация процесса приготовления напитка
    void finish(); // Завершение обслуживания
};
