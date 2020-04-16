#include "logic.h"

#include <QDebug>

Logic::Logic(QObject *parent) : QObject(parent)
{
    displayEdit = nullptr;
    lbResult = nullptr;

    calculation = new Calculation(this);
}

void Logic::setDisplayEdit(QLineEdit *value)
{
    displayEdit = value;
}

void Logic::setLbResult(QLabel *value)
{
    lbResult = value;
}

void Logic::startOfInput(const QString &textButton)
{
    // If entered an math operator then we stop input new
    // operators
    if (textButton == "+" || textButton == "-" ||
            textButton == "*" || textButton == "/" || textButton == ".")
    {
        if (!operatorEntered)
            displayEdit->insert(textButton);

        operatorEntered = true;
    }
    else
    {
        operatorEntered = false;
    }


    // Crear all display edit
    if (textButton == "Clear"){
        displayEdit->clear();
        lbResult->clear();
        operatorEntered = false;
    }
    // Remove one symbol
    else if (textButton == "rmOneSym")
    {
        displayEdit->backspace();
    }
    // Make calculations
    else if (textButton == "=")
    {
        QString text = displayEdit->text();
        if (!text.isEmpty())
        {
            double result = calculation->solveExpression(text);
            lbResult->setText(QString::number(result));
        }
        
    }
    // Other just add new symbol to displat edit
    else
    {
        if (!operatorEntered)
            displayEdit->insert(textButton);

    }

}
