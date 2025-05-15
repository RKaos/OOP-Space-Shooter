#include"Bomb.h"

Bomb::Bomb(std::string png_path,int x, int y,float s1,float s2)
{
tex.loadFromFile(png_path);
sprite.setTexture(tex);
sprite.setPosition(x+30,y-7);
sprite.setScale(s1,s2);
}


void Bomb::move(){
    float delta_y = -1;
        delta_y = 1;
    delta_y *= speed;


    sprite.move(0, delta_y);
}



void Bomb::moveL(string &s){
    float delta_x=0,delta_y=0;
if(s=="l")
	delta_x=-1;

delta_x*=speed;
delta_y*=speed;

sprite.move(delta_x, delta_y);

if(sprite.getPosition().x<-30)
s="r";
}

void Bomb::moveR(string &s){
    float delta_x=0,delta_y=0;
if(s=="r")
	delta_x=1;

delta_x*=speed;
delta_y*=speed;

sprite.move(delta_x, delta_y);

if(sprite.getPosition().x>570)
s="l";
}