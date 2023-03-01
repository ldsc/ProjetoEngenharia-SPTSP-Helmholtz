#include "CHelmholtzAgua.h"
CHelmholtzNbutano::CHelmholtzNbutano()
{
	tCritica=425.125;
	dCritica=228;
	rEspecifico=0.14305157;
	int a[5]={4,7,16,2,0};
	for(int i=0;i<5;i++)numeroCoeficientes[i]=a[i];
	double b[3]={12.54882924,-5.46976878,3.24680487};
	coeficientesIdeais1 = new double[3];
	for(int i=0;i<3;i++)coeficientesIdeais1[i]=b[i];
	double c[4][2]={
	{5.54913289,0.7748404445},
	{11.4648996,3.3406025522},
	{7.59987584,4.9705130961},
	{9.66033239,9.9755537783}};
	coeficientesIdeais2=Aloca(numeroCoeficientes[0],2);
	for(int i=0;i<numeroCoeficientes[0];i++){
		for(int j=0;j<2;j++)coeficientesIdeais2[i][j]=c[i][j];
	}
	double d[7][3]={
	{1,0.5,0.25536998241635E1},
	{1,1,-0.44585951806696E1},
	{1,1.5,0.82425886369063},
	{2,0,0.11215007011442},
	{3,0.5,-0.35910933680333E-1},
	{4,0.5,0.16790508518103E-1},
	{4,0.75,0.32734072508724E-1}};
	coeficientesPolinomio=Aloca(numeroCoeficientes[1],3);
	for(int i=0;i<numeroCoeficientes[1];i++){
		for(int j=0;j<3;j++)coeficientesPolinomio[i][j]=d[i][j];
	}
	double e[16][4]={
	{1,1,2,0.95571232982005},
	{1,1,2.5,-0.10003385753419E1},
	{1,2,2.5,0.85581548803855E-1},
	{1,7,1.5,-0.25147918369616E-1},
	{1,8,1,-0.15202958578918E-2},
	{1,8,1.5,0.47060682326420E-2},
	{2,1,4,-0.97845414174006E-1},
	{2,2,7,-0.48317904158760E-1},
	{2,3,3,0.17841271865468},
	{2,3,7,0.18173836739334E-1},
	{2,4,3,-0.11399068074953},
	{2,5,1,0.19329896666669E-1},
	{2,5,6,0.11575877401010E-2},
	{2,10,0,0.15253808698116E-3},
	{3,2,6,-0.43688558458471E-1},
	{3,6,13,-0.82403190629989E-2}};
	coeficientesExponenciais=Aloca(numeroCoeficientes[2],4);
	for(int i=0;i<numeroCoeficientes[2];i++){
		for(int j=0;j<4;j++)coeficientesExponenciais[i][j]=e[i][j];
	}
	double f[2][7]={
		{1,2,-0.28390056949441E-1,10,150,1.16,0.85},
		{2,0,0.14904666224681E-2,10,200,1.13,1}};
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
