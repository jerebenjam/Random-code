#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->N0,SIGNAL(clicked()),
            this,SLOT(numberClickedHandler()),Qt::QueuedConnection);

    connect(ui->N1,SIGNAL(clicked()),
            this,SLOT(numberClickedHandler()),Qt::QueuedConnection);

    connect(ui->N2,SIGNAL(clicked()),
            this,SLOT(numberClickedHandler()),Qt::QueuedConnection);

    connect(ui->N3,SIGNAL(clicked()),
            this,SLOT(numberClickedHandler()),Qt::QueuedConnection);

    connect(ui->N4,SIGNAL(clicked()),
            this,SLOT(numberClickedHandler()),Qt::QueuedConnection);

    connect(ui->N5,SIGNAL(clicked()),
            this,SLOT(numberClickedHandler()),Qt::QueuedConnection);

    connect(ui->N6,SIGNAL(clicked()),
            this,SLOT(numberClickedHandler()),Qt::QueuedConnection);

    connect(ui->N7,SIGNAL(clicked()),
            this,SLOT(numberClickedHandler()),Qt::QueuedConnection);

    connect(ui->N8,SIGNAL(clicked()),
            this,SLOT(numberClickedHandler()),Qt::QueuedConnection);

    connect(ui->N9,SIGNAL(clicked()),
            this,SLOT(numberClickedHandler()),Qt::QueuedConnection);

    connect(ui->clear,SIGNAL(clicked()),
            this,SLOT(clearAndEnterClickhandler()),Qt::QueuedConnection);

    connect(ui->enter,SIGNAL(clicked()),
            this,SLOT(clearAndEnterClickhandler()),Qt::QueuedConnection);

    connect(ui->add,SIGNAL(clicked()),
            this,SLOT(addSubMulDivClickHandler()),Qt::QueuedConnection);

    connect(ui->sub,SIGNAL(clicked()),
            this,SLOT(addSubMulDivClickHandler()),Qt::QueuedConnection);

    connect(ui->mul,SIGNAL(clicked()),
            this,SLOT(addSubMulDivClickHandler()),Qt::QueuedConnection);

    connect(ui->div,SIGNAL(clicked()),
            this,SLOT(addSubMulDivClickHandler()),Qt::QueuedConnection);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickedHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    //qDebug() << "Button name:" << name;

    if(state == 1){
        number1 = number1 + name.back();
        ui->num1->setText(QString(number1));
    }
    else{
        number2 = number2 + name.back();
        ui->num2->setText(QString(number2));
    }

    //float n1 = number1.toFloat();
    //float n2 = number2.toFloat();
    //qDebug() << "number 1 = "<< n1 <<" and number 2 = "<<n2<<Qt::endl;

}

void MainWindow::clearAndEnterClickhandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();

    if(name == "clear"){
        state = 1;
        number1 = "";
        number2 = "";
        resetLineEdits();
    }
    else{
        float n1 = number1.toFloat();
        float n2 = number2.toFloat();
        switch (operand) {
            case 0:
                result = n1+n2;
                ui->result->setText(QString::number(result));
                break;
            case 1:
                result = n1-n2;
                ui->result->setText(QString::number(result));
                break;
            case 2:
                result = n1*n2;
                ui->result->setText(QString::number(result));
                break;
            case 3:
                result = n1/n2;
                ui->result->setText(QString::number(result));
                break;
            default:
                break;
            }
    }
}

void MainWindow::addSubMulDivClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    //qDebug() << "Operand name:" << name;

    if(name == "add"){
        operand = 0;
    }else if(name == "sub"){
        operand = 1;
    }else if(name == "mul"){
        operand = 2;
    }else{
        operand = 3;
    }

    state = 2;
}

void MainWindow::resetLineEdits()
{
    ui->num1->setText(0);
    ui->num2->setText(0);
    ui->result->setText(0);
}

