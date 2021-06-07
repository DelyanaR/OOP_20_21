#pragma once
#include<iostream>
class Drink {
public:
    Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price);
    Drink(const Drink&);
    Drink& operator=(const Drink&);

    const char* get_name() const;
    int get_calories() const;
    double get_quantity() const;
    double get_price() const;

    void set_name(const char* new_name);

    Drink();
    ~Drink();
    void set_calories(const int new_calories);
    void set_quantity(const double new_quantity);
    void set_price(const double new_price);
    bool checkNames(const char*) const;
    void print() const;
    unsigned int my_strlen(const char* s)const;
private:
    char* name = nullptr;
    int calories;
    double quantity;
    double price;
};

