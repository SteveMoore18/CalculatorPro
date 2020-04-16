#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>


#include "calculation.h"

class Logic : public QObject
{
    Q_OBJECT
public:
    explicit Logic(QObject *parent = nullptr);

    void setDisplayEdit(QLineEdit *value);

    void setLbResult(QLabel *value);

private:
    QLineEdit *displayEdit;
    QLabel *lbResult;

    Calculation *calculation;

    bool operatorEntered = false;;

public slots:
    void startOfInput(const QString &textButton);

};

#endif // LOGIC_H
