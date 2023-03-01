#include "CHelmholtz.h"
////////////////////////////////////////////////////////////////////////
/// @author Thomas Augusto Menegazzo
/// @class CHelmholtzAgua
/// @file CHelmholtzAgua.h
/// @brief Classe para passar os coeficientes da água para CHelmholtz.
////////////////////////////////////////////////////////////////////////
class CHelmholtzAgua: public CHelmholtz{
	public:
		CHelmholtzAgua();
		~CHelmholtzAgua();
};

/// @class CHelmholtzMetano
/// @file CHelmholtzAgua.h
/// @brief Classe para passar os coeficientes do metano para CHelmholtz.
class CHelmholtzMetano: public CHelmholtz{
	public:
		CHelmholtzMetano();
		~CHelmholtzMetano();
};

/// @class CHelmholtzEtano
/// @file CHelmholtzAgua.h
/// @brief Classe para passar os coeficientes do etano para CHelmholtz.
class CHelmholtzEtano: public CHelmholtz{
	public:
		CHelmholtzEtano();
		~CHelmholtzEtano();
};

/// @class CHelmholtzIsobutano
/// @file CHelmholtzAgua.h
/// @brief Classe para passar os coeficientes do isobutano para CHelmholtz.
class CHelmholtzIsobutano: public CHelmholtz{
	public:
		CHelmholtzIsobutano();
		~CHelmholtzIsobutano();
};

/// @class CHelmholtzNbutano
/// @file CHelmholtzAgua.h
/// @brief Classe para passar os coeficientes do n-butano para CHelmholtz.
class CHelmholtzNbutano: public CHelmholtz{
	public:
		CHelmholtzNbutano();
		~CHelmholtzNbutano();
};

/// @class CHelmholtzDioxidoCarbono
/// @file CHelmholtzAgua.h
/// @brief Classe para passar os coeficientes do dioxido de carbono para CHelmholtz.
class CHelmholtzDioxidoCarbono: public CHelmholtz{
	public:
		CHelmholtzDioxidoCarbono();
		~CHelmholtzDioxidoCarbono();
};

/// @class CHelmholtzNitrogenio
/// @file CHelmholtzAgua.h
/// @brief Classe para passar os coeficientes do nitrogenio para CHelmholtz.
class CHelmholtzNitrogenio: public CHelmholtz{
	public:
		CHelmholtzNitrogenio();
		~CHelmholtzNitrogenio();
};
