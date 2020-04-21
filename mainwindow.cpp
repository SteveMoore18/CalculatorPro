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
    
    displayEdit = new QPlainTextEdit(this);
    historyList = new QListWidget(this);
    //cbMode = new QComboBox(this);
    tabMode = new QTabWidget(this);
    logic = new Logic(this);
    lbResult = new QLabel(this);

    int w = screen->geometry().width() - 18;

    //displayEdit->setText("2+(2*(4-2))");
    //displayEdit->setReadOnly(true);

    displayEdit->setMinimumSize(w, 60);
    displayEdit->setMaximumSize(w, 90);

    historyList->setMinimumSize(w, 70);
    historyList->setMaximumSize(w, 200);
    
//    for (int i = 0; i < 100; i++){
//        historyList->addItem(QString::number(i));
//        historyList->item(i)->setSizeHint(QSize(0, 50));
//    }
//    
    QScroller::grabGesture(historyList, QScroller::LeftMouseButtonGesture);
    historyList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    
    lbResult->setFixedSize(w, 50);
    
    mainVLayout->addWidget(historyList, 1, Qt::AlignHCenter);
    mainVLayout->addWidget(lbResult, 1, Qt::AlignHCenter);
    mainVLayout->addWidget(displayEdit, 1, Qt::AlignHCenter);
    
    tabMode->addTab(normalMode, "Basic");
    tabMode->addTab(mathMode, "Math");
    
    mainVLayout->addWidget(tabMode);

    logic->setDisplayEdit(displayEdit);
    logic->setLbResult(lbResult);
    logic->setHistoryList(historyList);

    connect(normalMode, SIGNAL(buttonClicked(QString)),  logic, SLOT(startInputBasic(QString)));
    connect(mathMode, SIGNAL(buttonClicked(QString)), logic, SLOT(startInputMath(QString)));

    centralWidget->setLayout(mainVLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
}

