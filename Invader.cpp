#include"Invader.h"

Invader::Invader(){}
Invader::Invader(int bbx, int bby, std::string png_path,string t,int s,int xt1,int xt2,int x=0, int y=0) : Enemy(png_path,x,y,t,s,xt1,xt2){bx=bbx;by=bby;}
void Invader::fireR(){}
void Invader::fireL(){}
void Invader::fire()
{
b=new Bomb("img/PNG/Lasers/laserRed08.png",sprite.getPosition().x+bx,sprite.getPosition().y+by);
}
void Invader::moveR(string &){}
void Invader::moveL(string &){}
