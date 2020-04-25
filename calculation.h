#ifndef CALCULATION_H
#define CALCULATION_H

#include <QObject>
#include <QVector>
#include <QStack>
#include <QMap>
#include <QtMath>

#include "MathMode.hpp"
class MathMode;

class Calculation : public QObject
{
    Q_OBJECT
public:
    explicit Calculation(QObject *parent = nullptr);

    QString solveExpression(const QString &expression);

    void setMathMode(MathMode *mathMode);

private:
    QString expression;
    QMap<QString, int> *precedence;
    MathMode *mathMode;

    QVector<QString> *numbersAndOperators;

    // This function shares numbers and operators to vector
    // for further distribution for stack.
    void fillVectorNumbersAndOperators();
    
    // Here makes a transform
    QStack<double> *numberStack;
    QStack<QString> *operatorStack;
    QVector<QString> *postfixVector;
    void transformToPostfix();
    
    void calculatePostfix();
    
    QString errorMessage;
    bool checkBrackets();
    
    int numbers = 0;
    int operators = 0;
    bool checkNumbersAndOperators();
    
    double solveTrigonometric(const QString &oper);
    
    QVector<QString> *trigOperators;
    bool isTrigonometricFunc(const QString &oper);
    
    double solveLogarithm(const QString &oper);
    
    QVector<QString> *logarithmOperators;
    bool isLogarithm(const QString &oper);
    
};

#endif // CALCULATION_H
