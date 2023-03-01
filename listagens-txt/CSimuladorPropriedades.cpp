#include "CSimuladorPropriedades.h"
#include <iostream>
#include <cmath>
CSimuladorPropriedades::CSimuladorPropriedades(std::string subs, double t, double d)
{
	if (subs=="H2O"){p_Helm=new CHelmholtzAgua;substancia.massaMolar=18;substancia.nome="Agua";}
	if (subs=="CH4"){p_Helm=new CHelmholtzMetano;substancia.massaMolar=16;substancia.nome="Metano";}
	if (subs=="C2H6"){p_Helm=new CHelmholtzEtano;substancia.massaMolar=30;substancia.nome="Etano";}	
	if (subs=="CO2"){p_Helm=new CHelmholtzDioxidoCarbono;substancia.massaMolar=44;substancia.nome="Dioxido de Carbono";}	
	if (subs=="nC4H10"){p_Helm=new CHelmholtzNbutano;substancia.massaMolar=58.12;substancia.nome="n-Butano";}	
	if (subs=="iC4H10"){p_Helm=new CHelmholtzIsobutano;substancia.massaMolar=58.12;substancia.nome="isoButano";}	
	if (subs=="N2"){p_Helm=new CHelmholtzNitrogenio;substancia.massaMolar=28.013;substancia.nome="Nitrogenio";}	
	substancia.temperatura=t;
	substancia.densidade=d;
	p_Helm->tau=p_Helm->tCritica/t;
	p_Helm->delta=d/p_Helm->dCritica;
	flag_derivadas=1;
}
CSimuladorPropriedades::CSimuladorPropriedades(std::string subs, double t, double d, int flag)
{
	if (subs=="H2O"){p_Helm=new CHelmholtzAgua;substancia.massaMolar=18.01528;substancia.nome="Agua";}
	if (subs=="CH4"){p_Helm=new CHelmholtzMetano;substancia.massaMolar=16.04;substancia.nome="Metano";}
	if (subs=="C2H6"){p_Helm=new CHelmholtzEtano;substancia.massaMolar=30.07;substancia.nome="Etano";}	
	if (subs=="CO2"){p_Helm=new CHelmholtzDioxidoCarbono;substancia.massaMolar=44.01;substancia.nome="Dioxido de Carbono";}	
	if (subs=="nC4H10"){p_Helm=new CHelmholtzNbutano;substancia.massaMolar=58.12;substancia.nome="n-Butano";}
	if (subs=="iC4H10"){p_Helm=new CHelmholtzIsobutano;substancia.massaMolar=58.12;substancia.nome="isoButano";}	
	if (subs=="N2"){p_Helm=new CHelmholtzNitrogenio;substancia.massaMolar=28.013;substancia.nome="Nitrogenio";}	
	substancia.temperatura=t;
	substancia.densidade=d;
	p_Helm->tau=p_Helm->tCritica/t;
	p_Helm->delta=d/p_Helm->dCritica;
	flag_derivadas=flag;
}
void CSimuladorPropriedades::Display()
{
	std::cout<<std::endl<<"Calculando propriedades para "<<substancia.nome<<" a T="<<substancia.temperatura<<" e D="<<substancia.densidade<<':'<<std::endl;
	substancia.Display();	
}
void CSimuladorPropriedades::Calculo_dp()
{
	if (substancia.pressao.d==0)
	{
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		if (p_Helm->fResidual_dd==0){p_Helm->FR_dd();}
		substancia.pressao.d=(1+2*p_Helm->delta*p_Helm->fResidual_d+pow(p_Helm->delta,2)*p_Helm->fResidual_dd)*substancia.temperatura*p_Helm->rEspecifico/100;
	}
	substancia.d_p=1/substancia.pressao.d;
}
void CSimuladorPropriedades::CalcularTudo()
{
	Pressao();
	Entalpia();
	Entropia();
	EnergiaInterna();
	EnergiaGibbs();
	CapCalorificaIsobarica();
	CapCalorificaIsovolumetrica();
	CoefJouleThomson();
	CoefEnforcamento();
	VelocidadeSom();
	CoefIsentropico();
}
void CSimuladorPropriedades::Pressao(int flag)
{
    int temp = flag_derivadas;
    Set_Flag(flag);
    Pressao();
    Set_Flag(temp);
}
void CSimuladorPropriedades::Pressao()
{
	int temp=flag_derivadas;
	if (temp>=8)temp-=8;
	if (temp>=4){
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		if (p_Helm->fResidual_dd==0){p_Helm->FR_dd();}
		temp-=4;
		}
	if (temp>=2){
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		if (p_Helm->fResidual_dt==0){p_Helm->FR_dt();}
		temp-=2;
		}
	if (temp>=1){if (p_Helm->fResidual_d==0){p_Helm->FR_d();}temp-=1;}
	temp=flag_derivadas;
	if (temp>=8)temp-=8;
	if (temp>=4){
		substancia.pressao.d=(1+2*p_Helm->delta*p_Helm->fResidual_d+pow(p_Helm->delta,2)*p_Helm->fResidual_dd)*substancia.temperatura*p_Helm->rEspecifico/100;
		temp-=4;
		}
	if (temp>=2){
		double x=substancia.densidade*p_Helm->rEspecifico*substancia.temperatura*(p_Helm->delta*p_Helm->fResidual_dt-((p_Helm->delta*p_Helm->fResidual_d+1)/p_Helm->tau))/100;
		substancia.pressao.t=-x*p_Helm->tau/substancia.temperatura;
		temp-=2;
		}
	if (temp>=1){
		substancia.pressao.valor=((1+(p_Helm->delta*p_Helm->fResidual_d))*substancia.densidade*substancia.temperatura*p_Helm->rEspecifico)/100;
		temp--;
		}
}
void CSimuladorPropriedades::Entalpia(int flag)
{
    int temp = flag_derivadas;
    Set_Flag(flag);
    Entalpia();
    Set_Flag(temp);
}
void CSimuladorPropriedades::Entalpia()
{
	int temp=flag_derivadas;
	if (temp>=8)temp-=8;
	if (temp>=4){
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		if (p_Helm->fResidual_dt==0){p_Helm->FR_dt();}
		if (p_Helm->fResidual_dd==0){p_Helm->FR_dd();} 
		temp-=4;
		}
	if (temp>=2){
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		if (p_Helm->fResidual_dt==0){p_Helm->FR_dt();}
		if (p_Helm->fResidual_tt==0){p_Helm->FR_tt();} 
		if (p_Helm->fIdeal_tt==0){p_Helm->FI_tt();} 
		temp-=2;}
	if (temp>=1){
		if (p_Helm->fResidual_t==0){p_Helm->FR_t();}
		if (p_Helm->fIdeal_t==0){p_Helm->FI_t();}
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		temp-=1;
		}
	temp=flag_derivadas;
	if (temp>=4){
		substancia.entalpia.d=p_Helm->tCritica*p_Helm->rEspecifico*(p_Helm->fResidual_dt+(p_Helm->fResidual_d+p_Helm->delta*p_Helm->fResidual_dd)/p_Helm->tau)/p_Helm->dCritica;
		if (temp>=8){
			if (substancia.d_p==0) Calculo_dp();
			substancia.entalpia.p=substancia.entalpia.d*substancia.d_p; 
			temp-=8;
			}
		temp-=4;
		}
	if (temp>=2){
		substancia.entalpia.t=-p_Helm->rEspecifico*(pow(p_Helm->tau,2)*(p_Helm->fIdeal_tt+p_Helm->fResidual_tt)+p_Helm->tau*p_Helm->delta*p_Helm->fResidual_dt-(p_Helm->delta*p_Helm->fResidual_d+1));
		temp-=2;
		}
	if (temp>=1){
		substancia.entalpia.valor=(1+p_Helm->tau*(p_Helm->fIdeal_t+p_Helm->fResidual_t)+p_Helm->delta*p_Helm->fResidual_d)*p_Helm->rEspecifico*substancia.temperatura;
		temp-=1;
		}
}void CSimuladorPropriedades::Entropia(int flag)
{
    int temp = flag_derivadas;
    Set_Flag(flag);
    Entropia();
    Set_Flag(temp);
}
void CSimuladorPropriedades::Entropia()
{
	int temp=flag_derivadas;
	if (temp>=8)temp-=8;
	if (temp>=4){
		if (p_Helm->fResidual_dt==0){p_Helm->FR_dt();}
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		temp-=4;
		}
	if (temp>=2){
		if (p_Helm->fResidual_tt==0){p_Helm->FR_tt();}
		if (p_Helm->fIdeal_tt==0){p_Helm->FI_tt();} 
		temp-=2;
		}
	if (temp>=1){
		if (p_Helm->fResidual_t==0){p_Helm->FR_t();}
		if (p_Helm->fIdeal_t==0){p_Helm->FI_t();}
		if (p_Helm->fResidual==0){p_Helm->FR();}
		if (p_Helm->fIdeal==0){p_Helm->FI();}
		temp-=1;
		}
	temp=flag_derivadas;
	if (temp>=4){
		substancia.entropia.d=p_Helm->rEspecifico*(p_Helm->tau*p_Helm->fResidual_dt-p_Helm->fResidual_d-pow(p_Helm->delta,-1))/p_Helm->dCritica;
		if (temp>=8){
			if (substancia.d_p==0) Calculo_dp();
			substancia.entropia.p=substancia.entropia.d*substancia.d_p; 
			temp-=8;
			}
		temp-=4;}
	if (temp>=2){
		substancia.entropia.t=-p_Helm->rEspecifico*pow(p_Helm->tau,2)*(p_Helm->fIdeal_tt+p_Helm->fResidual_tt)/substancia.temperatura;
		temp-=2;}
	if (temp>=1){
		substancia.entropia.valor=(p_Helm->tau*(p_Helm->fIdeal_t+p_Helm->fResidual_t)-(p_Helm->fIdeal+p_Helm->fResidual))*p_Helm->rEspecifico;
		temp-=1;}
}
void CSimuladorPropriedades::EnergiaGibbs(int flag)
{
    int temp = flag_derivadas;
    Set_Flag(flag);
    EnergiaGibbs();
    Set_Flag(temp);
}
void CSimuladorPropriedades::EnergiaGibbs()
{
	int temp=flag_derivadas;
	if (temp>=8)temp-=8;
	if (temp>=4){
		if (p_Helm->fResidual_dd==0){p_Helm->FR_dd();}
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		temp-=4;
		}
	if (temp>=2){
		if (p_Helm->fResidual_t==0){p_Helm->FR_t();}
		if (p_Helm->fResidual_dt==0){p_Helm->FR_dt();}
		if (p_Helm->fIdeal_t==0){p_Helm->FI_t();}
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		if (p_Helm->fResidual==0){p_Helm->FR();}
		if (p_Helm->fIdeal==0){p_Helm->FI();}
		temp-=2;
		}
	if (temp>=1){
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		if (p_Helm->fResidual==0){p_Helm->FR();}
		if (p_Helm->fIdeal==0){p_Helm->FI();}
		temp-=1;
		}
	temp=flag_derivadas;
	if (temp>=4){
		substancia.energiaGibbs.d=p_Helm->rEspecifico*substancia.temperatura*(pow(p_Helm->delta,-1)+2*p_Helm->fResidual_d+p_Helm->delta*p_Helm->fResidual_dd)/p_Helm->dCritica;
		if (temp>=8){
			if (substancia.d_p==0) Calculo_dp();
			substancia.energiaGibbs.p=substancia.energiaGibbs.d*substancia.d_p; 
			temp-=8;
			}
		temp-=4;}
	if (temp>=2){
		double x=p_Helm->tCritica*(p_Helm->fIdeal_t+p_Helm->fResidual_t+p_Helm->delta*p_Helm->fResidual_dt);
		x-=substancia.temperatura*(1+p_Helm->fIdeal+p_Helm->fResidual+p_Helm->delta*p_Helm->fResidual_d);
		substancia.energiaGibbs.t=-x*p_Helm->rEspecifico/substancia.temperatura;
		temp-=2;}
	if (temp>=1){substancia.energiaGibbs.valor=(1+p_Helm->fIdeal+p_Helm->fResidual+(p_Helm->delta*p_Helm->fResidual_d))*p_Helm->rEspecifico*substancia.temperatura;
		temp-=1;}
}
void CSimuladorPropriedades::EnergiaInterna(int flag)
{
    int temp = flag_derivadas;
    Set_Flag(flag);
    EnergiaInterna();
    Set_Flag(temp);
}
void CSimuladorPropriedades::EnergiaInterna()
{
	int temp=flag_derivadas;
	if (temp>=8)temp-=8;
	if (temp>=4){
		if (p_Helm->fResidual_dt==0){p_Helm->FR_dt();} 
		temp-=4;
		}
	if (temp>=2){
		if (p_Helm->fResidual_tt==0){p_Helm->FR_tt();}
		if (p_Helm->fIdeal_tt==0){p_Helm->FI_tt();} 
		temp-=2;
		}
	if (temp>=1){
		if (p_Helm->fResidual_t==0){p_Helm->FR_t();}
		if (p_Helm->fIdeal_t==0){p_Helm->FI_t();}
		temp-=1;
		}
	temp=flag_derivadas;
	if (temp>=4){
		substancia.energiaInterna.d=p_Helm->tCritica*p_Helm->rEspecifico*p_Helm->fResidual_dt/p_Helm->dCritica;	
		if (temp>=8){
			if (substancia.d_p==0) Calculo_dp();
			substancia.energiaInterna.p=substancia.energiaInterna.d*substancia.d_p; 
			temp-=8;
			}
		temp-=4;}
	if (temp>=2){
		substancia.energiaInterna.t=-p_Helm->tCritica*p_Helm->rEspecifico*(p_Helm->fResidual_tt+p_Helm->fIdeal_tt)*p_Helm->tau/substancia.temperatura;
		temp-=2;
		}
	if (temp>=1){
		substancia.energiaInterna.valor=p_Helm->tau*(p_Helm->fResidual_t+p_Helm->fIdeal_t)*p_Helm->rEspecifico*substancia.temperatura;
		temp-=1;
		}
}
void CSimuladorPropriedades::CapCalorificaIsovolumetrica(int flag)
{
    int temp = flag_derivadas;
    Set_Flag(flag);
    CapCalorificaIsovolumetrica();
    Set_Flag(temp);
}
void CSimuladorPropriedades::CapCalorificaIsovolumetrica()
{
	int temp=flag_derivadas;
	if (temp>=8)temp-=8;
	if (temp>=4){
		if (p_Helm->fResidual_dtt==0){p_Helm->FR_dtt();}
		temp-=4;
		}
	if (temp>=2){
		if (p_Helm->fResidual_ttt==0){p_Helm->FR_ttt();}
		if (p_Helm->fIdeal_ttt==0){p_Helm->FI_ttt();}
		if (p_Helm->fResidual_tt==0){p_Helm->FR_tt();}
		if (p_Helm->fIdeal_tt==0){p_Helm->FI_tt();}
		temp-=2;
		}
	if (temp>=1){
		if (p_Helm->fResidual_tt==0){p_Helm->FR_tt();}
		if (p_Helm->fIdeal_tt==0){p_Helm->FI_tt();}
		temp-=1;
		}
	temp=flag_derivadas;
	if (temp>=4){
		substancia.capCalorificaIsovolumetrica.d=-p_Helm->rEspecifico*pow(p_Helm->tau,2)*p_Helm->fResidual_dtt/p_Helm->dCritica;
		if (temp>=8){
			if (substancia.d_p==0) Calculo_dp();
			substancia.capCalorificaIsovolumetrica.p=substancia.capCalorificaIsovolumetrica.d*substancia.d_p; 
			temp-=8;
			}
		temp-=4;
		}
	if (temp>=2){
		substancia.capCalorificaIsovolumetrica.t=p_Helm->rEspecifico*pow(p_Helm->tau,2)*(p_Helm->tau*(p_Helm->fResidual_ttt+p_Helm->fIdeal_ttt)+2*(p_Helm->fResidual_tt+p_Helm->fIdeal_tt))/substancia.temperatura;
		temp-=2;}
	if (temp>=1){substancia.capCalorificaIsovolumetrica.valor=-p_Helm->tau*p_Helm->tau*(p_Helm->fResidual_tt+p_Helm->fIdeal_tt)*p_Helm->rEspecifico;
		temp-=1;
		}
}
void CSimuladorPropriedades::CapCalorificaIsobarica(int flag)
{
    int temp = flag_derivadas;
    Set_Flag(flag);
    CapCalorificaIsobarica();
    Set_Flag(temp);
}
void CSimuladorPropriedades::CapCalorificaIsobarica()
{
	int temp=flag_derivadas;
	if (temp>=8)temp-=8;
	if (temp>=4){
		if (p_Helm->fResidual_dd==0){p_Helm->FR_dd();}
		if (p_Helm->fResidual_ddt==0){p_Helm->FR_ddt();}
		if (p_Helm->fResidual_ddd==0){p_Helm->FR_ddd();}
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		if (p_Helm->fResidual_dtt==0){p_Helm->FR_dtt();}
		if (p_Helm->fResidual_dt==0){p_Helm->FR_dt();}
		temp-=4;
		}
	if (temp>=2){
		if (p_Helm->fResidual_dd==0){p_Helm->FR_dd();}
		if (p_Helm->fResidual_ddt==0){p_Helm->FR_ddt();}
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		if (p_Helm->fResidual_dtt==0){p_Helm->FR_dtt();}
		if (p_Helm->fResidual_dt==0){p_Helm->FR_dt();}
		if (substancia.capCalorificaIsovolumetrica.t==0)CapCalorificaIsovolumetrica();
		temp-=2;
		}
	if (temp>=1){
		if (p_Helm->fResidual_tt==0){p_Helm->FR_tt();}
		if (p_Helm->fIdeal_tt==0){p_Helm->FI_tt();}
		if (p_Helm->fResidual_dt==0){p_Helm->FR_dt();}
		if (p_Helm->fResidual_dd==0){p_Helm->FR_dd();}
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		temp-=1;
		}
	temp=flag_derivadas;
	if (temp>=4){
		double p1=-pow(p_Helm->tau,2)*p_Helm->fResidual_dtt;
		double den=1+2*p_Helm->delta*p_Helm->fResidual_d+pow(p_Helm->delta,2)*p_Helm->fResidual_dd;
		double p2=(p_Helm->fResidual_d+p_Helm->delta*p_Helm->fResidual_dd-p_Helm->tau*p_Helm->fResidual_dt-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_ddt)*2*(1+p_Helm->delta*p_Helm->fResidual_d-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dt)*den;
		double p3=(2*p_Helm->fResidual_d+4*p_Helm->delta*p_Helm->fResidual_dd+pow(p_Helm->delta,2)*p_Helm->fResidual_ddd)*pow(1+p_Helm->delta*p_Helm->fResidual_d-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dt,2);
		double x=p1+(p2-p3)/pow(den,2);
		substancia.capCalorificaIsobarica.d=x*p_Helm->rEspecifico/p_Helm->dCritica;
		if (temp>=8){
			if (substancia.d_p==0) Calculo_dp();
			substancia.capCalorificaIsobarica.p=substancia.capCalorificaIsobarica.d*substancia.d_p; 
			temp-=8;
			}
		temp-=4;
		}
	if (temp>=2){
		double den=1+2*p_Helm->delta*p_Helm->fResidual_d+pow(p_Helm->delta,2)*p_Helm->fResidual_dd;
		double p1=-2*p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dtt*(1+p_Helm->delta*p_Helm->fResidual_d-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dt)*den;
		double p2=(2*p_Helm->delta*p_Helm->fResidual_dt+pow(p_Helm->delta,2)*p_Helm->fResidual_ddt)*pow(1+p_Helm->delta*p_Helm->fResidual_d-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dt,2);
		double f=p_Helm->rEspecifico*(p1-p2)/pow(den,2);
		substancia.capCalorificaIsobarica.t=substancia.capCalorificaIsovolumetrica.t-f*p_Helm->tau/substancia.temperatura;
		temp-=2;
		}
	if (temp>=1){
		double x=-p_Helm->tau*p_Helm->tau*(p_Helm->fIdeal_tt+p_Helm->fResidual_tt);
		x+=pow(1+p_Helm->delta*p_Helm->fResidual_d-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dt,2)/(1+2*p_Helm->delta*p_Helm->fResidual_d+p_Helm->fResidual_dd*pow(p_Helm->delta,2));
		substancia.capCalorificaIsobarica.valor=x*p_Helm->rEspecifico;
		temp-=1;
		}
}
void CSimuladorPropriedades::VelocidadeSom(int flag)
{
    int temp = flag_derivadas;
    Set_Flag(flag);
    VelocidadeSom();
    Set_Flag(temp);
}
void CSimuladorPropriedades::VelocidadeSom()
{
	int temp=flag_derivadas;
	if (temp>=8)temp-=8;
	if (temp>=4){
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		if (p_Helm->fResidual_dd==0){p_Helm->FR_dd();}
		if (p_Helm->fResidual_ddd==0){p_Helm->FR_ddd();}
		if (p_Helm->fResidual_dt==0){p_Helm->FR_dt();}
		if (p_Helm->fResidual_tt==0){p_Helm->FR_tt();}
		if (p_Helm->fResidual_dt==0){p_Helm->FR_ddt();}
		if (p_Helm->fResidual_tt==0){p_Helm->FR_dtt();}
		temp-=4;
		}
	if (temp>=2){
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		if (p_Helm->fResidual_dd==0){p_Helm->FR_dd();}
		if (p_Helm->fResidual_dt==0){p_Helm->FR_dt();}
		if (p_Helm->fResidual_tt==0){p_Helm->FR_tt();}
		if (p_Helm->fIdeal_tt==0){p_Helm->FI_tt();}
		if (p_Helm->fResidual_ddt==0){p_Helm->FR_ddt();}
		if (p_Helm->fResidual_dtt==0){p_Helm->FR_dtt();}
		if (p_Helm->fResidual_ttt==0){p_Helm->FR_ttt();}
		if (p_Helm->fIdeal_ttt==0){p_Helm->FI_ttt();}
		temp-=2;
		}
	if (temp>=1){
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		if (p_Helm->fResidual_dd==0){p_Helm->FR_dd();}
		if (p_Helm->fResidual_dt==0){p_Helm->FR_dt();}
		if (p_Helm->fResidual_tt==0){p_Helm->FR_tt();}
		if (p_Helm->fIdeal_tt==0){p_Helm->FI_tt();}
		temp-=1;
		}
	temp=flag_derivadas;
	if (temp>=4){
		if(substancia.velocidadeSom.valor==0){
			double x=1+2*p_Helm->delta*p_Helm->fResidual_d+pow(p_Helm->delta,2)*p_Helm->fResidual_dd;
			x-=pow(1+p_Helm->delta*p_Helm->fResidual_d-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dt,2)/(pow(p_Helm->tau,2)*(p_Helm->fResidual_tt+p_Helm->fIdeal_tt));
			substancia.velocidadeSom.valor=sqrt(x*p_Helm->rEspecifico*substancia.temperatura)*31.623164418947891;
			}
		double den=pow(p_Helm->tau,2)*(p_Helm->fIdeal_tt+p_Helm->fResidual_tt);
		double p1=2*p_Helm->fResidual_d+4*p_Helm->delta*p_Helm->fResidual_dd+pow(p_Helm->delta,2)*p_Helm->fResidual_ddd;
		double p2=(p_Helm->fResidual_d+p_Helm->delta*p_Helm->fResidual_dd-p_Helm->tau*p_Helm->fResidual_dt-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_ddt)*2*(1+p_Helm->delta*p_Helm->fResidual_d-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dt)*den;
		double p3=pow(p_Helm->tau,2)*p_Helm->fResidual_dtt*pow(1+p_Helm->delta*p_Helm->fResidual_d-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dt,2);
		substancia.velocidadeSom.d=1000*p_Helm->rEspecifico*substancia.temperatura*(p1-(p2-p3)/pow(den,2))/(2*p_Helm->dCritica*substancia.velocidadeSom.valor);
		if (temp>=8){
			if (substancia.d_p==0) Calculo_dp();
			substancia.velocidadeSom.p=substancia.velocidadeSom.d*substancia.d_p; 
			temp-=8;
			}
		temp-=4;
		}
	if (temp>=2){
		if(substancia.velocidadeSom.valor==0){
			double x=1+2*p_Helm->delta*p_Helm->fResidual_d+pow(p_Helm->delta,2)*p_Helm->fResidual_dd;
			x-=pow(1+p_Helm->delta*p_Helm->fResidual_d-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dt,2)/(pow(p_Helm->tau,2)*(p_Helm->fResidual_tt+p_Helm->fIdeal_tt));
			substancia.velocidadeSom.valor=sqrt(x*p_Helm->rEspecifico*substancia.temperatura)*31.623164418947891;
			}
		double den=pow(p_Helm->tau,2)*(p_Helm->fIdeal_tt+p_Helm->fResidual_tt);
		double p1=(pow(1+p_Helm->delta*p_Helm->fResidual_d-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dt,2)/den-(1+2*p_Helm->delta*p_Helm->fResidual_d+pow(p_Helm->delta,2)*p_Helm->fResidual_dd))/p_Helm->tau;
		double p2=2*p_Helm->delta*p_Helm->fResidual_dt+pow(p_Helm->delta,2)*p_Helm->fResidual_ddt;
		double p3=p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dtt*2*(1+p_Helm->delta*p_Helm->fResidual_d-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dt)*den;
		double p4=(2*p_Helm->tau*(p_Helm->fIdeal_tt+p_Helm->fResidual_tt)+pow(p_Helm->tau,2)*(p_Helm->fIdeal_ttt+p_Helm->fResidual_ttt))*pow(1+p_Helm->delta*p_Helm->fResidual_d-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dt,2);
		substancia.velocidadeSom.t=-1000*p_Helm->tau*p_Helm->rEspecifico*(p1+p2+(p3+p4)/pow(den,2))/(2*substancia.velocidadeSom.valor);
		temp-=2;
		}
	if (temp>=1&&substancia.velocidadeSom.valor==0){
		double x=1+2*p_Helm->delta*p_Helm->fResidual_d+pow(p_Helm->delta,2)*p_Helm->fResidual_dd;
		x-=pow(1+p_Helm->delta*p_Helm->fResidual_d-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dt,2)/(pow(p_Helm->tau,2)*(p_Helm->fResidual_tt+p_Helm->fIdeal_tt));
		substancia.velocidadeSom.valor=sqrt(x*p_Helm->rEspecifico*substancia.temperatura)*31.623164418947891;
		temp-=1;
		}
}
void CSimuladorPropriedades::CoefEnforcamento(int flag)
{
    int temp = flag_derivadas;
    Set_Flag(flag);
    CoefEnforcamento();
    Set_Flag(temp);
}
void CSimuladorPropriedades::CoefEnforcamento()
{
	int temp=flag_derivadas;
	if (temp>=8)temp-=8;
	if (temp>=4){
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		if (p_Helm->fResidual_dd==0){p_Helm->FR_dd();}
		if (p_Helm->fResidual_dt==0){p_Helm->FR_dt();}
		if (p_Helm->fResidual_ddt==0){p_Helm->FR_ddt();}
		if (p_Helm->fResidual_ddd==0){p_Helm->FR_ddd();}
		temp-=4;
		}
	if (temp>=2){
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		if (p_Helm->fResidual_dd==0){p_Helm->FR_dd();}
		if (p_Helm->fResidual_dt==0){p_Helm->FR_dt();}
		if (p_Helm->fResidual_ddt==0){p_Helm->FR_ddt();}
		if (p_Helm->fResidual_dtt==0){p_Helm->FR_dtt();}
		temp-=2;
		}
	if (temp>=1){
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		if (p_Helm->fResidual_dd==0){p_Helm->FR_dd();}
		if (p_Helm->fResidual_dt==0){p_Helm->FR_dt();}
		temp-=1;
		}
	temp=flag_derivadas;
	if (temp>=4){
		double num=1+p_Helm->delta*p_Helm->fResidual_d-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dt;
		double den=1+2*p_Helm->delta*p_Helm->fResidual_d+pow(p_Helm->delta,2)*p_Helm->fResidual_dd;
		double p1=(num/den-1)/p_Helm->delta;
		double p21=p_Helm->fResidual_d+p_Helm->delta*p_Helm->fResidual_dd-p_Helm->tau*p_Helm->fResidual_dt-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_ddt;
		double p22=2*p_Helm->fResidual_d+4*p_Helm->delta*p_Helm->fResidual_dd+pow(p_Helm->delta,2)*p_Helm->fResidual_ddd;
		double p2=(p22*num-p21*den)/pow(den,2);
		substancia.coefEnforcamento.d=(p1+p2)/(substancia.densidade*p_Helm->dCritica);
		if (temp>=8){
			if (substancia.d_p==0) Calculo_dp();
			substancia.coefEnforcamento.p=substancia.coefEnforcamento.d*substancia.d_p; 
			temp-=8;
			}
		temp-=4;
		}
	if (temp>=2){
		double num=1+p_Helm->delta*p_Helm->fResidual_d-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dt;
		double den=1+2*p_Helm->delta*p_Helm->fResidual_d+pow(p_Helm->delta,2)*p_Helm->fResidual_dd;
		double x=(p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dtt*den+(2*p_Helm->delta*p_Helm->fResidual_dt+pow(p_Helm->delta,2)*p_Helm->fResidual_ddt)*num)/(pow(den,2)*substancia.densidade);
		substancia.coefEnforcamento.t=-x*p_Helm->tau/substancia.temperatura;
		temp-=2;
		}
	if (temp>=1){
		substancia.coefEnforcamento.valor=1-(1+p_Helm->delta*p_Helm->fResidual_d-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dt)/(1+2*p_Helm->delta*p_Helm->fResidual_d+pow(p_Helm->delta,2)*p_Helm->fResidual_dd);
		substancia.coefEnforcamento.valor/=substancia.densidade;
		temp-=1;
		}
}
void CSimuladorPropriedades::CoefJouleThomson(int flag)
{
    int temp = flag_derivadas;
    Set_Flag(flag);
    CoefJouleThomson();
    Set_Flag(temp);
}
void CSimuladorPropriedades::CoefJouleThomson()
{
	int temp=flag_derivadas;
	if (temp>=8)temp-=8;
	if (temp>=4){
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		if (p_Helm->fResidual_dd==0){p_Helm->FR_dd();}
		if (p_Helm->fResidual_dt==0){p_Helm->FR_dt();}
		if (p_Helm->fResidual_ddt==0){p_Helm->FR_ddt();}
		if (p_Helm->fResidual_dtt==0){p_Helm->FR_dtt();}
		if (p_Helm->fResidual_tt==0){p_Helm->FR_tt();}
		if (p_Helm->fIdeal_tt==0){p_Helm->FI_tt();}
		temp-=4;
		}
	if (temp>=2){
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		if (p_Helm->fResidual_dd==0){p_Helm->FR_dd();}
		if (p_Helm->fResidual_dt==0){p_Helm->FR_dt();}
		if (p_Helm->fResidual_ddt==0){p_Helm->FR_ddt();}
		if (p_Helm->fResidual_dtt==0){p_Helm->FR_dtt();}
		if (p_Helm->fResidual_tt==0){p_Helm->FR_tt();}
		if (p_Helm->fIdeal_tt==0){p_Helm->FI_tt();}
		if (p_Helm->fResidual_ttt==0){p_Helm->FR_ttt();}
		if (p_Helm->fIdeal_ttt==0){p_Helm->FI_ttt();}
		temp-=2;
		}
	if (temp>=1){
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		if (p_Helm->fResidual_dd==0){p_Helm->FR_dd();}
		if (p_Helm->fResidual_dt==0){p_Helm->FR_dt();}
		if (p_Helm->fResidual_tt==0){p_Helm->FR_tt();}
		if (p_Helm->fIdeal_tt==0){p_Helm->FI_tt();}
		temp-=1;
		}
	temp=flag_derivadas;
	if (temp>=4){
		double fdt=p_Helm->fResidual_dt;
		double t=p_Helm->tau; double d=p_Helm->delta;
		double den=pow(1+d*p_Helm->fResidual_d-d*t*fdt,2)-pow(t,2)*(p_Helm->fIdeal_tt+p_Helm->fResidual_tt)*(1+2*d*p_Helm->fResidual_d+pow(d,2)*p_Helm->fResidual_dd);
		double num=d*p_Helm->fResidual_d+pow(d,2)*p_Helm->fResidual_dd+d*t*fdt;
		double p1=num/(den*d);
		double p2=p_Helm->fResidual_d+3*d*p_Helm->fResidual_dd+pow(d,2)*p_Helm->fResidual_dd+t*fdt+d*t*p_Helm->fResidual_ddt;
		double p31=(p_Helm->fResidual_d+d*p_Helm->fResidual_dd-t*fdt-d*t*p_Helm->fResidual_ddt)*2*(1+d*p_Helm->fResidual_d-d*t*fdt);
		double p32=pow(t,2)*p_Helm->fResidual_dtt*(1+2*d*p_Helm->fResidual_d+pow(d,2)*p_Helm->fResidual_dd);
		double p33=pow(t,2)*(p_Helm->fResidual_tt+p_Helm->fIdeal_tt)*(2*p_Helm->fResidual_d+4*d*p_Helm->fResidual_dd+pow(d,2)*p_Helm->fResidual_dd);
		double p3=p31-p32-p33;
		double x=(p1-(p2*den-p3*num)/pow(den,2))/(p_Helm->rEspecifico*substancia.densidade);
		substancia.coefJouleThomson.d=x*1000/p_Helm->dCritica;
		if (temp>=8){
			if (substancia.d_p==0) Calculo_dp();
			substancia.coefJouleThomson.p=substancia.coefJouleThomson.d*substancia.d_p; 
			temp-=8;
			}
		temp-=4;
		}
	if (temp>=2){
		double fdt=p_Helm->fResidual_dt;
		double t=p_Helm->tau; double d=p_Helm->delta;
		double den=pow(1+d*p_Helm->fResidual_d-d*t*fdt,2)-pow(t,2)*(p_Helm->fIdeal_tt+p_Helm->fResidual_tt)*(1+2*d*p_Helm->fResidual_d+pow(d,2)*p_Helm->fResidual_dd);
		double num=d*p_Helm->fResidual_d+pow(d,2)*p_Helm->fResidual_dd+d*t*fdt;
		double p1=2*d*fdt+pow(d,2)*p_Helm->fResidual_ddt+d*t*p_Helm->fResidual_dtt;
		double p21=-2*t*(p_Helm->fIdeal_tt+p_Helm->fResidual_tt)*(1+2*d*p_Helm->fResidual_d+pow(d,2)*p_Helm->fResidual_dd);
		double p22=-pow(t,2)*(p_Helm->fResidual_ttt+p_Helm->fIdeal_ttt)*(1+2*d*p_Helm->fResidual_d+pow(d,2)*p_Helm->fResidual_dd);
		double p23=-pow(t,2)*(p_Helm->fResidual_tt+p_Helm->fIdeal_tt)*(2*d*fdt+pow(d,2)*p_Helm->fResidual_ddt);
		double p2=-2*d*t*p_Helm->fResidual_dtt*(1+d*p_Helm->fResidual_d-d*t*fdt)+(p21+p22+p23);
		double x=-(p1*den-p2*num)/(pow(den,2)*p_Helm->rEspecifico*substancia.densidade);
		substancia.coefJouleThomson.t=-x*t*1000/substancia.temperatura;
		temp-=2;
		}
	if (temp>=1){
		double x=pow(1+p_Helm->delta*p_Helm->fResidual_d-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dt,2);
		x-=pow(p_Helm->tau,2)*(p_Helm->fResidual_tt+p_Helm->fIdeal_tt)*(1+2*p_Helm->delta*p_Helm->fResidual_d+pow(p_Helm->delta,2)*p_Helm->fResidual_dd);
		substancia.coefJouleThomson.valor=-(p_Helm->delta*p_Helm->fResidual_d+pow(p_Helm->delta,2)*p_Helm->fResidual_dd+p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dt)/x;
		substancia.coefJouleThomson.valor*=1000/(p_Helm->rEspecifico*substancia.densidade);
		temp-=1;
		}
}
void CSimuladorPropriedades::CoefIsentropico(int flag)
{
    int temp = flag_derivadas;
    Set_Flag(flag);
    CoefIsentropico();
    Set_Flag(temp);
}
void CSimuladorPropriedades::CoefIsentropico()
{
	int temp=flag_derivadas;
	if (temp>=8)temp-=8;
	if (temp>=4){
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		if (p_Helm->fResidual_dd==0){p_Helm->FR_dd();}
		if (p_Helm->fResidual_dt==0){p_Helm->FR_dt();}
		if (p_Helm->fResidual_ddd==0){p_Helm->FR_ddd();}
		if (p_Helm->fResidual_dtt==0){p_Helm->FR_dtt();}
		if (p_Helm->fResidual_tt==0){p_Helm->FR_tt();}
		if (p_Helm->fIdeal_tt==0){p_Helm->FI_tt();}
		temp-=4;
		}
	if (temp>=2){
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		if (p_Helm->fResidual_dd==0){p_Helm->FR_dd();}
		if (p_Helm->fResidual_dt==0){p_Helm->FR_dt();}
		if (p_Helm->fResidual_ddt==0){p_Helm->FR_ddt();}
		if (p_Helm->fResidual_dtt==0){p_Helm->FR_dtt();}
		if (p_Helm->fResidual_tt==0){p_Helm->FR_tt();}
		if (p_Helm->fIdeal_tt==0){p_Helm->FI_tt();}
		if (p_Helm->fResidual_ttt==0){p_Helm->FR_ttt();}
		if (p_Helm->fIdeal_ttt==0){p_Helm->FI_ttt();}
		temp-=2;
		}
	if (temp>=1){
		if (p_Helm->fResidual_d==0){p_Helm->FR_d();}
		if (p_Helm->fResidual_dd==0){p_Helm->FR_dd();}
		if (p_Helm->fResidual_dt==0){p_Helm->FR_dt();}
		if (p_Helm->fResidual_tt==0){p_Helm->FR_tt();}
		if (p_Helm->fIdeal_tt==0){p_Helm->FI_tt();}
		temp-=1;
		}
	temp=flag_derivadas;
	if (temp>=4){
		double t=p_Helm->tau;double d=p_Helm->delta;
		double num=1+d*p_Helm->fResidual_d-d*t*p_Helm->fResidual_dt;
		double den=pow(num,2)-(pow(t,2)*(p_Helm->fResidual_tt+p_Helm->fIdeal_tt)*(1+2*d*p_Helm->fResidual_d+pow(d,2)*p_Helm->fResidual_dd));
		double p1=p_Helm->fResidual_d+d*p_Helm->fResidual_dd-t*p_Helm->fResidual_dt-d*t*p_Helm->fResidual_dtt;
		double p21=2*p1*num-pow(t,2)*p_Helm->fResidual_dtt*(1+2*d*p_Helm->fResidual_d+pow(d,2)*p_Helm->fResidual_dd);
		double p22=pow(t,2)*(p_Helm->fResidual_tt+p_Helm->fIdeal_tt)*(4*d*p_Helm->fResidual_dd+2*p_Helm->fResidual_d+pow(d,2)*p_Helm->fResidual_ddd);
		double p2=p21-p22;
		double x=(p1*den-p2*num)/pow(den,2);
		double y=x-num/(den*d);
		substancia.coefIsentropico.d=y/(p_Helm->dCritica*substancia.densidade*p_Helm->rEspecifico);
		if (temp>=8){
			if (substancia.d_p==0) Calculo_dp();
			substancia.coefIsentropico.p=substancia.coefIsentropico.d*substancia.d_p; 
			temp-=8;
			}
		temp-=4;
		}
	if (temp>=2){
		double t=p_Helm->tau;double d=p_Helm->delta;
		double num=1+d*p_Helm->fResidual_d-d*t*p_Helm->fResidual_dt;
		double den=pow(num,2)-(pow(t,2)*(p_Helm->fResidual_tt+p_Helm->fIdeal_tt)*(1+2*d*p_Helm->fResidual_d+pow(d,2)*p_Helm->fResidual_dd));
		double p11=-2*d*t*p_Helm->fResidual_dtt*num;
		double p12=2*t*(p_Helm->fResidual_tt+p_Helm->fIdeal_tt)*(1+2*d*p_Helm->fResidual_d+pow(d,2)*p_Helm->fResidual_dd);
		double p13=pow(t,2)*(p_Helm->fResidual_ttt+p_Helm->fIdeal_ttt)*(1+2*d*p_Helm->fResidual_d+pow(d,2)*p_Helm->fResidual_dd);
		double p14=pow(t,2)*(p_Helm->fResidual_tt+p_Helm->fIdeal_tt)*(2*d*p_Helm->fResidual_dt+pow(d,2)*p_Helm->fResidual_ddt);
		double p1=p11-(p12+p13+p14);
		double x=(-d*t*p_Helm->fResidual_dtt*den-p1*num)/(p_Helm->rEspecifico*substancia.densidade*pow(den,2));
		substancia.coefIsentropico.t=-x*t/substancia.temperatura;
		temp-=2;
		}
	if (temp>=1){
		double x=pow(1+p_Helm->delta*p_Helm->fResidual_d-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dt,2);
		x-=pow(p_Helm->tau,2)*(p_Helm->fResidual_tt+p_Helm->fIdeal_tt)*(1+2*p_Helm->delta*p_Helm->fResidual_d+pow(p_Helm->delta,2)*p_Helm->fResidual_dd);
		substancia.coefIsentropico.valor=(1+p_Helm->delta*p_Helm->fResidual_d-p_Helm->delta*p_Helm->tau*p_Helm->fResidual_dt)/x;
		substancia.coefIsentropico.valor/=(p_Helm->rEspecifico*substancia.densidade);
		temp-=1;
		}
}
