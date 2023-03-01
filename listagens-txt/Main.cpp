#include <iostream>
#include "CSimuladorPropriedades.h"
#include <string>
using namespace std;

int main()
{
	string str[7]={"H2O","N2","CO2","CH4","C2H6","nC4H10","iC4H10"};
	cout<<"Deseja calcular propriedades para:\n1 - Agua\n2 - Nitrogenio\n3 - Dioxido de carbono";
	cout<<endl<<"4 - Metano\n5 - Etano\n6 - n-Butano\n7 - isoButano\n";
	int sub;
	cin>>sub;cin.get();
	double t, d;
	cout<<"Digite a temperatura e densidade: ";
	cin>>t>>d;
	cin.clear();cin.clear();
	CSimuladorPropriedades CSimulador9(str[sub-1],t,d,15);
	CSimulador9.CalcularTudo();
	CSimulador9.Display();
	cout<<endl<<endl<<"Aperte qualquer botao para sair...";
	cin.get();cin.get();
	return 0;
}
