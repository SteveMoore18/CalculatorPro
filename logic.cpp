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

void Logic::setLbResult(QPushButton *value)
{
    lbResult = value;
}

void Logic::setMathMode(MathMode *mathMode)
{
    this->mathMode = mathMode;
    calculation->setMathMode(mathMode);
}

void Logic::startInputBasic(const QString &textButton)
{
    
    startingInput(textButton);
}

void Logic::startInputMath(const QString &textButton)
{
    
    startingInput(textButton);
}

void Logic::startInputProgrammer(const QString &textButton)
{
    startingInput(textButton);
}

void Logic::startingInput(const QString &textButton)
{
    if (textButton == "Clear")
    {
        displayEdit->clear();
        lbResult->setText("0");
    }
    else if (textButton == "=")
    {
        QString expression = displayEdit->toPlainText();
        QString result = calculation->solveExpression(expression);
        lbResult->setText(result);
        
        historyList->addItem(QString("%1 = %2").arg(expression).arg(result));
        historyList->item(historyList->count() - 1)->setSizeHint(QSize(0, 70));
        historyList->scrollToBottom();
    }
    else if (textButton == "rmOneSym")
    {
        QString text = displayEdit->toPlainText();
        
        int size = text.size();
        
        if (size != 0)
        {
            QString currentSymbol = text.at(size - 1);
            // First we check if caught a math function
            if (currentSymbol == "(" and size > 1)
            {
                bool isFuncFound = false;
                int removeSymbols = 0;
                
                if (text.at(size - 2) == "^")
                {
                    isFuncFound = true;
                    removeSymbols = 2;
                }
                else if (text.at(size - 2) == "√")
                {
                    isFuncFound = true;
                    removeSymbols = 2;
                }
                else if (text.at(size - 2) == "n" and text.at(size - 3) == "i" and text.at(size - 4) == "s")
                {
                    isFuncFound = true;
                    removeSymbols = 4;
                }
                else if (text.at(size - 2) == "s" and text.at(size - 3) == "o" and text.at(size - 4) == "c")
                {
                    isFuncFound = true;
                    removeSymbols = 4;
                }
                else if (text.at(size - 2) == "n" and text.at(size - 3) == "a" and text.at(size - 4) == "t")
                {
                    isFuncFound = true;
                    removeSymbols = 4;
                }
                else if (text.at(size - 2) == "g" and text.at(size - 3) == "t" and text.at(size - 4) == "c")
                {
                    isFuncFound = true;
                    removeSymbols = 4;
                }
                else if (text.at(size - 2) == "0" and text.at(size - 3) == "1"
                         and text.at(size - 4) == "g" and text.at(size - 5) == "o" and text.at(size - 6) == "l")
                {
                    isFuncFound = true;
                    removeSymbols = 6;
                }
                else if (text.at(size - 2) == "2" and text.at(size - 3) == "g" and text.at(size - 4) == "o"
                         and text.at(size - 5) == "l")
                {
                    isFuncFound = true;
                    removeSymbols = 5;
                }
                else if (text.at(size - 2) == "n" and text.at(size - 3) == "l")
                {
                    isFuncFound = true;
                    removeSymbols = 3;
                }
                else
                    displayEdit->textCursor().deletePreviousChar();
                
                if (isFuncFound)
                {
                    for (int i = 0; i < removeSymbols; i++)
                    displayEdit->textCursor().deletePreviousChar();
                }
            }
            else
                displayEdit->textCursor().deletePreviousChar();
        }
        
        
        
    }
    else
    {
        displayEdit->textCursor().insertHtml(textButton);
    }
    
}


void Logic::setHistoryList(QListWidget *historyList)
{
    this->historyList = historyList;
}

void Logic::setProgrammerMode(ProgrammerMode *programmerMode)
{
    this->programmerMode = programmerMode;
    calculation->setProgrammerMode(programmerMode);
    programmerMode->setCalculationMode(calculation);
}
