#include "Automata.h"

int main() {
    Automata automata;
    automata.on();
    automata.getMenu();
    automata.coin(50);
    automata.choice(2); // Предположим, что пользователь выбрал кофе (2)
    automata.off();

    return 0;
}
