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
    
    
    static int gcd(int a, int b) {
        // Euclidean algorithm
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    void reduce() {
        int g = gcd(abs(_numerator), _denominator);
        _numerator /= g;
        _denominator /= g;
    }
    
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
        else if (d<0 and n >= 0){
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
        reduce();
        
    };
    int numerator() const {return _numerator; }
    int denominator() const {return _denominator; }
    // increment operators
    Fraction& operator++();   // pre-increment (++f)
    Fraction operator++(int); // post-increment (f++)
    Fraction& operator+=(const Fraction& frac);
};

std::ostream& operator<<(std::ostream& out, const Fraction& frac);
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
