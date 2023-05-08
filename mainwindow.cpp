 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "speedometer.h"
//#include "distance.h"
#include <QHBoxLayout>
#include <QPixmap>
//#include <traininfo.h>
#include <QDesktopWidget>
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include <QLineEdit>
#include <QLabel>
//#include <trainthread.h>
MainWindow::MainWindow(QWidget *parent):

    QMainWindow(parent),
    ui(new Ui::MainWindow)

{

    Speedometer *speedometer = new Speedometer();
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(speedometer);
    setCentralWidget(new QWidget);
    centralWidget()->setLayout(layout);
    QRect desktopRect = QApplication::desktop()->screenGeometry();
    // Center the main window on the desktop
    move((desktopRect.width() + width()*1.2) / 2, (desktopRect.height() - height()) / 1.7);
    back=new trainSim;
    connect(back,SIGNAL(valueGeneratedSignal(int)),this,SLOT(valueGeneratedSlot(int)));
    connect(back,SIGNAL(signalDistance(int)),this,SLOT(distanceSlot(int)));
    connect(back,SIGNAL(signalForStation(std::string)),this,SLOT(stationSlot(std::string)));
    ui->setupUi(this);
    QPixmap pix(":/img/img/Quest.jpg");
    ui->label_pic->setPixmap(pix);

   timer = new QTimer(this);

        connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));

                timer->start(1000);


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    start='y';
    TrainThread* tt=new TrainThread;
   // tt.start();
    tt->start();

    //qInfo()<<start;
ui->statusBar->showMessage("Train Control System Is Connnected");


   // hide();// its use to hide the pop-up window when we working on another

 // TrainInfo *t= new TrainInfo(this);
 // t->show();

}



void MainWindow::myfunction()
{
   QTime time = QTime::currentTime();

       QString time_text =time.toString("hh:mm:ss");

       ui->label_date->setText(time_text);
}

//void MainWindow::on_lineEdit_t_returnPressed()
//{
////    trainNumber= ui->lineEdit_t->text();
////    qInfo()<<trainNumber;
//}

void MainWindow::on_pushButton_2_clicked()
{
    exit(0);
}

void MainWindow::valueGeneratedSlot(int value)
{
    ui->speed_label->setText(QString::number(value));

    update();
}

void MainWindow::distanceSlot(int val)
{
    ui->distance_label->setText(QString::number(val));
    update();
}

void MainWindow::stationSlot(std::string str)
{
    ui->station_label->setText(QString::fromStdString(str));
    update();
}
void MainWindow::setLabelText(QString str){
   //qInfo() << str;
  //ui->label>setText(str);

  MainWindow mainwindow;
  connect(&mainwindow,SIGNAL(lineEdit_TrainNumber_inputted),this, SLOT(update_label_3_fields)
            );


}

