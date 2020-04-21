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
    if (textButton == "^" && powEntered)
    {
        return;
    }
    else if (textButton == "-" && minusEntered)
    {
        return;
    }
    if (textButton == "^" && !powEntered)
    {
        powEntered = true;
    }
    else if (isOperator(textButton) && textButton != "-")
    {
        powEntered = false;
    }
    else if (textButton == "-" && !minusEntered)
    {
        minusEntered = true;
    }
    
    
    
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
        powEntered = false;
        infixExpression = "";
    }
    // Remove one symbol
    else if (textButton == "rmOneSym")
    {
        cursor.deletePreviousChar();
        
        //infixExpression.remove(infixExpression.size() - 1, 1);
        if (infixExpression.size() != 0)
        {
            
        }
        
    }
    // Make calculations
    else if (textButton == "=")
    {
        QString text = infixExpression;
        if (!text.isEmpty())
        {
            // Get how pow operations in expression
            int powCount = text.count("^");
            
            // Adding brackets
            for (int j = 0; j < powCount; j++)
            {
                
                int pos = text.indexOf("^");
                if (pos != -1)
                {
                    // Add after ^ operation
                    text.insert(pos + 1, "(");
                    
                    // Finding end of number pow
                    for (int i = pos + 2; i <= text.size(); i++)
                    {
                        if (i == text.size())
                        {
                            text += ")";
                            break;
                        }
                        else if (isOperator(text.at(i)))
                        {
                            text.insert(i, ")");
                            break;
                        }
                    }
                }
                
            }
            
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
        
        infixExpression += textButton;
        if (powEntered)
        {
            
            if (textButton != "^")
            {
                cursor.insertHtml("<sup>" + textButton + "</sup>");
            }
//            else if (textButton == "^")
//                infixExpression += "(";
        }
        else
        {
            cursor.insertHtml(textButton);
        }

        
    }
}

bool Logic::isOperator(const QString &str)
{
    QVector<QString> operators;
    operators.push_back("+");
    operators.push_back("*");
    operators.push_back("-");
    operators.push_back("/");
    operators.push_back("(");
    operators.push_back(")");
    
    for (int i = 0; i < operators.size(); i++)
        if (str == operators.at(i))
            return true;

    return false;
}
