#include"Alpha.h"

Alpha::Alpha() : Invader (5,40,"img/PNG/Enemies/enemyBlue1.png","Alpha",10,-7,90) {
tex.loadFromFile("img/PNG/Enemies/enemyBlue1.png");
sprite.setTexture(tex);
sprite.setScale(1,1);
}

Alpha::Alpha(int x, int y) : Invader(5,40,"img/PNG/Enemies/enemyBlue1.png","Alpha",10,-7,90,x,y){}