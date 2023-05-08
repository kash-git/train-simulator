
#ifndef TRAINTHREAD_H
#define TRAINTHREAD_H

#include <QThread>
#include <trainsim.h>
#include <mainwindow.h>

class TrainThread : public QThread {
    Q_OBJECT

public:
    TrainThread(QObject *parent = nullptr);
    ~TrainThread();

protected:
    void run() override;

public:
    trainSim* m_train;
};

#endif
