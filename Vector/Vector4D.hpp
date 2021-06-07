#pragma once

// Add all other required methods and fields of the class.

class Vector4D {

public:

    Vector4D(double, double, double, double);
    double& operator[](int index);
    Vector4D& operator=(const Vector4D& rhs);
    Vector4D operator+ (const Vector4D& rhs)const;
    Vector4D& operator+= (const Vector4D& rhs);
    Vector4D operator- (const Vector4D& rhs)const;
    Vector4D& operator-= (const Vector4D& rhs);
    Vector4D operator* (const Vector4D& rhs)const;
    Vector4D operator*(double scalar)const;
    Vector4D& operator*= (const Vector4D& rhs);
    Vector4D& operator*= (double scalar);
    Vector4D operator/ (const Vector4D& rhs)const;
    Vector4D& operator/= (const Vector4D& rhs);
    bool operator== (const Vector4D& rhs)const;
    bool operator!= (const Vector4D& rhs)const;
    bool operator< (const Vector4D& rhs)const;
    bool operator> (const Vector4D& rhs)const;
    bool operator<= (const Vector4D& rhs)const;
    bool operator>= (const Vector4D& rhs)const;
    bool operator!()const;
    Vector4D operator-()const;

private:
    double vector[4];
    const int FOUR = 4;
};

