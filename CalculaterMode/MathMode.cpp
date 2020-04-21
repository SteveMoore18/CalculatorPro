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
    btnSqrt = new QPushButton(this);
    btnSin = new QPushButton(this);
    btnCos = new QPushButton(this);
    btnTan = new QPushButton(this);
    btnCtg = new QPushButton(this);
    
    
    btnPow2->setText("xʸ");
    btnSqrt->setText("√");
    btnSin->setText("sin");
    btnCos->setText("cos");
    btnTan->setText("tan");
    btnCtg->setText("ctg");
    
    
    btnPow2->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnSqrt->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnSin->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnCos->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnTan->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnCtg->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    
    
    mathLayout->addWidget(btnPow2, 0, 0);
    mathLayout->addWidget(btnSqrt, 0, 1);
    mathLayout->addWidget(btnSin, 1, 0);
    mathLayout->addWidget(btnCos, 1, 1);
    mathLayout->addWidget(btnTan, 2, 0);
    mathLayout->addWidget(btnCtg, 2, 1);
    
    mainLayout->addLayout(mathLayout);
    mainLayout->addWidget(normalMode);
    
    connect(btnPow2, SIGNAL(clicked()), this, SLOT(on_btnPow2_clicked()));
    connect(btnSqrt, SIGNAL(clicked()), this, SLOT(on_btnSqrt_clicked()));
    connect(normalMode, SIGNAL(buttonClicked(QString)), this, SLOT(on_normalMode_clicked(QString)));
    
    setLayout(mainLayout);
}

void MathMode::on_normalMode_clicked(const QString &textButton)
{
    emit buttonClicked(textButton);
}

void MathMode::on_btnPow2_clicked()
{
    btnPowClicked = true;
    emit buttonClicked("^");
}

void MathMode::on_btnSqrt_clicked()
{
    emit buttonClicked("√");
}
