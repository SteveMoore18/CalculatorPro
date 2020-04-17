#ifndef CALCULATION_H
#define CALCULATION_H

#include <QObject>
#include <QVector>
#include <QStack>
#include <QMap>

class Calculation : public QObject
{
    Q_OBJECT
public:
    explicit Calculation(QObject *parent = nullptr);

    QString solveExpression(const QString &expression);


private:
    QString expression;
    QMap<QString, int> *precedence;

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

};

#endif // CALCULATION_H
