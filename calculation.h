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

    int solveExpression(const QString &expression);

private:
    QString expression;

    QVector<QString> *numbersAndOperators;
    QStack<int> *numberStack;
    QStack<QString> *operatorStack;

    void fillVectorNumbersAndOperators();
    void stackDistribution();
    int makeResult();

};

#endif // CALCULATION_H
