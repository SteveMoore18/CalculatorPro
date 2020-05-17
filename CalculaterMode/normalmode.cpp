#include "normalmode.h"

NormalMode::NormalMode(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QGridLayout;

    btn0 = new QPushButton("0");
    btn1 = new QPushButton("1");
    btn2 = new QPushButton("2");
    btn3 = new QPushButton("3");
    btn4 = new QPushButton("4");
    btn5 = new QPushButton("5");
    btn6 = new QPushButton("6");
    btn7 = new QPushButton("7");
    btn8 = new QPushButton("8");
    btn9 = new QPushButton("9");
    
    btnClear = new QPushButton();
    btnBracketOpen = new QPushButton("(");
    btnBracketClose = new QPushButton(")");
    btnPlus = new QPushButton("+");
    btnMinus = new QPushButton("-");
    btnMultiply = new QPushButton("×");
    btnDivision = new QPushButton("÷");
    btnRemoveOneSym = new QPushButton();
    btnDot = new QPushButton(".");
    btnEqual = new QPushButton("=");

    btnClear->setIcon(QIcon(QPixmap(":/images/Appearance/Images/btnRemoveAll.png")));
    btnClear->setIconSize(QSize(30, 30));
    
    btnRemoveOneSym->setIcon(QIcon(QPixmap(":/images/Appearance/Images/rmOneSym.png")));
    btnRemoveOneSym->setIconSize(QSize(35, 35));
    
    btn0->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btn1->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btn2->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btn3->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btn4->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btn5->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btn6->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btn7->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btn8->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btn9->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnClear->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnBracketOpen->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnBracketClose->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnPlus->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnMinus->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnMultiply->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnDivision->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnRemoveOneSym->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnDot->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnEqual->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

//    int bsize = 150;
//    btn0->setFixedSize(bsize, bsize);
//    btn1->setFixedSize(bsize, bsize);
//    btn2->setFixedSize(bsize, bsize);
//    btn3->setFixedSize(bsize, bsize);
//    btn4->setFixedSize(bsize, bsize);
//    btn5->setFixedSize(bsize, bsize);
//    btn6->setFixedSize(bsize, bsize);
//    btn7->setFixedSize(bsize, bsize);
//    btn8->setFixedSize(bsize, bsize);
//    btn9->setFixedSize(bsize, bsize);
    

    mainLayout->addWidget(btnClear, 0, 0);
    mainLayout->addWidget(btnBracketOpen, 0, 1);
    mainLayout->addWidget(btnBracketClose, 0, 2);
    mainLayout->addWidget(btnDivision, 0, 3);
    mainLayout->addWidget(btn7, 1, 0);
    mainLayout->addWidget(btn8, 1, 1);
    mainLayout->addWidget(btn9, 1, 2);
    mainLayout->addWidget(btnMultiply, 1, 3);
    mainLayout->addWidget(btn4, 2, 0);
    mainLayout->addWidget(btn5, 2, 1);
    mainLayout->addWidget(btn6, 2, 2);
    mainLayout->addWidget(btnMinus, 2, 3);
    mainLayout->addWidget(btn1, 3, 0);
    mainLayout->addWidget(btn2, 3, 1);
    mainLayout->addWidget(btn3, 3, 2);
    mainLayout->addWidget(btnPlus, 3, 3);
    mainLayout->addWidget(btn0, 4, 0);
    mainLayout->addWidget(btnDot, 4, 1);
    mainLayout->addWidget(btnRemoveOneSym, 4, 2);
    mainLayout->addWidget(btnEqual, 4, 3);
    
    //mainLayout->setMargin(0);

    connect(btn0, SIGNAL(clicked()), this, SLOT(on_btn0_clicked()));
    connect(btn1, SIGNAL(clicked()), this, SLOT(on_btn1_clicked()));
    connect(btn2, SIGNAL(clicked()), this, SLOT(on_btn2_clicked()));
    connect(btn3, SIGNAL(clicked()), this, SLOT(on_btn3_clicked()));
    connect(btn4, SIGNAL(clicked()), this, SLOT(on_btn4_clicked()));
    connect(btn5, SIGNAL(clicked()), this, SLOT(on_btn5_clicked()));
    connect(btn6, SIGNAL(clicked()), this, SLOT(on_btn6_clicked()));
    connect(btn7, SIGNAL(clicked()), this, SLOT(on_btn7_clicked()));
    connect(btn8, SIGNAL(clicked()), this, SLOT(on_btn8_clicked()));
    connect(btn9, SIGNAL(clicked()), this, SLOT(on_btn9_clicked()));
    connect(btnClear, SIGNAL(clicked()), this, SLOT(on_btnClear_clicked()));
    connect(btnBracketOpen, SIGNAL(clicked()), this, SLOT(on_btnBracketOpen_clicked()));
    connect(btnBracketClose, SIGNAL(clicked()), this, SLOT(on_btnBracketClose_clicked()));
    connect(btnPlus, SIGNAL(clicked()), this, SLOT(on_btnPlus_clicked()));
    connect(btnMinus, SIGNAL(clicked()), this, SLOT(on_btnMinus_clicked()));
    connect(btnMultiply, SIGNAL(clicked()), this, SLOT(on_btnMultiply_clicked()));
    connect(btnDivision, SIGNAL(clicked()), this, SLOT(on_btnDivision_clicked()));
    connect(btnRemoveOneSym, SIGNAL(clicked()), this, SLOT(on_btnRemoveOneSym_clicked()));
    connect(btnDot, SIGNAL(clicked()), this, SLOT(on_btnDot_clicked()));
    connect(btnEqual, SIGNAL(clicked()), this, SLOT(on_btnEqual_clicked()));

    
    numberButtonColor = QColor("#e8eaeb");
    numberButtonClickedColor = QColor("#dddfe3");
    otherButtonColor = QColor("#d2d4d8");
    otherButtonClickedColor = QColor("#c4c6c9");
    
    QFile buttonStyleFile(":/styles/Appearance/CSS/ButtonStyle.css");
    if (buttonStyleFile.open(QIODevice::ReadOnly))
    {
        QString text = buttonStyleFile.readAll();
        
        btnStyleForNumber = text;
        btnStyleForNumber = btnStyleForNumber.arg(numberButtonColor.name()).arg(numberButtonClickedColor.name());
        
        btnStyleForOther = text;
        btnStyleForOther = btnStyleForOther.arg(otherButtonColor.name()).arg(otherButtonClickedColor.name());
        
        btn0->setStyleSheet(btnStyleForNumber);
        btn1->setStyleSheet(btnStyleForNumber);
        btn2->setStyleSheet(btnStyleForNumber);
        btn3->setStyleSheet(btnStyleForNumber);
        btn4->setStyleSheet(btnStyleForNumber);
        btn5->setStyleSheet(btnStyleForNumber);
        btn6->setStyleSheet(btnStyleForNumber);
        btn7->setStyleSheet(btnStyleForNumber);
        btn8->setStyleSheet(btnStyleForNumber);
        btn9->setStyleSheet(btnStyleForNumber);
        
        btnClear->setStyleSheet(btnStyleForOther);
        btnBracketOpen->setStyleSheet(btnStyleForOther);
        btnBracketClose->setStyleSheet(btnStyleForOther);
        btnPlus->setStyleSheet(btnStyleForOther);
        btnMinus->setStyleSheet(btnStyleForOther);
        btnMultiply->setStyleSheet(btnStyleForOther);
        btnDivision->setStyleSheet(btnStyleForOther);
        btnRemoveOneSym->setStyleSheet(btnStyleForOther);
        btnDot->setStyleSheet(btnStyleForOther);
        btnEqual->setStyleSheet(btnStyleForOther);
        
    }
    buttonStyleFile.close();
    
    
    this->setStyleSheet("background-color: white;");
    
    setLayout(mainLayout);
}

void NormalMode::blockOperators(const bool status)
{
    btnPlus->setEnabled(status);
    btnMinus->setEnabled(status);
    btnMultiply->setEnabled(status);
    btnDivision->setEnabled(status);
    btnDot->setEnabled(status);

}

void NormalMode::on_btn0_clicked()
{
    emit buttonClicked("0");
}

void NormalMode::on_btn1_clicked()
{
    emit buttonClicked("1");
}

void NormalMode::on_btn2_clicked()
{
    emit buttonClicked("2");
}

void NormalMode::on_btn3_clicked()
{
    emit buttonClicked("3");
}

void NormalMode::on_btn4_clicked()
{
    emit buttonClicked("4");
}

void NormalMode::on_btn5_clicked()
{
    emit buttonClicked("5");
}

void NormalMode::on_btn6_clicked()
{
    emit buttonClicked("6");
}

void NormalMode::on_btn7_clicked()
{
   emit buttonClicked("7");
}

void NormalMode::on_btn8_clicked()
{
    emit buttonClicked("8");
}

void NormalMode::on_btn9_clicked()
{
    emit buttonClicked("9");
}

void NormalMode::on_btnClear_clicked()
{
    emit buttonClicked("Clear");
}

void NormalMode::on_btnBracketOpen_clicked()
{
    emit buttonClicked("(");
}

void NormalMode::on_btnBracketClose_clicked()
{
    emit buttonClicked(")");
}

void NormalMode::on_btnPlus_clicked()
{
    emit buttonClicked("+");
}

void NormalMode::on_btnMinus_clicked()
{
    emit buttonClicked("-");
}

void NormalMode::on_btnMultiply_clicked()
{
    emit buttonClicked("×");
}

void NormalMode::on_btnDivision_clicked()
{
    emit buttonClicked("÷");
    
}

void NormalMode::on_btnRemoveOneSym_clicked()
{
    emit buttonClicked("rmOneSym");
}

void NormalMode::on_btnDot_clicked()
{
    emit buttonClicked(".");
}

void NormalMode::on_btnEqual_clicked()
{
    emit buttonClicked("=");
}

QGridLayout *NormalMode::getMainLayout() const
{
    return mainLayout;
}

void NormalMode::removeDotButton()
{
    delete btnDot;
}

QString NormalMode::getOtherButtonStyle() const
{
    return btnStyleForOther;
}

QString NormalMode::getNumberButtonStyle() const
{
    return btnStyleForNumber;
}

QColor NormalMode::getNumberButtonColor() const
{
    return numberButtonColor;
}

QColor NormalMode::getOtherButtonColor() const
{
    return otherButtonColor;
}
