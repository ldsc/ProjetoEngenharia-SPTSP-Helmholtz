/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/


#ifndef SPTSPGUI_H
#define SPTSPGUI_H
#include <QCheckBox>
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QDialog>
#include <QTableView>
#include <QFile>
#include <QTextStream>
#include <QAbstractItemModel>
#include "CSimuladorPropriedades.h"
#include <QDoubleValidator>
QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE
class Botao;

////////////////////////////////////////////////////////////////////////
/// @author Thomas Augusto Menegazzo
/// @class SPTSPGUI
/// @file SPTSPGUI.h
/// @brief Classe para a implementa��o da interface gr�fica.
////////////////////////////////////////////////////////////////////////

class SPTSPGUI : public QWidget
{
    Q_OBJECT

public:
    /// Construtor da classe.
    SPTSPGUI(QWidget *pai = 0);

private slots:
    /// Fun��o chamada quando o bot�o calcular � clicado.
    void calcularClicado();

    /// Fun��o chamada quando checkTodos � clicado.
    void checkTodosClicado();

    /// Fun��o chamada quando checkPropriedades � clicado.
    void checkPropriedadesClicado();

    /// Fun��o chamada quando checkDerTemp � clicado.
    void checkDerTempClicado();

    /// Fun��o chamada quando checkDerDens � clicado.
    void checkDerDensClicado();

    /// Fun��o chamada quando checkDerPressao � clicado.
    void checkDerPressaoClicado();

    ///Fun��o chamada quando o bot�o de salvar em disco � clicado.
    void SalvarEmDisco();

private:
    ///Fun��o para criar um bot�o conectado a um slot.
    /// @param texto Texto do bot�o.
    /// @param membro Slot a ser conectado.
    /// @return Bot�o que realiza o slot escolhido quando clicado.
    Botao *criarBotao(const QString &texto, const char *membro);

    ///Fun��o para criar um CheckBox conectado a um slot.
    /// @param texto Texto do CheckBox.
    /// @param membro Slot a ser conectado.
    /// @return CheckBox que realiza o slot escolhido quando clicado.
    QCheckBox *criarCheck(const QString &texto, const char *membro);

    ///Checkbox para sele��o das propriedades a serem calculadas.
    QCheckBox *checkTodos, *checkPropriedades, *checkDerTemp, *checkDerDens, *checkDerPressao;
    QCheckBox *checkPressao,*checkEntalpia, *checkEntropia, *checkEnergiaInterna, *checkEnergiaGibbs, *checkCapCalorificaIsobarica;
    QCheckBox *checkPressao_t,*checkEntalpia_t, *checkEntropia_t, *checkEnergiaInterna_t, *checkEnergiaGibbs_t, *checkCapCalorificaIsobarica_t;
    QCheckBox *checkPressao_d, *checkEntalpia_d, *checkEntropia_d, *checkEnergiaInterna_d, *checkEnergiaGibbs_d, *checkCapCalorificaIsobarica_d;
    QCheckBox *checkEntalpia_p, *checkEntropia_p, *checkEnergiaInterna_p, *checkEnergiaGibbs_p, *checkCapCalorificaIsobarica_p;
    QCheckBox *checkCapCalorificaIsovolumetrica, *checkCoefJouleThomson, *checkCoefEnforcamento, *checkVelocidadeSom, *checkCoefIsentropico;
    QCheckBox *checkCapCalorificaIsovolumetrica_t, *checkCoefJouleThomson_t, *checkCoefEnforcamento_t, *checkVelocidadeSom_t, *checkCoefIsentropico_t;
    QCheckBox *checkCapCalorificaIsovolumetrica_d, *checkCoefJouleThomson_d, *checkCoefEnforcamento_d, *checkVelocidadeSom_d, *checkCoefIsentropico_d;
    QCheckBox *checkCapCalorificaIsovolumetrica_p, *checkCoefJouleThomson_p, *checkCoefEnforcamento_p, *checkVelocidadeSom_p, *checkCoefIsentropico_p;

    ///Fun��o para passar a subst�ncia escolhida.
    /// @return String usado no construtor do simulador.
    std::string Substancia();/*Funcao para passar a substancia correta para calculo*/

    ///Fun��o para calcular apenas as propriedades selecionadas.
    void EscolherCalculos();

    ///Popup com os resultados calculados.
    QDialog *popup;

    ///Fun��o para cria��o do popup.
    void CriadorPopup();

    ///Simulador que realizar� os calculos.
    CSimuladorPropriedades *sim;

    ///Caixa de entrada da densidade.
    QLineEdit *displayDensidade;

    ///Caixa de entrada da temperatura.
    QLineEdit *displayTemperatura;

    ///Caixa de sele��o da subst�ncia
    QComboBox *substanciaBox;
};

#endif
