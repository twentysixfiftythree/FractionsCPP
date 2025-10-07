//
//  fraction_20ipw.cpp
//  Fractions
//
//  Created by Isaac W on 2025-10-03.
//
#include <iostream>
#include "fraction20ipw.h"
#include <cmath>

// ----
// constructors
// ----
Fraction::Fraction(int n) : _numerator(n), _denominator(1) {}
Fraction::Fraction(int n, int d) {
    if (d == 0) throw FractionException();
    if (d < 0 && n < 0) {
        _numerator = std::abs(n);
        _denominator = std::abs(d);
    }
    else if (d < 0) {  // n >= 0
        _numerator = -n;
        _denominator = std::abs(d);
    }
    else {
        _numerator = n;
        _denominator = d;
    }
    reduce();
}
// Invalid fraction
const char* FractionException::what() const noexcept {
    return "Invalid Fraction. E.g div by 0";
}
// internal functions
int Fraction::gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void Fraction::reduce() {
    int g = gcd(abs(_numerator), _denominator);
    _numerator /= g;
    _denominator /= g;
}
// iostreamed functions
std::ostream& operator<<(std::ostream& out, const Fraction& frac) {
    out << frac.numerator()<< '/' << frac.denominator();
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& frac) {
    std::string input;
    if (!(in >> input)) {
        // no input read (EOF or stream error)
        return in;
    }

    size_t slashPos = input.find('/');

    try {
        if (slashPos == std::string::npos) {
            // single integer case
            int n = std::stoi(input);
            frac = Fraction(n);
        } else {
            // fraction case
            std::string numStr = input.substr(0, slashPos);
            std::string denStr = input.substr(slashPos + 1);

            if (denStr.empty()) throw FractionException();

            int n = std::stoi(numStr);
            int d = std::stoi(denStr);
            if (d == 0) throw FractionException();

            frac = Fraction(n, d);
        }
    }
    catch (const std::invalid_argument&) {
        // stoi failed (non-numeric)
        in.setstate(std::ios::failbit);
        throw FractionException();
    }

    return in;
}
Fraction operator+(const Fraction& left, const Fraction& right) {
    int common_denom = left.denominator() * right.denominator();
    int left_num = left.numerator() * right.denominator();
    int right_num = right.numerator() * left.denominator();

    int result_num = left_num + right_num;

    return Fraction(result_num, common_denom);
}

Fraction operator-(const Fraction& left, const Fraction& right){
    int common_denom = left.denominator() * right.denominator();
    int left_num = left.numerator() * right.denominator();
    int right_num = right.numerator() * left.denominator();
    int result_num = left_num - right_num;
    return Fraction(result_num, common_denom);
}




Fraction operator*(const Fraction& left, const Fraction& right) {
    return Fraction(left.numerator()*right.numerator(), left.denominator()*right.denominator());
}

Fraction operator/(const Fraction& left, const Fraction& right) {
    if (right.numerator() == 0) {
        throw FractionException(); // division by zero
    }
    return Fraction(left.numerator() * right.denominator(),
                    left.denominator() * right.numerator());
}


Fraction operator-(const Fraction& frac){
    return Fraction(-frac.numerator(), frac.denominator());
}

Fraction& Fraction::operator++() {   // pre-increment (++f)
    _numerator += _denominator;
    return *this;
}

Fraction Fraction::operator++(int) { // post-increment (f++)
    Fraction temp = *this;
    _numerator += _denominator;
    return temp;
}


Fraction& Fraction::operator+=(const Fraction& frac) {
    *this = *this + frac;
    return *this;
}


bool operator==(const Fraction& left, const Fraction& right){
    return (left.numerator() == right.numerator() and left.denominator() == right.denominator());
}
bool operator!=(const Fraction& left, const Fraction& right){
    return (not (left.numerator() == right.numerator() and left.denominator() == right.denominator()));
}



bool operator<(const Fraction& left, const Fraction& right) {
    return left.numerator() * right.denominator() < right.numerator() * left.denominator();
}


bool operator<=(const Fraction& left, const Fraction& right) {
    return left < right || (left.numerator() == right.numerator() && left.denominator() == right.denominator());
}


bool operator>(const Fraction& left, const Fraction& right) {
    return right < left;
}


bool operator>=(const Fraction& left, const Fraction& right) {
    return right <= left;
}
