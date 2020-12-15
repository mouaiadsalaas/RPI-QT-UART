#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QDebug>
#include <QTextStream>
#include <QTime>
#include <QDate>


#include <QCoreApplication>
#include <iostream>
#include <QSerialPort>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mTimer = new QTimer;
    serial= new QSerialPort;

/**********************/
/*****third step******/
/********************/
    //here we setup our library and set our pins mode then go to our slot functions
    wiringPiSetup();

    connect(mTimer, SIGNAL(timeout()), this, SLOT(updateCaption()));
    mTimer->start(500);



}

MainWindow::~MainWindow()
{
    delete ui;
}


//function has been created for timer duty
void MainWindow::updateCaption()
{

    serial->setPortName("ttyUSB0");
    serial->open(QIODevice::ReadWrite);

    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    while(!serial->isOpen()) serial->open(QIODevice::ReadWrite);

    if (serial->isOpen() && serial->isWritable())
    {
    qDebug() << "Serial is open";

    QByteArray output;
    QByteArray input;

    while(true)
    {
     output = "a";
     serial->write(output);
     serial->flush();
     mTimer->start(500);


      serial->waitForBytesWritten(100);
      serial->waitForReadyRead(100);

     if(serial->bytesAvailable()>=18)
      input = serial->read(18);
      qDebug()<<input;
      qDebug()<<"\n";

      }
    }
}
