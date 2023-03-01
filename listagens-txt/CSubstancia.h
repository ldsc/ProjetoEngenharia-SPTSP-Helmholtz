#ifndef CSUBSTANCIA_H
#define CSUBSTANCIA_H
#include <ostream>
#include <string>
//Declaracao dos structs que armazenam cada propriedade:
struct SPressao
{
	double valor;
	double d;/*derivada em relacao a densidade*/
	double t;/*em relacao a temperatura*/
};
struct SEntalpia
{
	double valor;
	double d;
	double t;
	double p;/*derivada em relacao a pressao*/
};
struct SEntropia
{
	double valor;
	double d;
	double t;
	double p;
};
struct SEnergiaInterna
{
	double valor;
	double d;
	double t;
	double p;
};
struct SEnergiaGibbs
{
	double valor;
	double d;
	double t;
	double p;
};
struct SCapCalorificaIsobarica
{
	double valor;
	double d;
	double t;
	double p;
};
struct SCapCalorificaIsovolumetrica
{
	double valor;
	double d;
	double t;
	double p;
};
struct SCoefJouleThomson
{
	double valor;
	double d;
	double t;
	double p;
};
struct SCoefEnforcamento
{
	double valor;
	double d;
	double t;
	double p;
};
struct SVelocidadeSom
{
	double valor;
	double d;
	double t;
	double p;
};
struct SIsentropico
{
	double valor;
	double d;
	double t;
	double p;
};
class CSubstancia
{
	public:
		double temperatura;/*temperatura da substancia*/
		double densidade;/*densidade da substancia*/
		double R;/*Constante especifica dos gases*/
		double d_p;/*derivada da densidade com relacao a pressao*/
		double massaMolar;/*massa molar da substancia*/
		std::string nome;/*string que armazena o nome da sustancia*/
		//Structs para armazenamento das propriedades:
		SPressao pressao;
		SEntalpia entalpia;
		SEntropia entropia;
		SEnergiaInterna energiaInterna;
		SEnergiaGibbs energiaGibbs;
		SCapCalorificaIsobarica capCalorificaIsobarica;
		SCapCalorificaIsovolumetrica capCalorificaIsovolumetrica;
		SCoefJouleThomson coefJouleThomson;
		SCoefEnforcamento coefEnforcamento;
		SVelocidadeSom velocidadeSom;
		SIsentropico coefIsentropico;
	public:
		CSubstancia();
		void SetTemperatura(double t){temperatura=t;}
		void SetDensidade(double d){densidade=d;}
		void SetPressao(double p){pressao.valor=p;}
		void Display();/*Funcao para mostrar as propriedades diferentes de 0 na tela*/
		friend std::ostream& operator<<(std::ostream& out, const CSubstancia& s);	
};
#endif
