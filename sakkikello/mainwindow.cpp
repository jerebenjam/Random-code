#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    turn=0;
    ui->setupUi(this);

    state=1;    //initial state
    ui->label->setText("Choose time and press start");
    pQTimer = new QTimer(this);
    pQTimer->setInterval(1000);
    connect(pQTimer, &QTimer::timeout,this,&MainWindow::timeoutHandler);

    pQTimer2 = new QTimer(this);
    pQTimer2->setInterval(1000);
    connect(pQTimer2, &QTimer::timeout,this,&MainWindow::timeoutHandler2);



    connect(ui->startButton,SIGNAL(clicked()),
            this,SLOT(startStopHandler()),Qt::QueuedConnection);
    connect(ui->stopButton,SIGNAL(clicked()),
            this,SLOT(startStopHandler()),Qt::QueuedConnection);
    connect(ui->time1Button,SIGNAL(clicked()),
            this,SLOT(timeSelectHandler()),Qt::QueuedConnection);
    connect(ui->time2Button,SIGNAL(clicked()),
            this,SLOT(timeSelectHandler()),Qt::QueuedConnection);
    connect(ui->swich1,SIGNAL(clicked()),
            this,SLOT(switchButtonHandler()),Qt::QueuedConnection);
    connect(ui->swich2,SIGNAL(clicked()),
            this,SLOT(switchButtonHandler()),Qt::QueuedConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pQTimer;
    delete pQTimer2;
}

void MainWindow::startStopHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug() << "Button name: "<<name;
    if(state==2 || state == 3){
    if(name == "startButton"){
        state = 3; //kellon kÃ¤ynnistys
        pQTimer->start();
        ui->label->setText("Game is running");
    }
    else if(name == "stopButton"){
        state=1;
        pQTimer->stop();
        pQTimer2->stop();
        ui->label->setText("Game stopped");
    }
}
}
void MainWindow::timeSelectHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug() << "Button name: "<<name;


        if(name == "time1Button"){
            state=2;
            ui->progressBar1->setRange(0, 120);
            ui->progressBar1->setValue(120);
            ui->progressBar2->setRange(0, 120);
            ui->progressBar2->setValue(120);

    }
    else if(name == "time2Button"){
            state=2;
            ui->progressBar1->setRange(0, 300);
            ui->progressBar1->setValue(300);
            ui->progressBar2->setRange(0, 300);
            ui->progressBar2->setValue(300);

    }
}

void MainWindow::timeoutHandler(){
    // Update the value of progress bar 1
    int currentValue = ui->progressBar1->value();
    if (currentValue > ui->progressBar1->minimum()) {
        ui->progressBar1->setValue(currentValue - 1);
    } else {
        // Stop the timer if it reaches the minimum value
        pQTimer->stop();
        ui->label->setText("Player 2 won!");
    }
}
void MainWindow::timeoutHandler2(){
    // Update the value of progress bar 2
    int currentValue = ui->progressBar2->value();
    if (currentValue > ui->progressBar2->minimum()) {
        ui->progressBar2->setValue(currentValue - 1);
    } else {
        // Stop the timer if it reaches the minimum value
        pQTimer2->stop();
        ui->label->setText("Player 1 won!");
    }
}
void MainWindow::switchButtonHandler()
{

    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug() << "Button name: "<<name;

    if(turn==0){
    if(name == "swich1")
    {
        turn=1;
        pQTimer->stop();
        pQTimer2->start();
    }
   } else if (turn==1){
        if(name == "swich2"){
        turn=0;
        pQTimer2->stop();
        pQTimer->start();

    }
  }
}

