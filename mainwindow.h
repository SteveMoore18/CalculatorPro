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

#include "CalculaterMode/normalmode.h"
#include "logic.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QVBoxLayout *mainVLayout;

    NormalMode *normalMode;
    QLineEdit *displayEdit;
    QListWidget *historyList;
    QTabWidget *tabMode;
    QLabel *lbResult;

    QScreen *screen;
    QWidget *centralWidget;

    Logic *logic;


private slots:

};
#endif // MAINWINDOW_H
