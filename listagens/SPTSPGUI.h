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

//! [0]
class SPTSPGUI : public QWidget
{
    Q_OBJECT

public:
    SPTSPGUI(QWidget *pai = 0);

private slots:
    void calcularClicado();
    void checkTodosClicado();
    void checkPropriedadesClicado();
    void checkDerTempClicado();
    void checkDerDensClicado();
    void checkDerPressaoClicado();
    void SalvarEmDisco();

private:
    Botao *criarBotao(const QString &texto, const char *membro);
    QCheckBox *criarCheck(const QString &texto, const char *membro);
    //Checks para escolher o que calcular ao clicar o botao
    QCheckBox *checkTodos, *checkPropriedades, *checkDerTemp, *checkDerDens, *checkDerPressao;
    QCheckBox *checkPressao,*checkEntalpia, *checkEntropia, *checkEnergiaInterna, *checkEnergiaGibbs, *checkCapCalorificaIsobarica;
    QCheckBox *checkPressao_t,*checkEntalpia_t, *checkEntropia_t, *checkEnergiaInterna_t, *checkEnergiaGibbs_t, *checkCapCalorificaIsobarica_t;
    QCheckBox *checkPressao_d, *checkEntalpia_d, *checkEntropia_d, *checkEnergiaInterna_d, *checkEnergiaGibbs_d, *checkCapCalorificaIsobarica_d;
    QCheckBox *checkEntalpia_p, *checkEntropia_p, *checkEnergiaInterna_p, *checkEnergiaGibbs_p, *checkCapCalorificaIsobarica_p;
    QCheckBox *checkCapCalorificaIsovolumetrica, *checkCoefJouleThomson, *checkCoefEnforcamento, *checkVelocidadeSom, *checkCoefIsentropico;
    QCheckBox *checkCapCalorificaIsovolumetrica_t, *checkCoefJouleThomson_t, *checkCoefEnforcamento_t, *checkVelocidadeSom_t, *checkCoefIsentropico_t;
    QCheckBox *checkCapCalorificaIsovolumetrica_d, *checkCoefJouleThomson_d, *checkCoefEnforcamento_d, *checkVelocidadeSom_d, *checkCoefIsentropico_d;
    QCheckBox *checkCapCalorificaIsovolumetrica_p, *checkCoefJouleThomson_p, *checkCoefEnforcamento_p, *checkVelocidadeSom_p, *checkCoefIsentropico_p;
    std::string Substancia();/*Funcao para passar a substancia correta para calculo*/
    void EscolherCalculos();/*Funcao para calcular as propriedades que foram selecionadas*/
    void CriadorPopup();/*Cria o pop-up apos ser clicado o botao*/
    CSimuladorPropriedades *sim;
    QDialog *popup;
    QLineEdit *displayDensidade, *displayTemperatura;
    QComboBox *substanciaBox;
};

#endif
