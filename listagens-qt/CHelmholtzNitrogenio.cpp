#include "CHelmholtzAgua.h"
CHelmholtzNitrogenio::CHelmholtzNitrogenio()
{
	tCritica=126.192;
	dCritica=313.3;
	rEspecifico=0.2968038958;
	int a[5]={1,6,26,4,0};
	for(int i=0;i<5;i++)numeroCoeficientes[i]=a[i];
	double b[6]={-12.76952708,-0.00784163,2.5,-1.934819E-4,-1.247742E-5,6.678326E-8};
	coeficientesIdeais1 = new double[6];
	for(int i=0;i<6;i++)coeficientesIdeais1[i]=b[i];
	double c[1][2]={
	{1.012941,26.65788}};
	coeficientesIdeais2=Aloca(numeroCoeficientes[0],2);
	for(int i=0;i<numeroCoeficientes[0];i++){
		for(int j=0;j<2;j++)coeficientesIdeais2[i][j]=c[i][j];
	}
	double d[6][3]={
	{1,0.25,0.924803575275},
	{1,0.875,-0.492448489428},
	{2,0.5,0.661883336938},
	{2,0.875,-0.192902649201E1},
	{3,0.375,-0.622469309629E-1},
	{3,0.75,0.349943957581}};
	coeficientesPolinomio=Aloca(numeroCoeficientes[1],3);
	for(int i=0;i<numeroCoeficientes[1];i++){
		for(int j=0;j<3;j++)coeficientesPolinomio[i][j]=d[i][j];
	}
	double e[26][4]={
	{1,1,0.5,0.564857472498},
	{1,1,0.75,-0.161720005987E1},
	{1,1,2,-0.481395031883},
	{1,3,1.25,0.421150636384},
	{1,3,3.5,-0.161962230825E-1},
	{1,4,1,0.172100994165},
	{1,6,0.5,0.735448924933E-2},
	{1,6,3,0.168077305479E-1},
	{1,7,0,-0.107626664179E-2},
	{1,7,2.75,-0.137318088513E-1},
	{1,8,0.75,0.635466899859E-3},
	{1,8,2.5,0.304432279419E-2},
	{2,1,4,-0.435762336045E-1},
	{2,2,6,-0.723174889316E-1},
	{2,3,6,0.389644315272E-1},
	{2,4,3,-0.212201363910E-1},
	{2,5,3,0.408822981509E-2},
	{2,8,6,-0.551990017984E-4},
	{3,4,16,-0.462016716479E-1},
	{3,5,11,-0.300311716011E-2},
	{3,5,15,0.368825891208E-1},
	{3,8,12,-0.255856846220E-2},
	{4,3,12,0.896915264558E-2},
	{4,5,7,-0.441513370350E-2},
	{4,6,4,0.133722924858E-2},
	{4,9,16,0.264832491957E-3}};
	coeficientesExponenciais=Aloca(numeroCoeficientes[2],4);
	for(int i=0;i<numeroCoeficientes[2];i++){
		for(int j=0;j<4;j++)coeficientesExponenciais[i][j]=e[i][j];
	}
	double f[4][7]={
		{1,0,0.196688194015E2,20,325,1.16,1},
		{1,1,-0.209115600730E2,20,325,1.16,1},
		{3,2,0.167788306989E-2,15,300,1.13,1},
		{2,3,0.262767566274E4,25,275,1.25,1}};
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
