//
//  ProgrammerMode.hpp
//  CalculatorPro
//
//  Created by Савелий Никулин on 25.04.2020.
//

#ifndef ProgrammerMode_hpp
#define ProgrammerMode_hpp

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QLabel>

#include "normalmode.h"

#include "calculation.h"
class Calculation;

class ProgrammerMode : public QWidget
{
    Q_OBJECT
public:
    explicit ProgrammerMode(QWidget *parent = nullptr);
    
    enum NumberSystem
    {
        BIN,
        OCT,
        DEC,
        HEX,
        NONE
    };
    
    NumberSystem getNumberSystem() const;
    
    void setNumberSystem(NumberSystem numberSystem);
    
    void setDisplayEdit(QPlainTextEdit *displayEdit);
    
    void setLbResult(QLabel *lbResult);
    
    void setCalculationMode(Calculation *calculation);
    
signals:
    void buttonClicked(const QString &txButton);
    
private:
    NormalMode *normalMode;
    Calculation *calculation;
    
    QVector<QString> numbersAndOperators;
    
    QPlainTextEdit *displayEdit;
    QLabel *lbResult;
    
    QHBoxLayout *mainLayout;
    QVBoxLayout *vMainLayout;
    QHBoxLayout *modeLayout;
    QGridLayout *progPanel;
    
    QPushButton *btnFF;
    QPushButton *btnA;
    QPushButton *btnB;
    QPushButton *btnC;
    QPushButton *btnD;
    QPushButton *btnE;
    QPushButton *btnF;
    QPushButton *btnAnd;
    QPushButton *btnOr;
    QPushButton *btnXor;
    QPushButton *btnMod;
    
    QRadioButton *radioOctMode;
    QRadioButton *radioDecMode;
    QRadioButton *radioHexMode;
    QRadioButton *radioBinMode;
    
    NumberSystem numberSystem;
    
    void transformInNewNumberSystem(NumberSystem fromNSys, NumberSystem toNSys);
    
private slots:
    
    void on_btnFF_clicked();
    
    void on_btnA_clicked();
    
    void on_btnB_clicked();
    
    void on_btnC_clicked();
    
    void on_btnD_clicked();
    
    void on_btnE_clicked();
    
    void on_btnF_clicked();
    // реализовать функции
    void on_btnAnd_clicked();
    
    void on_btnOr_clicked();
    
    void on_btnXor_clicked();
    
    void on_btnMod_clicked();
    
    void on_normalMode_clicked(const QString &textButton);
    
    void on_radioOct_clicked();
    
    void on_radioDec_clicked();
    
    void on_radioHex_clicked();
    
    void on_radioBin_clicked();
    
};

#endif /* ProgrammerMode_hpp */
