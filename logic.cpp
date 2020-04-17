#include "logic.h"

#include <QDebug>

Logic::Logic(QObject *parent) : QObject(parent)
{
    displayEdit = nullptr;
    lbResult = nullptr;
    historyList = nullptr;

    calculation = new Calculation(this);
}

void Logic::setDisplayEdit(QPlainTextEdit *value)
{
    displayEdit = value;
}

void Logic::setLbResult(QLabel *value)
{
    lbResult = value;
}

void Logic::startInputBasic(const QString &textButton)
{
    startingInput(textButton);
}

void Logic::startInputMath(const QString &textButton)
{
    startingInput(textButton);
}

void Logic::setHistoryList(QListWidget *historyList)
{
    this->historyList = historyList;
}


void Logic::startingInput(const QString &textButton)
{
    // Crear all display edit
    if (textButton == "Clear"){
        displayEdit->clear();
        lbResult->clear();
        operatorEntered = false;
    }
    // Remove one symbol
    else if (textButton == "rmOneSym")
    {
        //displayEdit->bac
    }
    // Make calculations
    else if (textButton == "=")
    {
        
        
        QString text = displayEdit->toPlainText();
        if (!text.isEmpty())
        {
            
            QString result = calculation->solveExpression(text);
            lbResult->setText(result);
            
            QString strHistory = QString("%1 = %2").arg(text).arg(result);
            historyList->addItem(strHistory);
            
            int itemCount = historyList->count() - 1;
            historyList->item(itemCount)->setSizeHint(listItemSize);
            
        }
        
    }
    // Other just add new symbol to displat edit
    else
    {
        cursor = displayEdit->textCursor();
        cursor.insertHtml(textButton);
        
        
    }
}
