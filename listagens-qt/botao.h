#ifndef BOTAO_H
#define BOTAO_H
#include <QToolButton>
////////////////////////////////////////////////////////////////////////
/// @author Thomas Augusto Menegazzo
/// @class Botao
/// @file Botao.h
/// @brief Classe para cria��o do bot�o com as propriedades corretas.
////////////////////////////////////////////////////////////////////////
class Botao : public QToolButton
{
    Q_OBJECT

public:
    ///Construtor.
    ///@param texto Texto no bot�o.
    explicit Botao(const QString &texto, QWidget *pai = 0);

    ///Tamanho do bot�o.
    QSize sizeHint() const;
};
#endif
