#include "CHelmholtz.h"
#include <cmath>
#include <iostream>
using namespace std;
double** CHelmholtz::Aloca(int nx, int ny)
{
	double** pm=new double* [nx];
	for(int i=0;i<nx;i++) pm[i]=new double[ny];
	return pm;
}
void CHelmholtz::Desaloca (double**& pm, int nx)
{
	if(pm)
	for(int i=0;i<nx;i++)delete pm[i];
	delete pm;
}	
void CHelmholtz::FR()
{
	fResidual=0;
	for(int i=0;i<numeroCoeficientes[1];i++){
		fResidual+=coeficientesPolinomio[i][2]*pow(delta,coeficientesPolinomio[i][0])*pow(tau,coeficientesPolinomio[i][1]);
	}
	for(int i=0;i<numeroCoeficientes[2];i++){
		fResidual+=coeficientesExponenciais[i][3]*pow(delta,coeficientesExponenciais[i][1])*pow(tau,coeficientesExponenciais[i][2])*exp(-pow(delta,coeficientesExponenciais[i][0]));
	}
	for(int i=0;i<numeroCoeficientes[3];i++){
		double a=coeficientesGaussianos[i][2]*pow(delta,coeficientesGaussianos[i][0])*pow(tau,coeficientesGaussianos[i][1]);
		double b=exp(-coeficientesGaussianos[i][3]*pow((delta-coeficientesGaussianos[i][6]),2)-coeficientesGaussianos[i][4]*pow((tau-coeficientesGaussianos[i][5]),2));
		fResidual+=a*b;
	}
	for(int i=0;i<numeroCoeficientes[4];i++){
		double fi=(1-tau)+coeficientesNaoAnaliticos[i][6]*pow(pow((delta-1),2),(1/(2*coeficientesNaoAnaliticos[i][7])));
		double mdelta=pow(fi,2)+coeficientesNaoAnaliticos[i][2]*pow(pow((delta-1),2),coeficientesNaoAnaliticos[i][0]);
		double ex=exp(-(coeficientesNaoAnaliticos[i][4]*pow((delta-1),2)+coeficientesNaoAnaliticos[i][5]*pow((tau-1),2)));
		fResidual+=coeficientesNaoAnaliticos[i][3]*ex*delta*pow(mdelta,coeficientesNaoAnaliticos[i][1]);
	}
}
void CHelmholtz::FR_d()
{
	fResidual_d=0;
	for(int i=0;i<numeroCoeficientes[1];i++){
		fResidual_d+=coeficientesPolinomio[i][2]*coeficientesPolinomio[i][0]*pow(delta,((coeficientesPolinomio[i][0]-1)))*pow(tau,coeficientesPolinomio[i][1]);
	}
	for(int i=0;i<numeroCoeficientes[2];i++){
		fResidual_d+=coeficientesExponenciais[i][3]*pow(delta,(coeficientesExponenciais[i][1]-1))*pow(tau,coeficientesExponenciais[i][2])*(coeficientesExponenciais[i][1]-coeficientesExponenciais[i][0]*pow(delta,coeficientesExponenciais[i][0]))*exp(-pow(delta,coeficientesExponenciais[i][0]));
	}
	for(int i=0;i<numeroCoeficientes[3];i++){
		double a=coeficientesGaussianos[i][2]*pow(delta,coeficientesGaussianos[i][0])*pow(tau,coeficientesGaussianos[i][1]);
		double b=exp(-coeficientesGaussianos[i][3]*pow((delta-coeficientesGaussianos[i][6]),2)-coeficientesGaussianos[i][4]*pow((tau-coeficientesGaussianos[i][5]),2));
		double c=(coeficientesGaussianos[i][0]/delta)-2*coeficientesGaussianos[i][3]*(delta-coeficientesGaussianos[i][6]);
		fResidual_d+=a*b*c;
	}
	for(int i=0;i<numeroCoeficientes[4];i++){
		double fi=(1-tau)+coeficientesNaoAnaliticos[i][6]*pow(pow((delta-1),2),(1/(2*coeficientesNaoAnaliticos[i][7])));
		double mdelta=pow(fi,2)+coeficientesNaoAnaliticos[i][2]*pow(pow((delta-1),2),coeficientesNaoAnaliticos[i][0]);
		double mdelta_d=(delta-1)*(coeficientesNaoAnaliticos[i][6]*fi*(2/coeficientesNaoAnaliticos[i][7])*pow(pow((delta-1),2),(1/(2*coeficientesNaoAnaliticos[i][7]))-1)+2*coeficientesNaoAnaliticos[i][2]*coeficientesNaoAnaliticos[i][0]*pow(pow((delta-1),2),(coeficientesNaoAnaliticos[i][0]-1)));
		double mdeltab_d=coeficientesNaoAnaliticos[i][1]*pow(mdelta,(coeficientesNaoAnaliticos[i][1]-1))*mdelta_d;
		double ex=exp(-(coeficientesNaoAnaliticos[i][4]*pow((delta-1),2)+coeficientesNaoAnaliticos[i][5]*pow((tau-1),2)));
		double ex_d=-2*coeficientesNaoAnaliticos[i][4]*(delta-1)*ex;
		fResidual_d+=coeficientesNaoAnaliticos[i][3]*pow(mdelta,coeficientesNaoAnaliticos[i][1])*(ex+delta*ex_d);
		fResidual_d+=coeficientesNaoAnaliticos[i][3]*(delta*mdeltab_d*ex);
	}
}
void CHelmholtz::FR_dd()
{
	fResidual_dd=0;
	for(int i=0;i<numeroCoeficientes[1];i++){
		fResidual_dd+=coeficientesPolinomio[i][2]*coeficientesPolinomio[i][0]*(coeficientesPolinomio[i][0]-1)*pow(delta,((coeficientesPolinomio[i][0]-2)))*pow(tau,coeficientesPolinomio[i][1]);
	}
	for(int i=0;i<numeroCoeficientes[2];i++){
		fResidual_dd+=coeficientesExponenciais[i][3]*pow(delta,(coeficientesExponenciais[i][1]-2))*pow(tau,coeficientesExponenciais[i][2])*exp(-pow(delta,coeficientesExponenciais[i][0]))*((coeficientesExponenciais[i][1]-coeficientesExponenciais[i][0]*pow(delta,coeficientesExponenciais[i][0]))*(coeficientesExponenciais[i][1]-1-coeficientesExponenciais[i][0]*pow(delta,coeficientesExponenciais[i][0]))-pow(coeficientesExponenciais[i][0],2)*pow(delta,coeficientesExponenciais[i][0]));
	}
	for(int i=0;i<numeroCoeficientes[3];i++){
		double a=coeficientesGaussianos[i][2]*pow(tau,coeficientesGaussianos[i][1]);
		double b=exp(-coeficientesGaussianos[i][3]*pow((delta-coeficientesGaussianos[i][6]),2)-coeficientesGaussianos[i][4]*pow((tau-coeficientesGaussianos[i][5]),2));
		double c=-2*coeficientesGaussianos[i][3]*pow(delta,coeficientesGaussianos[i][0])+4*pow(coeficientesGaussianos[i][3],2)*pow(delta,coeficientesGaussianos[i][0])*pow(delta-coeficientesGaussianos[i][6],2);
		double d=-4*coeficientesGaussianos[i][0]*coeficientesGaussianos[i][3]*pow(delta,coeficientesGaussianos[i][0]-1)*(delta-coeficientesGaussianos[i][6])+coeficientesGaussianos[i][0]*(coeficientesGaussianos[i][0]-1)*pow(delta,coeficientesGaussianos[i][0]-2);
		fResidual_dd+=a*b*(c+d);
	}
	for(int i=0;i<numeroCoeficientes[4];i++){
		double fi=(1-tau)+coeficientesNaoAnaliticos[i][6]*pow(pow((delta-1),2),(1/(2*coeficientesNaoAnaliticos[i][7])));
		double mdelta=pow(fi,2)+coeficientesNaoAnaliticos[i][2]*pow(pow((delta-1),2),coeficientesNaoAnaliticos[i][0]);
		double mdelta_d=(delta-1)*(coeficientesNaoAnaliticos[i][6]*fi*(2/coeficientesNaoAnaliticos[i][7])*pow(pow((delta-1),2),(1/(2*coeficientesNaoAnaliticos[i][7]))-1)+2*coeficientesNaoAnaliticos[i][2]*coeficientesNaoAnaliticos[i][0]*pow(pow((delta-1),2),(coeficientesNaoAnaliticos[i][0]-1)));
		double mdeltab_d=coeficientesNaoAnaliticos[i][1]*pow(mdelta,(coeficientesNaoAnaliticos[i][1]-1))*mdelta_d;
		double ex=exp(-(coeficientesNaoAnaliticos[i][4]*pow((delta-1),2)+coeficientesNaoAnaliticos[i][5]*pow((tau-1),2)));
		double ex_d=-2*coeficientesNaoAnaliticos[i][4]*(delta-1)*ex;
		double ex_dd=(2*coeficientesNaoAnaliticos[i][4]*pow(delta-1,2)-1)*2*coeficientesNaoAnaliticos[i][4]*ex;
		double mdelta_dd=(1/(delta-1))*mdelta_d+pow(delta-1,2)*4*coeficientesNaoAnaliticos[i][2]*coeficientesNaoAnaliticos[i][0]*(coeficientesNaoAnaliticos[i][0]-1)*pow(pow(delta-1,2),coeficientesNaoAnaliticos[i][0]-2);
		mdelta_dd+=pow(delta-1,2)*2*pow(coeficientesNaoAnaliticos[i][6],2)*pow(1/coeficientesNaoAnaliticos[i][7],2)*pow(pow(pow(delta-1,2),1/((2*coeficientesNaoAnaliticos[i][7]))-1),2);
	
		mdelta_dd+=pow(delta-1,2)*coeficientesNaoAnaliticos[i][6]*fi*(4/coeficientesNaoAnaliticos[i][7])*(1/(2*coeficientesNaoAnaliticos[i][7])-1)*pow(pow(delta-1,2),(1/(2*coeficientesNaoAnaliticos[i][7]))-2);
		double mdeltab_dd=coeficientesNaoAnaliticos[i][1]*(pow(mdelta,coeficientesNaoAnaliticos[i][1]-1)*mdelta_dd+(coeficientesNaoAnaliticos[i][1]-1)*pow(mdelta,coeficientesNaoAnaliticos[i][1]-2)*pow(mdelta_d,2));
		
		double a1=pow(mdelta,coeficientesNaoAnaliticos[i][1])*(2*ex_d+delta*ex_dd);
		double a2=2*mdeltab_d*(ex+delta*ex_d);
		double a3=mdeltab_dd*delta*ex;
		fResidual_dd+=coeficientesNaoAnaliticos[i][3]*(a1+a2+a3);
	}
}
void CHelmholtz::FR_ddd()
{
	fResidual_ddd=0;
	for(int i=0;i<numeroCoeficientes[1];i++){
		fResidual_ddd+=coeficientesPolinomio[i][2]*coeficientesPolinomio[i][0]*(coeficientesPolinomio[i][0]-1)*(coeficientesPolinomio[i][0]-2)*pow(delta,((coeficientesPolinomio[i][0]-3)))*pow(tau,coeficientesPolinomio[i][1]);
	}
	for(int i=0;i<numeroCoeficientes[2];i++){
		double dc=pow(delta,coeficientesExponenciais[i][0]);
		double c=coeficientesExponenciais[i][0];
		fResidual_ddd+=coeficientesExponenciais[i][3]*exp(-dc)*pow(tau,coeficientesExponenciais[i][2])*(pow(delta,coeficientesExponenciais[i][1]-3)*((coeficientesExponenciais[i][1]-c*dc)*(coeficientesExponenciais[i][1]-1-c*dc)-pow(c,2)*dc)*(coeficientesExponenciais[i][1]-2)-c*pow(delta,c-1)*pow(delta,coeficientesExponenciais[i][1]-2)*((coeficientesExponenciais[i][1]-c*dc)*(coeficientesExponenciais[i][1]-1-c*dc)-pow(c,2)*dc)-pow(delta,coeficientesExponenciais[i][1]-2)*pow(c,2)*(c*pow(delta,c-1)+pow(delta,c-1)*(2*coeficientesExponenciais[i][1]-1-2*c*dc)));
	}
	for(int i=0;i<numeroCoeficientes[3];i++){
		double a=coeficientesGaussianos[i][2]*pow(tau,coeficientesGaussianos[i][1]);
		double b=exp(-coeficientesGaussianos[i][3]*pow((delta-coeficientesGaussianos[i][6]),2)-coeficientesGaussianos[i][4]*pow((tau-coeficientesGaussianos[i][5]),2));
		double c=-2*coeficientesGaussianos[i][3]*pow(delta,coeficientesGaussianos[i][0])+4*pow(coeficientesGaussianos[i][3],2)*pow(delta,coeficientesGaussianos[i][0])*pow(delta-coeficientesGaussianos[i][6],2)-4*coeficientesGaussianos[i][0]*coeficientesGaussianos[i][3]*pow(delta,coeficientesGaussianos[i][0]-1)*(delta-coeficientesGaussianos[i][6])+coeficientesGaussianos[i][0]*(coeficientesGaussianos[i][0]-1)*pow(delta,coeficientesGaussianos[i][0]-2);
		double d=-2*coeficientesGaussianos[i][3]*coeficientesGaussianos[i][0]*pow(delta,coeficientesGaussianos[i][0]-1)+4*pow(coeficientesGaussianos[i][3],2)*coeficientesGaussianos[i][0]*pow(delta,coeficientesGaussianos[i][0]-1)*pow(delta-coeficientesGaussianos[i][6],2)+8*pow(coeficientesGaussianos[i][3],2)*pow(delta,coeficientesGaussianos[i][0])*(delta-coeficientesGaussianos[i][6])-4*coeficientesGaussianos[i][0]*(coeficientesGaussianos[i][0]-1)*coeficientesGaussianos[i][3]*pow(delta,coeficientesGaussianos[i][0]-2)*(delta-coeficientesGaussianos[i][6])-4*coeficientesGaussianos[i][0]*coeficientesGaussianos[i][3]*pow(delta,coeficientesGaussianos[i][0]-1)+coeficientesGaussianos[i][0]*(coeficientesGaussianos[i][0]-1)*(coeficientesGaussianos[i][0]-2)*pow(delta,coeficientesGaussianos[i][0]-3);
		fResidual_ddd-=2*coeficientesGaussianos[i][3]*(delta-coeficientesGaussianos[i][6])*a*b*c;
		fResidual_ddd+=a*b*d;
	}
	for(int i=0;i<numeroCoeficientes[4];i++){
		double b=coeficientesNaoAnaliticos[i][1];
		double fi=(1-tau)+coeficientesNaoAnaliticos[i][6]*pow(pow((delta-1),2),(1/(2*coeficientesNaoAnaliticos[i][7])));
		double mdelta=pow(fi,2)+coeficientesNaoAnaliticos[i][2]*pow(pow((delta-1),2),coeficientesNaoAnaliticos[i][0]);
		double mdelta_d=(delta-1)*(coeficientesNaoAnaliticos[i][6]*fi*(2/coeficientesNaoAnaliticos[i][7])*pow(pow((delta-1),2),(1/(2*coeficientesNaoAnaliticos[i][7]))-1)+2*coeficientesNaoAnaliticos[i][2]*coeficientesNaoAnaliticos[i][0]*pow(pow((delta-1),2),(coeficientesNaoAnaliticos[i][0]-1)));
		double mdeltab_d=coeficientesNaoAnaliticos[i][1]*pow(mdelta,(coeficientesNaoAnaliticos[i][1]-1))*mdelta_d;
		double ex=exp(-(coeficientesNaoAnaliticos[i][4]*pow((delta-1),2)+coeficientesNaoAnaliticos[i][5]*pow((tau-1),2)));
		double ex_d=-2*coeficientesNaoAnaliticos[i][4]*(delta-1)*ex;
		double ex_dd=(2*coeficientesNaoAnaliticos[i][4]*pow(delta-1,2)-1)*2*coeficientesNaoAnaliticos[i][4]*ex;
		double mdelta_dd=(1/(delta-1))*mdelta_d+pow(delta-1,2)*4*coeficientesNaoAnaliticos[i][2]*coeficientesNaoAnaliticos[i][0]*(coeficientesNaoAnaliticos[i][0]-1)*pow(pow(delta-1,2),coeficientesNaoAnaliticos[i][0]-2);
		mdelta_dd+=pow(delta-1,2)*2*pow(coeficientesNaoAnaliticos[i][6],2)*pow(1/coeficientesNaoAnaliticos[i][7],2)*pow(pow(pow(delta-1,2),1/((2*coeficientesNaoAnaliticos[i][7]))-1),2);
		mdelta_dd+=pow(delta-1,2)*coeficientesNaoAnaliticos[i][6]*fi*(4/coeficientesNaoAnaliticos[i][7])*(1/(2*coeficientesNaoAnaliticos[i][7])-1)*pow(pow(delta-1,2),(1/(2*coeficientesNaoAnaliticos[i][7]))-2);
		
		double mdeltab_dd=coeficientesNaoAnaliticos[i][1]*(pow(mdelta,coeficientesNaoAnaliticos[i][1]-1)*mdelta_dd+(coeficientesNaoAnaliticos[i][1]-1)*pow(mdelta,coeficientesNaoAnaliticos[i][1]-2)*pow(mdelta_d,2));
		double mdelta_ddd=mdelta_dd/(delta-1)-mdelta_d/pow(delta-1,2);//ok
		mdelta_ddd+=2*(delta-1)*(4*coeficientesNaoAnaliticos[i][2]*coeficientesNaoAnaliticos[i][0]*(coeficientesNaoAnaliticos[i][0]-1)*pow(pow(delta-1,2),coeficientesNaoAnaliticos[i][0]-2)+2*pow(coeficientesNaoAnaliticos[i][6]/coeficientesNaoAnaliticos[i][7],2)*pow(pow(pow(delta-1,2),1/(2*coeficientesNaoAnaliticos[i][7])-1),2)+(4*coeficientesNaoAnaliticos[i][6]/coeficientesNaoAnaliticos[i][7])*fi*(1/(2*coeficientesNaoAnaliticos[i][7])-1)*pow(pow(delta-1,2),1/(2*coeficientesNaoAnaliticos[i][7])-2));
		mdelta_ddd+=pow(delta-1,3)*(8*coeficientesNaoAnaliticos[i][2]*coeficientesNaoAnaliticos[i][0]*(coeficientesNaoAnaliticos[i][0]-1)*(coeficientesNaoAnaliticos[i][0]-2)*pow(pow(delta-1,2),coeficientesNaoAnaliticos[i][0]-3)+12*pow(coeficientesNaoAnaliticos[i][6]/coeficientesNaoAnaliticos[i][7],2)*(1/(2*coeficientesNaoAnaliticos[i][7])-1)*pow(pow(delta-1,2),1/(2*coeficientesNaoAnaliticos[i][7])-1)*pow(pow(delta-1,2),1/(2*coeficientesNaoAnaliticos[i][7])-2)+8*(coeficientesNaoAnaliticos[i][6]/coeficientesNaoAnaliticos[i][7])*fi*(1/(2*coeficientesNaoAnaliticos[i][7])-1)*(1/(2*coeficientesNaoAnaliticos[i][7])-2)*pow(pow(delta-1,2),1/(2*coeficientesNaoAnaliticos[i][7])-3));
		double ex_ddd=4*pow(coeficientesNaoAnaliticos[i][4],2)*(delta-1)*(3-2*coeficientesNaoAnaliticos[i][4]*pow(delta-1,2))*ex;
		double mdeltab_ddd=b*(pow(mdelta,b-1)*mdelta_ddd+(b-1)*pow(mdelta,b-2)*mdelta_d*mdelta_dd+(b-1)*(b-2)*pow(mdelta,b-3)*pow(mdelta_d,3)+(b-1)*pow(mdelta,b-2)*mdelta_dd*2*mdelta_d);
		
		double p1=3*mdeltab_d*(2*ex_d+delta*ex_dd);
		double p2=3*mdeltab_dd*(ex+delta*ex_d);
		double p3=pow(mdelta,coeficientesNaoAnaliticos[i][1])*(3*ex_dd+delta*ex_ddd);
		double p4=mdeltab_ddd*delta*ex;
		fResidual_ddd+=coeficientesNaoAnaliticos[i][3]*(p1+p2+p3+p4);
	}
}
void CHelmholtz::FR_ddt()
{
	fResidual_ddt=0;
	for(int i=0;i<numeroCoeficientes[1];i++){
		fResidual_ddt+=coeficientesPolinomio[i][2]*coeficientesPolinomio[i][0]*(coeficientesPolinomio[i][0]-1)*pow(delta,((coeficientesPolinomio[i][0]-2)))*coeficientesPolinomio[i][1]*pow(tau,coeficientesPolinomio[i][1]-1);
	}
	for(int i=0;i<numeroCoeficientes[2];i++){
		fResidual_ddt+=coeficientesExponenciais[i][3]*pow(delta,(coeficientesExponenciais[i][1]-2))*coeficientesExponenciais[i][2]*pow(tau,coeficientesExponenciais[i][2]-1)*exp(-pow(delta,coeficientesExponenciais[i][0]))*((coeficientesExponenciais[i][1]-coeficientesExponenciais[i][0]*pow(delta,coeficientesExponenciais[i][0]))*(coeficientesExponenciais[i][1]-1-coeficientesExponenciais[i][0]*pow(delta,coeficientesExponenciais[i][0]))-pow(coeficientesExponenciais[i][0],2)*pow(delta,coeficientesExponenciais[i][0]));
	}
	for(int i=0;i<numeroCoeficientes[3];i++){
		double a=coeficientesGaussianos[i][2]*pow(tau,coeficientesGaussianos[i][1]);
		double b=exp(-coeficientesGaussianos[i][3]*pow((delta-coeficientesGaussianos[i][6]),2)-coeficientesGaussianos[i][4]*pow((tau-coeficientesGaussianos[i][5]),2));
		double c=-2*coeficientesGaussianos[i][3]*pow(delta,coeficientesGaussianos[i][0])+4*pow(coeficientesGaussianos[i][3],2)*pow(delta,coeficientesGaussianos[i][0])*pow(delta-coeficientesGaussianos[i][6],2);
		double d=-4*coeficientesGaussianos[i][0]*coeficientesGaussianos[i][3]*pow(delta,coeficientesGaussianos[i][0]-1)*(delta-coeficientesGaussianos[i][6])+coeficientesGaussianos[i][0]*(coeficientesGaussianos[i][0]-1)*pow(delta,coeficientesGaussianos[i][0]-2);
		double e=(coeficientesGaussianos[i][1]/tau)-2*coeficientesGaussianos[i][4]*(tau-coeficientesGaussianos[i][5]);
		fResidual_ddt+=a*b*(c+d)*e;
	}
	for(int i=0;i<numeroCoeficientes[4];i++){
		double fi=(1-tau)+coeficientesNaoAnaliticos[i][6]*pow(pow((delta-1),2),(1/(2*coeficientesNaoAnaliticos[i][7])));
		double mdelta=pow(fi,2)+coeficientesNaoAnaliticos[i][2]*pow(pow((delta-1),2),coeficientesNaoAnaliticos[i][0]);
		double mdelta_d=(delta-1)*(coeficientesNaoAnaliticos[i][6]*fi*(2/coeficientesNaoAnaliticos[i][7])*pow(pow((delta-1),2),(1/(2*coeficientesNaoAnaliticos[i][7]))-1)+2*coeficientesNaoAnaliticos[i][2]*coeficientesNaoAnaliticos[i][0]*pow(pow((delta-1),2),(coeficientesNaoAnaliticos[i][0]-1)));
		double mdeltab_d=coeficientesNaoAnaliticos[i][1]*pow(mdelta,(coeficientesNaoAnaliticos[i][1]-1))*mdelta_d;
		double ex=exp(-(coeficientesNaoAnaliticos[i][4]*pow((delta-1),2)+coeficientesNaoAnaliticos[i][5]*pow((tau-1),2)));
		double ex_d=-2*coeficientesNaoAnaliticos[i][4]*(delta-1)*ex;
		double ex_dd=(2*coeficientesNaoAnaliticos[i][4]*pow(delta-1,2)-1)*2*coeficientesNaoAnaliticos[i][4]*ex;
		double mdelta_dd=(1/(delta-1))*mdelta_d+pow(delta-1,2)*4*coeficientesNaoAnaliticos[i][2]*coeficientesNaoAnaliticos[i][0]*(coeficientesNaoAnaliticos[i][0]-1)*pow(pow(delta-1,2),coeficientesNaoAnaliticos[i][0]-2);
		mdelta_dd+=pow(delta-1,2)*2*pow(coeficientesNaoAnaliticos[i][6],2)*pow(1/coeficientesNaoAnaliticos[i][7],2)*pow(pow(pow(delta-1,2),1/((2*coeficientesNaoAnaliticos[i][7]))-1),2);
		mdelta_dd+=pow(delta-1,2)*coeficientesNaoAnaliticos[i][6]*fi*(4/coeficientesNaoAnaliticos[i][7])*(1/(2*coeficientesNaoAnaliticos[i][7])-1)*pow(pow(delta-1,2),(1/(2*coeficientesNaoAnaliticos[i][7]))-2);
		double mdeltab_dd=coeficientesNaoAnaliticos[i][1]*(pow(mdelta,coeficientesNaoAnaliticos[i][1]-1)*mdelta_dd+(coeficientesNaoAnaliticos[i][1]-1)*pow(mdelta,coeficientesNaoAnaliticos[i][1]-2)*pow(mdelta_d,2));
		double mdeltab_t=-2*fi*coeficientesNaoAnaliticos[i][1]*pow(mdelta,coeficientesNaoAnaliticos[i][1]-1);
		double ex_t=-2*coeficientesNaoAnaliticos[i][5]*(tau-1)*ex;
		double mdeltab_dt=-coeficientesNaoAnaliticos[i][6]*coeficientesNaoAnaliticos[i][1]*(2/coeficientesNaoAnaliticos[i][7])*pow(mdelta,coeficientesNaoAnaliticos[i][1]-1)*(delta-1)*pow(pow(delta-1,2),(1/(2*coeficientesNaoAnaliticos[i][7])-1))-2*fi*coeficientesNaoAnaliticos[i][1]*(coeficientesNaoAnaliticos[i][1]-1)*pow(mdelta,coeficientesNaoAnaliticos[i][1]-2)*mdelta_d;
		double ex_dt=4*coeficientesNaoAnaliticos[i][4]*coeficientesNaoAnaliticos[i][5]*(delta-1)*(tau-1)*ex;
		double mdelta_dt=(1-delta)*(0.64/0.3)*pow(pow(delta-1,2),(1/0.6)-1);
		
		double mdelta_ddt=mdelta_dt/(delta-1)-pow(delta-1,2)*coeficientesNaoAnaliticos[i][6]*(4/coeficientesNaoAnaliticos[i][7])*(1/(2*coeficientesNaoAnaliticos[i][7])-1)*pow(pow(delta-1,2),1/(2*coeficientesNaoAnaliticos[i][7])-2);
		
		double mdeltab_ddt=coeficientesNaoAnaliticos[i][1]*(mdelta_ddt*pow(mdelta,coeficientesNaoAnaliticos[i][1]-1)-2*fi*(coeficientesNaoAnaliticos[i][1]-1)*pow(mdelta,coeficientesNaoAnaliticos[i][1]-2)*mdelta_dd+(coeficientesNaoAnaliticos[i][1]-1)*pow(mdelta,coeficientesNaoAnaliticos[i][1]-2)*2*mdelta_dt*mdelta_d-2*fi*(coeficientesNaoAnaliticos[i][1]-2)*(coeficientesNaoAnaliticos[i][1]-1)*pow(mdelta,coeficientesNaoAnaliticos[i][1]-3)*mdelta_d*mdelta_d);
		
		double ex_ddt=-4*coeficientesNaoAnaliticos[i][5]*coeficientesNaoAnaliticos[i][4]*(tau-1)*(2*coeficientesNaoAnaliticos[i][4]*pow(delta-1,2)-1)*ex;
		
		double a1=pow(mdelta,coeficientesNaoAnaliticos[i][1])*(2*ex_dt+delta*ex_ddt);
		double a2=mdeltab_t*(2*ex_d+delta*ex_dd);
		double a3=2*mdeltab_d*(ex_t+delta*ex_dt);
		double a4=2*mdeltab_dt*(ex+delta*ex_d);
		double a5=mdeltab_dd*delta*ex_t;
		double a6=mdeltab_ddt*delta*ex;
		fResidual_ddt+=coeficientesNaoAnaliticos[i][3]*(a1+a2+a3+a4+a5+a6);
	}
}
void CHelmholtz::FR_dt()
{
	fResidual_dt=0;
	for(int i=0;i<numeroCoeficientes[1];i++){
		fResidual_dt+=coeficientesPolinomio[i][2]*coeficientesPolinomio[i][0]*coeficientesPolinomio[i][1]*pow(delta,((coeficientesPolinomio[i][0]-1)))*pow(tau,coeficientesPolinomio[i][1]-1);
	}
	for(int i=0;i<numeroCoeficientes[2];i++){
		fResidual_dt+=coeficientesExponenciais[i][3]*coeficientesExponenciais[i][2]*pow(delta,(coeficientesExponenciais[i][1]-1))*pow(tau,coeficientesExponenciais[i][2]-1)*(coeficientesExponenciais[i][1]-coeficientesExponenciais[i][0]*pow(delta,coeficientesExponenciais[i][0]))*exp(-pow(delta,coeficientesExponenciais[i][0]));
	}
	for(int i=0;i<numeroCoeficientes[3];i++){
		double a=coeficientesGaussianos[i][2]*pow(delta,coeficientesGaussianos[i][0])*pow(tau,coeficientesGaussianos[i][1]);
		double b=exp(-coeficientesGaussianos[i][3]*pow((delta-coeficientesGaussianos[i][6]),2)-coeficientesGaussianos[i][4]*pow((tau-coeficientesGaussianos[i][5]),2));
		double c=(coeficientesGaussianos[i][0]/delta)-2*coeficientesGaussianos[i][3]*(delta-coeficientesGaussianos[i][6]);
		double d=(coeficientesGaussianos[i][1]/tau)-2*coeficientesGaussianos[i][4]*(tau-coeficientesGaussianos[i][5]);
		fResidual_dt+=a*b*c*d;
	}
	for(int i=0;i<numeroCoeficientes[4];i++){
		double fi=(1-tau)+coeficientesNaoAnaliticos[i][6]*pow(pow((delta-1),2),(1/(2*coeficientesNaoAnaliticos[i][7])));
		double mdelta=pow(fi,2)+coeficientesNaoAnaliticos[i][2]*pow(pow((delta-1),2),coeficientesNaoAnaliticos[i][0]);
		double mdelta_d=(delta-1)*(coeficientesNaoAnaliticos[i][6]*fi*(2/coeficientesNaoAnaliticos[i][7])*pow(pow((delta-1),2),(1/(2*coeficientesNaoAnaliticos[i][7]))-1)+2*coeficientesNaoAnaliticos[i][2]*coeficientesNaoAnaliticos[i][0]*pow(pow((delta-1),2),(coeficientesNaoAnaliticos[i][0]-1)));
		double mdeltab_d=coeficientesNaoAnaliticos[i][1]*pow(mdelta,(coeficientesNaoAnaliticos[i][1]-1))*mdelta_d;
		double ex=exp(-(coeficientesNaoAnaliticos[i][4]*pow((delta-1),2)+coeficientesNaoAnaliticos[i][5]*pow((tau-1),2)));
		double ex_d=-2*coeficientesNaoAnaliticos[i][4]*(delta-1)*ex;
		double mdeltab_t=-2*fi*coeficientesNaoAnaliticos[i][1]*pow(mdelta,coeficientesNaoAnaliticos[i][1]-1);
		double ex_t=-2*coeficientesNaoAnaliticos[i][5]*(tau-1)*ex;
		double mdeltab_dt=-coeficientesNaoAnaliticos[i][6]*coeficientesNaoAnaliticos[i][1]*(2/coeficientesNaoAnaliticos[i][7])*pow(mdelta,coeficientesNaoAnaliticos[i][1]-1)*(delta-1)*pow(pow(delta-1,2),(1/(2*coeficientesNaoAnaliticos[i][7])-1))-2*fi*coeficientesNaoAnaliticos[i][1]*(coeficientesNaoAnaliticos[i][1]-1)*pow(mdelta,coeficientesNaoAnaliticos[i][1]-2)*mdelta_d;
		double ex_dt=4*coeficientesNaoAnaliticos[i][4]*coeficientesNaoAnaliticos[i][5]*(delta-1)*(tau-1)*ex;
		fResidual_dt+=coeficientesNaoAnaliticos[i][3]*pow(mdelta,coeficientesNaoAnaliticos[i][1])*(ex_t+delta*ex_dt);
		fResidual_dt+=coeficientesNaoAnaliticos[i][3]*delta*mdeltab_d*ex_t;
		fResidual_dt+=coeficientesNaoAnaliticos[i][3]*mdeltab_t*(ex+delta*ex_d);
		fResidual_dt+=coeficientesNaoAnaliticos[i][3]*mdeltab_dt*delta*ex;
	}
}
void CHelmholtz::FR_dtt()
{
	//falta terminar
	fResidual_dtt=0;
	for(int i=0;i<numeroCoeficientes[1];i++){
		fResidual_dtt+=coeficientesPolinomio[i][2]*coeficientesPolinomio[i][0]*coeficientesPolinomio[i][1]*(coeficientesPolinomio[i][1]-1)*pow(delta,coeficientesPolinomio[i][0]-1)*pow(tau,coeficientesPolinomio[i][1]-2);
	}
	for(int i=0;i<numeroCoeficientes[2];i++){
		fResidual_dtt+=coeficientesExponenciais[i][3]*coeficientesExponenciais[i][2]*(coeficientesExponenciais[i][2]-1)*pow(delta,(coeficientesExponenciais[i][1]-1))*pow(tau,coeficientesExponenciais[i][2]-2)*(coeficientesExponenciais[i][1]-coeficientesExponenciais[i][0]*pow(delta,coeficientesExponenciais[i][0]))*exp(-pow(delta,coeficientesExponenciais[i][0]));
	}
	for(int i=0;i<numeroCoeficientes[3];i++){
		double a=coeficientesGaussianos[i][2]*pow(delta,coeficientesGaussianos[i][0])*pow(tau,coeficientesGaussianos[i][1]);
		double b=exp(-coeficientesGaussianos[i][3]*pow((delta-coeficientesGaussianos[i][6]),2)-coeficientesGaussianos[i][4]*pow((tau-coeficientesGaussianos[i][5]),2));
		double c=(coeficientesGaussianos[i][0]/delta)-2*coeficientesGaussianos[i][3]*(delta-coeficientesGaussianos[i][6]);
		double d=pow((coeficientesGaussianos[i][1]/tau)-2*coeficientesGaussianos[i][4]*(tau-coeficientesGaussianos[i][5]),2)-(coeficientesGaussianos[i][1]/pow(tau,2))-2*coeficientesGaussianos[i][4];
		fResidual_dtt+=a*b*c*d;
	}	
}
void CHelmholtz::FR_t()
{
	fResidual_t=0;
	for(int i=0;i<numeroCoeficientes[1];i++){
		fResidual_t+=coeficientesPolinomio[i][2]*coeficientesPolinomio[i][1]*pow(delta,coeficientesPolinomio[i][0])*pow(tau,(coeficientesPolinomio[i][1]-1));
	}
	for(int i=0;i<numeroCoeficientes[2];i++){
		fResidual_t+=coeficientesExponenciais[i][3]*coeficientesExponenciais[i][2]*pow(delta,coeficientesExponenciais[i][1])*pow(tau,coeficientesExponenciais[i][2]-1)*exp(-pow(delta,coeficientesExponenciais[i][0]));
	}
	for(int i=0;i<numeroCoeficientes[3];i++){
		double a=coeficientesGaussianos[i][2]*pow(delta,coeficientesGaussianos[i][0])*pow(tau,coeficientesGaussianos[i][1]);
		double b=exp(-coeficientesGaussianos[i][3]*pow((delta-coeficientesGaussianos[i][6]),2)-coeficientesGaussianos[i][4]*pow((tau-coeficientesGaussianos[i][5]),2));
		double c=(coeficientesGaussianos[i][1]/tau)-2*coeficientesGaussianos[i][4]*(tau-coeficientesGaussianos[i][5]);
		fResidual_t+=a*b*c;
	}
	for(int i=0;i<numeroCoeficientes[4];i++){
		double fi=(1-tau)+coeficientesNaoAnaliticos[i][6]*pow(pow((delta-1),2),(1/(2*coeficientesNaoAnaliticos[i][7])));
		double mdelta=pow(fi,2)+coeficientesNaoAnaliticos[i][2]*pow(pow((delta-1),2),coeficientesNaoAnaliticos[i][0]);
		double ex=exp(-(coeficientesNaoAnaliticos[i][4]*pow((delta-1),2)+coeficientesNaoAnaliticos[i][5]*pow((tau-1),2)));
		double mdeltab_t=-2*fi*coeficientesNaoAnaliticos[i][1]*pow(mdelta,coeficientesNaoAnaliticos[i][1]-1);
		double ex_t=-2*coeficientesNaoAnaliticos[i][5]*(tau-1)*ex;
		
		fResidual_t+=coeficientesNaoAnaliticos[i][3]*delta*(pow(mdelta,coeficientesNaoAnaliticos[i][1])*ex_t+mdeltab_t*ex);
	}
}
void CHelmholtz::FR_tt()
{
	fResidual_tt=0;
	for(int i=0;i<numeroCoeficientes[1];i++){
		fResidual_tt+=coeficientesPolinomio[i][2]*coeficientesPolinomio[i][1]*(coeficientesPolinomio[i][1]-1)*pow(delta,coeficientesPolinomio[i][0])*pow(tau,(coeficientesPolinomio[i][1]-2));
	}
	for(int i=0;i<numeroCoeficientes[2];i++){
		fResidual_tt+=coeficientesExponenciais[i][3]*coeficientesExponenciais[i][2]*(coeficientesExponenciais[i][2]-1)*pow(delta,coeficientesExponenciais[i][1])*pow(tau,coeficientesExponenciais[i][2]-2)*exp(-pow(delta,coeficientesExponenciais[i][0]));
	}
	for(int i=0;i<numeroCoeficientes[3];i++){
		double a=coeficientesGaussianos[i][2]*pow(delta,coeficientesGaussianos[i][0])*pow(tau,coeficientesGaussianos[i][1]);
		double b=exp(-coeficientesGaussianos[i][3]*pow(delta-coeficientesGaussianos[i][6],2)-coeficientesGaussianos[i][4]*pow(tau-coeficientesGaussianos[i][5],2));
		double c=pow((coeficientesGaussianos[i][1]/tau)-2*coeficientesGaussianos[i][4]*(tau-coeficientesGaussianos[i][5]),2)-coeficientesGaussianos[i][1]*pow(tau,-2)-2*coeficientesGaussianos[i][4];
		fResidual_tt+=a*b*c;
	}
	for(int i=0;i<numeroCoeficientes[4];i++){
		double fi=(1-tau)+coeficientesNaoAnaliticos[i][6]*pow(pow((delta-1),2),(1/(2*coeficientesNaoAnaliticos[i][7])));
		double mdelta=pow(fi,2)+coeficientesNaoAnaliticos[i][2]*pow(pow((delta-1),2),coeficientesNaoAnaliticos[i][0]);
		double ex=exp(-(coeficientesNaoAnaliticos[i][4]*pow((delta-1),2)+coeficientesNaoAnaliticos[i][5]*pow((tau-1),2)));
		double mdeltab_t=-2*fi*coeficientesNaoAnaliticos[i][1]*pow(mdelta,coeficientesNaoAnaliticos[i][1]-1);
		double ex_t=-2*coeficientesNaoAnaliticos[i][5]*(tau-1)*ex;
		double ex_tt=(2*coeficientesNaoAnaliticos[i][5]*pow(tau-1,2)-1)*2*coeficientesNaoAnaliticos[i][5]*ex;
		double mdeltab_tt=2*coeficientesNaoAnaliticos[i][1]*pow(mdelta,coeficientesNaoAnaliticos[i][1]-1)+4*pow(fi,2)*coeficientesNaoAnaliticos[i][1]*(coeficientesNaoAnaliticos[i][1]-1)*pow(mdelta,coeficientesNaoAnaliticos[i][1]-2);
		
		fResidual_tt+=coeficientesNaoAnaliticos[i][3]*delta*(2*mdeltab_t*ex_t+mdeltab_tt*ex+pow(mdelta,coeficientesNaoAnaliticos[i][1])*ex_tt);
	}
}
void CHelmholtz::FR_ttt()
{
	fResidual_ttt=0;
	for(int i=0;i<numeroCoeficientes[1];i++){
		fResidual_ttt+=coeficientesPolinomio[i][2]*coeficientesPolinomio[i][1]*(coeficientesPolinomio[i][1]-1)*(coeficientesPolinomio[i][1]-2)*pow(delta,coeficientesPolinomio[i][0])*pow(tau,coeficientesPolinomio[i][1]-3);
	}
	for(int i=0;i<numeroCoeficientes[2];i++){
		fResidual_ttt+=coeficientesExponenciais[i][3]*coeficientesExponenciais[i][2]*(coeficientesExponenciais[i][2]-1)*(coeficientesExponenciais[i][2]-2)*pow(delta,coeficientesExponenciais[i][1])*pow(tau,coeficientesExponenciais[i][2]-3)*exp(-pow(delta,coeficientesExponenciais[i][0]));
	}
	for(int i=0;i<numeroCoeficientes[3];i++){
		double a=coeficientesGaussianos[i][2]*pow(delta,coeficientesGaussianos[i][0])*pow(tau,coeficientesGaussianos[i][1]);
		double b=exp(-coeficientesGaussianos[i][3]*pow(delta-coeficientesGaussianos[i][6],2)-coeficientesGaussianos[i][4]*pow(tau-coeficientesGaussianos[i][5],2));
		double c=coeficientesGaussianos[i][1]*pow(tau,-3)+(coeficientesGaussianos[i][1]/tau-2*coeficientesGaussianos[i][4]*(tau-coeficientesGaussianos[i][5]))*(pow(coeficientesGaussianos[i][1]/tau-2*coeficientesGaussianos[i][4]*(tau-coeficientesGaussianos[i][5]),2)-3*(coeficientesGaussianos[i][1]/pow(tau,2)+2*coeficientesGaussianos[i][4]));
		fResidual_ttt+=a*b*c;//erro
}
	for(int i=0;i<numeroCoeficientes[4];i++){
		double fi=(1-tau)+coeficientesNaoAnaliticos[i][6]*pow(pow((delta-1),2),(1/(2*coeficientesNaoAnaliticos[i][7])));
		double mdelta=pow(fi,2)+coeficientesNaoAnaliticos[i][2]*pow(pow((delta-1),2),coeficientesNaoAnaliticos[i][0]);
		double ex=exp(-(coeficientesNaoAnaliticos[i][4]*pow((delta-1),2)+coeficientesNaoAnaliticos[i][5]*pow((tau-1),2)));
		double mdeltab_t=-2*fi*coeficientesNaoAnaliticos[i][1]*pow(mdelta,coeficientesNaoAnaliticos[i][1]-1);
		double ex_t=-2*coeficientesNaoAnaliticos[i][5]*(tau-1)*ex;
		double ex_tt=(2*coeficientesNaoAnaliticos[i][5]*pow(tau-1,2)-1)*2*coeficientesNaoAnaliticos[i][5]*ex;
		double mdeltab_tt=2*coeficientesNaoAnaliticos[i][1]*pow(mdelta,coeficientesNaoAnaliticos[i][1]-1)+4*pow(fi,2)*coeficientesNaoAnaliticos[i][1]*(coeficientesNaoAnaliticos[i][1]-1)*pow(mdelta,coeficientesNaoAnaliticos[i][1]-2);
		double mdeltab_ttt=-12*coeficientesNaoAnaliticos[i][1]*(coeficientesNaoAnaliticos[i][1]-1)*fi*pow(mdelta,coeficientesNaoAnaliticos[i][1]-2)-8*coeficientesNaoAnaliticos[i][1]*(coeficientesNaoAnaliticos[i][1]-1)*(coeficientesNaoAnaliticos[i][1]-2)*pow(fi,3)*pow(mdelta,coeficientesNaoAnaliticos[i][1]-3);
		double ex_ttt=2*coeficientesNaoAnaliticos[i][5]*ex_t*(2*coeficientesNaoAnaliticos[i][5]*pow(tau-1,2)-1)+8*pow(coeficientesNaoAnaliticos[i][5],2)*(tau-1)*ex;
		fResidual_ttt+=coeficientesNaoAnaliticos[i][3]*delta*(mdeltab_ttt*ex+3*mdeltab_tt*ex_t+3*mdeltab_t*ex_tt+pow(mdelta,coeficientesNaoAnaliticos[i][1])*ex_ttt);
	}
}
void CHelmholtz::FI()
{
	fIdeal=log(delta)+coeficientesIdeais1[0]+coeficientesIdeais1[1]*tau+coeficientesIdeais1[2]*log(tau);
	for(int i=0;i<numeroCoeficientes[0];i++){
		fIdeal+=coeficientesIdeais2[i][0]*log(1-exp(-coeficientesIdeais2[i][1]*tau));
	}
	if(tCritica==126.192)fIdeal+=coeficientesIdeais1[3]/tau+coeficientesIdeais1[4]/pow(tau,2)+coeficientesIdeais1[5]/pow(tau,3);
}
void CHelmholtz::FI_t()
{
	fIdeal_t=coeficientesIdeais1[1]+(coeficientesIdeais1[2]/tau);
	for(int i=0;i<numeroCoeficientes[0];i++){
		fIdeal_t+=coeficientesIdeais2[i][0]*coeficientesIdeais2[i][1]*(pow((1-exp(-coeficientesIdeais2[i][1]*tau)),-1)-1);
	}
	if(tCritica==126.192)fIdeal_t-=coeficientesIdeais1[3]/pow(tau,2)+2*coeficientesIdeais1[4]/pow(tau,3)+3*coeficientesIdeais1[5]/pow(tau,4);
}
void CHelmholtz::FI_tt()
{
	fIdeal_tt=-coeficientesIdeais1[2]*pow(tau,-2);
	for(int i=0;i<numeroCoeficientes[0];i++){
		fIdeal_tt-=coeficientesIdeais2[i][0]*pow(coeficientesIdeais2[i][1],2)*exp(-coeficientesIdeais2[i][1]*tau)*pow(1-exp(-coeficientesIdeais2[i][1]*tau),-2);
	}
	if(tCritica==126.192)fIdeal_tt+=2*coeficientesIdeais1[3]/pow(tau,3)+6*coeficientesIdeais1[4]/pow(tau,4)+12*coeficientesIdeais1[5]/pow(tau,5);
}
void CHelmholtz::FI_ttt()
{
	fIdeal_ttt=2*coeficientesIdeais1[2]*pow(tau,-3);
	for(int i=0;i<numeroCoeficientes[0];i++){
		fIdeal_ttt+=coeficientesIdeais2[i][0]*pow(coeficientesIdeais2[i][1],3)*exp(-coeficientesIdeais2[i][1]*tau)*pow(1-exp(-coeficientesIdeais2[i][1]*tau),-2)*(1+2*exp(-coeficientesIdeais2[i][1]*tau)*(1-exp(-coeficientesIdeais2[i][1]*tau)));
	}
	if(tCritica==126.192)fIdeal_tt-=6*coeficientesIdeais1[3]/pow(tau,4)+24*coeficientesIdeais1[4]/pow(tau,5)+60*coeficientesIdeais1[5]/pow(tau,6);
}
