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

    double solveExpression(const QString &expression);


private:
    QString expression;

    QVector<QString> *numbersAndOperators;
    QStack<double> *numberStack;
    QStack<QString> *operatorStack;

    void fillVectorNumbersAndOperators();
    void stackDistribution();
    void makeResult();

};

#endif // CALCULATION_H
