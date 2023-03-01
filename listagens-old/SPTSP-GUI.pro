QT += widgets

HEADERS       = \
    CHelmholtz.h \
    CHelmholtzAgua.h \
    CSimuladorPropriedades.h \
    CSubstancia.h \
    botao.h \
    SPTSPGUI.h
SOURCES       = \
                main.cpp \
    CHelmholtz.cpp \
    CHelmholtzAgua.cpp \
    CSimuladorPropriedades.cpp \
    CSubstancia.cpp \
    CHelmholtzDioxidoCarbono.cpp \
    CHelmholtzEtano.cpp \
    CHelmholtzIsobutano.cpp \
    CHelmholtzMetano.cpp \
    CHelmholtzNbutano.cpp \
    CHelmholtzNitrogenio.cpp \
    botao.cpp \
    SPTSPGUI.cpp

# install
target.path = C:\Users\Thomas\Desktop\Faculdade\Programacao Pratica\SPTSP-GUI
INSTALLS += target
