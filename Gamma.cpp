#include"Gamma.h"

Gamma::Gamma(): Invader(10,40,"img/PNG/Enemies/enemyBlue3.png","Gamma",30,-7,100){
tex.loadFromFile("img/PNG/Enemies/enemyBlue3.png");
sprite.setTexture(tex);
sprite.setScale(1,1);
}
Gamma::Gamma(int x, int y) : Invader(10,40,"img/PNG/Enemies/enemyBlue3.png","Gamma",30,-7,100,x,y){}