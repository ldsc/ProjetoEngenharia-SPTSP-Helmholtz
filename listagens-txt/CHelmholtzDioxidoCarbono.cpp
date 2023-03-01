#include "CHelmholtzAgua.h"
CHelmholtzDioxidoCarbono::CHelmholtzDioxidoCarbono()
{
	tCritica=304.1282;
	dCritica=467.6;
	rEspecifico=0.1889241;
	int a[5]={5,7,27,5,3};
	for(int i=0;i<5;i++)numeroCoeficientes[i]=a[i];
	double b[3]={8.37304456,-3.70454304,2.50000000};
	coeficientesIdeais1 = new double[3];
	for(int i=0;i<3;i++)coeficientesIdeais1[i]=b[i];
	double c[5][2]={
	{1.99427042,3.15163},
	{0.62105248,6.11190},
	{0.41195293,6.77708},
	{1.04028922,11.32384},
	{0.08327678,27.08792}};
	coeficientesIdeais2=Aloca(numeroCoeficientes[0],2);
	for(int i=0;i<numeroCoeficientes[0];i++){
		for(int j=0;j<2;j++)coeficientesIdeais2[i][j]=c[i][j];
	}
	double d[7][3]={
	{1,0,0.38856823203161},
	{1,0.75,0.29385475942740E1},
	{1,1,-0.55867188534934E1},
	{1,2,-0.76753199592477},
	{2,0.75,0.31729005580416},
	{2,2,0.54803315897767},
	{3,0.75,0.12279411220335}};
	coeficientesPolinomio=Aloca(numeroCoeficientes[1],3);
	for(int i=0;i<numeroCoeficientes[1];i++){
		for(int j=0;j<3;j++)coeficientesPolinomio[i][j]=d[i][j];
	}
	double e[27][4]={
	{1,1,1.5,0.21658961543220E1},
	{1,2,1.5,0.15841735109724E1},
	{1,4,2.5,-0.23132705405503},
	{1,5,0,0.58116916431436E-1},
	{1,5,1.5,-0.55369137205382},
	{1,5,2,0.48946615909422},
	{1,6,0,-0.24275739843501E-1},
	{1,6,1,0.62494790501678E-1},
	{1,6,2,-0.12175860225246},
	{2,1,3,-0.37055685270086},
	{2,1,6,-0.16775879700426E-1},
	{2,4,3,-0.11960736637987},
	{2,4,6,-0.45619362508778E-1},
	{2,4,8,0.35612789270346E-1},
	{2,7,6,-0.74427727132052E-2},
	{2,8,0,-0.17395704902432E-2},
	{3,2,7,-0.21810121289527E-1},
	{3,3,12,0.24332166559236E-1},
	{3,3,16,-0.37440133423463E-1},
	{4,5,22,0.14338715756878},
	{4,5,24,-0.13491969083286},
	{4,6,16,-0.23151225053480E-1},
	{4,7,24,0.12363125492901E-1},
	{4,8,8,0.21058321972940E-2},
	{4,10,2,-0.33958519026368E-3},
	{5,4,28,0.55993651771592E-2},
	{6,8,14,-0.30335118055646E-3}};
	coeficientesExponenciais=Aloca(numeroCoeficientes[2],4);
	for(int i=0;i<numeroCoeficientes[2];i++){
		for(int j=0;j<4;j++)coeficientesExponenciais[i][j]=e[i][j];
	}
	double f[5][7]={
		{2,1,-0.21365488688320E3,25,325,1.16,1},
		{2,0,0.26641569149272E5,25,300,1.19,1},
		{2,1,-0.24027212204557E5,25,300,1.19,1},
		{3,3,-0.28341603423999E3,15,275,1.25,1},
		{3,3,0.21247284400179E3,20,275,1.22,1}};
	coeficientesGaussianos=Aloca(numeroCoeficientes[3],7);
	for(int i=0;i<numeroCoeficientes[3];i++){
		for(int j=0;j<7;j++)coeficientesGaussianos[i][j]=f[i][j];
	}
	double g[3][8]={
		{3.5,0.875,0.3,-0.66642276540751,10,275,0.7,0.3},
		{3.5,0.925,0.3,0.72608632349897,10,275,0.7,0.3},
		{3,0.875,1,0.55068668612842E-1,12.5,275,0.7,0.3}};
	coeficientesNaoAnaliticos=Aloca(numeroCoeficientes[4],8);
	for(int i=0;i<numeroCoeficientes[4];i++){
		for(int j=0;j<8;j++)coeficientesNaoAnaliticos[i][j]=g[i][j];
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
