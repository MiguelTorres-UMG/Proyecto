#METODO DE MULLER
#Autor: Miguel Torres 

clc
clear
format long

#function resultado = Fx(x)
   #resultado=(x ^ 5 + 11 * x ^ 4 - 21 * x ^ 3 - 10 * x ^ 2 - 21 * x -5);
#endfunction
#function resultado = Fx(x)
   #resultado=(x ^ 4 + x ^ 3 + 3 * x ^ 2 + 2 * x  + 2);
#endfunction
#function resultado = Fx(x)
   #resultado=(x ^ 3 - 9 * x ^ 2 + 12);
#endfunction
function resultado = Fx(x)
   resultado=((1.2222222222222) * x ^ 3 - (5.5) * x - 2);
endfunction

display('METODO DE MULLER');

i=3;
P0=2;
P1=2.5;
P2=3;
tol=0.000000000000001;
IT=100;
salida=0;

h1=P1-P0;
h2=P2-P1;
s1=(Fx(P1)-Fx(P0))/h1;
s2=(Fx(P2)-Fx(P1))/h2;
d=(s2-s1)/(h2+h1);

disp('IT                          P                       f(P)                 E');
 
while (i<=IT) && salida==0
  
  b=s2+h2*d;
  D=sqrt(b ^ 2 - 4 * Fx(P2)*d);
  
  if(abs(b-D)<abs(b+D))
  E=b+D;
else
  E=b-D;
end;
h=- 2 * Fx(P2) / E;
P=P2+h;
FP= Fx(P); 
iteracion=[i, P, FP, h];
disp(iteracion);
if (abs(h))< tol
display('SOLUCION ENCONTRADA CON EXITO');
    disp('P= '); disp(P);
    disp('FP= '); disp(FP);
    disp('Error= '); disp(h);
    display('Iteraciones= '); disp(i);
    salida=1;
  else
  i= i + 1;
  P0=P1;
  P1=P2;
  P2=P;
  h1=P1-P0;
  h2=P2-P1;
  s1=(Fx(P1)-Fx(P0))/h1;
  s2=(Fx(P2)-Fx(P1))/h2;
  d=(s2-s1)/(h2+h1);
  end;
end;
if (salida==0)
  disp('El metodo fracaso...');
  end