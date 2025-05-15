#include <SFML/Graphics.hpp>
#include<string.h>
using namespace std;
using namespace sf;

#ifndef BULLET_H_
#define BULLET_H_

class Bullet{
public:
bool c;
Texture tex;
Sprite sprite;
float speed=2;
int x,y;
Bullet(std::string png_path,int x, int y)
{
tex.loadFromFile(png_path);
sprite.setTexture(tex);
sprite.setPosition(x+30,y-7);
sprite.setScale(0.5,0.5);
c=1;
}


void move(int &i, int &r, int &q){
    float delta_x = 0, delta_y = -1;


    if(r){
        delta_y = -1;
        delta_x = -1;
        speed=1.75;
    delta_x *= speed;
    delta_y *= speed;
    }

    if(q){
        delta_y = -1;
        delta_x = 1;
        speed=1.75;
    delta_x *= speed;
    delta_y *= speed;
    }
    else{
        delta_y = -1;
        // speed=1.5;
    delta_x *= speed;
    delta_y *= speed;
    }

    sprite.move(delta_x, delta_y);

    if(sprite.getPosition().y<0 || sprite.getPosition().x<0 || sprite.getPosition().x>780){
     i=0;
    r=0;
    q=0;
    }
}

 

};
#endif