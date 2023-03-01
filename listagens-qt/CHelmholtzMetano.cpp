#include "CHelmholtzAgua.h"
CHelmholtzMetano::CHelmholtzMetano()
{
	tCritica=190.564;
	dCritica=162.66;
	rEspecifico=0.5182705;
	int a[5]={5,13,23,4,0};
	for(int i=0;i<5;i++)numeroCoeficientes[i]=a[i];
	double b[3]={9.91243972,-6.33270087,3.0016};
	coeficientesIdeais1 = new double[3];
	for(int i=0;i<3;i++)coeficientesIdeais1[i]=b[i];
	double c[5][2]={
	{0.008449,3.40043240},
	{4.6942,10.26951575},
	{3.4865,20.43932747},
	{1.6572,29.93744884},
	{1.4115,79.13351945}};
	coeficientesIdeais2=Aloca(numeroCoeficientes[0],2);
	for(int i=0;i<5;i++){
		for(int j=0;j<2;j++)coeficientesIdeais2[i][j]=c[i][j];
	}
	double d[13][3]={
	{1,-0.5,0.4367901028E-1},
	{1,0.5,0.6709236199},
	{1,1,-0.1765577859E1},
	{2,0.5,0.8582330241},
	{2,1,-0.1206513052E1},
	{2,1.5,0.5120467220},
	{2,4.5,-0.4000010791E-3},
	{3,0,-0.1247842423E-1},
	{4,1,0.3100269701E-1},
	{4,3,0.1754748522E-2},
	{8,1,-0.3171921605E-5},
	{9,3,-0.2240346840E-5},
	{10,3,0.2947056156E-6}};
	coeficientesPolinomio=Aloca(numeroCoeficientes[1],3);
	for(int i=0;i<13;i++){
		for(int j=0;j<3;j++)coeficientesPolinomio[i][j]=d[i][j];
	}
	double e[23][4]={
	{1,1,0,0.1830487909},
	{1,1,1,0.1511883679},
	{1,1,2,-0.4289363877},
	{1,2,0,0.6894002446E-1},
	{1,4,0,-0.1408313996E-1},
	{1,5,2,-0.3063054830E-1},
	{1,6,2,-0.2969906708E-1},
	{2,1,5,-0.1932040831E-1},
	{2,2,5,-0.1105739959},
	{2,3,5,0.9952548995E-1},
	{2,4,2,0.8548437825E-2},
	{2,4,4,-0.6150555662E-1},
	{3,3,12,-0.4291792423E-1},
	{3,5,8,-0.1813207290E-1},
	{3,5,10,0.3445904760E-1},
	{3,8,10,-0.2385919450E-2},
	{4,2,10,-0.1159094939E-1},
	{4,3,14,0.6641693602E-1},
	{4,4,12,-0.2371549590E-1},
	{4,4,18,-0.3961624905E-1},
	{4,4,22,-0.1387292044E-1},
	{4,5,18,0.3389489599E-1},
	{4,6,14,-0.2927378753E-2}};
	coeficientesExponenciais=Aloca(numeroCoeficientes[2],4);
	for(int i=0;i<23;i++){
		for(int j=0;j<4;j++)coeficientesExponenciais[i][j]=e[i][j];
	}
	double f[4][7]={
		{2,2,0.9324799946E-4,20,200,1.07,1},
		{0,0,-0.6287171518E1,40,250,1.11,1},
		{0,1,0.1271069467E2,40,250,1.11,1},
		{0,2,-0.6423953466E1,40,250,1.11,1}};
	coeficientesGaussianos=Aloca(numeroCoeficientes[3],7);
	for(int i=0;i<4;i++){
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
