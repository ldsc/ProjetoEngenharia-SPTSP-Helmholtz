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

#include <QtWidgets>
#include <math.h>
#include "CSimuladorPropriedades.h"
#include "botao.h"
#include "SPTSPGUI.h"

SPTSPGUI::SPTSPGUI(QWidget *pai)
    : QWidget(pai)
{
    //Criacao dos espacos para input de dados:
    displayDensidade = new QLineEdit();
    displayTemperatura = new QLineEdit();
    QDoubleValidator* doubleValidator = new QDoubleValidator(0.0, 9999.99999, 5, displayDensidade);
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    displayDensidade->setAlignment(Qt::AlignRight);
    displayDensidade->setValidator(doubleValidator);
    doubleValidator = new QDoubleValidator(0.0, 9999.99999, 5, displayTemperatura);
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    displayTemperatura->setAlignment(Qt::AlignRight);
    displayTemperatura->setValidator(doubleValidator);
    QFont font = displayTemperatura->font();
    font.setPointSize(font.pointSize() + 8);
    displayDensidade->setFont(font);
    displayTemperatura->setFont(font);

    //Criacao das labels para o input:
    QLabel *temperaturaLabel= new QLabel(tr("Temperatura:"));
    QLabel *densidadeLabel= new QLabel(tr("Densidade:"));
    QLabel *substanciaLabel= new QLabel(tr("Substancia:"));

    //Criacao da janela de escolha de substancia:
    substanciaBox= new QComboBox;
    substanciaBox->addItem(tr("Agua"));
    substanciaBox->addItem(tr("Dioxido de Carbono"));
    substanciaBox->addItem(tr("Nitrogenio"));
    substanciaBox->addItem(tr("Metano"));
    substanciaBox->addItem(tr("Etano"));
    substanciaBox->addItem(tr("n-Butano"));
    substanciaBox->addItem(tr("Isobutano"));

    //Criacao do botao:
    Botao *equalButton = criarBotao(tr("Calcular"), SLOT(calcularClicado()));

    //Criacao das caixas de selecao de calculo:
    QLabel *unidadeT = new QLabel(tr("K"));
    QLabel *unidadeD = new QLabel(tr("Kg/m³"));
    checkTodos = criarCheck(tr("Calcular todas as propriedades"),SLOT(checkTodosClicado()));
    QLabel *label1 = new QLabel("Calcular:");
    checkPropriedades = criarCheck(tr("Propriedade"),SLOT(checkPropriedadesClicado()));
    QLabel *label3 = new QLabel("Derivadas da:");
    label3->setAlignment(Qt::AlignRight);
    checkDerTemp = criarCheck(tr("Temperatura"),SLOT(checkDerTempClicado()));
    checkDerDens = criarCheck(tr("Densidade"),SLOT(checkDerDensClicado()));
    checkDerPressao = criarCheck(tr("Pressao"),SLOT(checkDerPressaoClicado()));
    QLabel *labelPressao = new QLabel("Pressao");
    QLabel *labelEntalpia = new QLabel("Entalpia");
    QLabel *labelEntropia = new QLabel("Entropia");
    QLabel *labelEnergiaInterna = new QLabel("Energia interna");
    QLabel *labelEnergiaGibbs = new QLabel("Energia de Gibbs");
    QLabel *labelCapCalorificaIsobarica = new QLabel("Capacidade calorifica isobarica");
    QLabel *labelCapCalorificaIsovolumetrica = new QLabel("Capacidade calorifica isovolumetrica");
    QLabel *labelCoefJouleThomson = new QLabel("Coeficiente de Joule-Thomson");
    QLabel *labelCoefEnforcamento = new QLabel("Coeficiente de enforcamento");
    QLabel *labelVelocidadeSom = new QLabel("Velocidade do som");
    QLabel *labelCoefIsentropico = new QLabel("Coeficiente de temperatura-pressao isentropico");
    checkPressao = new QCheckBox();
    checkEntalpia = new QCheckBox();
    checkEntropia = new QCheckBox();
    checkEnergiaInterna = new QCheckBox();
    checkEnergiaGibbs = new QCheckBox();
    checkCapCalorificaIsobarica = new QCheckBox();
    checkCapCalorificaIsovolumetrica = new QCheckBox();
    checkCoefJouleThomson = new QCheckBox();
    checkCoefEnforcamento = new QCheckBox();
    checkVelocidadeSom = new QCheckBox();
    checkCoefIsentropico = new QCheckBox();
    checkPressao_t = new QCheckBox();
    checkEntalpia_t = new QCheckBox();
    checkEntropia_t = new QCheckBox();
    checkEnergiaInterna_t = new QCheckBox();
    checkEnergiaGibbs_t = new QCheckBox();
    checkCapCalorificaIsobarica_t = new QCheckBox();
    checkCapCalorificaIsovolumetrica_t = new QCheckBox();
    checkCoefJouleThomson_t = new QCheckBox();
    checkCoefEnforcamento_t = new QCheckBox();
    checkVelocidadeSom_t = new QCheckBox();
    checkCoefIsentropico_t = new QCheckBox();
    checkPressao_d = new QCheckBox();
    checkEntalpia_d = new QCheckBox();
    checkEntropia_d = new QCheckBox();
    checkEnergiaInterna_d = new QCheckBox();
    checkEnergiaGibbs_d = new QCheckBox();
    checkCapCalorificaIsobarica_d = new QCheckBox();
    checkCapCalorificaIsovolumetrica_d = new QCheckBox();
    checkCoefJouleThomson_d = new QCheckBox();
    checkCoefEnforcamento_d = new QCheckBox();
    checkVelocidadeSom_d = new QCheckBox();
    checkCoefIsentropico_d = new QCheckBox();
    checkEntalpia_p = new QCheckBox();
    checkEntropia_p = new QCheckBox();
    checkEnergiaInterna_p = new QCheckBox();
    checkEnergiaGibbs_p = new QCheckBox();
    checkCapCalorificaIsobarica_p = new QCheckBox();
    checkCapCalorificaIsovolumetrica_p = new QCheckBox();
    checkCoefJouleThomson_p = new QCheckBox();
    checkCoefEnforcamento_p = new QCheckBox();
    checkVelocidadeSom_p = new QCheckBox();
    checkCoefIsentropico_p = new QCheckBox();

    //Ajuste do layout:
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addWidget(temperaturaLabel, 0, 0, 1, 1);
    mainLayout->addWidget(displayTemperatura, 0, 1, 1, 1);
    mainLayout->addWidget(unidadeT, 0, 2, 1, 1);
    mainLayout->addWidget(densidadeLabel, 0, 3, 1, 1);
    mainLayout->addWidget(displayDensidade, 0, 4, 1, 2);
    mainLayout->addWidget(unidadeD, 0, 6, 1, 1);
    mainLayout->addWidget(substanciaLabel, 1, 0, 1, 1);
    mainLayout->addWidget(substanciaBox, 1, 1, 1, 2);
    mainLayout->addWidget(checkTodos, 1, 3, 1, 3);
    mainLayout->addWidget(label1, 2, 0);
    mainLayout->addWidget(checkPropriedades, 2, 2);
    mainLayout->addWidget(label3, 2, 3);
    mainLayout->addWidget(checkDerTemp, 2, 4);
    mainLayout->addWidget(checkDerDens, 2, 5);
    mainLayout->addWidget(checkDerPressao, 2, 6);
    mainLayout->addWidget(labelPressao, 3, 0, 1 ,2);
    mainLayout->addWidget(labelEntalpia, 4, 0, 1 ,2);
    mainLayout->addWidget(labelEntropia, 5, 0, 1 ,2);
    mainLayout->addWidget(labelEnergiaInterna, 6, 0, 1 ,2);
    mainLayout->addWidget(labelEnergiaGibbs, 7, 0, 1 ,2);
    mainLayout->addWidget(labelCapCalorificaIsobarica, 8, 0, 1 ,2);
    mainLayout->addWidget(labelCapCalorificaIsovolumetrica, 9, 0, 1 ,2);
    mainLayout->addWidget(labelCoefJouleThomson, 10, 0, 1 ,2);
    mainLayout->addWidget(labelCoefEnforcamento, 11, 0, 1 ,2);
    mainLayout->addWidget(labelVelocidadeSom, 12, 0, 1 ,2);
    mainLayout->addWidget(labelCoefIsentropico, 13, 0, 1 ,2);
    mainLayout->addWidget(checkPressao, 3, 2);
    mainLayout->addWidget(checkEntalpia, 4, 2);
    mainLayout->addWidget(checkEntropia, 5, 2);
    mainLayout->addWidget(checkEnergiaInterna, 6, 2);
    mainLayout->addWidget(checkEnergiaGibbs, 7, 2);
    mainLayout->addWidget(checkCapCalorificaIsobarica, 8, 2);
    mainLayout->addWidget(checkCapCalorificaIsovolumetrica, 9, 2);
    mainLayout->addWidget(checkCoefJouleThomson, 10, 2);
    mainLayout->addWidget(checkCoefEnforcamento, 11, 2);
    mainLayout->addWidget(checkVelocidadeSom, 12, 2);
    mainLayout->addWidget(checkCoefIsentropico, 13, 2);
    mainLayout->addWidget(checkPressao_t, 3, 4);
    mainLayout->addWidget(checkEntalpia_t, 4, 4);
    mainLayout->addWidget(checkEntropia_t, 5, 4);
    mainLayout->addWidget(checkEnergiaInterna_t, 6, 4);
    mainLayout->addWidget(checkEnergiaGibbs_t, 7, 4);
    mainLayout->addWidget(checkCapCalorificaIsobarica_t, 8, 4);
    mainLayout->addWidget(checkCapCalorificaIsovolumetrica_t, 9, 4);
    mainLayout->addWidget(checkCoefJouleThomson_t, 10, 4);
    mainLayout->addWidget(checkCoefEnforcamento_t, 11, 4);
    mainLayout->addWidget(checkVelocidadeSom_t, 12, 4);
    mainLayout->addWidget(checkCoefIsentropico_t, 13, 4);
    mainLayout->addWidget(checkPressao_d, 3, 5);
    mainLayout->addWidget(checkEntalpia_d, 4, 5);
    mainLayout->addWidget(checkEntropia_d, 5, 5);
    mainLayout->addWidget(checkEnergiaInterna_d, 6, 5);
    mainLayout->addWidget(checkEnergiaGibbs_d, 7, 5);
    mainLayout->addWidget(checkCapCalorificaIsobarica_d, 8, 5);
    mainLayout->addWidget(checkCapCalorificaIsovolumetrica_d, 9, 5);
    mainLayout->addWidget(checkCoefJouleThomson_d, 10, 5);
    mainLayout->addWidget(checkCoefEnforcamento_d, 11, 5);
    mainLayout->addWidget(checkVelocidadeSom_d, 12, 5);
    mainLayout->addWidget(checkCoefIsentropico_d, 13, 5);
    mainLayout->addWidget(checkEntalpia_p, 4, 6);
    mainLayout->addWidget(checkEntropia_p, 5, 6);
    mainLayout->addWidget(checkEnergiaInterna_p, 6, 6);
    mainLayout->addWidget(checkEnergiaGibbs_p, 7, 6);
    mainLayout->addWidget(checkCapCalorificaIsobarica_p, 8, 6);
    mainLayout->addWidget(checkCapCalorificaIsovolumetrica_p, 9, 6);
    mainLayout->addWidget(checkCoefJouleThomson_p, 10, 6);
    mainLayout->addWidget(checkCoefEnforcamento_p, 11, 6);
    mainLayout->addWidget(checkVelocidadeSom_p, 12, 6);
    mainLayout->addWidget(checkCoefIsentropico_p, 13, 6);
    mainLayout->addWidget(equalButton, 14, 0, 1, 3);
    setLayout(mainLayout);
    setWindowTitle(tr("Calculadora de propriedades"));
}

void SPTSPGUI::EscolherCalculos()
{
    if (checkPressao->isChecked())sim->Pressao();
    if (checkPressao_t->isChecked())sim->Pressao(2);
    if (checkPressao_d->isChecked())sim->Pressao(4);
    if (checkEntalpia->isChecked())sim->Entalpia();
    if (checkEntalpia_t->isChecked())sim->Entalpia(2);
    if (checkEntalpia_d->isChecked())sim->Entalpia(4);
    if (checkEntalpia_p->isChecked())sim->Entalpia(8);
    if (checkEntropia->isChecked())sim->Entropia();
    if (checkEntropia_t->isChecked())sim->Entropia(2);
    if (checkEntropia_d->isChecked())sim->Entropia(4);
    if (checkEntropia_p->isChecked())sim->Entropia(8);
    if (checkEnergiaInterna->isChecked())sim->EnergiaInterna();
    if (checkEnergiaInterna_t->isChecked())sim->EnergiaInterna(2);
    if (checkEnergiaInterna_d->isChecked())sim->EnergiaInterna(4);
    if (checkEnergiaInterna_p->isChecked())sim->EnergiaInterna(8);
    if (checkEnergiaGibbs->isChecked())sim->EnergiaGibbs();
    if (checkEnergiaGibbs_t->isChecked())sim->EnergiaGibbs(2);
    if (checkEnergiaGibbs_d->isChecked())sim->EnergiaGibbs(4);
    if (checkEnergiaGibbs_p->isChecked())sim->EnergiaGibbs(8);
    if (checkCapCalorificaIsobarica->isChecked())sim->CapCalorificaIsobarica();
    if (checkCapCalorificaIsobarica_t->isChecked())sim->CapCalorificaIsobarica(2);
    if (checkCapCalorificaIsobarica_d->isChecked())sim->CapCalorificaIsobarica(4);
    if (checkCapCalorificaIsobarica_p->isChecked())sim->CapCalorificaIsobarica(8);
    if (checkCapCalorificaIsovolumetrica->isChecked())sim->CapCalorificaIsovolumetrica();
    if (checkCapCalorificaIsovolumetrica_t->isChecked())sim->CapCalorificaIsovolumetrica(2);
    if (checkCapCalorificaIsovolumetrica_d->isChecked())sim->CapCalorificaIsovolumetrica(4);
    if (checkCapCalorificaIsovolumetrica_p->isChecked())sim->CapCalorificaIsovolumetrica(8);
    if (checkCoefJouleThomson->isChecked())sim->CoefJouleThomson();
    if (checkCoefJouleThomson_t->isChecked())sim->CoefJouleThomson(2);
    if (checkCoefJouleThomson_d->isChecked())sim->CoefJouleThomson(4);
    if (checkCoefJouleThomson_p->isChecked())sim->CoefJouleThomson(8);
    if (checkCoefEnforcamento->isChecked())sim->CoefEnforcamento();
    if (checkCoefEnforcamento_t->isChecked())sim->CoefEnforcamento(2);
    if (checkCoefEnforcamento_d->isChecked())sim->CoefEnforcamento(4);
    if (checkCoefEnforcamento_p->isChecked())sim->CoefEnforcamento(8);
    if (checkVelocidadeSom->isChecked())sim->VelocidadeSom();
    if (checkVelocidadeSom_t->isChecked())sim->VelocidadeSom(2);
    if (checkVelocidadeSom_d->isChecked())sim->VelocidadeSom(4);
    if (checkVelocidadeSom_p->isChecked())sim->VelocidadeSom(8);
    if (checkCoefIsentropico->isChecked())sim->CoefIsentropico();
    if (checkCoefIsentropico_t->isChecked())sim->CoefIsentropico(2);
    if (checkCoefIsentropico_d->isChecked())sim->CoefIsentropico(4);
    if (checkCoefIsentropico_p->isChecked())sim->CoefIsentropico(8);
}

void SPTSPGUI::CriadorPopup()
{
    popup = new QDialog;
    QGridLayout *layout = new QGridLayout;
    layout->setSizeConstraint(QLayout::SetFixedSize);
    QLabel *inicio = new QLabel("Propriedades");
    QLabel *inicio2 = new QLabel("Valores");
    QLabel *inicio3 = new QLabel("Derivadas em relacao a:");
    QLabel *inicio4 = new QLabel("Temperatura");
    QLabel *inicio5 = new QLabel("Densidade");
    QLabel *inicio6 = new QLabel("Pressao");
    layout->addWidget(inicio, 0, 0, 1, 2);
    layout->addWidget(inicio2, 0, 2, 1, 2);
    layout->addWidget(inicio3, 0, 4, 1, 2);
    layout->addWidget(inicio4, 0, 6, 1, 2);
    layout->addWidget(inicio5, 0, 8, 1, 2);
    layout->addWidget(inicio6, 0, 10, 1, 2);
    //Inicio das propriedades
    //pressao
    if (checkPressao->isChecked()){
        QLabel *resultado_pressao = new QLabel();
        QLabel *label_pressao = new QLabel("Pressao:");
        resultado_pressao->setText(QString::number(sim->substancia.pressao.valor));
        resultado_pressao->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(label_pressao, 1, 0, 1, 2);
        layout->addWidget(resultado_pressao, 1, 2, 1, 2);
    }
    if (checkPressao_t->isChecked()){
        QLabel *resultado_pressao_t = new QLabel();
        if(layout->itemAtPosition(1,0)==0){
            QLabel *label_pressao = new QLabel("Pressao:");
            layout->addWidget(label_pressao, 1, 0, 1, 2);
        }
        resultado_pressao_t->setText(QString::number(sim->substancia.pressao.t));
        resultado_pressao_t->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_pressao_t, 1, 6, 1, 2);
    }
    if (checkPressao_d->isChecked()){
        QLabel *resultado_pressao_d = new QLabel();
        if(layout->itemAtPosition(1,0)==0){
            QLabel *label_pressao = new QLabel("Pressao:");
            layout->addWidget(label_pressao, 1, 0, 1, 2);
        }
        resultado_pressao_d->setText(QString::number(sim->substancia.pressao.d));
        resultado_pressao_d->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_pressao_d, 1, 8, 1, 2);
    }
    //entalpia
    if (checkEntalpia->isChecked()){
        QLabel *resultado_entalpia = new QLabel();
        QLabel *label_entalpia = new QLabel("Entalpia:");
        resultado_entalpia->setText(QString::number(sim->substancia.entalpia.valor));
        resultado_entalpia->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(label_entalpia, 2, 0, 1, 2);
        layout->addWidget(resultado_entalpia, 2, 2, 1, 2);
    }
    if (checkEntalpia_t->isChecked()){
        QLabel *resultado_entalpia_t = new QLabel();
        if(layout->itemAtPosition(2,0)==0){
            QLabel *label_entalpia = new QLabel("Entalpia:");
            layout->addWidget(label_entalpia, 2, 0, 1, 2);
        }
        resultado_entalpia_t->setText(QString::number(sim->substancia.entalpia.t));
        resultado_entalpia_t->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_entalpia_t, 2, 6, 1, 2);
    }
    if (checkEntalpia_d->isChecked()){
        QLabel *resultado_entalpia_d = new QLabel();
        if(layout->itemAtPosition(2,0)==0){
            QLabel *label_entalpia = new QLabel("Entalpia:");
            layout->addWidget(label_entalpia, 2, 0, 1, 2);
        }
        resultado_entalpia_d->setText(QString::number(sim->substancia.entalpia.d));
        resultado_entalpia_d->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_entalpia_d, 2, 8, 1, 2);
    }
    if (checkEntalpia_p->isChecked()){
        QLabel *resultado_entalpia_p = new QLabel();
        if(layout->itemAtPosition(2,0)==0){
            QLabel *label_entalpia = new QLabel("Entalpia:");
            layout->addWidget(label_entalpia, 2, 0, 1, 2);
        }
        resultado_entalpia_p->setText(QString::number(sim->substancia.entalpia.p));
        resultado_entalpia_p->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_entalpia_p, 2, 10, 1, 2);
    }
    //Entropia
    if (checkEntropia->isChecked()){
        QLabel *resultado_entropia = new QLabel();
        QLabel *label_entropia = new QLabel("Entropia:");
        resultado_entropia->setText(QString::number(sim->substancia.entropia.valor));
        resultado_entropia->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(label_entropia, 3, 0, 1, 2);
        layout->addWidget(resultado_entropia, 3, 2, 1, 2);
    }
    if (checkEntropia_t->isChecked()){
        if(layout->itemAtPosition(3,0)==0){
            QLabel *label_entropia = new QLabel("Entropia:");
            layout->addWidget(label_entropia, 3, 0, 1, 2);
        }
        QLabel *resultado_entropia_t = new QLabel();
        resultado_entropia_t->setText(QString::number(sim->substancia.entropia.t));
        resultado_entropia_t->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_entropia_t, 3, 6, 1, 2);
    }
    if (checkEntropia_d->isChecked()){
        if(layout->itemAtPosition(3,0)==0){
            QLabel *label_entropia = new QLabel("Entropia:");
            layout->addWidget(label_entropia, 3, 0, 1, 2);
        }
        QLabel *resultado_entropia_d = new QLabel();
        resultado_entropia_d->setText(QString::number(sim->substancia.entropia.d));
        resultado_entropia_d->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_entropia_d, 3, 8, 1, 2);
    }
    if (checkEntropia_p->isChecked()){
        if(layout->itemAtPosition(3,0)==0){
            QLabel *label_entropia = new QLabel("Entropia:");
            layout->addWidget(label_entropia, 3, 0, 1, 2);
        }
        QLabel *resultado_entropia_p = new QLabel();
        resultado_entropia_p->setText(QString::number(sim->substancia.entropia.p));
        resultado_entropia_p->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_entropia_p, 3, 10, 1, 2);
    }
    //Energia Interna
    if (checkEnergiaInterna->isChecked()){
        QLabel *resultado_energiaInterna = new QLabel();
        QLabel *label_energiaInterna = new QLabel("Energia interna:");
        resultado_energiaInterna->setText(QString::number(sim->substancia.energiaInterna.valor));
        resultado_energiaInterna->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(label_energiaInterna, 4, 0, 1, 2);
        layout->addWidget(resultado_energiaInterna, 4, 2, 1, 2);
    }
    if (checkEnergiaInterna_t->isChecked()){
        if(layout->itemAtPosition(4,0)==0){
            QLabel *label_energiaInterna = new QLabel("Energia Interna:");
            layout->addWidget(label_energiaInterna, 4, 0, 1, 2);
        }
        QLabel *resultado_energiaInterna_t = new QLabel();
        resultado_energiaInterna_t->setText(QString::number(sim->substancia.energiaInterna.t));
        resultado_energiaInterna_t->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_energiaInterna_t, 4, 6, 1, 2);
    }
    if (checkEnergiaInterna_d->isChecked()){
        if(layout->itemAtPosition(4,0)==0){
            QLabel *label_energiaInterna = new QLabel("Energia Interna:");
            layout->addWidget(label_energiaInterna, 4, 0, 1, 2);
        }
        QLabel *resultado_energiaInterna_d = new QLabel();
        resultado_energiaInterna_d->setText(QString::number(sim->substancia.energiaInterna.d));
        resultado_energiaInterna_d->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_energiaInterna_d, 4, 8, 1, 2);
    }
    if (checkEnergiaInterna_p->isChecked()){
        if(layout->itemAtPosition(4,0)==0){
            QLabel *label_energiaInterna = new QLabel("Energia Interna:");
            layout->addWidget(label_energiaInterna, 4, 0, 1, 2);
        }
        QLabel *resultado_energiaInterna_p = new QLabel();
        resultado_energiaInterna_p->setText(QString::number(sim->substancia.energiaInterna.p));
        resultado_energiaInterna_p->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_energiaInterna_p, 4, 10, 1, 2);
    }
    //Energia Gibbs
    if (checkEnergiaGibbs->isChecked()){
        QLabel *resultado_energiaGibbs = new QLabel();
        QLabel *label_energiaGibbs = new QLabel("Energia de Gibbs:");
        resultado_energiaGibbs->setText(QString::number(sim->substancia.energiaGibbs.valor));
        resultado_energiaGibbs->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(label_energiaGibbs, 5, 0, 1, 2);
        layout->addWidget(resultado_energiaGibbs, 5, 2, 1, 2);
    }
    if (checkEnergiaGibbs_t->isChecked()){
        if(layout->itemAtPosition(5,0)==0){
            QLabel *label_energiaGibbs = new QLabel("Energia Interna:");
            layout->addWidget(label_energiaGibbs, 5, 0, 1, 2);
        }
        QLabel *resultado_energiaGibbs_t = new QLabel();
        resultado_energiaGibbs_t->setText(QString::number(sim->substancia.energiaGibbs.t));
        resultado_energiaGibbs_t->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_energiaGibbs_t, 5, 6, 1, 2);
    }
    if (checkEnergiaGibbs_d->isChecked()){
        if(layout->itemAtPosition(5,0)==0){
            QLabel *label_energiaGibbs = new QLabel("Energia Interna:");
            layout->addWidget(label_energiaGibbs, 5, 0, 1, 2);
        }
        QLabel *resultado_energiaGibbs_d = new QLabel();
        resultado_energiaGibbs_d->setText(QString::number(sim->substancia.energiaGibbs.d));
        resultado_energiaGibbs_d->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_energiaGibbs_d, 5, 8, 1, 2);
    }
    if (checkEnergiaGibbs_p->isChecked()){
        if(layout->itemAtPosition(5,0)==0){
            QLabel *label_energiaGibbs = new QLabel("Energia Interna:");
            layout->addWidget(label_energiaGibbs, 5, 0, 1, 2);
        }
        QLabel *resultado_energiaGibbs_p = new QLabel();
        resultado_energiaGibbs_p->setText(QString::number(sim->substancia.energiaGibbs.p));
        resultado_energiaGibbs_p->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_energiaGibbs_p, 5, 10, 1, 2);
    }
    //Capacidade Calorifica Isobarica
    if (checkCapCalorificaIsobarica->isChecked()){
        QLabel *resultado_CapCalorificaIsobarica = new QLabel();
        QLabel *label_CapCalorificaIsobarica = new QLabel("Capacidade Calorifica Isobarica:");
        resultado_CapCalorificaIsobarica->setText(QString::number(sim->substancia.capCalorificaIsobarica.valor));
        resultado_CapCalorificaIsobarica->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(label_CapCalorificaIsobarica, 6, 0, 1, 2);
        layout->addWidget(resultado_CapCalorificaIsobarica, 6, 2, 1, 2);
    }
    if (checkCapCalorificaIsobarica_t->isChecked()){
        if(layout->itemAtPosition(6,0)==0){
            QLabel *label_CapCalorificaIsobarica = new QLabel("Energia Interna:");
            layout->addWidget(label_CapCalorificaIsobarica, 6, 0, 1, 2);
        }
        QLabel *resultado_CapCalorificaIsobarica_t = new QLabel();
        resultado_CapCalorificaIsobarica_t->setText(QString::number(sim->substancia.capCalorificaIsobarica.t));
        resultado_CapCalorificaIsobarica_t->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_CapCalorificaIsobarica_t, 6, 6, 1, 2);
    }
    if (checkCapCalorificaIsobarica_d->isChecked()){
        if(layout->itemAtPosition(6,0)==0){
            QLabel *label_CapCalorificaIsobarica = new QLabel("Energia Interna:");
            layout->addWidget(label_CapCalorificaIsobarica, 6, 0, 1, 2);
        }
        QLabel *resultado_CapCalorificaIsobarica_d = new QLabel();
        resultado_CapCalorificaIsobarica_d->setText(QString::number(sim->substancia.capCalorificaIsobarica.d));
        resultado_CapCalorificaIsobarica_d->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_CapCalorificaIsobarica_d, 6, 8, 1, 2);
    }
    if (checkCapCalorificaIsobarica_p->isChecked()){
        if(layout->itemAtPosition(6,0)==0){
            QLabel *label_CapCalorificaIsobarica = new QLabel("Energia Interna:");
            layout->addWidget(label_CapCalorificaIsobarica, 6, 0, 1, 2);
        }
        QLabel *resultado_CapCalorificaIsobarica_p = new QLabel();
        resultado_CapCalorificaIsobarica_p->setText(QString::number(sim->substancia.capCalorificaIsobarica.p));
        resultado_CapCalorificaIsobarica_p->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_CapCalorificaIsobarica_p, 6, 10, 1, 2);
    }
    //Capacidade Calorifica Isocorica
    if (checkCapCalorificaIsovolumetrica->isChecked()){
        QLabel *resultado_CapCalorificaIsovolumetrica = new QLabel();
        QLabel *label_CapCalorificaIsovolumetrica = new QLabel("Capacidade Calorifica Isovolumetrica:");
        resultado_CapCalorificaIsovolumetrica->setText(QString::number(sim->substancia.capCalorificaIsovolumetrica.valor));
        resultado_CapCalorificaIsovolumetrica->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(label_CapCalorificaIsovolumetrica, 7, 0, 1, 2);
        layout->addWidget(resultado_CapCalorificaIsovolumetrica, 7, 2, 1, 2);
    }
    if (checkCapCalorificaIsovolumetrica_t->isChecked()){
        if(layout->itemAtPosition(7,0)==0){
            QLabel *label_CapCalorificaIsovolumetrica = new QLabel("Energia Interna:");
            layout->addWidget(label_CapCalorificaIsovolumetrica, 7, 0, 1, 2);
        }
        QLabel *resultado_CapCalorificaIsovolumetrica_t = new QLabel();
        resultado_CapCalorificaIsovolumetrica_t->setText(QString::number(sim->substancia.capCalorificaIsovolumetrica.t));
        resultado_CapCalorificaIsovolumetrica_t->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_CapCalorificaIsovolumetrica_t, 7, 6, 1, 2);
    }
    if (checkCapCalorificaIsovolumetrica_d->isChecked()){
        if(layout->itemAtPosition(7,0)==0){
            QLabel *label_CapCalorificaIsovolumetrica = new QLabel("Energia Interna:");
            layout->addWidget(label_CapCalorificaIsovolumetrica, 7, 0, 1, 2);
        }
        QLabel *resultado_CapCalorificaIsovolumetrica_d = new QLabel();
        resultado_CapCalorificaIsovolumetrica_d->setText(QString::number(sim->substancia.capCalorificaIsovolumetrica.d));
        resultado_CapCalorificaIsovolumetrica_d->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_CapCalorificaIsovolumetrica_d, 7, 8, 1, 2);
    }
    if (checkCapCalorificaIsovolumetrica_p->isChecked()){
        if(layout->itemAtPosition(7,0)==0){
            QLabel *label_CapCalorificaIsovolumetrica = new QLabel("Energia Interna:");
            layout->addWidget(label_CapCalorificaIsovolumetrica, 7, 0, 1, 2);
        }
        QLabel *resultado_CapCalorificaIsovolumetrica_p = new QLabel();
        resultado_CapCalorificaIsovolumetrica_p->setText(QString::number(sim->substancia.capCalorificaIsovolumetrica.p));
        resultado_CapCalorificaIsovolumetrica_p->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_CapCalorificaIsovolumetrica_p, 7, 10, 1, 2);
    }
    //Coeficiente de Joule-Thomson
    if (checkCoefJouleThomson->isChecked()){
        QLabel *resultado_CoefJouleThomson= new QLabel();
        QLabel *label_CoefJouleThomson= new QLabel("Coeficiente de Joule-Thomson:");
        resultado_CoefJouleThomson->setText(QString::number(sim->substancia.coefJouleThomson.valor));
        resultado_CoefJouleThomson->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(label_CoefJouleThomson, 8, 0, 1, 2);
        layout->addWidget(resultado_CoefJouleThomson, 8, 2, 1, 2);
    }
    if (checkCoefJouleThomson_t->isChecked()){
        if(layout->itemAtPosition(8,0)==0){
            QLabel *label_CoefJouleThomson = new QLabel("Energia Interna:");
            layout->addWidget(label_CoefJouleThomson, 8, 0, 1, 2);
        }
        QLabel *resultado_CoefJouleThomson_t = new QLabel();
        resultado_CoefJouleThomson_t->setText(QString::number(sim->substancia.coefJouleThomson.t));
        resultado_CoefJouleThomson_t->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_CoefJouleThomson_t, 8, 6, 1, 2);
    }
    if (checkCoefJouleThomson_d->isChecked()){
        if(layout->itemAtPosition(8,0)==0){
            QLabel *label_CoefJouleThomson = new QLabel("Energia Interna:");
            layout->addWidget(label_CoefJouleThomson, 8, 0, 1, 2);
        }
        QLabel *resultado_CoefJouleThomson_d = new QLabel();
        resultado_CoefJouleThomson_d->setText(QString::number(sim->substancia.coefJouleThomson.d));
        resultado_CoefJouleThomson_d->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_CoefJouleThomson_d, 8, 8, 1, 2);
    }
    if (checkCoefJouleThomson_p->isChecked()){
        if(layout->itemAtPosition(8,0)==0){
            QLabel *label_CoefJouleThomson = new QLabel("Energia Interna:");
            layout->addWidget(label_CoefJouleThomson, 8, 0, 1, 2);
        }
        QLabel *resultado_CoefJouleThomson_p = new QLabel();
        resultado_CoefJouleThomson_p->setText(QString::number(sim->substancia.coefJouleThomson.p));
        resultado_CoefJouleThomson_p->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_CoefJouleThomson_p, 8, 10, 1, 2);
    }
    //Coeficiente de enforcamento
    if (checkCoefEnforcamento->isChecked()){
        QLabel *resultado_CoefEnforcamento= new QLabel();
        QLabel *label_CoefEnforcamento= new QLabel("Coeficiente de Enforcamento:");
        resultado_CoefEnforcamento->setText(QString::number(sim->substancia.coefEnforcamento.valor));
        resultado_CoefEnforcamento->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(label_CoefEnforcamento, 9, 0, 1, 2);
        layout->addWidget(resultado_CoefEnforcamento, 9, 2, 1, 2);
    }
    if (checkCoefEnforcamento_t->isChecked()){
        if(layout->itemAtPosition(9,0)==0){
            QLabel *label_CoefEnforcamento = new QLabel("Energia Interna:");
            layout->addWidget(label_CoefEnforcamento, 9, 0, 1, 2);
        }
        QLabel *resultado_CoefEnforcamento_t = new QLabel();
        resultado_CoefEnforcamento_t->setText(QString::number(sim->substancia.coefEnforcamento.t));
        resultado_CoefEnforcamento_t->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_CoefEnforcamento_t, 9, 6, 1, 2);
    }
    if (checkCoefEnforcamento_d->isChecked()){
        if(layout->itemAtPosition(9,0)==0){
            QLabel *label_CoefEnforcamento = new QLabel("Energia Interna:");
            layout->addWidget(label_CoefEnforcamento, 9, 0, 1, 2);
        }
        QLabel *resultado_CoefEnforcamento_d = new QLabel();
        resultado_CoefEnforcamento_d->setText(QString::number(sim->substancia.coefEnforcamento.d));
        resultado_CoefEnforcamento_d->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_CoefEnforcamento_d, 9, 8, 1, 2);
    }
    if (checkCoefEnforcamento_p->isChecked()){
        if(layout->itemAtPosition(9,0)==0){
            QLabel *label_CoefEnforcamento = new QLabel("Energia Interna:");
            layout->addWidget(label_CoefEnforcamento, 9, 0, 1, 2);
        }
        QLabel *resultado_CoefEnforcamento_p = new QLabel();
        resultado_CoefEnforcamento_p->setText(QString::number(sim->substancia.coefEnforcamento.p));
        resultado_CoefEnforcamento_p->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_CoefEnforcamento_p, 9, 10, 1, 2);
    }
    //Velocidade do som
    if (checkVelocidadeSom->isChecked()){
        QLabel *resultado_VelocidadeSom= new QLabel();
        QLabel *label_VelocidadeSom= new QLabel("Velocidade do Som:");
        resultado_VelocidadeSom->setText(QString::number(sim->substancia.velocidadeSom.valor));
        resultado_VelocidadeSom->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(label_VelocidadeSom, 10, 0, 1, 2);
        layout->addWidget(resultado_VelocidadeSom, 10, 2, 1, 2);
    }
    if (checkVelocidadeSom_t->isChecked()){
        if(layout->itemAtPosition(10,0)==0){
            QLabel *label_VelocidadeSom = new QLabel("Energia Interna:");
            layout->addWidget(label_VelocidadeSom, 10, 0, 1, 2);
        }
        QLabel *resultado_VelocidadeSom_t = new QLabel();
        resultado_VelocidadeSom_t->setText(QString::number(sim->substancia.velocidadeSom.t));
        resultado_VelocidadeSom_t->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_VelocidadeSom_t, 10, 6, 1, 2);
    }
    if (checkVelocidadeSom_d->isChecked()){
        if(layout->itemAtPosition(10,0)==0){
            QLabel *label_VelocidadeSom = new QLabel("Energia Interna:");
            layout->addWidget(label_VelocidadeSom, 10, 0, 1, 2);
        }
        QLabel *resultado_VelocidadeSom_d = new QLabel();
        resultado_VelocidadeSom_d->setText(QString::number(sim->substancia.velocidadeSom.d));
        resultado_VelocidadeSom_d->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_VelocidadeSom_d, 10, 8, 1, 2);
    }
    if (checkVelocidadeSom_p->isChecked()){
        if(layout->itemAtPosition(10,0)==0){
            QLabel *label_VelocidadeSom = new QLabel("Energia Interna:");
            layout->addWidget(label_VelocidadeSom, 10, 0, 1, 2);
        }
        QLabel *resultado_VelocidadeSom_p = new QLabel();
        resultado_VelocidadeSom_p->setText(QString::number(sim->substancia.velocidadeSom.p));
        resultado_VelocidadeSom_p->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_VelocidadeSom_p, 10, 10, 1, 2);
    }
    //Coeficiente de temperatura-pressao isentropico
    if (checkCoefIsentropico->isChecked()){
        QLabel *resultado_CoefIsentropico= new QLabel();
        QLabel *label_CoefIsentropico= new QLabel("Coeficiente Isentropico:");
        resultado_CoefIsentropico->setText(QString::number(sim->substancia.coefIsentropico.valor));
        resultado_CoefIsentropico->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(label_CoefIsentropico, 11, 0, 1, 2);
        layout->addWidget(resultado_CoefIsentropico, 11, 2, 1, 2);
    }
    if (checkCoefIsentropico_t->isChecked()){
        if(layout->itemAtPosition(11,0)==0){
            QLabel *label_CoefIsentropico = new QLabel("Energia Interna:");
            layout->addWidget(label_CoefIsentropico, 11, 0, 1, 2);
        }
        QLabel *resultado_CoefIsentropico_t = new QLabel();
        resultado_CoefIsentropico_t->setText(QString::number(sim->substancia.coefIsentropico.t));
        resultado_CoefIsentropico_t->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_CoefIsentropico_t, 11, 6, 1, 2);
    }
    if (checkCoefIsentropico_d->isChecked()){
        if(layout->itemAtPosition(11,0)==0){
            QLabel *label_CoefIsentropico = new QLabel("Energia Interna:");
            layout->addWidget(label_CoefIsentropico, 11, 0, 1, 2);
        }
        QLabel *resultado_CoefIsentropico_d = new QLabel();
        resultado_CoefIsentropico_d->setText(QString::number(sim->substancia.coefIsentropico.d));
        resultado_CoefIsentropico_d->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_CoefIsentropico_d, 11, 8, 1, 2);
    }
    if (checkCoefIsentropico_p->isChecked()){
        if(layout->itemAtPosition(11,0)==0){
            QLabel *label_CoefIsentropico = new QLabel("Energia Interna:");
            layout->addWidget(label_CoefIsentropico, 11, 0, 1, 2);
        }
        QLabel *resultado_CoefIsentropico_p = new QLabel();
        resultado_CoefIsentropico_p->setText(QString::number(sim->substancia.coefIsentropico.p));
        resultado_CoefIsentropico_p->setTextInteractionFlags(Qt::TextSelectableByMouse);
        layout->addWidget(resultado_CoefIsentropico_p, 11, 10, 1, 2);
    }
    //Fim das propriedades
    Botao *botaoSalvar = criarBotao(tr("Salvar em disco"), SLOT(SalvarEmDisco()));
    layout->addWidget(botaoSalvar, 12, 0, 1, 3);
    popup->setLayout(layout);
}
Botao *SPTSPGUI::criarBotao(const QString &texto, const char *membro)
{
    Botao *botao = new Botao(texto);
    connect(botao, SIGNAL(clicked()), this, membro);
    return botao;
}
QCheckBox *SPTSPGUI::criarCheck(const QString &texto, const char *membro)
{
    QCheckBox *check = new QCheckBox(texto);
    connect(check, SIGNAL(stateChanged(int)), this, membro);
    return check;
}

std::string SPTSPGUI::Substancia()
{
    switch (substanciaBox->currentIndex())
    {
        case 0:
        return "H2O";
        break;
        case 1:
        return "CO2";
        break;
        case 2:
        return "N2";
        break;
        case 3:
        return "CH4";
        break;
        case 4:
        return "C2H6";
        break;
        case 5:
        return "nC4H10";
        break;
        case 6:
        return "iC4H10";
        break;
    }
    return " ";
}

void SPTSPGUI::calcularClicado()
{
    sim= new CSimuladorPropriedades(Substancia(),displayTemperatura->text().toDouble(),displayDensidade->text().toDouble());
    EscolherCalculos();
    CriadorPopup();
    popup->show();
}

void SPTSPGUI::SalvarEmDisco()
{
    QString filePath;
    filePath = QFileDialog::getSaveFileName(this,
                                            "Escolha o arquivo de saida...",
                                            filePath,
                                            "Arquivos de saida(*.dat)");
    QFile file(filePath);
    QTextStream out(&file);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        out.setFieldWidth(50);
        out.setFieldAlignment(QTextStream::AlignLeft);
        out << "Propriedade";
        out.setFieldWidth(14);
        out << "Valor";
        if (checkPressao->isChecked()){
            out.setFieldWidth(50);
            out.setFieldAlignment(QTextStream::AlignLeft);
            out << "\nPressao";
            out.setFieldWidth(14);
            out << sim->substancia.pressao.valor;
        }
        if (checkEntalpia->isChecked()){
            out.setFieldWidth(50);
            out.setFieldAlignment(QTextStream::AlignLeft);
            out << "\nEntalpia";
            out.setFieldWidth(14);
            out << sim->substancia.entalpia.valor;
        }
        if (checkEntropia->isChecked()){
            out.setFieldWidth(50);
            out.setFieldAlignment(QTextStream::AlignLeft);
            out << "\nEntropia";
            out.setFieldWidth(14);
            out << sim->substancia.entropia.valor;
        }
        if (checkEnergiaInterna->isChecked()){
            out.setFieldWidth(50);
            out.setFieldAlignment(QTextStream::AlignLeft);
            out << "\nEnergia Interna";
            out.setFieldWidth(14);
            out << sim->substancia.energiaInterna.valor;
        }
        if (checkEnergiaGibbs->isChecked()){
            out.setFieldWidth(50);
            out.setFieldAlignment(QTextStream::AlignLeft);
            out << "\nEnergia de Gibbs";
            out.setFieldWidth(14);
            out << sim->substancia.energiaGibbs.valor;
        }
        if (checkCapCalorificaIsobarica->isChecked()){
            out.setFieldWidth(50);
            out.setFieldAlignment(QTextStream::AlignLeft);
            out << "\nCapacidade Calorifica Isobarica";
            out.setFieldWidth(14);
            out << sim->substancia.capCalorificaIsobarica.valor;
        }
        if (checkCapCalorificaIsovolumetrica->isChecked()){
            out.setFieldWidth(50);
            out.setFieldAlignment(QTextStream::AlignLeft);
            out << "\nCapacidade Calorifica Isovolumetrica";
            out.setFieldWidth(14);
            out << sim->substancia.capCalorificaIsovolumetrica.valor;
        }
        if (checkCoefJouleThomson->isChecked()){
            out.setFieldWidth(50);
            out.setFieldAlignment(QTextStream::AlignLeft);
            out << "\nCoeficiente de Joule-Thomson";
            out.setFieldWidth(14);
            out << sim->substancia.coefJouleThomson.valor;
        }
        if (checkCoefEnforcamento->isChecked()){
            out.setFieldWidth(50);
            out.setFieldAlignment(QTextStream::AlignLeft);
            out << "\nCoeficiente de Enforcamento";
            out.setFieldWidth(14);
            out << sim->substancia.coefEnforcamento.valor;
        }
        if (checkVelocidadeSom->isChecked()){
            out.setFieldWidth(50);
            out.setFieldAlignment(QTextStream::AlignLeft);
            out << "\nVelocidade do Som";
            out.setFieldWidth(14);
            out << sim->substancia.velocidadeSom.valor;
        }
        if (checkCoefIsentropico->isChecked()){
            out.setFieldWidth(50);
            out.setFieldAlignment(QTextStream::AlignLeft);
            out << "\nCoeficiente de temperatura-pressao Isentropico";
            out.setFieldWidth(14);
            out << sim->substancia.coefIsentropico.valor;
        }
        out << "\nDerivadas em relacao a:\n";
        out.setFieldWidth(12);
        out.setFieldAlignment(QTextStream::AlignLeft);
        out << "Temperatura";
        out.setFieldWidth(12);
        out.setFieldAlignment(QTextStream::AlignLeft);
        out << "Densidade";
        out.setFieldWidth(12);
        out << "Pressao\n";
        if (checkPressao_t->isChecked()){
            out.setFieldWidth(12);
            out.setFieldAlignment(QTextStream::AlignLeft);
            out << sim->substancia.pressao.t;
        }else{out.setFieldWidth(12);
            out << " ";}
        if (checkPressao_d->isChecked()){
            out.setFieldWidth(12);
            out.setFieldAlignment(QTextStream::AlignLeft);
            out << sim->substancia.pressao.d;
        }
        out << "\n";
        if (checkEntalpia_t->isChecked()){
            out.setFieldAlignment(QTextStream::AlignLeft);
            out.setFieldWidth(12);
            out << sim->substancia.entalpia.t;
        }else{out.setFieldWidth(12);
            out << " ";}
        if (checkEntalpia_d->isChecked()){
            out.setFieldAlignment(QTextStream::AlignLeft);
            out.setFieldWidth(12);
            out << sim->substancia.entalpia.d;
        }else{out.setFieldWidth(12);
            out << " ";}
        if (checkEntalpia_p->isChecked()){
            out.setFieldWidth(12);
            out << sim->substancia.entalpia.p;
        }
        out<< '\n';
        if (checkEntropia->isChecked()){
            out.setFieldWidth(25);
            out << " ";
            out.setFieldWidth(12);
            out << sim->substancia.entropia.valor;
        }
        if (checkEnergiaInterna->isChecked()){
            out.setFieldWidth(25);
            out << " ";
            out.setFieldWidth(12);
            out << sim->substancia.energiaInterna.valor;
        }
        if (checkEnergiaGibbs->isChecked()){
            out.setFieldWidth(25);
            out << " ";
            out.setFieldWidth(12);
            out << sim->substancia.energiaGibbs.valor;
        }
        if (checkCapCalorificaIsobarica->isChecked()){
            out.setFieldWidth(25);
            out << " ";
            out.setFieldWidth(12);
            out << sim->substancia.capCalorificaIsobarica.valor;
        }
        if (checkCapCalorificaIsovolumetrica->isChecked()){
            out.setFieldWidth(25);
            out << " ";
            out.setFieldWidth(12);
            out << sim->substancia.capCalorificaIsovolumetrica.valor;
        }
        if (checkCoefJouleThomson->isChecked()){
            out.setFieldWidth(25);
            out << " ";
            out.setFieldWidth(12);
            out << sim->substancia.coefJouleThomson.valor;
        }
        if (checkCoefEnforcamento->isChecked()){
            out.setFieldWidth(25);
            out << " ";
            out.setFieldWidth(12);
            out << sim->substancia.coefEnforcamento.valor;
        }
        if (checkVelocidadeSom->isChecked()){
            out.setFieldWidth(25);
            out << " ";
            out.setFieldWidth(12);
            out << sim->substancia.velocidadeSom.valor;
        }
        if (checkCoefIsentropico->isChecked()){
            out.setFieldWidth(25);
            out << " ";
            out.setFieldWidth(12);
            out << sim->substancia.coefIsentropico.valor;
        }
    }
    file.close();
}

void SPTSPGUI::checkTodosClicado()
{
    bool temp=checkTodos->isChecked();
    checkPropriedades->setChecked(temp);
    checkDerTemp->setChecked(temp);
    checkDerDens->setChecked(temp);
    checkDerPressao->setChecked(temp);
}

void SPTSPGUI::checkPropriedadesClicado()
{
    bool temp = checkPropriedades->isChecked();
    checkPressao->setChecked(temp);
    checkEntalpia->setChecked(temp);
    checkEntropia->setChecked(temp);
    checkEnergiaInterna->setChecked(temp);
    checkEnergiaGibbs->setChecked(temp);
    checkCapCalorificaIsobarica->setChecked(temp);
    checkCapCalorificaIsovolumetrica->setChecked(temp);
    checkCoefJouleThomson->setChecked(temp);
    checkCoefEnforcamento->setChecked(temp);
    checkVelocidadeSom->setChecked(temp);
    checkCoefIsentropico->setChecked(temp);
}

void SPTSPGUI::checkDerTempClicado()
{
    bool temp = checkDerTemp->isChecked();
    checkPressao_t->setChecked(temp);
    checkEntalpia_t->setChecked(temp);
    checkEntropia_t->setChecked(temp);
    checkEnergiaInterna_t->setChecked(temp);
    checkEnergiaGibbs_t->setChecked(temp);
    checkCapCalorificaIsobarica_t->setChecked(temp);
    checkCapCalorificaIsovolumetrica_t->setChecked(temp);
    checkCoefJouleThomson_t->setChecked(temp);
    checkCoefEnforcamento_t->setChecked(temp);
    checkVelocidadeSom_t->setChecked(temp);
    checkCoefIsentropico_t->setChecked(temp);
}

void SPTSPGUI::checkDerDensClicado()
{
    bool temp = checkDerDens->isChecked();
    checkPressao_d->setChecked(temp);
    checkEntalpia_d->setChecked(temp);
    checkEntropia_d->setChecked(temp);
    checkEnergiaInterna_d->setChecked(temp);
    checkEnergiaGibbs_d->setChecked(temp);
    checkCapCalorificaIsobarica_d->setChecked(temp);
    checkCapCalorificaIsovolumetrica_d->setChecked(temp);
    checkCoefJouleThomson_d->setChecked(temp);
    checkCoefEnforcamento_d->setChecked(temp);
    checkVelocidadeSom_d->setChecked(temp);
    checkCoefIsentropico_d->setChecked(temp);
}

void SPTSPGUI::checkDerPressaoClicado()
{
    bool temp = checkDerPressao->isChecked();
    checkEntalpia_p->setChecked(temp);
    checkEntropia_p->setChecked(temp);
    checkEnergiaInterna_p->setChecked(temp);
    checkEnergiaGibbs_p->setChecked(temp);
    checkCapCalorificaIsobarica_p->setChecked(temp);
    checkCapCalorificaIsovolumetrica_p->setChecked(temp);
    checkCoefJouleThomson_p->setChecked(temp);
    checkCoefEnforcamento_p->setChecked(temp);
    checkVelocidadeSom_p->setChecked(temp);
    checkCoefIsentropico_p->setChecked(temp);
}
