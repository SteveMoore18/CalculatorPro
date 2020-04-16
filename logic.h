#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <QListWidget>

#include "calculation.h"

class Logic : public QObject
{
    Q_OBJECT
private:
    const QSize listItemSize = QSize(0, 50);
    
public:
    explicit Logic(QObject *parent = nullptr);

    void setDisplayEdit(QLineEdit *value);

    void setLbResult(QLabel *value);
    
    void setHistoryList(QListWidget *historyList);

private:
    QLineEdit *displayEdit;
    QLabel *lbResult;
    QListWidget *historyList;

    Calculation *calculation;

    bool operatorEntered = false;
    bool dotEntered = false;
    

public slots:
    void startOfInput(const QString &textButton);

};

#endif // LOGIC_H
