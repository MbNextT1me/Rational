#include "rational.h"
#include <locale.h>

int main(void)
{
   setlocale(LC_ALL, "Russian");

   Rational e(7, 8), f(5, 12);
   cout << "����:" << endl;
   cout << "e = " << e << "\nf = " << f << "\n\n�����: e + f" << endl;
   cout << "\n������� ��������� g = m/n � �������: (m n) ";
   Rational g;
   cin >> g;
   if (e + f != g)
	   cout << "\n�����������! e + f = " << e + f << endl;
   else
	   cout << "\n���������!" << endl;

   return 0;
}