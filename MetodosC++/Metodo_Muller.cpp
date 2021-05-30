#include "pch.h"
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<cstdlib>
#include<Windows.h>
#include<cmath>
#include<iomanip>

using namespace std;

/*double f(double x) {
	//La funcion matematica es f(x) = x^5+11x^4-21x^3-10x^2-21x-5
	return (pow(x,5)+11*pow(x,4)-21*pow(x,3)-10*pow(x,2)-21*x-5);
}*/
/*double f(double x) {
	//La funcion matematica es f(x) = x^4+x^3+3x^2+2x+2
	return (pow(x,4)+pow(x,3)+3*pow(x,2)+2*x+2);
}*/
/*double f(double x) {
	//La funcion matematica es f(x) = x^3-9x^2+12
	return (pow(x,3)-9*pow(x,2)+12);
}*/
double f(double x) {
	//La funcion matematica es f(x) = (11/9)x^3-(11/2)x-2
	return ((1.2222222222222)*pow(x, 3) - (5.5) * x -2);
}
void ejecutar_metodo() {
	double h1, h2, s1, s2, d, b, D, E, h, p, FP, P0, P1, P2, TOL;
	int IT = 3;
	TOL = 0.000000000000001;
	P0 = 2;
	P1 = 2.5;
	P2 = 3;
	printf("METODO DE MULLER");
	printf_s("\n");
	printf("IT  \t\t     P \t\t            F(P) \t\t      ERROR");
	printf_s("\n");
	h1 = P1 - P0;
	h2 = P2 - P1;
	s1 = (f(P1) - f(P0)) / h1;
	s2 = (f(P2) - f(P1)) / h2;
	d = (s2 - s1) / (h2 + h1);
	do {
		b = s2 + h2 * d;
		D = sqrt(pow(b, 2) - 4 * f(P2)*d);
		if (abs(b - D) < abs(b + D)) {
			E = b + D;
		}
		else {
			E = b - D;
		}
		h = -2 * f(P2) / E;
		p = P2 + h;
		FP = f(p);
		cout << fixed << setprecision(15) << "Iteracion: " << IT << "\t" << p << "\t" << FP << "\t" << h << endl;
		P0 = P1;
		P1 = P2;
		P2 = p;
		h1 = P1 - P0;
		h2 = P2 - P1;
		s1 = (f(P1) - f(P0)) / h1;
		s2 = (f(P2) - f(P1)) / h2;
		d = (s2 - s1) / (h2 + h1);
		IT++;
	} while (abs(h)>TOL & IT<100);
	printf("APROXIMACION ALCANZADA CON EXITO: \nITERACIONES %i", IT-1);
	cout << " En el punto P: " << p << " FP= " << FP << " ERROR: " << h << endl;
}


int main()
{
	ejecutar_metodo();
}