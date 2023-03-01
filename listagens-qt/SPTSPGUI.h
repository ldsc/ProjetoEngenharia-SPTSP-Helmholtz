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
/// @brief Classe para a implementação da interface gráfica.
////////////////////////////////////////////////////////////////////////

class SPTSPGUI : public QWidget
{
    Q_OBJECT

public:
    /// Construtor da classe.
    SPTSPGUI(QWidget *pai = 0);

private slots:
    /// Função chamada quando o botão calcular é clicado.
    void calcularClicado();

    /// Função chamada quando checkTodos é clicado.
    void checkTodosClicado();

    /// Função chamada quando checkPropriedades é clicado.
    void checkPropriedadesClicado();

    /// Função chamada quando checkDerTemp é clicado.
    void checkDerTempClicado();

    /// Função chamada quando checkDerDens é clicado.
    void checkDerDensClicado();

    /// Função chamada quando checkDerPressao é clicado.
    void checkDerPressaoClicado();

    ///Função chamada quando o botão de salvar em disco é clicado.
    void SalvarEmDisco();

private:
    ///Função para criar um botão conectado a um slot.
    /// @param texto Texto do botão.
    /// @param membro Slot a ser conectado.
    /// @return Botão que realiza o slot escolhido quando clicado.
    Botao *criarBotao(const QString &texto, const char *membro);

    ///Função para criar um CheckBox conectado a um slot.
    /// @param texto Texto do CheckBox.
    /// @param membro Slot a ser conectado.
    /// @return CheckBox que realiza o slot escolhido quando clicado.
    QCheckBox *criarCheck(const QString &texto, const char *membro);

    ///Checkbox para seleção das propriedades a serem calculadas.
    QCheckBox *checkTodos, *checkPropriedades, *checkDerTemp, *checkDerDens, *checkDerPressao;
    QCheckBox *checkPressao,*checkEntalpia, *checkEntropia, *checkEnergiaInterna, *checkEnergiaGibbs, *checkCapCalorificaIsobarica;
    QCheckBox *checkPressao_t,*checkEntalpia_t, *checkEntropia_t, *checkEnergiaInterna_t, *checkEnergiaGibbs_t, *checkCapCalorificaIsobarica_t;
    QCheckBox *checkPressao_d, *checkEntalpia_d, *checkEntropia_d, *checkEnergiaInterna_d, *checkEnergiaGibbs_d, *checkCapCalorificaIsobarica_d;
    QCheckBox *checkEntalpia_p, *checkEntropia_p, *checkEnergiaInterna_p, *checkEnergiaGibbs_p, *checkCapCalorificaIsobarica_p;
    QCheckBox *checkCapCalorificaIsovolumetrica, *checkCoefJouleThomson, *checkCoefEnforcamento, *checkVelocidadeSom, *checkCoefIsentropico;
    QCheckBox *checkCapCalorificaIsovolumetrica_t, *checkCoefJouleThomson_t, *checkCoefEnforcamento_t, *checkVelocidadeSom_t, *checkCoefIsentropico_t;
    QCheckBox *checkCapCalorificaIsovolumetrica_d, *checkCoefJouleThomson_d, *checkCoefEnforcamento_d, *checkVelocidadeSom_d, *checkCoefIsentropico_d;
    QCheckBox *checkCapCalorificaIsovolumetrica_p, *checkCoefJouleThomson_p, *checkCoefEnforcamento_p, *checkVelocidadeSom_p, *checkCoefIsentropico_p;

    ///Função para passar a substância escolhida.
    /// @return String usado no construtor do simulador.
    std::string Substancia();/*Funcao para passar a substancia correta para calculo*/

    ///Função para calcular apenas as propriedades selecionadas.
    void EscolherCalculos();

    ///Popup com os resultados calculados.
    QDialog *popup;

    ///Função para criação do popup.
    void CriadorPopup();

    ///Simulador que realizará os calculos.
    CSimuladorPropriedades *sim;

    ///Caixa de entrada da densidade.
    QLineEdit *displayDensidade;

    ///Caixa de entrada da temperatura.
    QLineEdit *displayTemperatura;

    ///Caixa de seleção da substância
    QComboBox *substanciaBox;
};

#endif
