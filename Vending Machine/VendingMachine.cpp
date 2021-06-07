#include "VendingMachine.hpp"
using namespace std;

VendingMachine::VendingMachine() {
    this->drinks = new Drink[1]{ Drink("Fanta",100,0.5,2) };
    this->n_drinks = 1;
    this->income = 0;
}

VendingMachine::VendingMachine(const VendingMachine& from) {
    if (this != &from) {
        delete[] this->drinks;
    }
    this->n_drinks = from.n_drinks;
    this->drinks = new Drink[this->n_drinks];
    for (unsigned i = 0; i < this->n_drinks; i++) {
        this->drinks[i] = from.drinks[i];
    }
}

VendingMachine& VendingMachine::operator=(const VendingMachine& from) {
    if (this != &from) {
        delete[] this->drinks;
        this->n_drinks = from.n_drinks;
        this->drinks = new Drink[this->n_drinks];
        for (unsigned i = 0; i < this->n_drinks; i++) {
            this->drinks[i] = from.drinks[i];
        }
    }
    return *this;
}

bool VendingMachine::add_drink(const Drink& to_add) {
    for (unsigned i = 0; i < this->n_drinks; i++) {
        if (this->drinks[i].checkNames(to_add.get_name())) {
            return false;
        }
    }
    Drink* ptr = new Drink[this->n_drinks];
    for (unsigned i = 0; i < this->n_drinks; i++) {
        ptr[i]=this->drinks[i];
    }
    delete[] this->drinks;
    this->drinks = new Drink[this->n_drinks+1];
    for (unsigned i = 0; i < this->n_drinks; i++) {
        this->drinks[i].set_name(ptr[i].get_name());
        this->drinks[i].set_calories(ptr[i].get_calories());
        this->drinks[i].set_quantity(ptr[i].get_quantity());
        this->drinks[i].set_price(ptr[i].get_price());
    }
    delete[] ptr;
    this->drinks[this->n_drinks].set_name(to_add.get_name());
    this->drinks[this->n_drinks].set_calories(to_add.get_calories());
    this->drinks[this->n_drinks].set_quantity(to_add.get_quantity());
    this->drinks[this->n_drinks].set_price(to_add.get_price());
    this->n_drinks++;
    return true;
}

int VendingMachine::buy_drink(const char* drink_name, const double money) {
    bool check = false;
    unsigned  i = 0;
    for (; i < this->n_drinks; i++) {
        if (this->drinks[i].checkNames(drink_name)) {
            check = true;
            break;
        }
    }
    if (check && money >= this->drinks[i].get_price()) {
        this->income += money;
        this->n_drinks--;
        Drink* ptr = new Drink[this->n_drinks];
        int k = 0;
        for (unsigned j = 0; j < this->n_drinks+1; j++) {
            if (j != i) {
                ptr[k] = this->drinks[j];
                k++;
            }
            else {
                continue;
            }
        }
        delete[] this->drinks;
        this->drinks = new Drink[this->n_drinks];
        for (unsigned j = 0; j < this->n_drinks; j++) {
            this->drinks[j].set_name(ptr[j].get_name());
            this->drinks[j].set_calories(ptr[j].get_calories());
            this->drinks[j].set_quantity(ptr[j].get_quantity());
            this->drinks[j].set_price(ptr[j].get_price());
        }
        delete[] ptr;
        return 0;
    }
    else if (check && money < this->drinks[i].get_price()) {
        this->income += money;
        return 1;
    }
    return 2;
}

double VendingMachine::get_income() const {
    return this->income;
}

VendingMachine::~VendingMachine() {
    delete[] this->drinks;
}

VendingMachine::VendingMachine(Drink* new_drinks, const unsigned int new_n) {
    if (this->drinks != nullptr) {
        delete[] this->drinks;
    }
    this->n_drinks = new_n;
    this->drinks = new Drink[this->n_drinks];
    for (unsigned i = 0; i < this->n_drinks; i++) {
        this->drinks[i] = new_drinks[i];
    }
}

void VendingMachine::print()const {
    for (unsigned i = 0; i < this->n_drinks; i++) {
        this->drinks[i].print();
    }
    cout << this->n_drinks << endl;
}