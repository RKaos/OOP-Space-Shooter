#include"Dragon.h"

Dragon::Dragon() : Enemy ("img/dragon.png",140,0,"Dragon",40,0,0,2.2,1.5) {
}
Dragon::Dragon(int x, int y) : Enemy("img/dragon.png",x,y,"Dragon",40,0,0,2.2,1.5){}

void Dragon::fireL()
{
b=new Bomb("img/PNG/Lasers/dragon_fireL.png",sprite.getPosition().x-250,sprite.getPosition().y+270,1,1.25);
bc=1;
}
void Dragon::fire()
{
b=new Bomb("img/PNG/Lasers/dragon_fire.png",sprite.getPosition().x+137,sprite.getPosition().y+310,1,1.25);
bc=1;
}
void Dragon::fireR()
{
b=new Bomb("img/PNG/Lasers/dragon_fireR.png",sprite.getPosition().x+146,sprite.getPosition().y+250,1,1.25);
bc=1;
}

void Dragon::moveL(string &s){}
void Dragon::moveR(string &s){}