#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(){

int Nmax=100;
int i,it;
double x[Nmax+1];          // dimension des tableaux
double T[Nmax+1];
double Tn[Nmax+1];
double a=0;double b=1;
double dx=(b-a)/Nmax,dt=0.00001,t=0; // parametres
FILE *f;

printf(" Resolution de l’equation de la Chaleur 1D");
for (i=0; i<=Nmax; i++)
{  /*INITIALISATION*/
x[i] = a + i*dx;
T[i]=1;
Tn[i]=1;
}

// Calcul, avancee en temps
for(it=0;it<100000;it++)
{  t=t+dt;  // le temps augmente
T[0]=0;  // on force les conditions aux limites
T[Nmax]=0;
Tn[0]=0;
Tn[Nmax]=0;

for (i=1; i<Nmax; i++)
{ Tn[i]=T[i]+(dt/dx/dx)*(T[i+1]-2*T[i]+T[i-1]);
for (i=0; i<=Nmax; i++)
{T[i]=Tn[i];}
}  

//echange le nouveau devient lancien
printf("t=%lf\n",t);
// sauvegarde dans un fichier pour tracer avec gnuplot
f= fopen("resultat.dat","w");
for (i=0; i<=Nmax;i++)
{ fprintf(f,"%lf %lf \n",x[i], T[i]); }
fclose(f);
getchar();
}
return 1;}
