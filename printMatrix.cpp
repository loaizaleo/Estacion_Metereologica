//To compile use g++ source.cpp -o nombre
//To Run use ./nombre
//Codigo para obtener datos manuales en un array e 
//imprimir en una  matriz cuadrada en un archivo de texto.
//Modificad por Leonardo Loaiza 15 de febrero del 2023
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
int data[1000][1000],M,i,j;
FILE * (file);

cout<<"Input size of matrix (mxm) : ";
cin>>M;

for (i=0;i<M;i++)
{
	for (j=0;j<M;j++)
	{
		cout<<"data ["<<i+1<<"]["<<j+1<<"] : ";
		cin>>data[i][j];
	}
}
file=fopen("inputmatriz.txt","w");
for (i=0;i<M;i++)
{
	for (j=0;j<M;j++)
	{
		fprintf (file, "%d ",data[i][j]);
	}
	fprintf (file,"\n");
}
fclose (file);
return 0;
}
