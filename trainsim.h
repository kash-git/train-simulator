#ifndef TRAINSIM_H
#define TRAINSIM_H

#include <QObject>
#include <QTimer>
#include <string.h>

class trainSim : public QObject
{
    Q_OBJECT
public:
    trainSim();
private:
    int speed=0;
    QTimer *timer;
    bool direction=true;
    float dist[6][2]={{1,0},{2,1},{3,2},{4,3},{5,4},{6,5}};
    std::string stations[6][2]={{"1","Huda City Center"},{"2","Iffco Chowk"},{"3","MG Road"},{"4","Sikandarpur"},{"5","Guru Dronacharya"},{"6","ArjanGarh"}};

    //std::string now;
public:
    //int p_speed=0;
    //int source=0;
    std::string now;
    void acceleration(int prev_speed,int new_speed);
    void deceleration(int prev_speed,int new_speed);
    void movement(int c_dist,int distance);
    int distance(int sr, int dst);
    std::string station(int stat);
    int current_location(int src);
    std::string getCurrentDateTime( std::string s );
    void WriteLogFile( const std::string &text );
    void updateSource(int src);
    int getSource();
    void setSpeed(int s);
    int getSpeed();
    void setDirection(bool d);
    bool getDirection();
    void move();
    void stop();
    void repeat(int initial_speed,int speed,float c_dist,float dist);
    int mainLogic();

signals:
    void valueGeneratedSignal(int);
    void signalForGraph(int);
    void signalDistance(int);
    void signalForStation(std::string);

private slots:
    void generateValues();
    void graphSlot();
    void slotDistance();
    void slotStation();
};
//trainSim ts;

#endif // TRAINSIM_H
