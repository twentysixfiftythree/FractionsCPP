//
//  fraction_20ipw.cpp
//  Fractions
//
//  Created by Isaac W on 2025-10-03.
//
#include <iostream>
#include "fraction20ipw.h"



std::ostream& operator<<(std::ostream& out, const Fraction& frac) {
    out << frac.numerator()<< '/' << frac.denominator();
    return out;
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


//Fraction operator-(const Fraction& left, const int& num) {
//    Fraction num_frac = Fraction(num);
//    return left-num_frac;
//}

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
