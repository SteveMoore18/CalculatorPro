#include "logic.h"

#include <QDebug>

Logic::Logic(QObject *parent) : QObject(parent)
{
    displayEdit = nullptr;
    lbResult = nullptr;
    historyList = nullptr;

    calculation = new Calculation(this);
}

void Logic::setDisplayEdit(QLineEdit *value)
{
    displayEdit = value;
}

void Logic::setLbResult(QLabel *value)
{
    lbResult = value;
}

void Logic::startOfInput(const QString &textButton)
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
        displayEdit->backspace();
    }
    // Make calculations
    else if (textButton == "=")
    {
        QString text = displayEdit->text();
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
        
        displayEdit->insert(textButton);
        
    }

}

void Logic::setHistoryList(QListWidget *historyList)
{
    this->historyList = historyList;
}


