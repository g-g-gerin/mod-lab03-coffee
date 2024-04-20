// Copyright 2022 UNN-IASR
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
    Automata();
    void on();
    void off();
    void coin(int money);
    void getMenu();
    STATES getState();
    void choice(unsigned int drinkNumber);
    bool check(unsigned int drinkNumber);
    void cancel();
    void cook(unsigned int drinkNumber);
    void finish();
};
