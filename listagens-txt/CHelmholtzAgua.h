#include "CHelmholtz.h"
/*##############################################
## Classes usadas para passar os coeficientes ##
## certos para a equacao de cada substancia ####
##############################################*/
class CHelmholtzAgua: public CHelmholtz{
	public:
		CHelmholtzAgua();
		~CHelmholtzAgua();
};
class CHelmholtzMetano: public CHelmholtz{
	public:
		CHelmholtzMetano();
		~CHelmholtzMetano();
};
class CHelmholtzEtano: public CHelmholtz{
	public:
		CHelmholtzEtano();
		~CHelmholtzEtano();
};
class CHelmholtzIsobutano: public CHelmholtz{
	public:
		CHelmholtzIsobutano();
		~CHelmholtzIsobutano();
};
class CHelmholtzNbutano: public CHelmholtz{
	public:
		CHelmholtzNbutano();
		~CHelmholtzNbutano();
};
class CHelmholtzDioxidoCarbono: public CHelmholtz{
	public:
		CHelmholtzDioxidoCarbono();
		~CHelmholtzDioxidoCarbono();
};
class CHelmholtzNitrogenio: public CHelmholtz{
	public:
		CHelmholtzNitrogenio();
		~CHelmholtzNitrogenio();
};
