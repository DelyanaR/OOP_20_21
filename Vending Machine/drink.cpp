#include "drink.hpp"
using namespace std;

Drink::Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price) {
	set_name(init_name);
	this->calories = init_calories;
	this->quantity = init_quantity;
	this->price = init_price;
}

Drink::Drink(const Drink& from) {
	if (this->name != nullptr) {
		delete[] this->name;
	}
	int new_size = my_strlen(from.get_name());
	this->name = new char[new_size+1];
	for (int i = 0; i < new_size; i++) {
		this->name[i] = from.name[i];
	}
	this->name[new_size] = '\0';
	this->calories = from.calories;
	this->quantity = from.quantity;
	this->price = from.price;

}
Drink& Drink::operator=(const Drink& rhs) {
	if (this != &rhs) {
		if (this->name != nullptr) {
			delete[] this->name;
		}
		int new_size = my_strlen(rhs.get_name());
		this->name = new char[new_size+1]; 
		for (int i = 0; i < new_size; i++) {
			this->name[i] = rhs.name[i]; 
		}
		this->name[new_size] = '\0';
		this->calories = rhs.calories;
		this->quantity = rhs.quantity;
		this->price = rhs.price;
	}
	return *this;
}

const char* Drink::get_name() const {
	return this->name;
}
int Drink::get_calories() const {
	return this->calories;
}
double Drink::get_quantity() const {
	return this->quantity;
}
double Drink::get_price() const {
	return this->price;
}

void Drink::set_name(const char* new_name) {
	if (new_name != nullptr) {
		int i = my_strlen(new_name);
		if (this->name != nullptr) {
			delete[] this->name;
		}
		this->name = new char[i + 1];
		for (int j = 0; j < i; j++) {
			this->name[j] = new_name[j];
		}
		this->name[i] = '\0';
	}
	else {
		this->name = new char[1]{ '\0' };
	}
}

Drink::Drink() {
	this->name = nullptr;
	this->calories = 0;
	this->price = 0;
	this->quantity = 0;
};

Drink::~Drink() {
	delete[] this->name;
}

unsigned int Drink::my_strlen(const char* s)const {
	if (s == nullptr) {
		return 0;
	}
	unsigned int count = 0;
	while (*s != '\0'){
		count++;
		s++;
	}
	return count;
}

void Drink::set_calories(const int new_calories) {
	this->calories = new_calories;
}
void Drink::set_quantity(const double new_quantity) {
	this->quantity = new_quantity;
}
void Drink::set_price(const double new_price) {
	this->price = new_price;
}

bool Drink::checkNames(const char* from_name) const {
	int size_name = my_strlen(this->name);
	int size_from_name = my_strlen(from_name);
	if (size_name == size_from_name) {
		for (int i = 0; i < size_from_name; i++) {
			if (this->name[i] != from_name[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

void Drink::print() const {
	cout << this->name << " ";
	cout << " " << this->calories << " " << this->quantity << " " << this->price << endl;
}
