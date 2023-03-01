#ifndef CSIMULADORPROPRIEDADES_H
#define CSIMULADORPROPRIEDADES_H
#include "CHelmholtz.h"
#include "CHelmholtzAgua.h"
#include "CSubstancia.h"
#include <string>
////////////////////////////////////////////////////////////////////////
/// @author Thomas Augusto Menegazzo
/// @class CSimuladorPropriedades
/// @file CSimuladorPropriedades.h
/// @brief Classe com metodos de calculo das propriedades temodinamicas a partir de CHelmholtz.
////////////////////////////////////////////////////////////////////////

class CSimuladorPropriedades
{
	private:
		///Ponteiro para a classe que calcula a enegia de Helmholtz.
		CHelmholtz* p_Helm;

		///Atributo para definir o que calcular.
		///Funciona estilo somatorio: 1 para calcular a propriedade, 2, 4 e 8 para derivadas de temperatura,densidade e pressao respectivamente.
		///Ex: 7 calcularia tudo menos a derivada com relacao a pressao
		int flag_derivadas;
						
		///calcula a derivada da densidade com relacao a pressao,
		///usada para o calculo das derivadas com relacao a pressao
		void Calculo_dp();
	public:
		
		///Construtor da classe.
		///@param subs Substancia a ser calculada.
		///@param t Temperatura.
		///@param d Densidade.
		CSimuladorPropriedades(std::string subs, double t, double d);
		
		///Sobrecarga do construtor.
		///@param subs Substancia a ser calculada.
		///@param t Temperatura.
		///@param d Densidade.
		///@param flag Valor de flag_derivadas.
		CSimuladorPropriedades(std::string subs, double t, double d, int flag);
		
		///Objeto para armazenamento das propriedades obtidas.
        CSubstancia substancia;
        
        ///Calcula todas as propriedades.
		void CalcularTudo();
		
		///Seta o atributo flag_derivadas.
		///@param flag Valor a ser setado.
		void Set_Flag(int flag){flag_derivadas=flag;}
		
		///Calcula a pressao e suas derivadas.
		void Pressao();
		
		///Sobrecarga do método Pressao().
        ///@param flag Valor a ser usado temporariamente como flag_derivadas.
        void Pressao(int flag);
        
        ///Calcula a entalpia e suas derivadas.
        void Entalpia();
        
        ///Sobrecarga do método Entalpia().
        ///@param flag Valor a ser usado temporariamente como flag_derivadas.
        void Entalpia(int flag);
        
        ///Calcula a entropia e suas derivadas.
        void Entropia();
        
        ///Sobrecarga do método Entropia().
        ///@param flag Valor a ser usado temporariamente como flag_derivadas.
        void Entropia(int flag);
        
        ///Calcula a energia interna e suas derivadas.
        void EnergiaInterna();
        
        ///Sobrecarga do método EnergiaInterna().
        ///@param flag Valor a ser usado temporariamente como flag_derivadas.
        void EnergiaInterna(int flag);
        
        ///Calcula a energia de Gibbs e suas derivadas.
        void EnergiaGibbs();
        
        ///Sobrecarga do método EnergiaGibbs().
        ///@param flag Valor a ser usado temporariamente como flag_derivadas.
        void EnergiaGibbs(int flag);
        
        ///Calcula a capacidade calorífica isobárica e suas derivadas.
        void CapCalorificaIsobarica();
        
        ///Sobrecarga do método CapCalorificaIsobarica().
        ///@param flag Valor a ser usado temporariamente como flag_derivadas.
        void CapCalorificaIsobarica(int flag);
        
        ///Calcula a capacidade calorífica isocórica e suas derivadas.
        void CapCalorificaIsovolumetrica();
        
        ///Sobrecarga do método CapCalorificaIsovolumetrica().
        ///@param flag Valor a ser usado temporariamente como flag_derivadas.
        void CapCalorificaIsovolumetrica(int flag);
        
        ///Calcula coeficiente de Joule-Thomson e suas derivadas.
        void CoefJouleThomson();
        
        ///Sobrecarga do método CoefJouleThomson().
        ///@param flag Valor a ser usado temporariamente como flag_derivadas.
        void CoefJouleThomson(int flag);
        
        ///Calcula o coeficiente de enforcamento e suas derivadas.
        void CoefEnforcamento();
        
        ///Sobrecarga do método CoefEnforcamento().
        ///@param flag Valor a ser usado temporariamente como flag_derivadas.
        void CoefEnforcamento(int flag);
        
        ///Calcula a velocidade do som no meio e suas derivadas.
        void VelocidadeSom();
        
        ///Sobrecarga do método VelocidadeSom().
        ///@param flag Valor a ser usado temporariamente como flag_derivadas.
        void VelocidadeSom(int flag);
        
        ///Calcula o coeficiente de temperatura-pressão isentrópico e suas derivadas.
        void CoefIsentropico();
        
        ///Sobrecarga do método CoefIsentropico().
        ///@param flag Valor a ser usado temporariamente como flag_derivadas.
        void CoefIsentropico(int flag);
        
        ///função para mostrar os dados calculados na tela
        void Display();
};
#endif
