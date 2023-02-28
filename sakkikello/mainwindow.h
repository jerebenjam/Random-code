#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void timeoutHandler();
    void timeoutHandler2();

private:
    short player1Time;
    short player2Time;
    short currentPlayer;
    short gameTime;
    QTimer * pQTimer;
    QTimer * pQTimer2;
    short turn;
    int state;
    Ui::MainWindow *ui;

    void updateProgressBar();
    void setGameInfoText(QString,short);

private slots:
    void switchButtonHandler();
    void timeSelectHandler();
    void startStopHandler();

};
#endif // MAINWINDOW_H
