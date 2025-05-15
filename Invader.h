#include <SFML/Graphics.hpp>
#include<string.h>
#include"enemy.h"
using namespace std;
using namespace sf;

#ifndef INVADER_H_
#define INVADER_H_

class Invader : public Enemy{
public:
int bx;
int by;
Invader();
Invader(int bbx, int bby, std::string png_path,string t,int s,int xt1,int xt2,int x, int y);
void fireR();
void fireL();
void fire();
void moveR(string &);
void moveL(string &);
};
#endif