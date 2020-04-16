#ifndef CALCULATION_H
#define CALCULATION_H

#include <QObject>
#include <QVector>
#include <QStack>

class Calculation : public QObject
{
    Q_OBJECT
public:
    explicit Calculation(QObject *parent = nullptr);

    QString solveExpression(const QString &expression);


private:
    QString expression;

    QVector<QString> *numbersAndOperators;
    QStack<double> *numberStack;
    QStack<QString> *operatorStack;

    // This function shares numbers and operators to vector
    // for further distribution for stack.
    void fillVectorNumbersAndOperators();
    
    // Here makes a calculation.
    void stackDistribution();
    
    // This function make result from stacks.
    void makeResult();
    
    
    QString errorMessage;
    bool checkBrackets();
    
    int numbers = 0;
    int operators = 0;
    bool checkNumbersAndOperators();

};

#endif // CALCULATION_H
