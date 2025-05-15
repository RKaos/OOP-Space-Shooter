#include"Monster.h"


Monster::Monster() : Enemy ("img/monster2.png",200,0,"Monster",40,0,0,1,1) {}
Monster::Monster(int x, int y) : Enemy("img/monster2.png",x,y,"Monster",40,0,0,1,1){}

void Monster::fireR(){}
void Monster::fireL(){}
void Monster::fire()
{
b=new Bomb("img/PNG/Lasers/m_laser.png",sprite.getPosition().x+90,sprite.getPosition().y+240);
bc=1;
}

void Monster::moveL(string &s){
    float delta_x=0,delta_y=0;
if(s=="l")
	delta_x=-1;

delta_x*=speed;
delta_y*=speed;

sprite.move(delta_x, delta_y);

if(sprite.getPosition().x<-150)
s="r";
}

void Monster::moveR(string &s){
    float delta_x=0,delta_y=0;
if(s=="r")
	delta_x=1;

delta_x*=speed;
delta_y*=speed;

sprite.move(delta_x, delta_y);

if(sprite.getPosition().x>450)
s="l";
}