#include "mainwindow.h"

#include <QGuiApplication>
#include <QScreen>
#include <QSysInfo>
#include <QResizeEvent>
#include <QScroller>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    centralWidget = new QWidget;

    mainVLayout = new QVBoxLayout;

    screen = QGuiApplication::primaryScreen();

    normalMode = new NormalMode(this);
    mathMode = new MathMode(this);
    programmerMode = new ProgrammerMode(this);
    
    currentNumberSystem = ProgrammerMode::NumberSystem::DEC;
    
    displayEdit = new QPlainTextEdit(this);
    historyList = new QListWidget(this);
    tabMode = new QTabWidget(this);
    logic = new Logic(this);
    lbResult = new QPushButton(this);
    
    programmerMode->setDisplayEdit(displayEdit);
    programmerMode->setLbResult(lbResult);

    int w = screen->geometry().width() - 18;

    displayEdit->setMinimumSize(w, 60);
    displayEdit->setMaximumSize(w, 90);

    historyList->setMinimumSize(w, 70);
    historyList->setMaximumSize(w, 200);
    
    QScroller::grabGesture(historyList, QScroller::LeftMouseButtonGesture);
    historyList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    
    QScroller::grabGesture(displayEdit, QScroller::LeftMouseButtonGesture);
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setWidget(displayEdit);
    QScroller::grabGesture(scrollArea, QScroller::LeftMouseButtonGesture);
    
    lbResult->setFixedSize(w, 80);
    lbResult->setText("0");
    lbResult->setStyleSheet("text-align: left;");
    
    mainVLayout->addWidget(historyList, 1, Qt::AlignHCenter);
    mainVLayout->addWidget(lbResult, 1, Qt::AlignHCenter);
    mainVLayout->addWidget(displayEdit, 1, Qt::AlignHCenter);
    
    tabMode->addTab(normalMode, "Basic");
    tabMode->addTab(mathMode, "Math");
    tabMode->addTab(programmerMode, "Programmer");
    
    mainVLayout->addWidget(tabMode);

    logic->setDisplayEdit(displayEdit);
    logic->setLbResult(lbResult);
    logic->setHistoryList(historyList);
    logic->setMathMode(mathMode);
    logic->setProgrammerMode(programmerMode);
    
    mathMode->setDisplayEdit(displayEdit);

    connect(normalMode, SIGNAL(buttonClicked(QString)),  logic, SLOT(startInputBasic(QString)));
    connect(mathMode, SIGNAL(buttonClicked(QString)), logic, SLOT(startInputMath(QString)));
    connect(programmerMode, SIGNAL(buttonClicked(QString)), logic, SLOT(startInputProgrammer(QString)));
    
    connect(tabMode, SIGNAL(tabBarClicked(int)), this, SLOT(on_tabBar_clicked(int)));
    
    connect(lbResult, SIGNAL(clicked()), this, SLOT(copyResult()));

    centralWidget->setLayout(mainVLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
}



void MainWindow::on_tabBar_clicked(int index)
{
//    logic->setInfixExpression("");
//    displayEdit->clear();
//    lbResult->clear();
    
    
    
    if (index == CalculatorMode::PROGRAMMER)
    {
        programmerMode->setNumberSystem(currentNumberSystem);
    }
    else
    {
        currentNumberSystem = programmerMode->getNumberSystem();
        programmerMode->setNumberSystem(ProgrammerMode::NumberSystem::NONE);
    }
}

void MainWindow::copyResult()
{
    qDebug() << "Hello world";
}
