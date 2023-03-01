#ifndef CSUBSTANCIA_H
#define CSUBSTANCIA_H
#include <ostream>
#include <string>

/// @struct SPressao
/// @brief Struct com os valores relacionados à pressão.
struct SPressao
{
    /// Valor da pressão.
	double valor;

    /// Derivada da pressão em relação à densidade.
    double d;

    /// Derivada da pressão em relação à temperatura.
    double t;
};

/// @struct SEntalpia
/// @brief Struct com os valores relacionados à entalpia.
struct SEntalpia
{
    ///Valor da entalpia.
	double valor;

    /// Derivada da entalpia em relação à densidade.
    double d;

    /// Derivada da entalpia em relação à temperatura.
    double t;

    /// Derivada da entalpia em relação à pressão.
    double p;
};

/// @struct SEntropia
/// @brief Struct com os valores relacionados à entropia.
struct SEntropia
{
    ///Valor da entropia.
    double valor;

    /// Derivada da entalpia em relação à densidade.
    double d;

    /// Derivada da entalpia em relação à temperatura.
    double t;

    /// Derivada da entalpia em relação à pressão.
    double p;
};

/// @struct SEnergiaInterna
/// @brief Struct com os valores relacionados à energia interna.
struct SEnergiaInterna
{
    ///Valor da energia interna.
    double valor;

    /// Derivada da entalpia em relação à densidade.
    double d;

    /// Derivada da entalpia em relação à temperatura.
    double t;

    /// Derivada da entalpia em relação à pressão.
    double p;
};

/// @struct SEnergiaGibbs
/// @brief Struct com os valores relacionados à energia de Gibbs.
struct SEnergiaGibbs
{
    ///Valor da energia de Gibbs.
    double valor;

    /// Derivada da entalpia em relação à densidade.
    double d;

    /// Derivada da entalpia em relação à temperatura.
    double t;

    /// Derivada da entalpia em relação à pressão.
    double p;
};

/// @struct SCapCalorificaIsobarica
/// @brief Struct com os valores relacionados à capacidade calorífica isobárica.
struct SCapCalorificaIsobarica
{
    ///Valor da capacidade calorífica isobárica.
    double valor;

    /// Derivada da entalpia em relação à densidade.
    double d;

    /// Derivada da entalpia em relação à temperatura.
    double t;

    /// Derivada da entalpia em relação à pressão.
    double p;
};

/// @struct SCapCalorificaIsovolumetrica
/// @brief Struct com os valores relacionados à capacidade calorífica isovolumétrica.
struct SCapCalorificaIsovolumetrica
{
    ///Valor da capacidade calorífica isovolumétrica.
    double valor;

    /// Derivada da entalpia em relação à densidade.
    double d;

    /// Derivada da entalpia em relação à temperatura.
    double t;

    /// Derivada da entalpia em relação à pressão.
    double p;
};

/// @struct SCoefJouleThomson
/// @brief Struct com os valores relacionados ao coeficiente de Joule-Thomson.
struct SCoefJouleThomson
{
    ///Valor do coeficiente de Joule-Thomson.
    double valor;

    /// Derivada da entalpia em relação à densidade.
    double d;

    /// Derivada da entalpia em relação à temperatura.
    double t;

    /// Derivada da entalpia em relação à pressão.
    double p;
};

/// @struct SCoefEnforcamento
/// @brief Struct com os valores relacionados ao coeficiente de enforcamento.
struct SCoefEnforcamento
{
    ///Valor do coeficiente de enforcamento.
    double valor;

    /// Derivada da entalpia em relação à densidade.
    double d;

    /// Derivada da entalpia em relação à temperatura.
    double t;

    /// Derivada da entalpia em relação à pressão.
    double p;
};

/// @struct SVelocidadeSom
/// @brief Struct com os valores relacionados à velocidade do som no meio.
struct SVelocidadeSom
{
    ///Valor da velocidade do som no meio.
    double valor;

    /// Derivada da entalpia em relação à densidade.
    double d;

    /// Derivada da entalpia em relação à temperatura.
    double t;

    /// Derivada da entalpia em relação à pressão.
    double p;
};

/// @struct SIsentropico
/// @brief Struct com os valores relacionados ao coeficiente de temperatura-pressão isentrópico.
struct SIsentropico
{
    ///Valor do coeficiente de temperatura-pressão isentrópico.
    double valor;

    /// Derivada da entalpia em relação à densidade.
    double d;

    /// Derivada da entalpia em relação à temperatura.
    double t;

    /// Derivada da entalpia em relação à pressão.
    double p;
};

////////////////////////////////////////////////////////////////////////
/// @author Thomas Augusto Menegazzo
/// @class CSubstancia
/// @file CSubstancia.h
/// @brief Classe que armazena os valores calculados.
////////////////////////////////////////////////////////////////////////
class CSubstancia
{
	public:
		///Temperatura da substância.
		double temperatura;
		
		///Densidade da substância.
		double densidade;
		
		///Constante especifica dos gases.
		double R;
		
		///Derivada da densidade com relacao à pressão.
		double d_p;
		
		///Massa molar.
		double massaMolar;
		
		///Formula química da substância.
		std::string nome;
		
		///Struct para armazenamento da pressão.
		SPressao pressao;
		
		///Struct para armazenamento da entalpia.
		SEntalpia entalpia;
		
		///Struct para armazenamento da entropia.
		SEntropia entropia;
		
		///Struct para armazenamento da energia interna.
		SEnergiaInterna energiaInterna;
		
		///Struct para armazenamento da energia de Gibbs.
		SEnergiaGibbs energiaGibbs;
		
		///Struct para armazenamento da capacidade calorífica isobárica.
		SCapCalorificaIsobarica capCalorificaIsobarica;
		
		///Struct para armazenamento da capacidade calorífica isocórica.
		SCapCalorificaIsovolumetrica capCalorificaIsovolumetrica;
		
		///Struct para armazenamento do coeficiente de Joule-Thomson.
		SCoefJouleThomson coefJouleThomson;
		
		///Struct para armazenamento do coeficiente de enforcamento.
		SCoefEnforcamento coefEnforcamento;
		
		///Struct para armazenamento da velocidade do som.
		SVelocidadeSom velocidadeSom;
		
		///Struct para armazenamento do coeficiente de temperatura-pressão isentrópico.
		SIsentropico coefIsentropico;
	public:
		
		///Construtor da classe.
		CSubstancia();
		
		///Seta o valor da temperatura.
		///@param t Temperatura.
		void SetTemperatura(double t){temperatura=t;}
		
		///Seta o valor da densidade
		///@param d Densidade.
		void SetDensidade(double d){densidade=d;}
		
		///Seta o valor da pressão.
		///@param p pressão.
		void SetPressao(double p){pressao.valor=p;}
		
		///função para mostrar os dados calculados na tela
		void Display();
		};
#endif
