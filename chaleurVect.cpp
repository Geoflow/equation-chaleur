#define ARMA_DONT_USE_WRAPPER
#include <armadillo>
#include <stdio.hpp>
#include <stdlib.hpp>
#include <math.hpp>
#include <string.hpp>
#include <iostream>
using namespace std;
using namespace arma;
int main(){

//initialisation

double h; double dt; int Nmax; double a ; double b; 
FILE *f;

a=0.0; b=2.0; dt=0.0001; Nmax=1000; 



h=(b-a)/Nmax;
cout << h  << endl;

// condition CFL verification
//if( dt/(h*h) > 0.5){ 
  //  cout << "erreur sur la condition CFL";
    //exit(0);
     //}
     
// initialisation matrices
vec X(Nmax+1);
for (int i=0; i<=Nmax; i++){ 
X[i]=i*h;
}

mat A(Nmax+1, Nmax+1, fill::eye);
vec U(Nmax+1, fill:: zeros);

// initialisation second membre
vec B(Nmax+1);
for (int i=1; i<=Nmax+1; i++) { B[i]=X[i]*X[i]; }


// Construction matrice Laplacien // 
for (int i=1; i<Nmax; i++)
    { 
    A(i,i)=2;
    A(i,i-1)=-1;
    A(i,i+1)=-1;
    }
A(1,1)=2;
A(1,2)=-1;
A(Nmax,Nmax)=2;
A(Nmax,Nmax-1)=-1;
A=(1/h/h)*A;


// resolution syst lineaire //
U=solve(A,B);




// sauvegarde dans un fichier pour tracer avec gnuplot
f= fopen("chaleurarma.dat","w");
for (int i=1; i<=Nmax; i++){ 
fprintf(f,"%lf %lf \n", X[i], U[i] ); 
}
fclose(f);
getchar();
return(0);



}
 
