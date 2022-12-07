//John Turnbull
#include <iostream>
#include "fraction_20jjt.h"

using namespace std;

FractionException :: FractionException(const string& m) : msg(m) {} //error somehow
string FractionException :: what() const { 
    return msg; 
}

Fraction :: Fraction() : num(0), den(1) {}

Fraction :: Fraction(int n) : num(n), den(1) {}

Fraction :: Fraction(int n, int d) : num(n), den(d) {
    if(den == 0){
        throw FractionException("Denominators can't be zero you silly goose!");
    }
    else
        simplify();
}

int Fraction :: numerator() const {
    return num;
}

int Fraction :: denominator() const {
    return den;
}

Fraction& Fraction :: operator++() {
    num += den;
    return *this;
}

Fraction Fraction :: operator++(int unused) {
    Fraction clone(num, den);
    num += den;
    return clone;
}

Fraction& Fraction :: operator+=(const Fraction& frac) {
    num = num * frac.denominator() + den * frac.numerator();
    den = den * frac.denominator();
    simplify();
    return *this;
}

int Fraction :: compare(const Fraction& frac) const {
    int result;
    result = num * frac.denominator() - den * frac.numerator();
    return result;
}

int Fraction :: gcd(int n, int d) {
    if(d <= n && n % d == 0)
        return d;
    else if(n < d)
        return gcd(d, n);
    else 
        return gcd(d, n % d);
}

void Fraction :: simplify(){
    int sign;
    int div;
    if(num < 0 && den > 0){
        num = num * -1;
        sign = -1;
    }
    else if(num > 0 && den < 0){
        den = den * -1;
        sign = -1;
    }
    else if(num < 0 && den < 0){
        num = num * -1;
        den = den * -1;
        sign = 1;
    }
    else 
        sign = 1;
    
    div = gcd(num, den);
    num = sign * (num / div);
    den = (den / div);
}

Fraction operator+(const Fraction& num1, const Fraction& num2) {
    Fraction result(num1.numerator() * num2.denominator() + num2.numerator() * num1.denominator(), num1.denominator() * num2.denominator());
    return result;
}

Fraction operator-(const Fraction& num1, const Fraction& num2) {
    Fraction result(num1.numerator() * num2.denominator() - num2.numerator() * num1.denominator(), num1.denominator() * num2.denominator());
    return result;
}

Fraction operator*(const Fraction& num1, const Fraction& num2) {
    Fraction result(num1.numerator() * num2.numerator(), num1.denominator() * num2.denominator());
    return result;
}

Fraction operator/(const Fraction& num1, const Fraction& num2) {
    Fraction result(num1.numerator() * num2.denominator(), num1.denominator() * num2.numerator());
    return result;
}

Fraction operator-(const Fraction& value) {
    Fraction result(-value.numerator(), value.denominator());
    return result;
}

bool operator<(const Fraction& num1, const Fraction& num2) {
    return num1.compare(num2) < 0;
}

bool operator<=(const Fraction& num1, const Fraction& num2) {
    return num1.compare(num2) <= 0;
}

bool operator==(const Fraction& num1, const Fraction& num2) {
    return num1.compare(num2) == 0;
}

bool operator!=(const Fraction& num1, const Fraction& num2) {
    return num1.compare(num2) != 0;
}

bool operator>=(const Fraction& num1, const Fraction& num2) {
    return num1.compare(num2) >= 0;
}

bool operator>(const Fraction& num1, const Fraction& num2) {
    return num1.compare(num2) > 0;
}

ostream& operator<<(ostream& out, const Fraction& value) {
    out << value.numerator() << "/" << value.denominator();
    return out;
}

istream& operator>>(istream& in, Fraction& retFrac) {
    int num, den;
    in >> num;
    if (in.peek() != 10){
	    char nextChar;
	    in >> nextChar;
	    if (nextChar == '/')
            in >> den;
	    else
		    den = 1;
	    retFrac = Fraction(num, den);
    }
    else
	    retFrac = Fraction(num);
    return in;
}