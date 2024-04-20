// Copyright 2022 UNN-IASR
#include "Automata.h"
#include <gtest/gtest.h>

TEST(AutomataTest, TestOnOff) {
    Automata automata;
    EXPECT_EQ(automata.getState(), STATES::OFF);
    automata.on();
    EXPECT_EQ(automata.getState(), STATES::WAIT);
    automata.off();
    EXPECT_EQ(automata.getState(), STATES::OFF);
}
