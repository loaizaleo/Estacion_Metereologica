#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <cassert>
#include <fstream>

using namespace std;
int main(int argc, char* argv[]){
double pi=4*atan(1);
double rad=pi/180;
double grad=180./pi;

//Definicion de condiciones iniciales
double tetha_ini=8.*rad;
double omega_ini=0.;
double g=9.8;//Gravedad Terrestre metros/seg^2
int l=1;//Longitud de la cuerda en metros
double cte = g/l;
double step=0.05;//Magnitud del paso
int N=300;//Cantidad de iteraciones

//Variables angulares
double tetha[N];//Angulo
double omega[N];//Velocidad Angular
double tetha_final=0;//Valor de tetha n+1
double tetha_final_mejor=0;
double omega_final=0;//Valor de omega n+1
double omega_final_mejor=0;
//Generacion de archivo de datos
std::ofstream write_output ("pendulo_mejor.dat");
assert(write_output.is_open());
//Bucle para las iteraciones
for (int i=0;i<N;i++){

omega_final = omega_ini - step*cte*sin(tetha_ini);
tetha_final_mejor = tetha_ini + step*0.5*(omega_ini+omega_final);

tetha_final = tetha_ini + step*omega_ini;
omega_final_mejor = omega_ini - step*0.5*cte*( sin(tetha_ini) + sin(tetha_final) );

omega_ini = omega_final_mejor;
tetha_ini = tetha_final_mejor;

tetha[i]=tetha_ini;
omega[i]=omega_ini;

write_output<<step*i<<"\t"<<grad*tetha[i]<<"\t"<<omega[i]<<"\n";
}//End bucle for
write_output.close();

}//End main
