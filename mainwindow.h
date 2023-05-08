#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include "ui_mainwindow.h"
#include <QMainWindow>
#include <Qtimer>
#include <trainthread.h>
#include <trainsim.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setLabelText(QString str);
    QString trainNumber;
    QString start;
    trainSim *back;


private slots:
    void on_pushButton_clicked();
    //void push();


    void myfunction();

    //void on_lineEdit_t_editingFinished();

    //void on_lineEdit_t_returnPressed();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    //Distance *widget_2;
private slots:
    void valueGeneratedSlot(int);
    void distanceSlot(int);
    void stationSlot(std::string);

public:
    trainSim ts;
};

#endif // MAINWINDOW_H

