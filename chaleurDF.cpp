#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>

int main(){

//initialisation

double h; double dt; int Nmax; int Tmax; double a ; double b; 
FILE *f;

a=0.0; b=3.0; dt=0.0001; Nmax=100; Tmax=1000;

double u[Nmax+1][Tmax+1]; double x[Nmax+1];

h=(b-a)/Nmax;
std::cout << h ;

for (int i=0; i<=Nmax; i++){ 
x[i]=i*h;
}

if( dt/(h*h) > 0.5 ) { 
    std::cout << "erreur sur la condition CFL";
    exit(0);
     }
// Calcul aux différents temps // 

for (int i=1; i<=Nmax; i++) { u[i][0]=x[i]*x[i]; } 
  
  for(int tn=0; tn<=Tmax; tn++){
      u[0][tn]=0;
      u[Nmax+1][tn]=0;
      for(int j=1; j<=Nmax ; j++){

        u[j][tn+1]=u[j][tn]+(dt/h/h)*(u[j+1][tn]-2*u[j][tn]+u[j-1][tn]);
      }       
   } 


// sauvegarde dans un fichier pour tracer avec gnuplot
f= fopen("chaleurdata.dat","w");
for (int i=0; i<=Nmax; i++){ 
fprintf(f,"%lf %lf \n", x[i], u[i][0] ); 
}
fclose(f);
getchar();
return(0);
}
