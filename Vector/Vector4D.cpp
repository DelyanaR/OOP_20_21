#include "Vector4D.hpp"

Vector4D::Vector4D(double first, double second, double third, double fourth) {
	this->vector[0] = first;
	this->vector[1] = second;
	this->vector[2] = third;
	this->vector[3] = fourth;
}

double& Vector4D::operator[](int index) {
	return this->vector[index];
}

Vector4D& Vector4D::operator=(const Vector4D& rhs) {
    if (!rhs.vector) {}
    else {
        for (int i = 0; i < this->FOUR; i++) this->vector[i] = rhs.vector[i];
    }
    return *this;
}

Vector4D Vector4D::operator+ (const Vector4D& rhs)const {
	Vector4D result = *this;
	for(int i=0;i<this->FOUR;i++) result.vector[i] += rhs.vector[i];
	return result;
}

Vector4D& Vector4D::operator+= (const Vector4D& rhs) {
    if (!rhs.vector) {}
    else if (!this->vector){
        for (int i = 0; i< this->FOUR; i++) this->vector[i] = rhs.vector[i];
    }
    else{
        for (int i = 0; i< this->FOUR; i++){
            this->vector[i] += rhs.vector[i];
        }
	}
    return *this;
}

Vector4D Vector4D::operator- (const Vector4D& rhs)const {
	Vector4D result = *this;
	for (int i = 0; i< this->FOUR; i++) result.vector[i] -= rhs.vector[i];
	return result;
}

Vector4D& Vector4D::operator-= (const Vector4D& rhs) {
    if (!rhs.vector) {}
    else if (!this->vector) {
        for (int i = 0; i< this->FOUR; i++) this->vector[i] = rhs.vector[i];
    }
    else {
        for (int i = 0; i< this->FOUR; i++) {
            this->vector[i] -= rhs.vector[i];
        }
    }
    return *this;
}

Vector4D Vector4D::operator* (const Vector4D& rhs)const {
	Vector4D result = *this;
	for (int i = 0; i< this->FOUR; i++) result.vector[i] *= rhs.vector[i];
	return result;
}

Vector4D Vector4D::operator*(double scalar)const {
    Vector4D result = *this;
    for (int i = 0; i < this->FOUR; i++) result.vector[i] *= scalar;
    return result;
}

Vector4D& Vector4D::operator*= (const Vector4D& rhs) {
    if (!rhs.vector) {}
    else if (!this->vector) {
        for (int i = 0; i< this->FOUR; i++) this->vector[i] = rhs.vector[i];
    }
    else {
        for (int i = 0; i< this->FOUR; i++) {
            this->vector[i] *= rhs.vector[i];
        }
    }
    return *this;
}

Vector4D& Vector4D::operator*= (double scalar){
    for (int i = 0; i < this->FOUR; i++) {
        this->vector[i] *= scalar;
    }
    return *this;
}

Vector4D Vector4D::operator/ (const Vector4D& rhs)const {
	Vector4D result = *this;
	for (int i = 0; i< this->FOUR; i++) result.vector[i] /= rhs.vector[i];
	return result;
}

Vector4D& Vector4D::operator/= (const Vector4D& rhs) {
    if (!rhs.vector){}
    else if (!this->vector) {
        for (int i = 0; i< this->FOUR; i++) this->vector[i] = rhs.vector[i];
    }
    else {
        for (int i = 0; i< this->FOUR; i++) {
            this->vector[i] /= rhs.vector[i];
        }
    }
    return *this;
}

bool Vector4D::operator== (const Vector4D& rhs)const {
    for (int i = 0; i< this->FOUR; i++) {
        if (this->vector[i] == rhs.vector[i]) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

bool Vector4D::operator!= (const Vector4D& rhs)const {
    return !(*this == rhs);
}

bool Vector4D::operator< (const Vector4D& rhs)const {
    for(int i=0;i<this->FOUR;i++){
        if (this->vector[i] < rhs.vector[i]) {
            return true;
        }
        else if(this->vector[i]!=rhs.vector[i]){
            return false;
        }
    }
    return false;
}

bool Vector4D::operator> (const Vector4D& rhs)const {
    if (*this == rhs) {
        return false;
    }
    return !(*this < rhs);
}

bool Vector4D::operator<= (const Vector4D& rhs)const {
    for (int i = 0; i< this->FOUR; i++) {
        if (this->vector[i] <= rhs.vector[i]) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

bool Vector4D::operator>= (const Vector4D& rhs)const {
    if (*this == rhs) {
        return true;
    }
    return !(*this <= rhs);
}

bool Vector4D::operator!()const {
    for (int i = 0; i< this->FOUR; i++) {
        if (this->vector[i]==0) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

Vector4D Vector4D::operator- ()const {
    Vector4D result = *this;
    Vector4D my_new = Vector4D(-1, -1, -1, -1);
    result *= my_new;
    return result;
}
