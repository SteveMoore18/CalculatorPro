#include "calculation.h"

#include <QDebug>

Calculation::Calculation(QObject *parent) : QObject(parent)
{
    numbersAndOperators = new QVector<QString>();
    numberStack = new QStack<double>();
    operatorStack = new QStack<QString>();

}

QString Calculation::solveExpression(const QString &expression)
{
    this->expression = expression;

    numbersAndOperators->clear();
    operatorStack->clear();
    numberStack->clear();
    
    if (!checkBrackets())
        return errorMessage;
    

    fillVectorNumbersAndOperators();
    if (!checkNumbersAndOperators())
        return errorMessage;
    
    stackDistribution();

    if (!numberStack->isEmpty())
        return QString::number(numberStack->top());
    else
        return "Error!";
    
}

void Calculation::fillVectorNumbersAndOperators()
{
    
    numbers = 0;
    operators = 0;
    
    QString symbol = "";
    QString currentSymbol = "";
    bool isNumber = false;
    for (int i = 0; i < expression.size(); i++)
    {
        currentSymbol = expression.at(i);
        if (currentSymbol == ".")
        {
            symbol += ".";
            continue;
        }

        currentSymbol.toDouble(&isNumber);
        if (isNumber){
            symbol += currentSymbol;
            if (i + 1 == expression.size()){
                numbersAndOperators->push_back(symbol);
            }
            
            numbers++;
        }
        else{
            if (currentSymbol != "(" && currentSymbol != ")")
                operators++;
            
            numbersAndOperators->push_back(symbol);
            numbersAndOperators->push_back(currentSymbol);
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
    QString currentSymbol;
    for (int i = 0; i < numbersAndOperators->size(); i++)
    {
        isNumber = false;
        currentSymbol = numbersAndOperators->at(i);

        currentSymbol.toDouble(&isNumber);

        if (isNumber)
        {
            numberStack->push(currentSymbol.toDouble());
        }
        else if (currentSymbol == "(")
        {
            operatorStack->push(currentSymbol);
        }
        else
        {
            if (operatorStack->size() != 0)
            {
                if (numberStack->size() > 1)
                {


                    if (operatorStack->top() == "*" ||
                        operatorStack->top() == "/")
                    {
                        makeResult();
                    }


                }

                if (currentSymbol == ")")
                {
                    // Make calculations to close bracket
                    while (operatorStack->top() != "(")
                    {
                        if (numberStack->size() == 1)
                            break;

                        makeResult();
                    }
                    operatorStack->pop();

                    if (numberStack->size() > 1)
                    {
                        if (operatorStack->top() == "*" ||
                            operatorStack->top() == "/")
                        {
                            makeResult();
                        }
                    }
                }
            }
            
            if (currentSymbol != ")")
                operatorStack->push(currentSymbol);
        }


    }

    // Make calculations
    while (!numberStack->isEmpty())
    {
        if (numberStack->size() == 1)
            break;

        makeResult();
    }

}

void Calculation::makeResult()
{
    /* Taking 2 number and 1 operator from stack
     and makes operation.
     */
    
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

bool Calculation::checkBrackets()
{
    // Brackets check
    int openBrackets = 0;
    int closeBrackets = 0;
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression.at(i) == "(")
            openBrackets++;
        if (expression.at(i) == ")")
            closeBrackets++;
    }
    
    if (openBrackets != closeBrackets)
    {
        errorMessage = "Error with brackets!";
        return false;
    }
    
    
    return true;
}

bool Calculation::checkNumbersAndOperators()
{
    
    if (operators >= numbers){
        errorMessage = "Error with numbers or operators.";
        return false;
    }
    
    return true;
}
