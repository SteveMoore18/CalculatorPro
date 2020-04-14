#include "mainwindow.h"

#include <QGuiApplication>
#include <QScreen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget;

    mainLayout = new QVBoxLayout;

    normalMode = new NormalMode(this);
    displayEdit = new QLineEdit(this);
    historyList = new QListWidget(this);
    cbMode = new QComboBox(this);
    logic = new Logic(this);
    lbResult = new QLabel(this);

    QScreen *screen = QGuiApplication::primaryScreen();
    int w = screen->geometry().width() - 35;

    displayEdit->setText("");

    displayEdit->setFixedSize(w, 190);
    historyList->setFixedSize(w, 190);
    lbResult->setFixedSize(w, 50);
    cbMode->setFixedSize(w, 90);

    cbMode->addItem("Normal mode");
    cbMode->addItem("Programmer mode");
    cbMode->addItem("Math mode");

    mainLayout->addWidget(cbMode, 1, Qt::AlignHCenter);
    mainLayout->addWidget(historyList, 1, Qt::AlignHCenter);
    mainLayout->addWidget(lbResult, 1, Qt::AlignHCenter);
    mainLayout->addWidget(displayEdit, 1, Qt::AlignHCenter);
    mainLayout->addWidget(normalMode);

    logic->setDisplayEdit(displayEdit);

    connect(normalMode, SIGNAL(buttonClicked(QString)),  logic, SLOT(startOfInput(QString)));


    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
}
