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
    int result_num = right.numerator() - left.numerator();
    return Fraction(result_num, common_denom);
}



