#include <iostream>
#include "CSimuladorPropriedades.h"
using namespace std;

int main()
{
	CSimuladorPropriedades CSimulador1("H2O",500,838.025,15);
	CSimulador1.CalcularTudo();
	CSimulador1.Display();
	CSimuladorPropriedades CSimulador2("H2O",647,358);
	CSimulador2.CalcularTudo();
	CSimulador2.Display();
	CSimuladorPropriedades CSimulador3("CH4",280,1.037);
	CSimulador3.CalcularTudo();
	CSimulador3.Display();
	CSimuladorPropriedades CSimulador4("C2H6",100,641.15);
	CSimulador4.CalcularTudo();
	CSimulador4.Display();
	CSimuladorPropriedades CSimulador5("CO2",270,966.16);
	CSimulador5.CalcularTudo();
	CSimulador5.Display();
	CSimuladorPropriedades CSimulador6("nC4H10",150,722.25);
	CSimulador6.CalcularTudo();
	CSimulador6.Display();
	CSimuladorPropriedades CSimulador7("iC4H10",500,70.023);
	CSimulador7.CalcularTudo();
	CSimulador7.Display();
	CSimuladorPropriedades CSimulador8("N2",100,122.68/28.013);
	CSimulador8.CalcularTudo();
	CSimulador8.Display();

	double t, d;
	cout<<"Digite a temperatura e densidade: ";
	cin>>t>>d;
	cin.clear();cin.clear();
	CSimuladorPropriedades CSimulador9("H2O",t,d,15);
	CSimulador9.CalcularTudo();
	CSimulador9.Display();
	cout<<endl<<endl<<"Aperte qualquer botao para sair...";
	cin.get();cin.get();
	return 0;
}
