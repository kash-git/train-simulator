#ifndef TRAIN
#define TRAIN

#include <string>
#include <thread>
#include <QThread>

class Train:public QThread {
    Q_OBJECT
    private:
        int speed=0;
        bool direction=true;
        float dist[6][2];
        std::string stations[6][2];

        //std::string now;
public:
        int p_speed;
        int source=0;
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

};

#endif /* TRAIN_H */
