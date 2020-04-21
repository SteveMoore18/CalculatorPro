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
    QPushButton *btnSqrt;
    QPushButton *btnSin;
    QPushButton *btnCos;
    QPushButton *btnTan;
    QPushButton *btnCtg;
//    QPushButton *btnTan;
//    QPushButton *btnCtg;
    
    
    
    QHBoxLayout *mainLayout;
    QGridLayout *mathLayout;
    
    bool btnPowClicked = false;
    
private slots:
    void on_btnPow2_clicked();
    
    void on_btnSqrt_clicked();
    
    void on_normalMode_clicked(const QString &textButton);
    
};

#endif /* MathMode_hpp */
