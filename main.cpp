#include "rational.h"
#include <locale.h>

int main(void)
{
   setlocale(LC_ALL, "Russian");

   Rational e(7, 8), f(5, 12);
   cout << "Дано:" << endl;
   cout << "e = " << e << "\nf = " << f << "\n\nНайти: e + f" << endl;
   cout << "\nВведите результат g = m/n в формате: (m n) ";
   Rational g;
   cin >> g;
   if (e + f != g)
	   cout << "\nНеправильно! e + f = " << e + f << endl;
   else
	   cout << "\nПравильно!" << endl;

   return 0;
}