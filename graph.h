#ifndef GRAPH
#define GRAPH
#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include <QDesktopWidget>
#include <QTime>
#include <QPaintEvent>
#include <trainsim.h>
#include <QObject>


class MergingPoint : public QMainWindow {
    Q_OBJECT
public:
    MergingPoint(QWidget* parent = NULL);
    virtual ~MergingPoint();
    //void sour(int a);
    void startBlinking();
    void drawDot(QPainter& painter, const QRect& rect, bool visible, int dotNumber, const QString& label, const QColor& fillColor);
    void drawLine(QPainter& painter, const QPoint& p1, const QPoint& p2, const QColor& color);
    void onTimeout();
    void onTimer();
    void centerOnScreen();
    void sourc();
    QRect dot1Rect;
    QRect dot2Rect;
    QRect dot3Rect;
    QRect dot4Rect;
    QRect dot5Rect;
    QRect dot6Rect;

    bool m_dot1Rect = false;
    bool m_dot2Rect = false;
    bool m_dot3Rect = false;
    bool m_dot4Rect = false;
    bool m_dot5Rect = false;
    bool m_dot6Rect = false;
    //int sourc=0;
    QColor color1, color2;
    trainSim *back;

protected:
    void paintEvent(QPaintEvent*) override;
    //void mousePressEvent(QMouseEvent *event) override;
private slots:
    void graphSlots(int);
};


#endif // GRAPH

