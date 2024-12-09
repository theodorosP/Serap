#include "Rational.h"
#include <numeric>

// Constructor
Rational::Rational(int n, int d) : numerator(n), denominator(d) {
    if (denominator == 0) {
        cout << "Error: Denominator cannot be zero. Setting to 1." << endl;
        denominator = 1;
    }
    simplify();
}

void Rational::simplify() {
    int gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Rational Rational::operator+(const Rational& rhs) const {
    return Rational(numerator * rhs.denominator + rhs.numerator * denominator, denominator * rhs.denominator);
}

Rational& Rational::operator+=(const Rational& rhs) {
    *this = *this + rhs;
    return *this;
}

Rational Rational::operator-(const Rational& rhs) const {
    return Rational(numerator * rhs.denominator - rhs.numerator * denominator, denominator * rhs.denominator);
}

Rational& Rational::operator-=(const Rational& rhs) {
    *this = *this - rhs;
    return *this;
}

Rational Rational::operator*(const Rational& rhs) const {
    return Rational(numerator * rhs.numerator, denominator * rhs.denominator);
}

Rational& Rational::operator*=(const Rational& rhs) {
    *this = *this * rhs;
    return *this;
}

Rational Rational::operator/(const Rational& rhs) const {
    if (rhs.numerator == 0) {
        throw invalid_argument("Division by zero!");
    }
    return Rational(numerator * rhs.denominator, denominator * rhs.numerator);
}

Rational& Rational::operator/=(const Rational& rhs) {
    *this = *this / rhs;
    return *this;
}

bool Rational::operator==(const Rational& rhs) const {
    return numerator == rhs.numerator && denominator == rhs.denominator;
}

ostream& operator<<(ostream& os, const Rational& r) {
    os << r.numerator << "/" << r.denominator;
    return os;
}
