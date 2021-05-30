#METODO DE PUNTO FIJO
#Autor: Miguel Torres 

clc
clear
format long

function resultado = Fx(x)
   resultado=(2 ^ x-6* cos(x));
endfunction

function resultado = Gx(x)
   resultado=(log(2)* 2 ^ x + 6 * sin(x));
endfunction

display('METODO DE NEWTON RAPHSON');
i=1;
P0=-6.5;
tol=10^(-15);
    disp('IT                   P0                 P                 f(P)             error');
    do
      P = (P0-(Fx(P0)/Gx(P0)));
      funcionP= Fx(P);
      error=abs((P-P0)/P);
      display([i, P0, P, funcionP, error]);
      P0=P;
      i= i + 1;
    until error<tol
  display('Solucion en p= '); disp(P);
  display('Iteraciones= '); disp(i); 