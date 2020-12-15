#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
/****************************/
/******second step***********/
/****************************/
//here we include our library
//then we go to ui and creat our buttons and slots
#include "wiringPi.h"
#include "wiringPiSPI.h"
#include "wiringSerial.h"

#include <QtSerialPort/QSerialPort>
#include <QSerialPort>
#include <qserialportinfo.h>

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void updateCaption();

private:
    Ui::MainWindow *ui;

    QTimer        *mTimer;
    QSerialPort   *serial;


};

#endif // MAINWINDOW_H
