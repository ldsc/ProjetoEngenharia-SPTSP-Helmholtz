#ifndef CHELMHOLTZ_H
#define CHELMHOLTZ_H
//Classe com os metodos de calculo da energia de Helmholtz e suas derivadas
class CHelmholtz
{
	protected:
		//Coeficientes usados nos calculos:
		double** coeficientesPolinomio;
		double** coeficientesExponenciais;
		double** coeficientesGaussianos;
		double** coeficientesNaoAnaliticos;
		double* coeficientesIdeais1;
		double** coeficientesIdeais2;
		int numeroCoeficientes[5]; /*Matriz com o numero de somatorios de cada parte da equacao*/
		//funcoes para alocacao de matrizes dinamicas:
		static double** Aloca(int nx, int ny);
		static void Desaloca(double**& pm, int nx);	
	public:
		double tCritica; /*temperatura critica da substancia escolhida*/
		double dCritica; /*densidade critica da substancia escolhida*/
		double rEspecifico; /*Constante espeficia dos gases*/
		double delta, tau; /*densidade reduzida e inverso da temperatura reduzida*/
		double fIdeal, fIdeal_t, fIdeal_tt, fIdeal_ttt; /*Parte ideal e derivadas com relacao a temperatura da equacao*/
		double fResidual; /*parte residual da equacao*/
		double fResidual_t, fResidual_d; /*derivadas de primeiro grau da parte residual da equacao, a letra depois de _ indica em relacao a temperatura ou densidade*/
		double fResidual_dd, fResidual_dt, fResidual_tt; /*derivadas de segundo grau da parte residual da equacao*/
		double fResidual_ddd, fResidual_ddt, fResidual_dtt, fResidual_ttt; /*derivadas de terceiro grau da parte residual da equacao*/
	public:
		//Metodos para calulo da parte ideal e derivadas:
		void FI();
		void FI_t();
		void FI_tt();
		void FI_ttt();
		//Metodos para calulo da parte residual e derivadas:
		void FR();		
		void FR_d();
		void FR_t();
		void FR_dd();
		void FR_dt();
		void FR_tt();
		void FR_ddd();
		void FR_ddt();
		void FR_dtt();
		void FR_ttt();
};
#endif
