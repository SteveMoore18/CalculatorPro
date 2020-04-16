#include "mainwindow.h"

#include <QGuiApplication>
#include <QScreen>
#include <QSysInfo>
#include <QResizeEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    centralWidget = new QWidget;

    mainVLayout = new QVBoxLayout;

    screen = QGuiApplication::primaryScreen();


    normalMode = new NormalMode(this);
    displayEdit = new QLineEdit(this);
    historyList = new QListWidget(this);
    cbMode = new QComboBox(this);
    logic = new Logic(this);
    lbResult = new QLabel(this);

    int w = screen->geometry().width() - 35;

    displayEdit->setText("");
    displayEdit->setReadOnly(true);

    displayEdit->setMinimumSize(w, 60);
    displayEdit->setMaximumSize(w, 90);

    historyList->setMinimumSize(w, 40);
    historyList->setMaximumSize(w, 90);

    lbResult->setFixedSize(w, 50);

    cbMode->setMinimumSize(w, 50);
    cbMode->setMinimumSize(w, 60);


    cbMode->addItem("Normal mode");
    cbMode->addItem("Programmer mode");
    cbMode->addItem("Math mode");

    mainVLayout->addWidget(cbMode, 1, Qt::AlignHCenter);
    mainVLayout->addWidget(historyList, 1, Qt::AlignHCenter);
    mainVLayout->addWidget(lbResult, 1, Qt::AlignHCenter);
    mainVLayout->addWidget(displayEdit, 1, Qt::AlignHCenter);
    mainVLayout->addWidget(normalMode);


    logic->setDisplayEdit(displayEdit);
    logic->setLbResult(lbResult);

    connect(normalMode, SIGNAL(buttonClicked(QString)),  logic, SLOT(startOfInput(QString)));


    centralWidget->setLayout(mainVLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
}

