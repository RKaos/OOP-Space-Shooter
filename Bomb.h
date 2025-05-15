#include <SFML/Graphics.hpp>
#include<string.h>
using namespace std;
using namespace sf;

#ifndef BOMB_H_
#define BOMB_H_

class Bomb{
public:
bool c;
Texture tex;
Sprite sprite;
float speed=0.5;
int x,y;
Bomb(std::string png_path,int x, int y,float s1=0.5,float s2=0.5)
{
tex.loadFromFile(png_path);
sprite.setTexture(tex);
sprite.setPosition(x+30,y-7);
sprite.setScale(s1,s2);
}


void move(){
    float delta_y = -1;
        delta_y = 1;
    delta_y *= speed;


    sprite.move(0, delta_y);
}



void moveL(string &s){
    float delta_x=0,delta_y=0;
if(s=="l")
	delta_x=-1;

delta_x*=speed;
delta_y*=speed;

sprite.move(delta_x, delta_y);

if(sprite.getPosition().x<-30)
s="r";
}

void moveR(string &s){
    float delta_x=0,delta_y=0;
if(s=="r")
	delta_x=1;

delta_x*=speed;
delta_y*=speed;

sprite.move(delta_x, delta_y);

if(sprite.getPosition().x>570)
s="l";
}



};

#endif
