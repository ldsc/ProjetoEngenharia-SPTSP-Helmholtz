#ifndef CSUBSTANCIA_H
#define CSUBSTANCIA_H
#include <ostream>
#include <string>

/// @struct SPressao
/// @brief Struct com os valores relacionados � press�o.
struct SPressao
{
    /// Valor da press�o.
	double valor;

    /// Derivada da press�o em rela��o � densidade.
    double d;

    /// Derivada da press�o em rela��o � temperatura.
    double t;
};

/// @struct SEntalpia
/// @brief Struct com os valores relacionados � entalpia.
struct SEntalpia
{
    ///Valor da entalpia.
	double valor;

    /// Derivada da entalpia em rela��o � densidade.
    double d;

    /// Derivada da entalpia em rela��o � temperatura.
    double t;

    /// Derivada da entalpia em rela��o � press�o.
    double p;
};

/// @struct SEntropia
/// @brief Struct com os valores relacionados � entropia.
struct SEntropia
{
    ///Valor da entropia.
    double valor;

    /// Derivada da entalpia em rela��o � densidade.
    double d;

    /// Derivada da entalpia em rela��o � temperatura.
    double t;

    /// Derivada da entalpia em rela��o � press�o.
    double p;
};

/// @struct SEnergiaInterna
/// @brief Struct com os valores relacionados � energia interna.
struct SEnergiaInterna
{
    ///Valor da energia interna.
    double valor;

    /// Derivada da entalpia em rela��o � densidade.
    double d;

    /// Derivada da entalpia em rela��o � temperatura.
    double t;

    /// Derivada da entalpia em rela��o � press�o.
    double p;
};

/// @struct SEnergiaGibbs
/// @brief Struct com os valores relacionados � energia de Gibbs.
struct SEnergiaGibbs
{
    ///Valor da energia de Gibbs.
    double valor;

    /// Derivada da entalpia em rela��o � densidade.
    double d;

    /// Derivada da entalpia em rela��o � temperatura.
    double t;

    /// Derivada da entalpia em rela��o � press�o.
    double p;
};

/// @struct SCapCalorificaIsobarica
/// @brief Struct com os valores relacionados � capacidade calor�fica isob�rica.
struct SCapCalorificaIsobarica
{
    ///Valor da capacidade calor�fica isob�rica.
    double valor;

    /// Derivada da entalpia em rela��o � densidade.
    double d;

    /// Derivada da entalpia em rela��o � temperatura.
    double t;

    /// Derivada da entalpia em rela��o � press�o.
    double p;
};

/// @struct SCapCalorificaIsovolumetrica
/// @brief Struct com os valores relacionados � capacidade calor�fica isovolum�trica.
struct SCapCalorificaIsovolumetrica
{
    ///Valor da capacidade calor�fica isovolum�trica.
    double valor;

    /// Derivada da entalpia em rela��o � densidade.
    double d;

    /// Derivada da entalpia em rela��o � temperatura.
    double t;

    /// Derivada da entalpia em rela��o � press�o.
    double p;
};

/// @struct SCoefJouleThomson
/// @brief Struct com os valores relacionados ao coeficiente de Joule-Thomson.
struct SCoefJouleThomson
{
    ///Valor do coeficiente de Joule-Thomson.
    double valor;

    /// Derivada da entalpia em rela��o � densidade.
    double d;

    /// Derivada da entalpia em rela��o � temperatura.
    double t;

    /// Derivada da entalpia em rela��o � press�o.
    double p;
};

/// @struct SCoefEnforcamento
/// @brief Struct com os valores relacionados ao coeficiente de enforcamento.
struct SCoefEnforcamento
{
    ///Valor do coeficiente de enforcamento.
    double valor;

    /// Derivada da entalpia em rela��o � densidade.
    double d;

    /// Derivada da entalpia em rela��o � temperatura.
    double t;

    /// Derivada da entalpia em rela��o � press�o.
    double p;
};

/// @struct SVelocidadeSom
/// @brief Struct com os valores relacionados � velocidade do som no meio.
struct SVelocidadeSom
{
    ///Valor da velocidade do som no meio.
    double valor;

    /// Derivada da entalpia em rela��o � densidade.
    double d;

    /// Derivada da entalpia em rela��o � temperatura.
    double t;

    /// Derivada da entalpia em rela��o � press�o.
    double p;
};

/// @struct SIsentropico
/// @brief Struct com os valores relacionados ao coeficiente de temperatura-press�o isentr�pico.
struct SIsentropico
{
    ///Valor do coeficiente de temperatura-press�o isentr�pico.
    double valor;

    /// Derivada da entalpia em rela��o � densidade.
    double d;

    /// Derivada da entalpia em rela��o � temperatura.
    double t;

    /// Derivada da entalpia em rela��o � press�o.
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
		///Temperatura da subst�ncia.
		double temperatura;
		
		///Densidade da subst�ncia.
		double densidade;
		
		///Constante especifica dos gases.
		double R;
		
		///Derivada da densidade com relacao � press�o.
		double d_p;
		
		///Massa molar.
		double massaMolar;
		
		///Formula qu�mica da subst�ncia.
		std::string nome;
		
		///Struct para armazenamento da press�o.
		SPressao pressao;
		
		///Struct para armazenamento da entalpia.
		SEntalpia entalpia;
		
		///Struct para armazenamento da entropia.
		SEntropia entropia;
		
		///Struct para armazenamento da energia interna.
		SEnergiaInterna energiaInterna;
		
		///Struct para armazenamento da energia de Gibbs.
		SEnergiaGibbs energiaGibbs;
		
		///Struct para armazenamento da capacidade calor�fica isob�rica.
		SCapCalorificaIsobarica capCalorificaIsobarica;
		
		///Struct para armazenamento da capacidade calor�fica isoc�rica.
		SCapCalorificaIsovolumetrica capCalorificaIsovolumetrica;
		
		///Struct para armazenamento do coeficiente de Joule-Thomson.
		SCoefJouleThomson coefJouleThomson;
		
		///Struct para armazenamento do coeficiente de enforcamento.
		SCoefEnforcamento coefEnforcamento;
		
		///Struct para armazenamento da velocidade do som.
		SVelocidadeSom velocidadeSom;
		
		///Struct para armazenamento do coeficiente de temperatura-press�o isentr�pico.
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
		
		///Seta o valor da press�o.
		///@param p press�o.
		void SetPressao(double p){pressao.valor=p;}
		
		///fun��o para mostrar os dados calculados na tela
		void Display();
		};
#endif
