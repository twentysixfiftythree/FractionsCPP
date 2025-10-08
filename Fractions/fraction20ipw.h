//
//  fraction20ipw.h
//  Fractions
//
//  A Fraction class that stores and manipulates fractions in normalized form.
//  Supports arithmetic operations, comparisons, and I/O.
//  Created by Isaac Wood on 2025-10-03.
//

#include <iostream>
#include <exception>

// throws exception if the denominator is 0 -> divide by 0
// also is thrown when an invalid fraction is passed in
class FractionException : public std::exception {
public:
    const char* what() const noexcept override;
};
// Fraction class with overloaded member operators
class Fraction {
private:
    // can't use numerator as a private variable, since numerator() is a class function
    int _numerator;
    int _denominator;
    // should not be called outside of the class
    static int gcd(int a, int b);
    void reduce();

    
public:
    // constructors
    Fraction(int n = 0);
    Fraction(int n, int d);
    // getter functions
    int numerator() const {return _numerator; }
    int denominator() const {return _denominator; }
    // increment operators
    Fraction& operator++();   // pre-increment (++f)
    Fraction operator++(int); // post-increment (f++)
    Fraction& operator+=(const Fraction& frac);
};
// -----
// member operator declarations
// -----
std::ostream& operator<<(std::ostream& out, const Fraction& frac);
std::istream& operator>>(std::istream& in, Fraction& frac);
// -----
// non-member operator declarations
// -----

// note: all of these operators implicitly convert ints to fractions using the Fraction(int n) constructor, if needed
Fraction operator+(const Fraction& left, const Fraction& right);


Fraction operator-(const Fraction& left, const Fraction& right);
Fraction operator*(const Fraction& left, const Fraction& right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& frac);
//equality
bool operator==(const Fraction& left, const Fraction& right);

//inequality
bool operator!=(const Fraction& left, const Fraction& right);
bool operator<(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);
bool operator>(const Fraction& left, const Fraction& right);
bool operator>=(const Fraction& left, const Fraction& right);

