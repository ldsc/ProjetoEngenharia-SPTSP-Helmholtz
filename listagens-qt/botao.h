#ifndef BOTAO_H
#define BOTAO_H
#include <QToolButton>
////////////////////////////////////////////////////////////////////////
/// @author Thomas Augusto Menegazzo
/// @class Botao
/// @file Botao.h
/// @brief Classe para criação do botão com as propriedades corretas.
////////////////////////////////////////////////////////////////////////
class Botao : public QToolButton
{
    Q_OBJECT

public:
    ///Construtor.
    ///@param texto Texto no botão.
    explicit Botao(const QString &texto, QWidget *pai = 0);

    ///Tamanho do botão.
    QSize sizeHint() const;
};
#endif
