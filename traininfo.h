#ifndef TRAININFO_H
#define TRAININFO_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class TrainInfo;

}

class TrainInfo : public QDialog
{
    Q_OBJECT

public:
    explicit TrainInfo(QWidget *parent = 0);
    QString trainNumber;
    ~TrainInfo();

private slots:



//void setLabelText(QString str);


    void on_pushButton_clicked();

private:
    Ui::TrainInfo *ui;

};

#endif // TRAININFO_H
