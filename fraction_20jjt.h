//John Turnbull
#include <iostream>

using namespace std;

class FractionException{
    //Throws exception if user enters a 0 for the denominator
    public:
        FractionException(const string&);
        //Constructor for the exception

        string what() const; 
        //Returns error message

    private:
        string msg;
        //Attribute error message

};

class Fraction{
    //Computes Fraction of Form (#/#)
    public:
        Fraction();
        //Constructor Case 1: Numerator is 0, Denominator is 1

        Fraction(int n);
        //Constructor Case 2: Numerator Denominator is 1

        Fraction(int n, int d);
        //Constructor Case 3: Normal Fraction

        int numerator() const;
        //Accessor for Numerator

        int denominator() const;
        //Accessor for Denominator

        Fraction& operator++();
        //Pre-Increment Unary Operator		
        
        Fraction operator++(int unused);
        //Post-Increment Unary Operator	

        Fraction& operator+=(const Fraction& frac);
        //Adds fraction to the current fraction value
        //Unary Operator	

        int compare(const Fraction& frac) const;
        //Compares the fraction inputted to the current fraction
        //Returns negative if less than, zero if equal, positive if greater than

    private:
        int gcd(int n, int d);
        //Returns the greatest common divisor of two numbers

        void simplify();
        //Simplifies the fraction by reducing it to it's lowest common denominator form
        //Simplifies the negative signs to normal fraction form

        int num;
        //Attribute for the numerator

        int den;
        //Attribute for the denominator

};

//Non-member overloaded arithmetic/boolean binary operators
Fraction operator+(const Fraction& num1, const Fraction& num2);
Fraction operator-(const Fraction& num1, const Fraction& num2);
Fraction operator*(const Fraction& num1, const Fraction& num2);
Fraction operator/(const Fraction& num1, const Fraction& num2);
Fraction operator-(const Fraction& value);
bool operator<(const Fraction& num1, const Fraction& num2);
bool operator<=(const Fraction& num1, const Fraction& num2);
bool operator==(const Fraction& num1, const Fraction& num2);
bool operator!=(const Fraction& num1, const Fraction& num2);
bool operator>=(const Fraction& num1, const Fraction& num2);
bool operator>(const Fraction& num1, const Fraction& num2);

//Non-member stream operators
ostream& operator<<(ostream& out, const Fraction& value);
istream& operator>>(istream& in, Fraction& retFrac);