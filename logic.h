#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <QListWidget>
#include <QPlainTextEdit>

#include "calculation.h"
#include "MathMode.hpp"
class MathMode;

#include "ProgrammerMode.hpp"
class ProgrammerMode;

class Logic : public QObject
{
    Q_OBJECT
private:
    const QSize listItemSize = QSize(0, 50);
    
public:
    explicit Logic(QObject *parent = nullptr);

    void setDisplayEdit(QPlainTextEdit *value);

    void setLbResult(QPushButton *value);
    
    void setHistoryList(QListWidget *historyList);
    
    void setMathMode(MathMode *mathMode);
    
    void setProgrammerMode(ProgrammerMode *programmerMode);

    
private:
    QPlainTextEdit *displayEdit;
    QTextCursor cursor;
    
    MathMode *mathMode;
    ProgrammerMode *programmerMode;
    
    QPushButton *lbResult;
    QListWidget *historyList;

    Calculation *calculation;

    
    void startingInput(const QString &textButton);
    

public slots:
    void startInputBasic(const QString &textButton);
    
    void startInputMath(const QString &textButton);
    
    void startInputProgrammer(const QString &textButton);

};

#endif // LOGIC_H
