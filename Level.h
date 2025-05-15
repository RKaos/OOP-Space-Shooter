#include<iostream>
#include"enemy.h"
#include"Alpha.h"
#include"Beta.h"
#include"Gamma.h"
using namespace std;

class Level
{
public:
    Level(){}

    void lvl_1(Enemy ** enem){     //triangle
    enem[0] = new Alpha(75,100);
    enem[1] = new Alpha(250,100);
    enem[2] = new Alpha(425,100);
    enem[3] = new Alpha(600,100);
    enem[4] = new Beta(163,200);
    enem[5] = new Beta(338,200);
    enem[6] = new Beta(513,200);
    enem[7] = new Gamma(250,300);
    enem[8] = new Gamma(425,300);
    enem[9] = new Gamma(338,400);
    }


    void lvl_2(Enemy ** enem){   //rectangle

    for(int i=0;i<10;++i){
        delete enem[i];
        enem[i]=nullptr;
    }

    enem[0] = new Alpha(425,100);
    enem[1] = new Alpha(600,100);
    enem[2] = new Alpha(600,200);
    enem[3] = new Alpha(250,100);
    enem[4] = new Beta(75,100);
    enem[5] = new Beta(600,300);
    enem[6] = new Beta(75,200);
    enem[7] = new Gamma(75,300);
    enem[8] = new Gamma(250,300);
    enem[9] = new Gamma(425,300);
    }
    
    void lvl_3(Enemy ** enem){   //cross

    for(int i=0;i<10;++i){
        delete enem[i];
        enem[i]=nullptr;
    }

    enem[0] = new Alpha(75,50);
    enem[1] = new Alpha(200,150);
    enem[2] = new Alpha(475,150);
    enem[3] = new Alpha(600,50);
    enem[4] = new Beta(285,220);
    enem[5] = new Beta(600,350);
    enem[6] = new Beta(75,350);
    enem[7] = new Gamma(200,280);
    enem[8] = new Gamma(475,280);
    enem[9] = new Gamma(395,220);
    }

    void lvl_4(Enemy ** enem, Enemy ** mon){ //diamond

    for(int i=0;i<10;++i){
        delete enem[i];
        enem[i]=nullptr;
    }

    delete mon[0];
    // mon[0]=nullptr;

    enem[0] = new Alpha(355,30);  //1
    enem[1] = new Alpha(430,110);
    enem[2] = new Alpha(100,270);
    enem[3] = new Alpha(620,270);
    enem[4] = new Beta(165,190); //4
    enem[5] = new Beta(525,190); //5
    enem[6] = new Beta(260,110); //2
    enem[7] = new Gamma(380,450); //3
    enem[8] = new Gamma(490,350);
    enem[9] = new Gamma(240,350);
    }

    void lvl_5(Enemy ** enem){    //circle

    for(int i=0;i<10;++i){
        delete enem[i];
        enem[i]=nullptr;
    }

    enem[0] = new Alpha(400,50);  //1
    enem[1] = new Alpha(100,270);
    enem[2] = new Alpha(620,270);
    enem[3] = new Alpha(140,150);
    enem[4] = new Beta(550,100); //4
    enem[5] = new Beta(250,100); //5
    enem[6] = new Beta(150,400); //2
    enem[7] = new Gamma(550,400); //3
    enem[8] = new Gamma(250,450);
    enem[9] = new Gamma(380,480);
    }

    void lvl_6(Enemy ** enem, Enemy * drag){  //heart

    for(int i=0;i<10;++i){
        delete enem[i];
        enem[i]=nullptr;
    }

    delete drag;
    drag=nullptr;

    enem[0] = new Alpha(100,220);  //1
    enem[1] = new Alpha(140,50);
    enem[2] = new Alpha(240,150);
    enem[3] = new Alpha(490,150);
    enem[4] = new Beta(370,450); //4
    enem[5] = new Beta(630,220); //5
    enem[6] = new Beta(600,50); //2
    enem[7] = new Gamma(550,350); //3
    enem[8] = new Gamma(170,350);
    enem[9] = new Gamma(370,240);
    }

    void lvl_7(Enemy ** enem, Enemy ** enem2){    //rectangle (filled)

    for(int i=0;i<10;++i){
        delete enem[i];
        enem[i]=nullptr;
    }

    enem2[0] = new Alpha(425,100);
    enem2[1] = new Alpha(600,100);
    enem2[2] = new Alpha(600,200);
    enem2[3] = new Beta(250,100);
    enem2[4] = new Beta(75,100);
    enem2[5] = new Beta(600,300);
    enem2[6] = new Beta(75,200);
    enem2[7] = new Beta(75,300);
    enem2[8] = new Gamma(250,300);
    enem2[9] = new Gamma(425,300);
    enem2[10] = new Gamma(425,200);
    enem2[11] = new Gamma(250,200);
    }

    void lvl_8(Enemy ** enem2){      //diamond (filled)

    for(int i=0;i<12;++i){
        delete enem2[i];
        enem2[i]=nullptr;
    }

    enem2[0] = new Alpha(355,30);
    enem2[1] = new Alpha(430,110);
    enem2[2] = new Alpha(100,270);
    enem2[3] = new Beta(620,270);
    enem2[4] = new Beta(165,190);
    enem2[5] = new Beta(525,190);
    enem2[6] = new Beta(260,110);
    enem2[7] = new Beta(380,450);
    enem2[8] = new Gamma(490,350);
    enem2[9] = new Gamma(240,350);
    enem2[10] = new Gamma(400,250);
    enem2[11] = new Gamma(275,250);
    }


    void lvl_9(Enemy ** enem2){   //circle (filled)

    for(int i=0;i<12;++i){
        delete enem2[i];
        enem2[i]=nullptr;
    }

    enem2[0] = new Alpha(400,50);
    enem2[1] = new Alpha(100,270);
    enem2[2] = new Alpha(620,270);
    enem2[3] = new Beta(140,150);
    enem2[4] = new Beta(550,100);
    enem2[5] = new Beta(250,100);
    enem2[6] = new Beta(150,400);
    enem2[7] = new Beta(550,400);
    enem2[8] = new Gamma(250,450);
    enem2[9] = new Gamma(380,480);
    enem2[10] = new Gamma(400,250);
    enem2[11] = new Gamma(275,250);
    }

};


