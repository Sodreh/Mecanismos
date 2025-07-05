#include <math.h>
#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
#define N 4

/*Parâmetros do Iniciais do Problema*/

/*Parâmetros do Came*/
float b = 0.25;
float c = 0;
float d = 0.75;
float Ca = 5.5280;
float pi = M_PI;

/*Parâmetros do Comportamento*/

/*Estágios*/
float a0 = 0.0;
float a1 = 60.0;
float a2 = 90.0;
float a3 = 120.0;
float a4 = 210.0;
float a5 = 230.0;
float a6 = 250.0;
float a7 = 270.0;
float a8 = 300.0;
float a9 = 330.0;
float a10 = 360.0;

/*Alturas*/
float h0 = 0.0;
float h1 = 40.0;
float h2 = 50.0;
float h3 = 30.0;

/* Parâmetros adicionais */
float beta = 0.0;
float theta_p, theta;
float w = 2*pi/5;


/* Came [Polinomial] */
void zona(float theta, float z[])
{
	if(theta>=a0 && theta<a1)    /* Subida  h0 = 0 mm até h1 = 40 mm (a0 = 0° - a1 = 60°) */
	{
		beta = (a1-a0)*(2*pi/w)/360;
		theta_p = (theta-a0)*(2*pi/w)/360;
		z[0] = (h0) + (h1-h0)*(35*pow((theta_p/beta),4) - 84*pow((theta_p/beta),5) + 70*pow((theta_p/beta),6) - 20*pow((theta_p/beta),7));
		z[1] = (h1-h0)*(1/beta)*(140*pow((theta_p/beta),3) - 420*pow((theta_p/beta),4) + 420*pow((theta_p/beta),5) - 140*pow((theta_p/beta),6));
		z[2] = (h1-h0)*pow((1/beta),2)*(420*pow((theta_p/beta),2) - 1680*pow((theta_p/beta),3) + 2100*pow((theta_p/beta),4) - 840*pow((theta_p/beta),5));
		z[3] = (h1-h0)*pow((1/beta),3)*(840*pow((theta_p/beta),1) - 5040*pow((theta_p/beta),2) + 8400*pow((theta_p/beta),3) - 4200*pow((theta_p/beta),4));
	}	
	if(theta>=a1 && theta<a2)    /* Espera  h1 = 40 mm (a1 = 60° - a2 = 90°) */
	{
		z[0] = h1;
		z[1] = 0.0;
		z[2] = 0.0;
		z[3] = 0.0;
	}
	if(theta>=a2 && theta<a3)    /* Descida h1 = 40 mm até h0 = 0 mm (a2 = 90° - a3 = 120°) */
	{
		beta = (a3-a2)*(2*pi/w)/360;
		theta_p = (theta-a2)*(2*pi/w)/360;
		z[0] = (h1) + (10*(h0-h1))*pow((theta_p/beta),3) + (-15*(h0-h1))*pow((theta_p/beta),4) + (6*(h0-h1))*pow((theta_p/beta),5);
		z[1] = (1/beta)*((10*(h0-h1)*3)*pow((theta_p/beta),2) + (-15*(h0-h1)*4)*pow((theta_p/beta),3) + (6*(h0-h1)*5)*pow((theta_p/beta),4));
		z[2] = pow((1/beta),2)*((10*(h0-h1)*3*2)*pow((theta_p/beta),1) + (-15*(h0-h1)*4*3)*pow((theta_p/beta),2) + (6*(h0-h1)*5*4)*pow((theta_p/beta),3));
		z[3] = pow((1/beta),3)*((10*(h0-h1)*3*2) + (-15*(h0-h1)*4*3*2)*pow((theta_p/beta),1) + (6*(h0-h1)*5*4*3)*pow((theta_p/beta),2));
	}
	if(theta>=a3 && theta<a4)    /* Espera  h0 = 0. mm (a3 = 120° - a4 = 210°) */
	{
		z[0] = 0.0;
		z[1] = 0.0;
		z[2] = 0.0;
		z[3] = 0.0;
	}	
	if(theta>=a4 && theta<a5)    /* Subida  h0 = 0. mm até h2 = 50 mm (a4 = 210° - a5 = 230°) */
	{
		beta = (a5-a4)*(2*pi/w)/360;
		theta_p = (theta-a4)*(2*pi/w)/360;
		z[0] = (h0) + (10*(h2-h0))*pow((theta_p/beta),3) + (-15*(h2-h0))*pow((theta_p/beta),4) + (6*(h2-h0))*pow((theta_p/beta),5);
		z[1] = (1/beta)*((10*(h2-h0)*3)*pow((theta_p/beta),2) + (-15*(h2-h0)*4)*pow((theta_p/beta),3) + (6*(h2-h0)*5)*pow((theta_p/beta),4));
		z[2] = pow((1/beta),2)*((10*(h2-h0)*3*2)*pow((theta_p/beta),1) + (-15*(h2-h0)*4*3)*pow((theta_p/beta),2) + (6*(h2-h0)*5*4)*pow((theta_p/beta),3));
		z[3] = pow((1/beta),3)*((10*(h2-h0)*3*2) + (-15*(h2-h0)*4*3*2)*pow((theta_p/beta),1) + (6*(h2-h0)*5*4*3)*pow((theta_p/beta),2));
	}
	if(theta>=a5 && theta<a6)    /* Espera  h2 = 50 mm (a5 = 230° - a6 = 250°) */
	{
		z[0] = h2;
		z[1] = 0.0;
		z[2] = 0.0;
		z[3] = 0.0;
	}
	if(theta>=a6 && theta<a7)    /* Descida h2 = 50 mm até h3 = 30 mm (a6 = 250° - a7 = 270°) */
	{
		beta = (a7-a6)*(2*pi/w)/360;
		theta_p = (theta-a6)*(2*pi/w)/360;
		z[0] = (h2) + (10*(h3-h2))*pow((theta_p/beta),3) + (-15*(h3-h2))*pow((theta_p/beta),4) + (6*(h3-h2))*pow((theta_p/beta),5);
		z[1] = (1/beta)*((10*(h3-h2)*3)*pow((theta_p/beta),2) + (-15*(h3-h2)*4)*pow((theta_p/beta),3) + (6*(h3-h2)*5)*pow((theta_p/beta),4));
		z[2] = pow((1/beta),2)*((10*(h3-h2)*3*2)*pow((theta_p/beta),1) + (-15*(h3-h2)*4*3)*pow((theta_p/beta),2) + (6*(h3-h2)*5*4)*pow((theta_p/beta),3));
		z[3] = pow((1/beta),3)*((10*(h3-h2)*3*2) + (-15*(h3-h2)*4*3*2)*pow((theta_p/beta),1) + (6*(h3-h2)*5*4*3)*pow((theta_p/beta),2));
	}
	if(theta>=a7 && theta<a8)    /* Espera  h3 = 30 mm (a7 = 270° - a8 = 300°) */
	{
		z[0] = h3;
		z[1] = 0.0;
		z[2] = 0.0;
		z[3] = 0.0;
	}
	if(theta>=a8 && theta<a9)    /* Descida h3 = 30 mm até h0 = 0 mm (a8 = 300° - a9 = 330°) */
	{
		beta = (a9-a8)*(2*pi/w)/360;
		theta_p = (theta-a8)*(2*pi/w)/360;
		z[0] = (h3) + (10*(h0-h3))*pow((theta_p/beta),3) + (-15*(h0-h3))*pow((theta_p/beta),4) + (6*(h0-h3))*pow((theta_p/beta),5);
		z[1] = (1/beta)*((10*(h0-h3)*3)*pow((theta_p/beta),2) + (-15*(h0-h3)*4)*pow((theta_p/beta),3) + (6*(h0-h3)*5)*pow((theta_p/beta),4));
		z[2] = pow((1/beta),2)*((10*(h0-h3)*3*2)*pow((theta_p/beta),1) + (-15*(h0-h3)*4*3)*pow((theta_p/beta),2) + (6*(h0-h3)*5*4)*pow((theta_p/beta),3));
		z[3] = pow((1/beta),3)*((10*(h0-h3)*3*2) + (-15*(h0-h3)*4*3*2)*pow((theta_p/beta),1) + (6*(h0-h3)*5*4*3)*pow((theta_p/beta),2));
	}
	if(theta>=a9 && theta<=a10)  /* Espera  h0 = 0. mm (a9 = 330° - a10 = 360°) */
	{
		z[0] = h0;
		z[1] = 0.0;
		z[2] = 0.0;
		z[3] = 0.0;
	}
}

int main ()
{
	FILE *output;
	output = fopen("Saida_Polinomial.txt","w");
	float esp, vel, acel, pulso, theta, theta_p;
	
	float z[N] = {0.0, 0.0, 0.0, 0.0};

	for(int i=0;i<=360;i++)
	{
		zona(theta,z);
		esp = z[0];
		vel = z[1];
		acel = z[2];
		pulso = z[3];
		fprintf(output, "%d\t %g\t %g\t %g\t %g\n",i,esp,vel,acel,pulso);
		theta++;	
	}
}		
return 0


