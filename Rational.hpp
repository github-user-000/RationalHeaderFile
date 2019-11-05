
#ifndef RATIONAL_H_4_11_2019_16_35
#define RATIONAL_H_4_11_2019_16_35

#include <iostream>

// helping function
// greatest common factor
long long gcd(long long a, long long b)
{
        long long product = 1;
        for(int i = 2; i < (a < b ? b : a);)
        {
                if(a % i == 0 && b % i == 0)  // find all the terms divisible both the terms
                {
                        product *= i;
                        a /= i;
                        b /= i;
                }
                else i++;
        }
        product *= a * b; // multiply both the remaining terms
        return product;
}

// class signifying in terms of integral Fraction i.e. numerator / denominator
class Rational
{
public:
        class Invalid {}; // for error types

        // default : deine to zero
        Rational()
        {
                n = 0;
                d = 1;
        }
        // taking an integer
        Rational(long long n_)
        {
                n = n_;
                d = 1;
        }
        Rational(long long n_, long long d_)
        {
                n = n_;
                d = d_;
                if(d == 0) // denominator cannot be zero
                        throw Invalid();
                if(d < 0)
                {
                        n *= -1;
                        d *= -1;
                }
        }
        Raional(const Rational& r)
        {
                n = r.numerator();
                d = r.denominator();
        }

        // returns both the prvate character
        long long numerator() const { return n; }
        long long denominator() const { return d; }

        Rational simplified();  // get the simplified version of the Rational fraction
        double to_decimal();     // get the decimal version

        Rational operator+=(const Rational& left);
        Rational operator-=(const Rational& left);
        Rational operator*=(const Rational& left);
        Rational operator/=(const Rational& left);
        Rational operator++();
        Rational operator--();


private:
        long long n; // numerator
        long long d; // denominator
};

// output
// syntax: "(" numerator "/" denominator ")"
std::ostream& operator<<(std::ostream& os, const Rational& r);
// output
// syntax: numerator "/" denominator
std::istream& operator>>(std::istream& is, Rational& r);

// arithmetic operator
Rational operator+(Rational r1, const Rational& r2);
Rational operator-(Rational r1, const Rational& r2);
Rational operator/(Rational r1, const Rational& r2);
Rational operator*(Rational r1, const Rational& r2);

// conditional operator
bool operator==(const Rational& r1, const Rational& r2);
bool operator!=(const Rational& r1, const Rational& r2);
bool operator>(const Rational& r1, const Rational& r2);
bool operator<(const Rational& r1, const Rational& r2);
bool operator>=(const Rational& r1, const Rational& r2);
bool operator<=(const Rational& r1, const Rational& r2);

// =======================definations===========================

std::ostream& operator<<(std::ostream& os, const Rational& r)
{
        return os << "(" << r.numerator() << "/" << r.denominator() << ")";
}

std::istream& operator>>(std::istream& is, Rational& r)
{
        long long n, d;
        char ch;
        is >> n >> ch >> d;  // long long '/' long long

        if(!is)
                return is;
        if(ch != '/')
                return is;

        r = Rational(n, d);

}

// arithmetic operator
Rational operator+(Rational r1, const Rational& r2)
{
        return r1 += r2;
}

Rational operator-(Rational r1, const Rational& r2)
{
        return r1 -= r2;
}

Rational operator/(Rational r1, const Rational& r2)
{
        return r1 /= r2;
}

Rational operator*(Rational r1, const Rational& r2)
{
        return r1 *= r2;
}

// conditional operators
bool operator==(const Rational& r1, const Rational& r2)
{
        return (r1.numerator() * r2.denominator()) == (r1.denominator() * r2.numerator());
}

bool operator!=(const Rational& r1, const Rational& r2)
{
        return !(r1 == r2);
}

bool operator>(const Rational& r1, const Rational& r2)
{
        return (r1.numerator() * 1.0/r1.denominator()) > (r2.numerator() * 1.0/ r2.denominator());
}

bool operator<(const Rational& r1, const Rational& r2)
{
        return (r1 != r2 && !(r1 > r2));
}

bool operator>=(const Rational& r1, const Rational& r2)
{
        return r1 > r2 && r1 == r2;
}

bool operator<=(const Rational& r1, const Rational& r2)
{
        return r1 < r2 && r1 == r2;
}


// member functions

Rational Rational::simplified()
{
        long long temp_n = n, temp_d = d;
        for(long long i = 2; i <= (abs(temp_n) < abs(temp_d) ? abs(temp_n) : abs(temp_d)); )
        {
                // getting the LCM and dividing the original values
                if(temp_n % i == 0 && temp_d % i == 0)
                {
                        temp_n /= i;
                        temp_d /= i;
                }
                else i++;
        }
        return Rational(temp_n, temp_d);
}

// returning double
double Rational::to_decimal()
{
        return double(n) / double(d);
}

// look any maths book
Rational Rational::operator+=(const Rational& left)
{
        long long deno = gcd(d, left.denominator());
        n = n * (deno / d) + left.numerator() * (deno / left.denominator());
        d = deno;
        return *this;
}

//...
Rational Rational::operator-=(const Rational& left)
{
        long long deno = gcd(d, left.denominator());
        n = n * (deno / d) - left.numerator() * (deno / left.denominator());
        d = deno;
        return *this;
}

//...
Rational Rational::operator*=(const Rational& left)
{
        long long temp_n = n * left.numerator();
        long long temp_d = d * left.denominator();
        Rational temp = Rational(temp_n, temp_d).simplified();
        n = temp.numerator();
        d = temp.denominator();
        return temp;
}

// here the left gets inverted
Rational Rational::operator/=(const Rational& left)
{
        long long temp_n = n * left.denominator();
        long long temp_d = d * left.numerator();
        Rational temp = Rational(temp_n, temp_d).simplified();
        n = temp.numerator();
        d = temp.denominator();
        return temp;
}

//...
Rational Rational::operator++()
{
        return (*this) += 1;
}

//...
Rational Rational::operator--()
{
        return (*this) -= 1;
}

#endif
