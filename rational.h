#ifndef _RATIONAL_H
#define _RATIONAL_H

#include <iostream>
using namespace std;

class Rational
{
   int numer, denom;
   void simplify();

public:
   Rational();
   Rational(int number);
   Rational(int n, int d);

   Rational operator -() const;

   Rational operator +(const Rational& r) const;
   Rational& operator +=(const Rational& r);

   Rational operator -(const Rational& r) const;
   Rational& operator -=(const Rational& r);

   Rational operator *(const Rational& r) const;
   Rational& operator *=(const Rational& r);

   Rational operator /(const Rational& r) const;
   Rational& operator /=(const Rational& r);

   Rational operator ++(int);
   Rational& operator ++();

   bool operator ==(const Rational& r) const;
   bool operator !=(const Rational& r) const;

   operator int() const;
   operator double() const;

   friend istream& operator >>(istream& in, Rational& r);
   friend ostream& operator <<(ostream& out, const Rational& r);
};

#endif