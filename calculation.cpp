#include "calculation.h"

#include <QDebug>

Calculation::Calculation(QObject *parent) : QObject(parent)
{
    numbersAndOperators = new QVector<QString>();
    numberStack = new QStack<double>();
    operatorStack = new QStack<QString>();

}

double Calculation::solveExpression(const QString &expression)
{
    this->expression = expression;

    numbersAndOperators->clear();
    operatorStack->clear();
    numberStack->clear();

    fillVectorNumbersAndOperators();
    stackDistribution();

    return numberStack->top();
}

void Calculation::fillVectorNumbersAndOperators()
{
    QString symbol = "";
    bool isNumber = false;
    for (int i = 0; i < expression.size(); i++)
    {
        QString t = expression.at(i);
        if (t == ".")
        {
            symbol += ".";
            continue;
        }

        t.toDouble(&isNumber);
        if (isNumber){
            symbol += t;
            if (i + 1 == expression.size()){
                numbersAndOperators->push_back(symbol);
            }
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

        sym.toDouble(&isNumber);

        if (isNumber)
        {
            numberStack->push(sym.toDouble());
        }else if (sym == "(")
        {
            operatorStack->push(sym);
        }
        else
        {
            if (operatorStack->size() != 0)
            {
                if (operatorStack->top() == "*" && numberStack->size() > 1)
                {
                    makeResult();
                }
                else if (operatorStack->top() == "/" && numberStack->size() > 1)
                {
                    makeResult();
                }
//                else if (operatorStack->top() == "-" && numberStack->size() > 1)
//                {
//                    makeResult();
//                }

                if (sym == ")")
                {
                    while (operatorStack->top() != "(")
                    {
                        if (numberStack->size() == 1)
                            break;

                        makeResult();
                    }
                    operatorStack->pop();

                    if (operatorStack->top() == "*" && numberStack->size() > 1)
                    {
                        makeResult();
                    }
                    else if (operatorStack->top() == "/" && numberStack->size() > 1)
                    {
                        makeResult();
                    }

                    if (operatorStack->top() == "-" && numberStack->size() > 1)
                    {
                        makeResult();
                    }

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

}

void Calculation::makeResult()
{
    double result = 0;

    double a = numberStack->top();
    numberStack->pop();

    double b = numberStack->top();
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

