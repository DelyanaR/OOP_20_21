#pragma once
#include "drink.hpp"
#include <iostream>

class VendingMachine {
public:
    VendingMachine();
    VendingMachine(const VendingMachine& from);
    VendingMachine& operator=(const VendingMachine& from);

    bool add_drink(const Drink& to_add);
    int buy_drink(const char* drink_name, const double money);

    double get_income() const;

    ~VendingMachine();
    VendingMachine(Drink* new_drinks, const unsigned int new_n);
    void print()const;
private:
    Drink* drinks;
    unsigned int n_drinks;
    double income;
};

