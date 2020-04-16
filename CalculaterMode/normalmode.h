#ifndef NORMALMODE_H
#define NORMALMODE_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

class NormalMode : public QWidget
{
    Q_OBJECT
public:
    explicit NormalMode(QWidget *parent = nullptr);

    void blockOperators(const bool status);

signals:
    void buttonClicked(const QString &textButton);
    
private slots:
    void on_btn0_clicked();
    void on_btn1_clicked();
    void on_btn2_clicked();
    void on_btn3_clicked();
    void on_btn4_clicked();
    void on_btn5_clicked();
    void on_btn6_clicked();
    void on_btn7_clicked();
    void on_btn8_clicked();
    void on_btn9_clicked();

    void on_btnClear_clicked();
    void on_btnBracketOpen_clicked();
    void on_btnBracketClose_clicked();
    void on_btnPlus_clicked();
    void on_btnMinus_clicked();
    void on_btnMultiply_clicked();
    void on_btnDivision_clicked();
    void on_btnRemoveOneSym_clicked();
    void on_btnDot_clicked();
    void on_btnEqual_clicked();

    
private:
    QGridLayout *mainLayout;
    bool operatorEntered;
    bool dotEntered;


    QPushButton *btn0;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btn7;
    QPushButton *btn8;
    QPushButton *btn9;

    QPushButton *btnClear;
    QPushButton *btnBracketOpen;
    QPushButton *btnBracketClose;
    QPushButton *btnPlus;
    QPushButton *btnMinus;
    QPushButton *btnMultiply;
    QPushButton *btnDivision;
    QPushButton *btnRemoveOneSym;
    QPushButton *btnDot;
    QPushButton *btnEqual;

};

#endif // NORMALMODE_H
