#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

class Rational {
private:
    int numerator;
    int denominator;

    void simplify();

public:
    Rational(int n = 0, int d = 1);

    // Operator overloads
    Rational operator+(const Rational& rhs) const;
    Rational& operator+=(const Rational& rhs);

    Rational operator-(const Rational& rhs) const;
    Rational& operator-=(const Rational& rhs);

    Rational operator*(const Rational& rhs) const;
    Rational& operator*=(const Rational& rhs);

    Rational operator/(const Rational& rhs) const;
    Rational& operator/=(const Rational& rhs);

    bool operator==(const Rational& rhs) const;

    friend ostream& operator<<(ostream& os, const Rational& r);
};

#endif
