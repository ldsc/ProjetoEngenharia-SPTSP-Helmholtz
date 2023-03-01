#include "CSubstancia.h"
#include <iostream>
void CSubstancia::Display()
{
	if (pressao.valor!=0){
		std::cout<<"***************************************";
		std::cout<<std::endl<<"Pressao: "<<pressao.valor;
		if(pressao.t!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a temperatura = "<<pressao.t;}
		if(pressao.d!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a densidade = "<<pressao.d;}
		std::cout<<std::endl;		
	}	
	if (entalpia.valor!=0){
		std::cout<<"***************************************";
		std::cout<<std::endl<<"Entalpia: "<<entalpia.valor;
		if(entalpia.t!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a temperatura = "<<entalpia.t;}
		if(entalpia.d!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a densidade = "<<entalpia.d;}
		if(entalpia.p!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a pressao = "<<entalpia.p;}
		std::cout<<std::endl;		
	}		
	if (entropia.valor!=0){
		std::cout<<"***************************************";
		std::cout<<std::endl<<"Entropia: "<<entropia.valor;
		if(entropia.t!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a temperatura = "<<entropia.t;}
		if(entropia.d!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a densidade = "<<entropia.d;}
		if(entropia.p!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a pressao = "<<entropia.p;}
		std::cout<<std::endl;		
	}
	if (energiaInterna.valor!=0){
		std::cout<<"***************************************";
		std::cout<<std::endl<<"Energia Interna: "<<energiaInterna.valor;
		if(energiaInterna.t!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a temperatura = "<<energiaInterna.t;}
		if(energiaInterna.d!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a densidade = "<<energiaInterna.d;}
		if(energiaInterna.p!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a pressao = "<<energiaInterna.p;}
		std::cout<<std::endl;		
	}
	if (energiaGibbs.valor!=0){
		std::cout<<"***************************************";
		std::cout<<std::endl<<"Energia de Gibbs: "<<energiaGibbs.valor;
		if(energiaGibbs.t!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a temperatura = "<<energiaGibbs.t;}
		if(energiaGibbs.d!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a densidade = "<<energiaGibbs.d;}
		if(energiaGibbs.p!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a pressao = "<<energiaGibbs.p;}
		std::cout<<std::endl;		
	}		
	if (capCalorificaIsobarica.valor!=0){
		std::cout<<"***************************************";
		std::cout<<std::endl<<"Capacidade Calorifica Isobarica: "<<capCalorificaIsobarica.valor;
		if(capCalorificaIsobarica.t!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a temperatura = "<<capCalorificaIsobarica.t;}
		if(capCalorificaIsobarica.d!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a densidade = "<<capCalorificaIsobarica.d;}
		if(capCalorificaIsobarica.p!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a pressao = "<<capCalorificaIsobarica.p;}
		std::cout<<std::endl;		
	}	
	if (capCalorificaIsovolumetrica.valor!=0){
		std::cout<<"***************************************";
		std::cout<<std::endl<<"Capacidade Calorifica Isovolumetrica: "<<capCalorificaIsovolumetrica.valor;
		if(capCalorificaIsovolumetrica.t!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a temperatura = "<<capCalorificaIsovolumetrica.t;}
		if(capCalorificaIsovolumetrica.d!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a densidade = "<<capCalorificaIsovolumetrica.d;}
		if(capCalorificaIsovolumetrica.p!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a pressao = "<<capCalorificaIsovolumetrica.p;}
		std::cout<<std::endl;		
	}
	if (coefJouleThomson.valor!=0){
		std::cout<<"***************************************";
		std::cout<<std::endl<<"Coeficiente de Joule-Thomson: "<<coefJouleThomson.valor;
		if(coefJouleThomson.t!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a temperatura = "<<coefJouleThomson.t;}
		if(coefJouleThomson.d!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a densidade = "<<coefJouleThomson.d;}
		if(coefJouleThomson.p!=0.0){
		std::cout<<std::endl<<"Derivada com relacao a pressao = "<<coefJouleThomson.p;}
		std::cout<<std::endl;		
	}
	if (coefEnforcamento.valor!=0){
		std::cout<<"***************************************";
		std::cout<<std::endl<<"Coeficiente de Enforcamento: "<<coefEnforcamento.valor;
		if(coefEnforcamento.t!=0){
		std::cout<<std::endl<<"Derivada com relacao a temperatura = "<<coefEnforcamento.t;}
		if(coefEnforcamento.d!=0){
		std::cout<<std::endl<<"Derivada com relacao a densidade = "<<coefEnforcamento.d;}
		if(coefEnforcamento.p!=0){
		std::cout<<std::endl<<"Derivada com relacao a pressao = "<<coefEnforcamento.p;}
		std::cout<<std::endl;		
	}
	if (velocidadeSom.valor!=0){
		std::cout<<"***************************************";
		std::cout<<std::endl<<"Velocidade do Som: "<<velocidadeSom.valor;
		if(velocidadeSom.t!=0){
		std::cout<<std::endl<<"Derivada com relacao a temperatura = "<<velocidadeSom.t;}
		if(velocidadeSom.d!=0){
		std::cout<<std::endl<<"Derivada com relacao a densidade = "<<velocidadeSom.d;}
		if(velocidadeSom.p!=0){
		std::cout<<std::endl<<"Derivada com relacao a pressao = "<<velocidadeSom.p;}
		std::cout<<std::endl;		
	}
		if (coefIsentropico.valor!=0){
		std::cout<<"***************************************";
		std::cout<<std::endl<<"Coeficiente de pressao-temperatura isentropico: "<<coefIsentropico.valor;
		if(coefIsentropico.t!=0){
		std::cout<<std::endl<<"Derivada com relacao a temperatura = "<<coefIsentropico.t;}
		if(coefIsentropico.d!=0){
		std::cout<<std::endl<<"Derivada com relacao a densidade = "<<coefIsentropico.d;}
		if(coefIsentropico.p!=0){
		std::cout<<std::endl<<"Derivada com relacao a pressao = "<<coefIsentropico.p;}
		std::cout<<std::endl;		
	}
	std::cout<<"***************************************";
	std::cout<<std::endl<<std::endl;
}
CSubstancia::CSubstancia()
{
		nome=" ";
		temperatura=0;
		densidade=0;
		R=0;
		d_p=0;
		pressao.valor=0;
		pressao.d=0;
		pressao.t=0;
		entalpia.valor=0;
		entalpia.d=0;
		entalpia.p=0;
		entalpia.t=0;
		entropia.valor=0;
		entropia.d=0;
		entropia.t=0;
		entropia.p=0;
		energiaInterna.valor=0;
		energiaInterna.d=0;
		energiaInterna.t=0;
		energiaInterna.p=0;
		energiaGibbs.valor=0;
		energiaGibbs.d=0;
		energiaGibbs.t=0;
		energiaGibbs.p=0;
		capCalorificaIsobarica.valor=0;
		capCalorificaIsobarica.d=0;
		capCalorificaIsobarica.t=0;
		capCalorificaIsobarica.p=0;
		capCalorificaIsovolumetrica.valor=0;
		capCalorificaIsovolumetrica.d=0;
		capCalorificaIsovolumetrica.t=0;
		capCalorificaIsovolumetrica.p=0;
		coefJouleThomson.valor=0;
		coefJouleThomson.d=0;
		coefJouleThomson.t=0;
		coefJouleThomson.p=0;
		coefEnforcamento.valor=0;
		coefEnforcamento.d=0;
		coefEnforcamento.t=0;
		coefEnforcamento.p=0;
		velocidadeSom.valor=0;
		velocidadeSom.d=0;
		velocidadeSom.p=0;
		velocidadeSom.t=0;
		coefIsentropico.valor=0;
		coefIsentropico.t=0;
		coefIsentropico.d=0;
		coefIsentropico.p=0;
		massaMolar=0;
}
