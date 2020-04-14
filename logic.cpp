#include "logic.h"

#include <QDebug>

Logic::Logic(QObject *parent) : QObject(parent)
{
    displayEdit = nullptr;

    calculation = new Calculation(this);
}

void Logic::setDisplayEdit(QLineEdit *value)
{
    displayEdit = value;
}

void Logic::startOfInput(const QString &textButton)
{
    if (textButton == "Clear")
        displayEdit->clear();
    else if (textButton == "=")
    {
        calculation->solveExpression(displayEdit->text());
    }
    else
    {
        displayEdit->insert(textButton);
    }

}
