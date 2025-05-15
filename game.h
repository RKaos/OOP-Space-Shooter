#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
#include"enemy.cpp"
#include"addon.cpp"
#include"Invader.cpp"
#include "Alpha.cpp"
#include"Beta.cpp"
#include"Gamma.cpp"
#include "player.cpp"
#include "Level.h"
#include<fstream>
#include"Monster.cpp"
#include"Dragon.cpp"
#include"PowerUp.cpp"
#include"Fire.cpp"
#include"Life.cpp"
#include"Danger.cpp"
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

#ifndef GAME_H_
#define GAME_H_

class Game
{
public:
Sprite background; //Game background sprite
Texture bg_texture;
Player* p; //player 
// add other game attributes

Game();
void start_game();
};

#endif