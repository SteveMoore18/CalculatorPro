#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>
#include <QComboBox>
#include <QLineEdit>


#include "calculation.h"

class Logic : public QObject
{
    Q_OBJECT
public:
    explicit Logic(QObject *parent = nullptr);

    void setDisplayEdit(QLineEdit *value);

private:
    QLineEdit *displayEdit;

    Calculation *calculation;

public slots:
    void startOfInput(const QString &textButton);

};

#endif // LOGIC_H
