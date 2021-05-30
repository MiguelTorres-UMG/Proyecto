#METODO DE LA SECANTE
#Autor: Miguel Torres 

clc
clear
format long


#function resultado = Fx(x)
   #resultado=(2 ^ x - 6 * cos (x));
#endfunction
function resultado = Fx(x)
   resultado=(exp(-x)-log(x));
endfunction
display('METODO DE DE LA SECANTE');
i=2;
P0=1;
P1=2;
tol=0.0000000001;
IT=100;
salida=0;

Q0 = Fx(P0);
Q1 = Fx(P1);

    disp('IT        P0         P1          Q1            Q0             P               f(P)             E');
    
    while (i<=IT) && salida==0
 
    P = P1 - Q1 * (P1 - P0) / (Q1 - Q0);
		FP = Fx(P);
		E = abs((P - P1) / P);
    
    display([i, P0, P1, Q0, Q1, P, FP, E]);
    
    if Fx(P)==0 || E<tol
    display('SOLUCION ENCONTRADA CON EXITO');
    disp('P= '); disp(P);
    disp('FP= '); disp(FP);
    disp('Error= '); disp(E);
    display('Iteraciones= '); disp(i);
    salida=1;
 else 
      i= i + 1;
      P0 = P1;
			Q0 = Q1;
			P1 = P;
			Q1 = FP;
      end
end
if (salida==0)
  disp('El metodo fracaso...');
  end