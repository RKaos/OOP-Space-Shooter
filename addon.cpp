#include"addon.h"

addon::addon(std::string png_path)
{
tex.loadFromFile(png_path);
sprite.setTexture(tex);
int x=rand() % 731 + 20;
sprite.setPosition(x,0);
sprite.setScale(1,1);
c=1;
scradd=0;
pt=rand() % 11 + 1;
}

void addon::move(){
    float delta_y = 1;
        delta_y = 1;
    delta_y *= speed;


    sprite.move(0, delta_y);

    if(sprite.getPosition().y>780){
        c=0;
    }
}