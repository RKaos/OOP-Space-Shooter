#include <SFML/Graphics.hpp>
#include<string.h>
#include"Enemy.h"
using namespace std;
using namespace sf;

#ifndef DRAGON_H_
#define DRAGON_H_

class Dragon : public Enemy{
public:
Dragon();
Dragon(int x, int y);

void fireL();
void fire();
void fireR();

void moveL(string &s);
void moveR(string &s);

};

#endif