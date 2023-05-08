#include "mainwindow.h"
#include <QApplication>
#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include <QDesktopWidget>
#include <QTime>
#include <QPaintEvent>
#include <source.h>
#include <QDebug>
#include <QTimer>
#include <graph.h>
#include <trainsim.h>
//#include <train.h>
//#include <sourceheader.h>


//visibility status for each ellipse

bool m_dot1Rect=false;
bool m_dot2Rect=false;
bool m_dot3Rect=false;
bool m_dot4Rect=false;
bool m_dot5Rect=false;
bool m_dot6Rect=false;
QRect dot1Rect;
QRect dot2Rect;
QRect dot3Rect;
QRect dot4Rect;
QRect dot5Rect;
QRect dot6Rect;
int sour=0;
// Blinking interval in milliseconds for each ellipse
   const int BLINK_INTERVAL = 500;

    //so s;

    //abc aa;
    MergingPoint::MergingPoint(QWidget* parent) : QMainWindow(parent) {
        setFixedSize(1300, 300);
//        QTimer* m_timer=new QTimer(this);
//        connect(m_timer,&QTimer::timeout,this,&MergingPoint::sourc);
//        //source=t.getSource();
//        m_timer->start(100);
        back=new trainSim;
        connect(back,SIGNAL(signalForGraph(int)),this,SLOT(graphSlots(int)));
        centerOnScreen();
        startBlinking();
    }

    MergingPoint::~MergingPoint()
    {

    }


        QColor color1, color2;
//        void MergingPoint::sourc(){
//            source=t.getSource();
//            //qInfo()<<source;
//            update();
//        }


//    void updateData(){

//    }
//    void MergingPoint::onTimer(){

//        update();

//    }
        void MergingPoint::graphSlots(int src)
        {
            sour=src;
            //qInfo()<<sour;
            update();
        }

    void MergingPoint::paintEvent(QPaintEvent*) {
        QPainter painter(this);

        // define ellipse and line positions for first row
        dot1Rect = QRect(100, 100, 30, 30);
        dot2Rect = QRect(300, 100, 30, 30);
        dot3Rect = QRect(500, 100, 30, 30);
        dot4Rect = QRect(700, 100, 30, 30);
        dot5Rect = QRect(900, 100, 30, 30);
        dot6Rect = QRect(1100, 100, 30, 30);

        QPoint dot1Center = dot1Rect.center();
        QPoint dot2Center = dot2Rect.center();
        QPoint dot3Center = dot3Rect.center();
        QPoint dot4Center = dot4Rect.center();
        QPoint dot5Center = dot5Rect.center();
        QPoint dot6Center = dot5Rect.center();

        // draw the blinking dots
        drawDot(painter, dot1Rect, m_dot1Rect, 1,"Huda City Centre",Qt::yellow);
        drawDot(painter, dot2Rect, m_dot2Rect, 2,"IFFCO Chowk",Qt::yellow);
        drawDot(painter, dot3Rect, m_dot3Rect, 3,"MG Road",Qt::yellow);
        drawDot(painter, dot4Rect, m_dot4Rect, 4,"Sikandarpur",Qt::yellow);
        drawDot(painter, dot5Rect, m_dot5Rect, 5,"Guru Dronacharya",Qt::yellow);
        drawDot(painter, dot6Rect, m_dot6Rect, 6,"Arjangarh",Qt::yellow);

        // draw the lines connecting the dots
        painter.setPen(QPen(Qt::yellow, 4));
        painter.drawLine(dot1Rect.right(), dot1Center.y(), dot2Rect.left(), dot2Center.y());
        painter.drawLine(dot2Rect.right(), dot2Center.y(), dot3Rect.left(), dot3Center.y());
        painter.drawLine(dot3Rect.right(), dot3Center.y(), dot4Rect.left(), dot4Center.y());
        painter.drawLine(dot4Rect.right(), dot4Center.y(), dot5Rect.left(), dot5Center.y());
        painter.drawLine(dot5Rect.right(), dot5Center.y(), dot6Rect.left(), dot6Center.y());

        //modifyDot(painter, dot1Rect, m_dot1Rect, 1,"Huda City Centre",Qt::red);
    }


    void MergingPoint::startBlinking() {
        // Create a timer that fires every 500 milliseconds
        QTimer* timer = new QTimer(this);
        timer->setInterval(100);
        connect(timer, &QTimer::timeout, this, &MergingPoint::onTimeout);
        timer->start();
    }


    void MergingPoint::drawDot(QPainter& painter, const QRect& rect, bool visible, int dotNumber, const QString& label, const QColor& fillColor)
    {
        int a=dotNumber;
//        QColor color1, color2;
//        if (dotNumber % 2 == 0) {
//            color1 = Qt::yellow;
//            color2 = Qt::green;
//        } else {
//            color1 = Qt::blue;
//            color2 = Qt::green;
//        }
        color1=Qt::yellow;
        color2=Qt::red;
        painter.setBrush(fillColor);
        painter.setPen(QPen(visible ? color2 : color1, 7));
        painter.drawEllipse(rect);

        // draw the label
        QRect labelRect = QRect(rect.x(), rect.y() + rect.height(), 90, 70);
        painter.setPen(Qt::black);  // set the pen color to black
        painter.drawText(labelRect, Qt::AlignCenter | Qt::TextWordWrap, label);  // draw the full text label with word wrap

    }



    void MergingPoint::drawLine(QPainter& painter, const QPoint& p1, const QPoint& p2, const QColor& color) {
        painter.setPen(QPen(color, 2));
        painter.drawLine(p1, p2);
    }

    void MergingPoint::onTimeout() {
        // Toggle the visibility status for each ellipse based on its blinking interval
                int currentTime = QTime::currentTime().msecsSinceStartOfDay();
//                QPaintEvent q;
//                q.Paint;
                //so s;
//                aa.ab->sourc
                //qInfo()<<s.sourc;
                switch(sour){
                    case 10:
                        m_dot1Rect=true;
                        break;
                    case 1:
                    m_dot1Rect=true;
                        m_dot2Rect = (currentTime % (2 * BLINK_INTERVAL) < BLINK_INTERVAL);
                        //qInfo()<<s.sourc;
                        break;
                    case 2:
                    m_dot1Rect=true;
                    m_dot2Rect=true;
                        m_dot3Rect = (currentTime % (2 * BLINK_INTERVAL) < BLINK_INTERVAL);
                        break;
                    case 3:
                    m_dot1Rect=true;
                    m_dot2Rect=true;
                    m_dot3Rect=true;
                        m_dot4Rect = (currentTime % (2 * BLINK_INTERVAL) < BLINK_INTERVAL);
                        break;
                    case 4:
                    m_dot1Rect=true;
                    m_dot2Rect=true;
                    m_dot3Rect=true;
                    m_dot4Rect=true;
                        m_dot5Rect = (currentTime % (2 * BLINK_INTERVAL) < BLINK_INTERVAL);
                        break;
                    case 5:
                    m_dot1Rect=true;
                    m_dot2Rect=true;
                    m_dot3Rect=true;
                    m_dot4Rect=true;
                    m_dot5Rect=true;
                        m_dot6Rect = (currentTime % (2 * BLINK_INTERVAL) < BLINK_INTERVAL);
                        break;
                    case 6:
                    m_dot1Rect=true;
                    m_dot2Rect=true;
                    m_dot3Rect=true;
                    m_dot4Rect=true;
                    m_dot5Rect=true;
                    m_dot6Rect=true;
                    break;
                    default:
                    m_dot1Rect=false;
                    m_dot2Rect=false;
                    m_dot3Rect=false;
                    m_dot4Rect=false;
                    m_dot5Rect=false;
                    m_dot6Rect=false;
                }
        update();
    }

    void MergingPoint::centerOnScreen() {
        // Get the geometry of the user's desktop
        QRect desktopRect = QApplication::desktop()->screenGeometry();
        QApplication::desktop()->windowTitleChanged("graph");
        // Center the main window on the desktop
        move((desktopRect.width() - width()*1.45) / 2, (desktopRect.height() - height()) / 2);
    }







