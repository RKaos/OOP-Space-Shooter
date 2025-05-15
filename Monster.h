#include <SFML/Graphics.hpp>
#include<string.h>
#include"Invader.h"
using namespace std;
using namespace sf;

#ifndef MONSTER_H_
#define MONSTER_H_

class Monster : public Enemy{
public:
Monster();
Monster(int x, int y);

void fireR();
void fireL();
void fire();

void moveL(string &s);

void moveR(string &s);


};

#endif