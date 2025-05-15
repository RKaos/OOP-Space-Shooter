#include"Beta.h"


Beta::Beta(): Invader(10,40,"img/PNG/Enemies/enemyBlue2.png","Beta",20,-7,100){
tex.loadFromFile("img/PNG/Enemies/enemyBlue2.png");
sprite.setTexture(tex);
sprite.setScale(1,1);
}
Beta::Beta(int x, int y) : Invader(10,40,"img/PNG/Enemies/enemyBlue2.png","Beta",20,-7,100,x,y){}