#include "calculation.h"

#include <QDebug>

Calculation::Calculation(QObject *parent) : QObject(parent)
{
    numbersAndOperators = new QVector<QString>();
    numberStack = new QStack<int>();
    operatorStack = new QStack<QString>();
}

int Calculation::solveExpression(const QString &expression)
{
    this->expression = expression;
    numbersAndOperators->clear();
    operatorStack->clear();
    numberStack->clear();
    fillVectorNumbersAndOperators();
    stackDistribution();

    return 0;
}

void Calculation::fillVectorNumbersAndOperators()
{
    QString symbol = "";
    bool isNumber = false;
    for (int i = 0; i < expression.size(); i++)
    {
        QString t = expression.at(i);

        t.toInt(&isNumber);
        if (isNumber){
            symbol += t;
            if (i + 1 == expression.size())
                numbersAndOperators->push_back(symbol);
        }
        else{
            numbersAndOperators->push_back(symbol);
            numbersAndOperators->push_back(t);
            symbol = "";
        }
    }

    for (int i = 0; i < numbersAndOperators->size(); i++)
        if (numbersAndOperators->at(i) == "")
            numbersAndOperators->remove(i);

}

void Calculation::stackDistribution()
{
    bool isNumber = false;
    for (int i = 0; i < numbersAndOperators->size(); i++)
    {
        isNumber = false;
        QString sym = numbersAndOperators->at(i);

        sym.toInt(&isNumber);

        if (isNumber)
            numberStack->push(sym.toInt());
        else
        {
            if (operatorStack->size() != 0)
            {
                if (operatorStack->top() == "*")
                {
                    makeResult();
                }
                else if (operatorStack->top() == "/")
                {
                    makeResult();
                }
                if (sym == ")")
                {
                    while (operatorStack->top() != "(")
                    {
                        if (numberStack->size() == 1)
                            break;

                        makeResult();
                    }
                    operatorStack->pop();
                }
            }
            if (sym != ")")
                operatorStack->push(sym);
        }


    }

    while (!numberStack->isEmpty())
    {
        if (numberStack->size() == 1)
            break;

        makeResult();
    }

    qDebug() << numberStack->top();

}

int Calculation::makeResult()
{
    int result = 0;

    int a = numberStack->top();
    numberStack->pop();

    int b = numberStack->top();
    numberStack->pop();

    QString oper = operatorStack->top();
    operatorStack->pop();


    if (oper == "+")
        result = a + b;
    else if (oper == "-")
        result = b - a;
    else if (oper == "*")
        result = a * b;
    else if (oper == "/")
        result = b / a;

    numberStack->push(result);
}

