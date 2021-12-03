#include "rational.h"

Rational::Rational()
{
   numer=0;
   denom=1;
}

Rational::Rational(int number)
{
   numer=number;
   denom=1;
}

Rational::Rational(int n, int d)
{
   numer=n;
   denom=d;
   simplify();
}

Rational Rational::operator -() const
{
   Rational r(-numer, denom);
   return r;
}

Rational& Rational::operator +=(const Rational& r)
{
   numer = (numer*r.denom+denom*r.numer);
   denom *= r.denom;
   simplify();
   return *this;
}

Rational Rational::operator +(const Rational &r) const
{
   Rational res(*this);
   return res += r;
}

Rational& Rational::operator -=(const Rational& r)
{
   return (*this += (-r));
}

Rational Rational::operator -(const Rational &r) const
{
   Rational res(*this);
   return res -= r;
}

Rational& Rational::operator *=(const Rational& r)
{
   numer *= r.numer;
   denom *= r.denom;
   simplify();
   return *this;
}

Rational Rational::operator *(const Rational &r) const
{
   Rational res(*this);
   return res *= r;
}

Rational& Rational::operator /=(const Rational& r)
{
   numer *= r.denom;
   denom *= r.numer;
   simplify();
   return *this;
}

Rational Rational::operator /(const Rational &r) const
{
   Rational res(*this);
   return res /= r;
}

bool Rational::operator ==(const Rational& r) const
{
   return (numer==r.numer) && (denom==r.denom);
}

bool Rational::operator !=(const Rational& r) const
{
   return !(*this==r);
}

Rational Rational::operator ++(int)
{
   Rational r(*this);
   numer += denom;
   return r;
}

Rational& Rational::operator ++()
{
   numer += denom;
   return *this;
}

Rational::operator int() const
{
   return numer / denom;
}

Rational::operator double() const
{
   return ((double)numer)/denom;
}

void Rational::simplify(){
    long tnum, tden, temp, gcd;
    tnum = labs(numer);
    tden = labs(denom);
    if (tden == 0)
    {
        cout << "\nДелитель не может быть равен нулю!\n"; exit(1);
    }
    else if (tnum == 0)
    {
        numer = 0; denom = 1; return;
    }
    while (tnum != 0)
    {

        if (tnum < tden)
        {
            temp = tnum; tnum = tden; tden = temp;
        }

        tnum = tnum - tden;
    }
    gcd = tden;
    numer = numer / gcd;
    denom = denom / gcd;
}

istream& operator >>(istream& in, Rational& r)
{
   in>>r.numer>>r.denom;
   return in;
}

ostream& operator <<(ostream& out, const Rational& r)
{
   out<<r.numer<<"/"<<r.denom;
   return out;
}