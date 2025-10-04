//
//  fraction20ipw.h
//  Fractions
//
//  Created by Isaac W on 2025-10-03.
//

class FractionException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Fraction with 0 denominator";
    }
};

class Fraction {
private:
    int _numerator;
    int _denominator;
public:
    Fraction(int n = 0){
        _numerator = n;
        _denominator = 1;
    }
    Fraction(int n, int d){
        if (d<0 and n < 0) {
            _numerator = abs(n);
            _denominator = abs(d);
        }
        else if (d<0 and n > 0){
            _numerator = -1*n;
            _denominator = abs(d);
        }
        else if (d == 0){
            throw FractionException();
        }
        else {
            _numerator = n;
            _denominator = d;
        }
        
    };
    int numerator() const {return _numerator; }
    int denominator() const {return _denominator; }
};

std::ostream& operator<<(std::ostream& out, const Fraction& frac);
Fraction operator+(const Fraction& left, const Fraction& right);
