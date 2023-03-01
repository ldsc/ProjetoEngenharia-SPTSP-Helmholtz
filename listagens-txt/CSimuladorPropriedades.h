#ifndef CSIMULADORPROPRIEDADES_H
#define CSIMULADORPROPRIEDADES_H
#include "CHelmholtz.h"
#include "CHelmholtzAgua.h"
#include "CSubstancia.h"
#include <string>
//Classe com metodos de calculo das propriedades temodinamicas a partir da energia de Helmholtz e objeto para armazenar essas propriedades
class CSimuladorPropriedades
{
	private:
		CHelmholtz* p_Helm;/*Ponteiro para a classe que calcula a enegia de Helmholtz*/

		int flag_derivadas;/*atributo para definir o que calcular;
							Funciona estilo somatorio, 1 para calcular a propriedade; 
							2,4,8 para derivadas de temperatura,densidade e pressao respectivamente
							Ex: 7 calcularia tudo menos a derivada com relacao a pressao*/
							
		void Calculo_dp();/*calcula a derivada da densidade com relacao a pressao,
							usada para o calculo das derivadas com relacao a pressao*/
	public:
		CSimuladorPropriedades(std::string subs, double t, double d);
		CSimuladorPropriedades(std::string subs, double t, double d, int flag);
        CSubstancia substancia;/*Objeto para armazenamento das propriedades obtidas*/
		void CalcularTudo();/*Calcula todas as propriedades*/
		void Set_Flag(int flag){flag_derivadas=flag;}
		void Pressao();/*Calcula a pressao e suas derivadas*/
        void Pressao(int flag);
        void Entalpia();/*Calcula a entalpia e suas derivadas*/
        void Entalpia(int flag);
        void Entropia();/*Calcula a entropia e suas derivadas*/
        void Entropia(int flag);
        void EnergiaInterna();/*Calcula a energia interna e suas derivadas*/
        void EnergiaInterna(int flag);
        void EnergiaGibbs();/*Calcula a energia de Gibbs e suas derivadas*/
        void EnergiaGibbs(int flag);
        void CapCalorificaIsobarica();/*Calcula a capacidade calorifica isobarica e suas derivadas*/
        void CapCalorificaIsobarica(int flag);
        void CapCalorificaIsovolumetrica();/*Calcula a capacidade calorifica isobarica e suas derivadas*/
        void CapCalorificaIsovolumetrica(int flag);
        void CoefJouleThomson();/*Calcula o coeficiente de Joule-Thomson e suas derivadas*/
        void CoefJouleThomson(int flag);
        void CoefEnforcamento();/*Calcula o coeficiente de enforcamento e suas derivadas*/
        void CoefEnforcamento(int flag);
        void VelocidadeSom();/*Calcula a velocidade do som no meio e suas derivadas*/
        void VelocidadeSom(int flag);
        void CoefIsentropico();/*Calcula o coeficiente de temperatura-pressao isentropico e suas derivadas*/
        void CoefIsentropico(int flag);
        void Display();/*funcao para mostrar os dados calculados na tela*/
};
#endif
