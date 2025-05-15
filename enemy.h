#include <SFML/Graphics.hpp>
#include<string.h>
#include"bomb.h"
using namespace std;
using namespace sf;

#ifndef ENEMY_H_
#define ENEMY_H_

class Enemy{
public:
int xtrx1;
int xtrx2;
string type;
int c;
int bc;
Texture tex;
Sprite sprite;
float speed=0.5;
int x,y;
int score;
int scradd;

Bomb *b;

Enemy();
Enemy(std::string png_path, int x, int y, string t,int scr,int xt1=0, int xt2=0,float s1=1, float s2=1);
virtual void fireL()=0;
virtual void fire()=0;
virtual void fireR()=0;
virtual void moveR(string &)=0;
virtual void moveL(string &)=0;
};
#endif