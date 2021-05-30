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
	//La funcion matematica es f(x) = x^3+x+16
	return (pow(2,x)-6*cos(x));
}*/
double f(double x) {
	//La funcion matematica es f(x) = e^-x-ln(x)
	return (exp(-x) - log(x));
}
void ejecutar_metodo() {
	double P0, P1, Q0, Q1, P, FP, E, TOL;
	int IT = 2;
	TOL = 0.0000000001;
	P0 = 1;
	P1 = 2;
	printf("METODO DE LA SECANTE");
	printf_s("\n");
	printf("IT  \t\t     P0  \t    P1 \t           Q0 \t\t     Q1 \t     P \t\t      FP \t ERROR");
	printf_s("\n");
	do {
		
		Q0 = f(P0);
		Q1 = f(P1);
		P = P1 - Q1*(P1 - P0) / (Q1 - Q0);
		FP = f(P);
		E = abs((P - P1) / P);
		cout << fixed << setprecision(12) << "Iteracion: " << IT << "\t" << P0 << "\t" << P1 << "\t" <<Q0 << "\t" <<Q1 << "\t" <<P << "\t" <<FP << "\t" <<E<<endl ;
			P0 = P1; 
			Q0 = Q1;
			P1 = P;
			Q1 = FP;
			IT++;
		} while (E>TOL &(IT < 100));
		printf("APROXIMACION ALCANZADA CON EXITO: \nITERACIONES %i", IT-1);
		cout << " En el punto P: " << P << " FP= " << FP << " ERROR: " << E << endl;
}

int main()
{
	ejecutar_metodo();
}

