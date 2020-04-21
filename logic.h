#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <QListWidget>
#include <QPlainTextEdit>

#include "calculation.h"

class Logic : public QObject
{
    Q_OBJECT
private:
    const QSize listItemSize = QSize(0, 50);
    
public:
    explicit Logic(QObject *parent = nullptr);

    void setDisplayEdit(QPlainTextEdit *value);

    void setLbResult(QLabel *value);
    
    void setHistoryList(QListWidget *historyList);

private:
    QPlainTextEdit *displayEdit;
    QTextCursor cursor;
    
    bool powEntered = false;
    bool minusEntered = false;
    QString infixExpression = "";
    
    QLabel *lbResult;
    QListWidget *historyList;

    Calculation *calculation;

    bool operatorEntered = false;
    bool dotEntered = false;
    
    void startingInput(const QString &textButton);
    
    bool isOperator(const QString &str);

public slots:
    void startInputBasic(const QString &textButton);
    
    void startInputMath(const QString &textButton);

};

#endif // LOGIC_H
