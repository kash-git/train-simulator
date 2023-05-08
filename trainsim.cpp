#include "trainsim.h"
#include <iostream>
#include <windows.h>
#include <thread>
#include <time.h>
#include <fstream>
#include "graph.h"
#include <mainwindow.h>
#include <qdebug.h>
trainSim::trainSim()
{
    timer=new QTimer(this);
    timer->start(100);
    connect(timer,SIGNAL(timeout()),this,SLOT(generateValues()));
    connect(timer,SIGNAL(timeout()),this,SLOT(graphSlot()));
    connect(timer,SIGNAL(timeout()),this,SLOT(slotDistance()));
    connect(timer,SIGNAL(timeout()),this,SLOT(slotStation()));
}

using namespace std;
    int p_speed=0;
        int speed;
        bool direction;
        int source;
        int cdist;
        //int source;
        //abc aaa;
        //Train t;
        //dist={{1,0},{2,1},{3,2},{4,3},{5,4},{6,5}};
        //string stations[6][2]={{"1","Huda City Center"},{"2","Iffco Chowk"},{"3","MG Road"},{"4","Sikandarpur"},{"5","Guru Dronacharya"},{"6","ArjanGarh"}};

        //so s;
        //int p_speed=0; //presenet speed
        //string now;
       // MergingPoint m;
//        Train::Train() {
//            speed = 0;
//            direction = true;
//        }
        void trainSim::generateValues(){
            emit valueGeneratedSignal(p_speed);
            //ab++;
        }

        void trainSim::graphSlot()
        {
            emit signalForGraph(source);
        }

        void trainSim::slotDistance()
        {
            emit signalDistance(cdist);
        }

        void trainSim::slotStation()
        {
            emit signalForStation(station(getSource()));
        }
        void trainSim::setSpeed(int s) {
            speed = s;
        }
        int trainSim::getSpeed() {
            return speed;
        }
        void trainSim::setDirection(bool d) {
            direction = d;
        }
        bool trainSim::getDirection() {
            return direction;
        }
        void trainSim::move() {
                if (direction==1&&p_speed!=0) {
                    cout << "Train is moving forward." << endl;
                }/* else {
                    cout << "Train is moving backward." << endl;
                }*/
            //}
        }

        void trainSim::stop() {
            int prev_speed=getSpeed();
            //speed = 0;
            if(p_speed==0||prev_speed<=speed){
                cout<<"Train is already stopped"<<endl;
            }else if(prev_speed>speed){
                deceleration(prev_speed,0);
                cout << "Train has stopped." << endl;
            }
        }
        void trainSim::acceleration(int prev_speed,int new_speed){
            for(int i=prev_speed;i<=new_speed;i++){
                //qDebug()<<i<<" ";
                p_speed=i;
                //emit valueGeneratedSignal(p_speed);
                Sleep(300);
            }
            cout<<endl;
        }
        void trainSim::deceleration(int prev_speed,int new_speed){
            int i=0;
//            if(prev_speed==0||p_speed==0){
//                cout<<"Goodbye!"<<endl;
//                exit(0);
//            }
            for(i=prev_speed-1;i>=new_speed;i--){
                cout<<i<<" ";
                p_speed=i;
               // emit valueGeneratedSignal(p_speed);
                Sleep(250);
            }
            setSpeed(i);
            cout<<endl;
        }
        void trainSim::movement(int c_dist,int distance){
//            int distance=1000;
           // cout<<endl;
            int speed =getSpeed();
            float u_dist;
            float curr=c_dist;

            u_dist=distance*0.85;
            float n_dist=distance*0.99;
            float mspeed=speed * 0.27;
            for(;curr<=u_dist;curr+=mspeed){
                Sleep(1000);
                cdist=curr;
                cout<<curr<<"m ";
            }
            p_speed=speed;
            speed=speed*.15;
            mspeed=speed*0.27;
            //deceleration(p_speed,speed);
            now = getCurrentDateTime("now");
           WriteLogFile(now+": "+"decelerating") ;
            for(;curr<=n_dist;curr+=mspeed){
                Sleep(1000);
                std::thread t1([&] {deceleration(p_speed,p_speed*0.98);});
                std::thread t2([&] {cdist=curr; cout<<curr<<"m ";});
                t1.join();

                t2.join();
                p_speed*=.98;
                //mspeed=p_speed*0.27;
                //cout<<curr<<" ";
            }
                //p_speed=speed;
            std::thread t3([&] {deceleration(p_speed,0);});
            std::thread t4([&] {cdist=curr;});
            t3.join();
            t4.join();
               // deceleration(p_speed,0);
                p_speed=0;
                //c_dist=curr;
                cdist=c_dist+1*1000;
        }

        int trainSim::distance(int sr, int dst){
            sr-=1;
            dst-=1;
            if(sr==dst){
                //cout<<"abc";
                return 0;
}            else if(sr>dst){
                return -1;
            }
            else {
                //cout<<dist[dst][1]-dist[sr][1]<<endl;

                return dist[dst][1]-dist[sr][1];
            }
        }
        string trainSim::station(int stat){
            return stations[stat][1];
        }
        void trainSim::repeat(int initial_speed,int speed,float c_dist,float dist){   //thread execution

//            acceleration(initial_speed,speed);
//            movement(dist);
            //trainSim t;
            now = getCurrentDateTime("now");
            WriteLogFile(now+": "+"Data recieved at thread ") ;
            std::thread t1([&] {acceleration(initial_speed,speed);});
            std::thread t2([&] {movement(c_dist,dist);});
            t1.join();
            now = getCurrentDateTime("now");
             WriteLogFile(now+": "+"accelerating") ;
            t2.join();
        }
        int trainSim::current_location(int src){
            return dist[src-1][1];
        }
        string trainSim::getCurrentDateTime( string s ){
            time_t now = time(0);
            struct tm  tstruct;
            char  buf[80];
            tstruct = *localtime(&now);
            if(s=="now")
                strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
            else if(s=="date")
                strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
            return string(buf);
        }
        void trainSim::WriteLogFile( const std::string &text )
        {
            std::ofstream log_file(
                "log_file.txt", std::ios_base::out | std::ios_base::app );
            log_file << text << endl;
        }
        int trainSim::getSource(){
            return source;
        }
        void trainSim::updateSource(int src){
            source=src;
        }
trainSim myTrain;
        int trainSim::mainLogic(){
           // trainSim* myTrain=new trainSim();
           // qDebug()<<"abc";
            int speed=0, option=1,src=0,dstn=0,train_no=1,dis=0;
            int dtt=0;//distance to travel
           // int cdist=0;//current location
            string start;
            string now;

            // Set speed and direction
            //myTrain.setSpeed(50);
            //setDirection(true);

            cout<<"Start Train(Y/N): \t";
            //cin>>start;
            start='y';
            if(start=="y"||start=="Y"){
                now = myTrain.getCurrentDateTime("now");
              //  qDebug()<<"hii";
                myTrain.WriteLogFile(now+": "+"Train Started") ;
                 myTrain.updateSource(0);
                Sleep(2000);

                //display options for train data
                cout<<"Enter train data"<<endl;
        //        cout<<"\tStation Code \t Station Name \n";
        //        for(int i=0;i<6;i++){
        //            cout<<"\t\t"<<i+1<<"\t"<<myTrain.station(i)<<endl;
        //        }
        //        cout<<"Enter Source station code:"<<endl;
        //        cin>>src;
        //        cout<<"Enter destination station code"<<endl;
        //        cin>>dstn;
                cout<<"Enter Train no.: ";
                //cin>>train_no;
                train_no=1;
                now =myTrain.getCurrentDateTime("now");
                myTrain.WriteLogFile(now+": "+"train data recieved") ;
                if(train_no==1){
                    src=1;
                    dstn=6;
                }else if(train_no==2){
                    src=1;
                    dstn=5;
                }else if(train_no==3){
                    src=2;
                    dstn=6;
                }else{
                    cout<<"Wrong Train no."<<endl;
                    exit(0);
                }
                //cout<<src<<"    "<<dstn<<endl;
                //to calculate distance between source and destination
                dis=myTrain.distance(src,dstn);
                cout<<dis<<endl;
                if(dis==0){
                    cout<<"Source and destination can't be same!"<<endl;
                    exit(0);
                }else if(dis==-1){
                    cout<<"wrong destination chosen"<<endl;
                    exit(0);
                }else{
                    //cout<<"Enter the permitted speed: ";
                    //cin>>speed;
                    speed=100;
                    cout<<"Total distance to be travelled: "<<dis<<" km"<<endl;
                    now = myTrain.getCurrentDateTime("now");
                     myTrain.WriteLogFile(now+": "+"Train speed recieved") ;




                    do {
                        // Display current speed and direction
                        myTrain.setSpeed(speed);
                        cout << "Current Speed: " <<myTrain.getSpeed() << endl;
                        if(src==dstn)
                            exit(0);
                        // Move train
                        //myTrain.move();

                        while(src!=dstn){
                            //so s;
//                            aaa.ab->sourc=src;
                            //s.sourc=src;
                              //cout<<aaa.ab->sourc<<endl;
                            myTrain.updateSource(src);
                            //m.sourc(src);
                            //cout<<myTrain.getSource();
                            dtt=myTrain.distance(src,src+1)*1000;
                            cout<<"Train is moving towards: "<<myTrain.station(src)<<endl;
                            now = myTrain.getCurrentDateTime("now");
                            myTrain.WriteLogFile(now+": "+"train started moving towards "+myTrain.station(src)) ;
                            //myTrain.acceleration(0,speed);
                            cdist=myTrain.current_location(src);
                            myTrain.WriteLogFile(now+": "+"Current distance to travel calculated ") ;
                            myTrain.repeat(0,speed,cdist,dtt);
                            myTrain.setSpeed(speed);
                            cout<<"Train has reached to "<<myTrain.station(src)<<endl;
                            now = myTrain.getCurrentDateTime("now");
                             myTrain.WriteLogFile(now+": "+"train has reached to "+myTrain.station(src)) ;
                            Sleep(7000);
                            //myTrain.movement(dtt,speed);
                            src+=1;
                            if(src==dstn){
                                myTrain.updateSource(src);
                                cout<<"Train has reached to it's destination."<<endl;
                                now = getCurrentDateTime("now");
                                 WriteLogFile(now+": "+"train reached to it's final destination") ;
                                return 0;
                            }
//                            // Prompt user for input
//                            cout << "Enter option: " << endl;
//                            cout << "1. Change speed" << endl;
//                            //cout << "2. Change direction" << endl;
//                            cout << "2. Stop train" << endl;
//                            cout << "3. Quit" << endl;
                            //cin >> option;
                            option=1;
                            switch (option) {
                            int prev_speed;
                                case 1:
                                    // Change speed
                                    prev_speed=getSpeed();
                                    cout << "Enter new speed: ";
                                   // cin >> speed;
                                    speed=rand()%15+85;
                                    cout<<speed<<endl;
                                    now = myTrain.getCurrentDateTime("now");
                                     myTrain.WriteLogFile(now+": "+"speed changed ") ;
        //                            if(prev_speed>speed){//deceleration
        //                                myTrain.deceleration(myTrain.p_speed,speed);
        //                            }else{//acceleration
        //                                myTrain.acceleration(myTrain.p_speed,speed);
        //                            }
                                    myTrain.setSpeed(speed);
                                    break;
                                case 2:
                                    // Stop train
                                    stop();
                                    break;
                                case 3:
                                    // Quit program
                                    //prev_speed=myTrain.getSpeed();
                                    if(p_speed==0||prev_speed==0){
                                        cout<<"Goodbye!"<<endl;
                                        exit(0);
                                    }
                                    deceleration(p_speed,0);
                                    cout << "Goodbye!" << endl;
                                    return 0;
                                default:
                                    // Invalid input
                                    cout << "Invalid option." << endl;
                                    break;
                            }
                        }

                    } while (option != 3);

                }
            }else{
                cout<<"Train is off"<<endl;
            }
        }


