#include "CHelmholtzAgua.h"
CHelmholtzIsobutano::CHelmholtzIsobutano()
{
	tCritica=407.81;
	dCritica=225.5;
	rEspecifico=0.14305157;
	int a[5]={4,7,16,2,0};
	for(int i=0;i<5;i++)numeroCoeficientes[i]=a[i];
	double b[3]={11.60865546,-5.29450411,3.05956619};
	coeficientesIdeais1 = new double[3];
	for(int i=0;i<3;i++)coeficientesIdeais1[i]=b[i];
	double c[4][2]={
	{4.94641014,0.9512779015},
	{4.09475197,2.3878958853},
	{15.6632824,4.3469042691},
	{9.73918122,10.3688586351}};
	coeficientesIdeais2=Aloca(numeroCoeficientes[0],2);
	for(int i=0;i<numeroCoeficientes[0];i++){
		for(int j=0;j<2;j++)coeficientesIdeais2[i][j]=c[i][j];
	}
	double d[7][3]={
	{1,0.5,0.20686820727966E1},
	{1,1,-0.36400098615204E1},
	{1,1.5,0.51968754427244},
	{2,0,0.17745845870123},
	{3,0.5,-0.12361807851599},
	{4,0.5,0.45145314010528E-1},
	{4,0.75,0.30476479965980E-1}};
	coeficientesPolinomio=Aloca(numeroCoeficientes[1],3);
	for(int i=0;i<numeroCoeficientes[1];i++){
		for(int j=0;j<3;j++)coeficientesPolinomio[i][j]=d[i][j];
	}
	double e[16][4]={
	{1,1,2,0.75508387706302},
	{1,1,2.5,-0.85885381015629},
	{1,2,2.5,0.36324009830684E-1},
	{1,7,1.5,-0.19548799450550E-1},
	{1,8,1,-0.44452392904960E-2},
	{1,8,1.5,0.46410763666460E-2},
	{2,1,4,-0.71444097992825E-1},
	{2,2,7,-0.80765060030713E-1},
	{2,3,3,0.15560460945053},
	{2,3,7,0.20318752160332E-2},
	{2,4,3,-0.10624883571689},
	{2,5,1,0.39807690546305E-1},
	{2,5,6,0.16371431292386E-1},
	{2,10,0,0.53212200682628E-3},
	{3,2,6,-0.78681561156387E-2},
	{3,6,13,-0.30981191888963E-2}};
	coeficientesExponenciais=Aloca(numeroCoeficientes[2],4);
	for(int i=0;i<numeroCoeficientes[2];i++){
		for(int j=0;j<4;j++)coeficientesExponenciais[i][j]=e[i][j];
	}
	double f[2][7]={
		{1,2,-0.42276036810382E-1,10,150,1.16,0.85},
		{2,0,-0.53001044558079E-2,10,200,1.13,1}};
	coeficientesGaussianos=Aloca(numeroCoeficientes[3],7);
	for(int i=0;i<numeroCoeficientes[3];i++){
		for(int j=0;j<7;j++)coeficientesGaussianos[i][j]=f[i][j];
	}
	fIdeal=0;
	fIdeal_t=0;
	fIdeal_tt=0;
	fIdeal_ttt=0;
	fResidual=0;
	fResidual_t=0;
	fResidual_d=0;
	fResidual_dd=0;
	fResidual_dt=0;
	fResidual_tt=0;
	fResidual_ddd=0;
	fResidual_ddt=0;
	fResidual_dtt=0;
	fResidual_ttt=0;
}
