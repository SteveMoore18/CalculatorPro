#include "logic.h"

#include <QDebug>

Logic::Logic(QObject *parent) : QObject(parent)
{
    displayEdit = nullptr;
    lbResult = nullptr;
    historyList = nullptr;

    calculation = new Calculation(this);
}

void Logic::setDisplayEdit(QPlainTextEdit *value)
{
    displayEdit = value;
}

void Logic::setLbResult(QLabel *value)
{
    lbResult = value;
}

void Logic::setMathMode(MathMode *mathMode)
{
    this->mathMode = mathMode;
    calculation->setMathMode(mathMode);
}

void Logic::startInputBasic(const QString &textButton)
{
    
    startingInput(textButton);
}

void Logic::startInputMath(const QString &textButton)
{
    
    startingInput(textButton);
}

void Logic::startInputProgrammer(const QString &textButton)
{
    startingInput(textButton);
}

void Logic::startingInput(const QString &textButton)
{
    if (textButton == "Clear")
    {
        displayEdit->clear();
        infixExpression.clear();
        lbResult->clear();
    }
    else if (textButton == "=")
    {
        QString result = calculation->solveExpression(displayEdit->toPlainText());
        lbResult->setText(result);
    }
    else if (textButton == "rmOneSym")
    {
        displayEdit->textCursor().deletePreviousChar();
        infixExpression.resize(infixExpression.size() - 1);
    }
    else
    {
        infixExpression += textButton;
        displayEdit->textCursor().insertHtml(textButton);
    }
    
}

bool Logic::isOperator(const QString &str)
{
    QVector<QString> operators;
    operators.push_back("+");
    operators.push_back("*");
    operators.push_back("-");
    operators.push_back("/");
    operators.push_back("(");
    operators.push_back(")");
    
    for (int i = 0; i < operators.size(); i++)
        if (str == operators.at(i))
            return true;

    return false;
}

void Logic::setHistoryList(QListWidget *historyList)
{
    this->historyList = historyList;
}

void Logic::setProgrammerMode(ProgrammerMode *programmerMode)
{
    this->programmerMode = programmerMode;
    calculation->setProgrammerMode(programmerMode);
    programmerMode->setCalculationMode(calculation);
}

void Logic::setInfixExpression(const QString &value)
{
    infixExpression = value;
}
