#ifndef CHELMHOLTZ_H
#define CHELMHOLTZ_H
////////////////////////////////////////////////////////////////////////
/// @author Thomas Augusto Menegazzo
/// @class CHelmholtz
/// @file CHelmholtz.h
/// @brief Classe com os metodos de calculo da energia de Helmholtz e suas derivadas.
////////////////////////////////////////////////////////////////////////

class CHelmholtz
{
	protected:
		///Matriz de coeficientes para a parte polinomial.
		double** coeficientesPolinomio;
		
		///Matriz de coeficientes para a parte exponencial.
		double** coeficientesExponenciais;
		
		///Matriz de coeficientes para a parte de curva Gaussiana.
		double** coeficientesGaussianos;
		
		///Matriz de coeficientes para a parte não-analítica.
		double** coeficientesNaoAnaliticos;
		
		///Vetor de coeficientes do inicio da parte ideal.
		double* coeficientesIdeais1;
		
		///Matriz de coeficientes do fim da parte ideal.
		double** coeficientesIdeais2;
		
		///Matriz com o numero de somatorios de cada parte da equacao.
		int numeroCoeficientes[5]; 
		
		///Funcão para alocacao de matrizes dinâmicas.
		///@param nx Número de linhas da matriz.
		///@param ny Número de colunas da matriz.
		static double** Aloca(int nx, int ny);
		
		///Função para desalocação.
		///@param pm Ponteiro para matriz a ser desalocada.
		///@param nx Número de linhas da matriz.
		static void Desaloca(double**& pm, int nx);	
	public:
		
        ///Temperatura crítica da substancia escolhida.
		double tCritica;
		
        ///Densidade crítica da substancia escolhida.
		double dCritica;
		
        ///Constante específica dos gases.
		double rEspecifico;
        
		///Densidade reduzida.
        double delta;
		
		///Temperatura reduzida.
		double tau;
		
		///Valor da parte ideal da equação.
		double fIdeal;
		
		///Valor da primeira derivada com relação à temperatura da parte ideal.
		double fIdeal_t;
		
		///Valor da segunda derivada com relação à temperatura da parte ideal.
		double fIdeal_tt;
		
		///Valor da terceira derivada com relação à temperatura da parte ideal.
		double fIdeal_ttt;
		
		///Valor da parte residual da equacao.
		double fResidual;
		
		///Valor da primeira derivada com relação à temperatura da parte residual.
		double fResidual_t;
		
		///Valor da primeira derivada com relação à densidade da parte residual.
		double fResidual_d;
		
		///Valor da segunda derivada com relação à densidade da parte residual.
		double fResidual_dd;
		
		///Valor da segunda derivada mista.
		double fResidual_dt;
		
		///Valor da segunda derivada com relação à temperatura da parte residual.
		double fResidual_tt;
		
		///Valor da terceira derivada com relação à densidade da parte residual.
		double fResidual_ddd;
		
		///Valor da derivada com relação à temperatura de fResidual_dd.
		double fResidual_ddt;
		
		///Valor da derivada com relação à temperatura de fResidual_dt.
		double fResidual_dtt;
		
		///Valor da terceira derivada com relação à temperatura da parte residual.
		double fResidual_ttt;
	public:
		
		///Metodo para cálculo de fIdeal.
		void FI();
		
		///Metodo para cálculo de fIdeal_t.
		void FI_t();
		
		///Metodo para cálculo de fIdeal_tt.
		void FI_tt();
		
		///Metodo para cálculo de fIdeal_ttt.
		void FI_ttt();
		
		///Metodo para cálculo de fResidual.
		void FR();
		
		///Metodo para cálculo de fResidual_d.		
		void FR_d();
		
		///Metodo para cálculo de fResidual_t.
		void FR_t();
		
		///Metodo para cálculo de fResidual_dd.
		void FR_dd();
		
		///Metodo para cálculo de fResidual_dt.
		void FR_dt();
		
		///Metodo para cálculo de fResidual_tt.
		void FR_tt();
		
		///Metodo para cálculo de fResidual_ddd.
		void FR_ddd();
		
		///Metodo para cálculo de fResidual_ddt.
		void FR_ddt();
		
		///Metodo para cálculo de fResidual_dtt.
		void FR_dtt();
		
		///Metodo para cálculo de fResidual_ttt.
		void FR_ttt();
};
#endif
