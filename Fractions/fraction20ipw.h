//
//  fraction20ipw.h
//  Fractions
//
//  Created by Isaac W on 2025-10-03.
//
#ifndef FRACTION20IPW_H
#define FRACTION20IPW_H
#include <iostream>
#include <exception>
class FractionException : public std::exception {
public:
    const char* what() const noexcept override; // only declaration
};

class Fraction {
private:
    int _numerator;
    int _denominator;
    static int gcd(int a, int b);  
    void reduce();

    
public:
    // Constructors
    Fraction(int n = 0);
    Fraction(int n, int d);

    int numerator() const {return _numerator; }
    int denominator() const {return _denominator; }
    // increment operators
    Fraction& operator++();   // pre-increment (++f)
    Fraction operator++(int); // post-increment (f++)
    Fraction& operator+=(const Fraction& frac);
};

// non-member operator declarations
std::ostream& operator<<(std::ostream& out, const Fraction& frac);
std::istream& operator>>(std::istream& in, Fraction& frac);
Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& left, const Fraction& right);
Fraction operator*(const Fraction& left, const Fraction& right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& frac);
bool operator==(const Fraction& left, const Fraction& right);
bool operator!=(const Fraction& left, const Fraction& right);
bool operator<(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);
bool operator>(const Fraction& left, const Fraction& right);
bool operator>=(const Fraction& left, const Fraction& right);
#endif
