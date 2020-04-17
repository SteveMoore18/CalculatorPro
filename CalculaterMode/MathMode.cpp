//
//  MathMode.cpp
//  CalculatorPro
//
//  Created by Савелий Никулин on 17.04.2020.
//

#include "MathMode.hpp"

#include <QDebug>

MathMode::MathMode(QWidget *parent)
    : QWidget(parent)
{
    normalMode = new NormalMode(this);
    mainLayout = new QHBoxLayout;
    mathLayout = new QGridLayout;
    
    btnPow2 = new QPushButton(this);
    btnPow2->setText("x2");
    
    mainLayout->addWidget(btnPow2);
    mainLayout->addWidget(normalMode);
    
    connect(btnPow2, SIGNAL(clicked()), this, SLOT(on_btnPow2_clicked()));
    
    setLayout(mainLayout);
}

void MathMode::on_btnPow2_clicked()
{
    emit buttonClicked("<sup>2</sup>");
}
