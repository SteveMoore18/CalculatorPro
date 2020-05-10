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
    
    displayEdit = nullptr;
    
    trigMode = TrigMode::RADIAN;
    
    btnPow2 = new QPushButton(this);
    btnSqrt = new QPushButton(this);
    btnSin =  new QPushButton(this);
    btnCos =  new QPushButton(this);
    btnTan =  new QPushButton(this);
    btnCtg =  new QPushButton(this);
    btnTrigMode = new QPushButton(this);
    btnPi =   new QPushButton(this);
    btnE =    new QPushButton(this);
    btnLog10 = new QPushButton(this);
    btnLog2 = new QPushButton(this);
    btnLn =   new QPushButton(this);
    
    
    btnPow2->setText("xʸ");
    btnSqrt->setText("√");
    btnSin->setText("sin");
    btnCos->setText("cos");
    btnTan->setText("tan");
    btnCtg->setText("ctg");
    btnTrigMode->setText("Rad");
    btnPi->setText("π");
    btnE->setText("e");
    btnLog10->setText("log₁₀");
    btnLog2->setText("log₂");
    btnLn->setText("lnₑ");
    
    btnPow2->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnPow2->setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding );
    btnSqrt->setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding );
    btnSin->setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding );
    btnCos->setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding );
    btnTan->setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding );
    btnCtg->setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding );
    btnPi->setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding );
    btnTrigMode->setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding );
    btnE->setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding );
    btnLog10->setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding );
    btnLog2->setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding );
    btnLn->setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding );
    
    normalMode->getMainLayout()->setMargin(0);
    
    mathLayout->addWidget(btnPow2, 0, 0);
    mathLayout->addWidget(btnSqrt, 0, 1);
    mathLayout->addWidget(btnTrigMode, 0, 2);
    mathLayout->addWidget(btnSin, 1, 0);
    mathLayout->addWidget(btnCos, 1, 1);
    mathLayout->addWidget(btnPi, 1, 2);
    mathLayout->addWidget(btnTan, 2, 0);
    mathLayout->addWidget(btnCtg, 2, 1);
    mathLayout->addWidget(btnE, 2, 2);
    mathLayout->addWidget(btnLog2, 3, 0);
    mathLayout->addWidget(btnLn, 3, 1);
    mathLayout->addWidget(btnLog10, 3, 2);
    
    mainLayout->addLayout(mathLayout);
    mainLayout->addWidget(normalMode);
    
    //mainLayout->setSpacing(0);
    
    connect(btnPow2, SIGNAL(clicked()), this, SLOT(on_btnPow2_clicked()));
    connect(btnSqrt, SIGNAL(clicked()), this, SLOT(on_btnSqrt_clicked()));
    connect(btnSin,  SIGNAL(clicked()), this, SLOT(on_btnSin_clicked()));
    connect(btnCos,  SIGNAL(clicked()), this, SLOT(on_btnCos_clicked()));
    connect(btnTan,  SIGNAL(clicked()), this, SLOT(on_btnTan_clicked()));
    connect(btnCtg,  SIGNAL(clicked()), this, SLOT(on_btnCtg_clicked()));
    connect(btnPi,   SIGNAL(clicked()), this, SLOT(on_btnPi_clicked()));
    connect(btnE,    SIGNAL(clicked()), this, SLOT(on_btnE_clicked()));
    connect(btnTrigMode, SIGNAL(clicked()), this, SLOT(on_btnTrigMode_clicked()));
    connect(btnLog2, SIGNAL(clicked()), this, SLOT(on_btnLog2_clicked()));
    connect(btnLn,   SIGNAL(clicked()), this, SLOT(on_btnLn_clicked()));
    connect(btnLog10, SIGNAL(clicked()), this, SLOT(on_btnLog10_clicked()));
    
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
    emit buttonClicked("^(");
}

void MathMode::on_btnSqrt_clicked()
{
    emit buttonClicked("√(");
}

void MathMode::on_btnSin_clicked()
{
    emit buttonClicked("sin(");
}

void MathMode::on_btnCos_clicked()
{
    emit buttonClicked("cos(");
}

void MathMode::on_btnTan_clicked()
{
    emit buttonClicked("tan(");
}

void MathMode::on_btnCtg_clicked()
{
    emit buttonClicked("ctg(");
}

void MathMode::on_btnTrigMode_clicked()
{
    if (trigMode == TrigMode::RADIAN)
    {
        trigMode = TrigMode::DEGREE;
        btnTrigMode->setText("Deg");
    }
    else
    {
        trigMode = TrigMode::RADIAN;
        btnTrigMode->setText("Rad");
    }
}

void MathMode::on_btnPi_clicked()
{
    emit buttonClicked("π");
}

void MathMode::on_btnE_clicked()
{
    emit buttonClicked("e");
}

void MathMode::on_btnLog10_clicked()
{
    emit buttonClicked("log10(");
}

void MathMode::on_btnLog2_clicked()
{
    emit buttonClicked("log2(");
}

void MathMode::on_btnLn_clicked()
{
    emit buttonClicked("ln(");
}

MathMode::TrigMode MathMode::getTrigMode() const
{
    return trigMode;
}

void MathMode::setDisplayEdit(QPlainTextEdit *displayEdit)
{
    this->displayEdit = displayEdit;
}
