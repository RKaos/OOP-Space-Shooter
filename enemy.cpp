#include"enemy.h"

Enemy::Enemy(){c=1;}

Enemy::Enemy(std::string png_path, int x, int y, string t,int scr,int xt1, int xt2,float s1, float s2)
{
tex.loadFromFile(png_path);
sprite.setTexture(tex);
this->x=x;this->y=y;
sprite.setPosition(x,y);
sprite.setScale(s1,s2);
c=1;
bc=0;
type=t;
xtrx1=xt1;
xtrx2=xt2;
score=scr;
scradd=false;
}

