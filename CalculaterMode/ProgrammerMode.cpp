//
//  ProgrammerMode.cpp
//  CalculatorPro
//
//  Created by Савелий Никулин on 25.04.2020.
//

#include "ProgrammerMode.hpp"

#include <QDebug>

ProgrammerMode::ProgrammerMode(QWidget *parent)
    : QWidget(parent)
{
    normalMode = new NormalMode(this);
    normalMode->getMainLayout()->setMargin(0);
    
    buttonsLayout = new QHBoxLayout;
    progPanel = new QGridLayout;
    vMainLayout = new QVBoxLayout;
    modeLayout = new QHBoxLayout;
    
    lbResult = nullptr;
    displayEdit = nullptr;
    
    btnA = new QPushButton(this);
    btnB = new QPushButton(this);
    btnC = new QPushButton(this);
    btnD = new QPushButton(this);
    btnE = new QPushButton(this);
    btnF = new QPushButton(this);
    btnAnd = new QPushButton(this);
    btnOr = new QPushButton(this);
    btnXor = new QPushButton(this);
    btnMod = new QPushButton(this);
    
    radioOctMode = new QRadioButton(this);
    radioDecMode = new QRadioButton(this);
    radioHexMode = new QRadioButton(this);
    radioBinMode = new QRadioButton(this);
    
    btnA->setText("A");
    btnB->setText("B");
    btnC->setText("C");
    btnD->setText("D");
    btnE->setText("E");
    btnF->setText("F");
    
    btnAnd->setText("AND (∧)");
    btnOr->setText("OR (∨)");
    btnXor->setText("XOR (⊕)");
    btnMod->setText("MOD (%)");
    
    
    
    radioOctMode->setText("Oct");
    radioDecMode->setText("Dec");
    radioHexMode->setText("Hex");
    radioBinMode->setText("Bin");
    
    
    modeLayout->addWidget(radioBinMode);
    modeLayout->addWidget(radioOctMode);
    modeLayout->addWidget(radioDecMode);
    modeLayout->addWidget(radioHexMode);
    
    
    
    btnA->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnB->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnC->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnD->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnE->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnF->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnAnd->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnOr->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnXor->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    btnMod->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    
    normalMode->removeDotButton();
    
    btnFF = new QPushButton(this);
    btnFF->setText("FF");
    btnFF->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    normalMode->getMainLayout()->addWidget(btnFF, 4, 1);
    
    progPanel->addWidget(btnA, 0, 1);
    progPanel->addWidget(btnB, 1, 1);
    progPanel->addWidget(btnC, 2, 1);
    progPanel->addWidget(btnD, 3, 1);
    progPanel->addWidget(btnE, 4, 1);
    progPanel->addWidget(btnF, 4, 0);
    
    progPanel->addWidget(btnAnd, 0, 0);
    progPanel->addWidget(btnOr, 1, 0);
    progPanel->addWidget(btnXor, 2, 0);
    progPanel->addWidget(btnMod, 3, 0);
    
    
    buttonsLayout->addLayout(progPanel);
    buttonsLayout->addWidget(normalMode);
    
    
    vMainLayout->addLayout(modeLayout);
    vMainLayout->addLayout(buttonsLayout);
    
    connect(normalMode, SIGNAL(buttonClicked(QString)), this, SLOT(on_normalMode_clicked(QString)));
    connect(btnFF, SIGNAL(clicked()), this, SLOT(on_btnFF_clicked()));
    connect(btnA, SIGNAL(clicked()), this, SLOT(on_btnA_clicked()));
    connect(btnB, SIGNAL(clicked()), this, SLOT(on_btnB_clicked()));
    connect(btnC, SIGNAL(clicked()), this, SLOT(on_btnC_clicked()));
    connect(btnD, SIGNAL(clicked()), this, SLOT(on_btnD_clicked()));
    connect(btnE, SIGNAL(clicked()), this, SLOT(on_btnE_clicked()));
    connect(btnF, SIGNAL(clicked()), this, SLOT(on_btnF_clicked()));
    
    connect(btnAnd, SIGNAL(clicked()), this, SLOT(on_btnAnd_clicked()));
    connect(btnOr, SIGNAL(clicked()), this, SLOT(on_btnOr_clicked()));
    connect(btnXor, SIGNAL(clicked()), this, SLOT(on_btnXor_clicked()));
    connect(btnMod, SIGNAL(clicked()), this, SLOT(on_btnMod_clicked()));
    
    connect(radioOctMode, SIGNAL(clicked()), this, SLOT(on_radioOct_clicked()));
    connect(radioDecMode, SIGNAL(clicked()), this, SLOT(on_radioDec_clicked()));
    connect(radioHexMode, SIGNAL(clicked()), this, SLOT(on_radioHex_clicked()));
    connect(radioBinMode, SIGNAL(clicked()), this, SLOT(on_radioBin_clicked()));
    
    numberSystem = NumberSystem::DEC;
    radioDecMode->setChecked(true);
    on_radioDec_clicked();
    
    setLayout(vMainLayout);
}

void ProgrammerMode::on_normalMode_clicked(const QString &textButton)
{
    emit buttonClicked(textButton);
}

void ProgrammerMode::on_btnFF_clicked()
{
    emit buttonClicked("FF");
}

void ProgrammerMode::on_btnA_clicked()
{
    emit buttonClicked("A");
}

void ProgrammerMode::on_btnB_clicked()
{
    emit buttonClicked("B");
}

void ProgrammerMode::on_btnC_clicked()
{
    emit buttonClicked("C");
}

void ProgrammerMode::on_btnD_clicked()
{
    emit buttonClicked("D");
}

void ProgrammerMode::on_btnE_clicked()
{
    emit buttonClicked("E");
}

void ProgrammerMode::on_btnF_clicked()
{
    emit buttonClicked("F");
}

ProgrammerMode::NumberSystem ProgrammerMode::getNumberSystem() const
{
    return numberSystem;
}

void ProgrammerMode::setNumberSystem(NumberSystem numberSystem)
{
    this->numberSystem = numberSystem;
    
    if (numberSystem == NumberSystem::BIN)
        on_radioBin_clicked();
    else if (numberSystem == NumberSystem::OCT)
        on_radioOct_clicked();
    else if (numberSystem == NumberSystem::DEC)
        on_radioDec_clicked();
    else if (numberSystem == NumberSystem::HEX)
        on_radioHex_clicked();
}

void ProgrammerMode::on_radioOct_clicked()
{
    if (lbResult != nullptr)
    {
        transformInNewNumberSystem(numberSystem, NumberSystem::OCT);
    }
    
    
    
    numberSystem = NumberSystem::OCT;
    
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(1, 0)->widget())->setEnabled(true);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(1, 1)->widget())->setEnabled(false);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(1, 2)->widget())->setEnabled(false);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(2, 0)->widget())->setEnabled(true);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(2, 1)->widget())->setEnabled(true);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(2, 2)->widget())->setEnabled(true);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(3, 1)->widget())->setEnabled(true);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(3, 2)->widget())->setEnabled(true);
    btnA->setEnabled(false);
    btnB->setEnabled(false);
    btnC->setEnabled(false);
    btnD->setEnabled(false);
    btnE->setEnabled(false);
    btnF->setEnabled(false);
    btnFF->setEnabled(false);
    
}

void ProgrammerMode::on_radioDec_clicked()
{
    if (lbResult != nullptr)
    {
        transformInNewNumberSystem(numberSystem, NumberSystem::DEC);
    }
    
    
    numberSystem = NumberSystem::DEC;
    
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(1, 0)->widget())->setEnabled(true);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(1, 1)->widget())->setEnabled(true);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(1, 2)->widget())->setEnabled(true);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(2, 0)->widget())->setEnabled(true);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(2, 1)->widget())->setEnabled(true);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(2, 2)->widget())->setEnabled(true);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(3, 1)->widget())->setEnabled(true);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(3, 2)->widget())->setEnabled(true);
    btnA->setEnabled(false);
    btnB->setEnabled(false);
    btnC->setEnabled(false);
    btnD->setEnabled(false);
    btnE->setEnabled(false);
    btnF->setEnabled(false);
    btnFF->setEnabled(false);
}

void ProgrammerMode::on_radioHex_clicked()
{
    if (lbResult != nullptr)
    {
        transformInNewNumberSystem(numberSystem, NumberSystem::HEX);
    }
    
    numberSystem = NumberSystem::HEX;
    
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(1, 0)->widget())->setEnabled(true);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(1, 1)->widget())->setEnabled(true);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(1, 2)->widget())->setEnabled(true);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(2, 0)->widget())->setEnabled(true);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(2, 1)->widget())->setEnabled(true);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(2, 2)->widget())->setEnabled(true);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(3, 1)->widget())->setEnabled(true);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(3, 2)->widget())->setEnabled(true);
    btnA->setEnabled(true);
    btnB->setEnabled(true);
    btnC->setEnabled(true);
    btnD->setEnabled(true);
    btnE->setEnabled(true);
    btnF->setEnabled(true);
    btnFF->setEnabled(true);
}

void ProgrammerMode::on_radioBin_clicked()
{
    
    if (lbResult != nullptr)
    {
        transformInNewNumberSystem(numberSystem, NumberSystem::BIN);
    }
    
    numberSystem = NumberSystem::BIN;
    
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(1, 0)->widget())->setEnabled(false);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(1, 1)->widget())->setEnabled(false);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(1, 2)->widget())->setEnabled(false);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(2, 0)->widget())->setEnabled(false);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(2, 1)->widget())->setEnabled(false);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(2, 2)->widget())->setEnabled(false);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(3, 1)->widget())->setEnabled(false);
    dynamic_cast<QPushButton*>(normalMode->getMainLayout()->itemAtPosition(3, 2)->widget())->setEnabled(false);
    
    btnA->setEnabled(false);
    btnB->setEnabled(false);
    btnC->setEnabled(false);
    btnD->setEnabled(false);
    btnE->setEnabled(false);
    btnF->setEnabled(false);
    btnFF->setEnabled(false);
}

void ProgrammerMode::transformInNewNumberSystem(NumberSystem fromNSys, NumberSystem toNSys)
{
    
    if (fromNSys == toNSys)
        return;
    
    QString s = "";
    if (lbResult != nullptr)
    {
        int f = 0;
        int t = 0;
        
        if (fromNSys == NumberSystem::DEC and toNSys == NumberSystem::HEX)
        {
            f = 10;
            t = 16;
        }
        else if (fromNSys == NumberSystem::DEC and toNSys == NumberSystem::OCT)
        {
            f = 10;
            t = 8;
        }
        else if (fromNSys == NumberSystem::DEC and toNSys == NumberSystem::BIN)
        {
            f = 10;
            t = 2;
        }
        
        else if (fromNSys == NumberSystem::HEX and toNSys == NumberSystem::DEC)
        {
            f = 16;
            t = 10;
        }
        else if (fromNSys == NumberSystem::HEX and toNSys == NumberSystem::OCT)
        {
            f = 16;
            t = 8;
        }
        else if (fromNSys == NumberSystem::HEX and toNSys == NumberSystem::BIN)
        {
            f = 16;
            t = 2;
        }
        
        else if (fromNSys == NumberSystem::OCT and toNSys == NumberSystem::DEC)
        {
            f = 8;
            t = 10;
        }
        else if (fromNSys == NumberSystem::OCT and toNSys == NumberSystem::HEX)
        {
            f = 8;
            t = 16;
        }
        else if (fromNSys == NumberSystem::OCT and toNSys == NumberSystem::BIN)
        {
            f = 8;
            t = 2;
        }
        
        else if (fromNSys == NumberSystem::BIN and toNSys == NumberSystem::DEC)
        {
            f = 2;
            t = 10;
        }
        else if (fromNSys == NumberSystem::BIN and toNSys == NumberSystem::HEX)
        {
            f = 2;
            t = 16;
        }
        else if (fromNSys == NumberSystem::BIN and toNSys == NumberSystem::OCT)
        {
            f = 2;
            t = 8;
        }
        
        // Transform expression in displayEdit
        numbersAndOperators.clear();
        calculation->fillVectorNumbersAndOperators(numbersAndOperators, displayEdit->toPlainText());
        displayEdit->clear();
        for (int i = 0; i < numbersAndOperators.size(); i++)
        {
            // Take symbol
            QString currentSymbol = numbersAndOperators.at(i);
            bool isNumber = false;
            // translate from the current number system to dec
            int number = currentSymbol.toUInt(&isNumber, f);
            if (isNumber){
                // translate to choosed number system
                s.setNum(number, t);
                s = s.toUpper();
            }
            else
                s = currentSymbol;
            
            displayEdit->insertPlainText(s);
        }
        
        // Transform expression in lbResult
        s.clear();
        QString currentResult = lbResult->text();
        bool temp = false;
        int number = currentResult.toUInt(&temp, f);
        s.setNum(number, t);
        s = s.toUpper();
        lbResult->setText(s);
        
    }
    
    
        
}

void ProgrammerMode::setDisplayEdit(QPlainTextEdit *displayEdit)
{
    this->displayEdit = displayEdit;
}

void ProgrammerMode::setLbResult(QPushButton *lbResult)
{
    this->lbResult = lbResult;
}

void ProgrammerMode::on_btnAnd_clicked()
{
    emit buttonClicked("∧");
}

void ProgrammerMode::on_btnOr_clicked()
{
    emit buttonClicked("∨");
}

void ProgrammerMode::on_btnXor_clicked()
{
    emit buttonClicked("⊕");
}

void ProgrammerMode::on_btnMod_clicked()
{
    emit buttonClicked("%");
}

void ProgrammerMode::setCalculationMode(Calculation *calculation)
{
    this->calculation = calculation;
}
