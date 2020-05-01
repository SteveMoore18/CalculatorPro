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
    
    enum TrigMode
    {
        RADIAN,
        DEGREE
    };
    
    TrigMode getTrigMode() const;
    
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
    QPushButton *btnTrigMode;
    QPushButton *btnPi;
    QPushButton *btnE;
    QPushButton *btnLog10;
    QPushButton *btnLog2;
    QPushButton *btnLn;
    
    TrigMode trigMode;
    
    QHBoxLayout *mainLayout;
    QGridLayout *mathLayout;
    
    bool btnPowClicked = false;
    
private slots:
    void on_btnPow2_clicked();
    
    void on_btnSqrt_clicked();
    
    void on_btnSin_clicked();
    
    void on_btnCos_clicked();
    
    void on_btnTan_clicked();
    
    void on_btnCtg_clicked();
    
    void on_btnTrigMode_clicked();
    
    void on_btnPi_clicked();
    
    void on_btnE_clicked();
    
    void on_btnLog10_clicked();
    
    void on_btnLog2_clicked();
    
    void on_btnLn_clicked();
    
    void on_normalMode_clicked(const QString &textButton);
    
    
    
    
};

#endif /* MathMode_hpp */
