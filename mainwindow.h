#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDebug>
#include <QListWidget>
#include <QComboBox>
#include <QLabel>
#include <QTabWidget>
#include <QScrollArea>
#include <QPoint>
#include <QMenu>
#include <QClipboard>
#include <QApplication>
#include <QTimer>

#include "CalculaterMode/normalmode.h"
#include "logic.h"
#include "CalculaterMode/MathMode.hpp"
#include "CalculaterMode/ProgrammerMode.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    enum CalculatorMode
    {
        BASE,
        MATH,
        PROGRAMMER
    };
    
private:
    QVBoxLayout *mainVLayout;

    NormalMode *normalMode;
    MathMode *mathMode;
    ProgrammerMode *programmerMode;
    Logic *logic;
    
    ProgrammerMode::NumberSystem currentNumberSystem;
    
    QPlainTextEdit *displayEdit;
    QListWidget *historyList;
    QTabWidget *tabMode;
    QPushButton *lbResult;

    QScreen *screen;
    QWidget *centralWidget;

    QClipboard *clipboard;
    QTimer *timerCopied;
    QString tempsResult;

private slots:
    void on_tabBar_clicked(int index);
    
    void copyResult();
    
    void copyExpression(QListWidgetItem *item);
    
    void on_timerCopiedTimeout();

};
#endif // MAINWINDOW_H
