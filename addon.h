#include <SFML/Graphics.hpp>
#include<string.h>
using namespace std;
using namespace sf;

#ifndef ADDON_H_
#define ADDON_H_

class addon{
public:
bool c;
Texture tex;
Sprite sprite;
float speed=0.5;
int x,y;
    int pt;
    int scradd;


addon(std::string png_path);
void move();


};

#endif