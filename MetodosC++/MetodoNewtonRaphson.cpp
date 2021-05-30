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
	//La funcion matematica es f(x) = -x^3 - cos(x)
	return (pow(-x,3)-cos (x));
}*/

/*double dx(double x) {
	//derivada de la funcion f'(x) =-3x^2 + sin (x)
	return (-3*pow(x,2)+sin(x));
}*/

/*double f(double x) {
	//La funcion matematica es f(x) = x^2 - 5x + 4
	return (pow(x,2)- 5 *(x)+4);
}

double dx(double x) {
	//derivada de la funcion f'(x) = 2x - 5
	return (2*(x)-5);
}*/
double f(double x) {
	//La funcion matematica es f(x) = x^2 + x - 1
	return (pow(x,2)+x-1);
}

double dx(double x) {
	//derivada de la funcion f'(x) = 2x + 1
	return (2*(x)+1);
}

void ejecutar_metodo() {
	double P0, P, funcion_p, error, tol;
	int IT = 0;
	tol = 0.00001;
	P0 = -1;
	printf("Metodo de Newton Raphson");
	printf_s("\n");
	printf("IT  \t\t     P0  \t    P \t              F(P) \t    E\n");
	do {
		IT++;
		P = (P0 - (f(P0) / dx(P0)));
		funcion_p = f(P);
		error = abs((P - P0) / P);
		cout <<fixed<<setprecision(10)<<"Iteracion: "<<IT << "\t" << P0 << "\t" << P << "\t" << funcion_p << "\t" <<error << endl;
		P0 = P;
	} while ((error > tol) & (IT<100));
	printf("APROXIMACION ALCANZADA CON EXITO: \nITERACIONES %i", IT );
	cout << " En el punto P0: " << P0 << " P= " << P << " F(P): " << funcion_p << " E: " << error << endl;

}

int main()
{
	ejecutar_metodo();
}