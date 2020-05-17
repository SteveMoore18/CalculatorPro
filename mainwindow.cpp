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
    
    clipboard = QApplication::clipboard();
    timerCopied = new QTimer(this);
    
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
    
    connect(timerCopied, SIGNAL(timeout()), this, SLOT(on_timerCopiedTimeout()));
    connect(historyList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(copyExpression(QListWidgetItem*)));

    this->setStyleSheet("background-color: white;");
    tabMode->tabBar()->setExpanding(true);

//    width: 160px;
//    height: 40px;
    
    QFile tabBarStyle(":/styles/Appearance/CSS/TabBarStyle.css");
    if (tabBarStyle.open(QIODevice::ReadOnly))
    {
        QString css = tabBarStyle.readAll();
        css = css.arg(normalMode->getNumberButtonColor().name());
        
        tabMode->setStyleSheet(css);
    }
    tabBarStyle.close();
    
    QFile textEditStyle(":/styles/Appearance/CSS/TextEdit.css");
    if (textEditStyle.open(QIODevice::ReadOnly))
    {
        QString css = textEditStyle.readAll();
        css = css.arg(normalMode->getNumberButtonColor().name());
        
        displayEdit->setStyleSheet(css);
    }
    textEditStyle.close();
    
    QFile resultButtonStyle(":/styles/Appearance/CSS/ResultButton.css");
    if (resultButtonStyle.open(QIODevice::ReadOnly))
    {
        QString css = resultButtonStyle.readAll();
        css = css.arg(normalMode->getNumberButtonColor().name());
        
        lbResult->setStyleSheet(css);
    }
    resultButtonStyle.close();
    
    QFile listWidgetStyle(":/styles/Appearance/CSS/ListWidget.css");
    if (listWidgetStyle.open(QIODevice::ReadOnly))
    {
        QString css = listWidgetStyle.readAll();
        css = css.arg(normalMode->getNumberButtonColor().name()).arg(normalMode->getOtherButtonColor().name());
        
        historyList->setStyleSheet(css);
    }
    listWidgetStyle.close();
    
    
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
        programmerMode->transformInNewNumberSystem(ProgrammerMode::NumberSystem::DEC, currentNumberSystem);
    }
    else
    {
        if (programmerMode->getNumberSystem() != ProgrammerMode::NumberSystem::NONE)
        {
            currentNumberSystem = programmerMode->getNumberSystem();
            programmerMode->transformInNewNumberSystem(currentNumberSystem, ProgrammerMode::NumberSystem::DEC);
            programmerMode->setNumberSystem(ProgrammerMode::NumberSystem::NONE);
        }
        
    }
}

void MainWindow::copyResult()
{
    if (lbResult->text() != "Copied!")
    {
        clipboard->setText(lbResult->text());
        tempsResult = lbResult->text();
        lbResult->setText("Copied!");
        timerCopied->start(1000);
    }
}

void MainWindow::on_timerCopiedTimeout()
{
    lbResult->setText(tempsResult);
    timerCopied->stop();
}

void MainWindow::copyExpression(QListWidgetItem *item)
{
    if (lbResult->text() != "Copied!")
    {
        clipboard->setText(item->text());
        tempsResult = lbResult->text();
        lbResult->setText("Copied!");
        
        timerCopied->start(1000);
    }
    
    
    QString onlyExpression = "";
    for (int i = 0; i < item->text().size(); i++)
    {
        QString curr = QString(item->text()[i]);
        if (curr == "=")
            break;
        onlyExpression += curr;
    }
    
    displayEdit->setPlainText(onlyExpression);
    
    QTextCursor cursor = displayEdit->textCursor();
    cursor.setPosition(onlyExpression.size() - 1);
    displayEdit->setTextCursor(cursor);
    
    
}
