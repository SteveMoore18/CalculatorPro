#include "calculation.h"

#include <QDebug>

Calculation::Calculation(QObject *parent) : QObject(parent)
{
    numbersAndOperators = new QVector<QString>();
    numberStack = new QStack<double>();
    operatorStack = new QStack<QString>();
    postfixVector = new QVector<QString>();
    precedence = new QMap<QString, int>();
    trigOperators = new QVector<QString>();
    logarithmOperators = new QVector<QString>();
    
    trigOperators->push_back("sin");
    trigOperators->push_back("cos");
    trigOperators->push_back("tan");
    trigOperators->push_back("ctg");
    
    logarithmOperators->push_back("log2");
    logarithmOperators->push_back("log10");
    logarithmOperators->push_back("ln");
    
    precedence->insert("ln", 4);
    precedence->insert("log2", 4);
    precedence->insert("log10", 4);
    precedence->insert("ctg", 4);
    precedence->insert("tan", 4);
    precedence->insert("cos", 4);
    precedence->insert("sin", 4);
    precedence->insert("√", 4);
    precedence->insert("^", 4);
    precedence->insert("*", 3);
    precedence->insert("%", 3);
    precedence->insert("∧", 3);
    precedence->insert("∨", 3);
    precedence->insert("⊕", 3);
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
    

    fillVectorNumbersAndOperators(*numbersAndOperators, expression);
    
    try {
        transformToPostfix();
    } catch (QString error) {
        errorMessage = error;
        return errorMessage;
    }
    
    
    
    try {
        calculatePostfix();
    } catch (QString error) {
        errorMessage = error;
        return errorMessage;
    }
    
    

    if (!numberStack->isEmpty())
    {
        QString s;
        int numberSystem = 0;
        if (programmerMode->getNumberSystem() == ProgrammerMode::NumberSystem::BIN)
        {
            numberSystem = 2;
        }
        else if (programmerMode->getNumberSystem() == ProgrammerMode::NumberSystem::OCT)
        {
            numberSystem = 8;
        }
        else if (programmerMode->getNumberSystem() == ProgrammerMode::NumberSystem::DEC)
        {
            numberSystem = 10;
        }
        else if (programmerMode->getNumberSystem() == ProgrammerMode::NumberSystem::HEX)
        {
            numberSystem = 16;
        }
        else
        {
            return QString::number(numberStack->top());
        }
        
        int number = numberStack->top();
        if (number < 0)
        {
            int positiveNumber = abs(number);
            s.setNum((uint)positiveNumber, numberSystem);
            s = s.toUpper();
            s = "-" + s;
        }
        else
        {
            s.setNum((uint)number, numberSystem);
            s = s.toUpper();
        }
        
        
        return s;
        
        //return QString::number(numberStack->top());
    }
    else
    {
        return "Error!";
    }
    
}

void Calculation::fillVectorNumbersAndOperators(QVector<QString> &vector, QString expr)
{
    
    numbers = 0;
    operators = 0;
    
    QString symbol = "";
    QString currentSymbol = "";
    bool isNumber = false;
    for (int i = 0; i < expr.size(); i++)
    {
        currentSymbol = expr.at(i);
        if (currentSymbol == ".")
        {
            symbol += ".";
            continue;
        }

        currentSymbol.toDouble(&isNumber);
        if (isNumber){
            symbol += currentSymbol;
            if (i + 1 == expr.size()){
                vector.push_back(symbol);
            }
            
            numbers++;
        }
        else if (currentSymbol == "A" || currentSymbol == "B" || currentSymbol == "C" ||
                 currentSymbol == "D" || currentSymbol == "E" || currentSymbol == "F")
        {
            symbol += currentSymbol;
            if (i + 1 == expr.size()){
                vector.push_back(symbol);
            }
        }
        else if (currentSymbol == "l" and expr.at(i + 1) == "n")
        {
            currentSymbol += "n";
            i += 1;
            vector.push_back(currentSymbol);
        }
        else if (currentSymbol == "l" and expr.at(i + 3) == "2")
        {
            currentSymbol += "og2";
            i += 3;
            vector.push_back(currentSymbol);
        }
        else if (currentSymbol == "l" and expr.at(i + 3) == "1")
        {
            currentSymbol += "og10";
            i += 4;
            vector.push_back(currentSymbol);
        }
        else if (currentSymbol == "s")
        {
            currentSymbol += "in";
            i += 2;
            vector.push_back(currentSymbol);
        }
        else if (currentSymbol == "c" and expr.at(i + 1) == "t")
        {
            currentSymbol += "tg";
            i += 2;
            vector.push_back(currentSymbol);
        }
        else if (currentSymbol == "c")
        {
            currentSymbol += "os";
            i += 2;
            vector.push_back(currentSymbol);
        }
        else if (currentSymbol == "t")
        {
            currentSymbol += "an";
            i += 2;
            vector.push_back(currentSymbol);
        }
        else if (currentSymbol == "π")
        {
            vector.push_back(QString::number(M_PI));
            continue;
        }
        else if (currentSymbol == "e")
        {
            vector.push_back(QString::number(M_E));
            continue;
        }
        else{
            if (currentSymbol != "(" and currentSymbol != ")" and currentSymbol != "^")
                operators++;
            
            
            vector.push_back(symbol);
            vector.push_back(currentSymbol);
            symbol = "";
        }
    }

    for (int i = 0; i < vector.size(); i++){
        if (vector.at(i) == "" or vector.at(i) == " ")
            vector.remove(i);
    }
    
    if (programmerMode->getNumberSystem() != ProgrammerMode::NumberSystem::NONE)
    {
    
        bool s = false;
        int nSystem = 0;
        
        if (programmerMode->getNumberSystem() == ProgrammerMode::NumberSystem::BIN)
        {
            nSystem = 2;
        }
        else if (programmerMode->getNumberSystem() == ProgrammerMode::NumberSystem::OCT)
        {
            nSystem = 8;
        }
        else if (programmerMode->getNumberSystem() == ProgrammerMode::NumberSystem::DEC)
        {
            nSystem = 10;
        }
        else if (programmerMode->getNumberSystem() == ProgrammerMode::NumberSystem::HEX)
        {
            nSystem = 16;
        }
    
    
        for (int i = 0; i < vector.size(); i++){
            int number = vector.at(i).toUInt(&s, nSystem);
            if (s)
            {
                vector.replace(i, QString::number(number));
            }
        }
    }
    
//    for (int i = 0; i < numbersAndOperators->size(); i++){
//        qDebug() << numbersAndOperators->at(i);
//    }
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
    
    // if the degree of the number is negative make this ( example: 2^(-3) = 1/(2^3) )
    QString s = "";
    int size = postfixVector->size();
    for (int i = 0; i < size; i++)
    {
        if (postfixVector->at(i) == "^" and i == 0)
            throw QString("Error.");
        if (postfixVector->at(i) == "^" and postfixVector->at(i - 1) == "-")
        {
            postfixVector->insert(i - 3, "1");
            postfixVector->insert(i + 2, "/");
            postfixVector->remove(i);
        }
    }

//    for (int i = 0; i < postfixVector->size(); i++)
//    {
//        s += postfixVector->at(i) + " ";
//    }
//    qDebug() << s;

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
            if (numberStack->isEmpty())
                throw QString("Error. No numbers.");
            
            double result = 0;

            if (currentSymbol == "√")
            {
                double a = numberStack->top();
                numberStack->pop();

                result = sqrt(a);
                numberStack->push(result);
                continue;
            }
            else if (isTrigonometricFunc(currentSymbol))
            {
                solveTrigonometric(currentSymbol);
                continue;
            }
            
            if (isLogarithm(currentSymbol))
            {
                solveLogarithm(currentSymbol);
                continue;
            }
            

            double a = numberStack->top();
            numberStack->pop();
            
            double b = 0;
            if (!numberStack->isEmpty())
            {
                b = numberStack->top();
                numberStack->pop();
            }
            
            if (currentSymbol == "+")
                result = a + b;
            else if (currentSymbol == "-")
                result = b - a;
            else if (currentSymbol == "*")
                result = a * b;
            else if (currentSymbol == "/")
            {
                if (a == 0)
                    throw QString("You cannot divide by zero.");
                result = b / a;
            }
            else if (currentSymbol == "^")
                result = pow(b, a);
            else if (currentSymbol == "∧")
                result = static_cast<int>(a) & static_cast<int>(b);
            else if (currentSymbol == "∨")
                result = static_cast<int>(a) | static_cast<int>(b);
            else if (currentSymbol == "⊕")
                result = static_cast<int>(a) ^ static_cast<int>(b);
            else if (currentSymbol == "%")
                result = static_cast<int>(b) % static_cast<int>(a);
            
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

void Calculation::setMathMode(MathMode *mathMode)
{
    this->mathMode = mathMode;
}

double Calculation::solveTrigonometric(const QString &oper)
{
    double a = numberStack->top();
    numberStack->pop();
    
    double result = 0;
    MathMode::TrigMode trigMode = mathMode->getTrigMode();
    
    // if mode is degree then convert radian to degree
    if (trigMode == MathMode::TrigMode::DEGREE)
        a = a * M_PI / 180;
    
    if (oper == "sin")
        result = sin(a);
    else if (oper == "cos")
        result = cos(a);
    else if (oper == "tan")
        result = tan(a);
    else if (oper == "ctg")
        result = (cos(a) / sin(a));
    
    numberStack->push(result);
    
    return result;
}

bool Calculation::isTrigonometricFunc(const QString &oper)
{
    for (int i = 0; i < trigOperators->size(); i++)
        if (oper == trigOperators->at(i))
            return true;
    
    return false;
}

double Calculation::solveLogarithm(const QString &oper)
{
    double a = numberStack->top();
    numberStack->pop();

    double result = 0;
    
    if (oper == "log2")
        result = log2(a);
    else if (oper == "log10")
        result = log10(a);
    else if (oper == "ln")
        result = qLn(a);
    
    numberStack->push(result);
    
    return result;
}

bool Calculation::isLogarithm(const QString &oper)
{
    for (int i = 0; i < logarithmOperators->size(); i++)
        if (oper == logarithmOperators->at(i))
            return true;
    return false;
}

void Calculation::setProgrammerMode(ProgrammerMode *programmerMode)
{
    this->programmerMode = programmerMode;
}
