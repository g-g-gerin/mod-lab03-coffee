#include "Automata.h"
#include <iostream>

Automata::Automata() : cash(0), state(STATES::OFF) {
    // Инициализация меню и цен для примера
    menu = {"Чай", "Кофе", "Молоко"};
    prices = {25, 50, 30};
}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        std::cout << "Автомат включен" << std::endl;
    }
}

void Automata::off() {
    if (state == STATES::WAIT) {
        state = STATES::OFF;
        std::cout << "Автомат выключен" << std::endl;
    }
}

void Automata::coin(int money) {
    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        cash += money;
        state = STATES::ACCEPT;
        std::cout << "Баланс: " << cash << std::endl;
    }
}

void Automata::getMenu() {
    std::cout << "Меню:" << std::endl;
    for (size_t i = 0; i < menu.size(); ++i) {
        std::cout << i + 1 << ". " << menu[i] << " - " << prices[i] << std::endl;
    }
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(unsigned int drinkNumber) {
    if (state == STATES::ACCEPT && drinkNumber <= menu.size()) {
        state = STATES::CHECK;
        if (check(drinkNumber - 1)) {
            cook(drinkNumber - 1);
        } else {
            std::cout << "Недостаточно средств" << std::endl;
            cancel();
        }
    }
}

bool Automata::check(unsigned int drinkNumber) {
    return cash >= prices[drinkNumber];
}

void Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::CHECK) {
        std::cout << "Возврат средств: " << cash << std::endl;
        cash = 0;
        state = STATES::WAIT;
    }
}

void Automata::cook(unsigned int drinkNumber) {
    if (state == STATES::CHECK) {
        std::cout << "Приготовление: " << menu[drinkNumber] << std::endl;
        cash -= prices[drinkNumber];
        state = STATES::COOK;
        finish();
    }
}

void Automata::finish() {
    std::cout << "Ваш напиток готов. Заберите свой заказ." << std::endl;
    state = STATES::WAIT;
}
