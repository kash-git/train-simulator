#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QThread>
#include <QTimer>
#include "graph.h"
#include "trainthread.h"


TrainThread::TrainThread(QObject *parent):QThread(parent)
{}

TrainThread::~TrainThread()
{
    delete m_train;
}

void TrainThread::run()
{
    //qInfo()<<"hello";
    m_train->mainLogic();
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    TrainThread* trainThread=new TrainThread;

    MergingPoint window;
    window.show();


    w.show();
    int ret =a.exec();

//     Wait for the thread to finish before exiting

    trainThread->wait();
    trainThread->quit();

    return ret;
}
