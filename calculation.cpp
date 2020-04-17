#include "calculation.h"

#include <QDebug>

Calculation::Calculation(QObject *parent) : QObject(parent)
{
    numbersAndOperators = new QVector<QString>();
    numberStack = new QStack<double>();
    operatorStack = new QStack<QString>();
    postfixVector = new QVector<QString>();
    precedence = new QMap<QString, int>();
    
    precedence->insert("*", 3);
    precedence->insert("/", 3);
    precedence->insert("+", 2);
    precedence->insert("-", 2);
    precedence->insert("(", 1);

}

QString Calculation::solveExpression(const QString &expression)
{
    this->expression = expression;

    numbersAndOperators->clear();
    operatorStack->clear();
    numberStack->clear();
    postfixVector->clear();
    
    if (!checkBrackets())
        return errorMessage;
    

    fillVectorNumbersAndOperators();
    if (!checkNumbersAndOperators())
        return errorMessage;
    
    transformToPostfix();
    calculatePostfix();
    

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

    for (int i = 0; i < numbersAndOperators->size(); i++){
        if (numbersAndOperators->at(i) == "")
            numbersAndOperators->remove(i);
    }
    
  
    
}

void Calculation::transformToPostfix()
{
    QString currentSymbol = "";
    bool isNumber = false;
    for (int i = 0; i < numbersAndOperators->size(); i++)
    {
        currentSymbol = numbersAndOperators->at(i);
        currentSymbol.toDouble(&isNumber);
        
        if (isNumber)
            postfixVector->push_back(currentSymbol);
        else if (currentSymbol == "(")
            operatorStack->push_back(currentSymbol);
        else if (currentSymbol == ")")
        {
            while (operatorStack->top() != "(")
            {
                postfixVector->push_back(operatorStack->top());
                operatorStack->pop();
            }
            operatorStack->pop();
        }
        else
        {
            while (!operatorStack->isEmpty()
                   and precedence->value(operatorStack->top()) >= precedence->value(currentSymbol))
            {
                postfixVector->push_back(operatorStack->top());
                operatorStack->pop();
            }
            operatorStack->push(currentSymbol);
        }
    }
    
    while (!operatorStack->isEmpty())
    {
        postfixVector->push_back(operatorStack->top());
        operatorStack->pop();
    }

}

void Calculation::calculatePostfix()
{
    QString currentSymbol = "";
    bool isNumber = false;
    
    for (int i = 0; i < postfixVector->size(); i++)
    {
        currentSymbol = postfixVector->at(i);
        
        currentSymbol.toDouble(&isNumber);
        
        if (isNumber)
            numberStack->push(currentSymbol.toDouble());
        else
        {
                double a = numberStack->top();
                numberStack->pop();
                
                double b = numberStack->top();
                numberStack->pop();
                
                double result = 0;
                if (currentSymbol == "+")
                    result = a + b;
                else if (currentSymbol == "-")
                    result = b - a;
                else if (currentSymbol == "*")
                    result = a * b;
                else if (currentSymbol == "/")
                    result = b / a;
                
                numberStack->push(result);
            
            
            
        }
    }
    
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
