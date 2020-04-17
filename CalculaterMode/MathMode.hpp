//
//  MathMode.hpp
//  CalculatorPro
//
//  Created by Савелий Никулин on 17.04.2020.
//

#ifndef MathMode_hpp
#define MathMode_hpp

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QObject>

#include "normalmode.h"
class NormalMode;

class MathMode : public QWidget
{
    Q_OBJECT
    
public:
    explicit MathMode(QWidget *parent = nullptr);
    
signals:
    void buttonClicked(const QString &textButton);
    
private:
    NormalMode *normalMode;
    
    QPushButton *btnPow2;
    
    QHBoxLayout *mainLayout;
    QGridLayout *mathLayout;
    
private slots:
    void on_btnPow2_clicked();
    
};

#endif /* MathMode_hpp */
