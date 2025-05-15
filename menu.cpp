
#include "menu.h"


//add menu attributes here
Menu::Menu(){}

void Menu::display_menu()
{
RenderWindow menu(VideoMode(780, 780), "Menu");
    Sprite back;
    Texture tex;
    tex.loadFromFile("img/black_start.jpg");
    back.setTexture(tex);
    back.setPosition(0,0);
        while (menu.isOpen())
        {
            Event e;
            while (menu.pollEvent(e))
            {
                if (e.type == Event::Closed)
                    menu.close();
                if (Keyboard::isKeyPressed(Keyboard::Num1))
                    start();
                if (Keyboard::isKeyPressed(Keyboard::Num2))
                    instruct();
                if (Keyboard::isKeyPressed(Keyboard::Num3))
                    highscr();
                if (Keyboard::isKeyPressed(Keyboard::Escape))
                    return;
            }
            menu.draw(back);
            menu.display();
        }
}
void Menu::start(){
    Game g; 
    g.start_game();
}

void Menu::instruct(){

    Sprite back;
    Texture tex;
    tex.loadFromFile("img/background_1.png");
    back.setTexture(tex);
    back.setPosition(0,0);

RenderWindow instruc(VideoMode(780, 780), "Instructions");
        while (instruc.isOpen())
        {
            Event e;
            while (instruc.pollEvent(e))
            {
                if (e.type == Event::Closed)
                    instruc.close();
                if (Keyboard::isKeyPressed(Keyboard::B))
                    return; 
            }
            instruc.draw(back);
            instruc.display();
        }
}


void Menu::highscr(){
    Font font;
    font.loadFromFile("img/MADEINFINITY PERSONALUSE-Regular.otf");
    Text text;
    text.setFont(font);
    text.setString("High Scores");
    text.setPosition(250,100);
    text.setScale(2,2);
    
    Sprite back;
    Texture tex;
    tex.loadFromFile("img/black.jpg");
    back.setTexture(tex);
    back.setPosition(0,0);
    
    Sprite gold;
    Texture tex1;
    tex1.loadFromFile("img/gold.png");
    gold.setTexture(tex1);
    gold.setPosition(500,250);
    gold.setScale(0.05,0.05);
    
    Sprite silver;
    Texture tex2;
    tex2.loadFromFile("img/silver.png");
    silver.setTexture(tex2);
    silver.setPosition(500,400);
    silver.setScale(0.05,0.05);

    Sprite bronze;
    Texture tex3;
    tex3.loadFromFile("img/bronze.png");
    bronze.setTexture(tex3);
    bronze.setPosition(500,550);
    bronze.setScale(0.05,0.05);

RenderWindow highsc(VideoMode(780, 780), "High Score");
       
       
                   ifstream file("score.txt");
            string scr1;
            string scr2;
            string scr3;
            int sc1;
            int sc2;
            int sc3;

            file>>scr1;
            file>>sc1;
            file>>scr2;
            file>>sc2;
            file>>scr3;
            file>>sc3;

            
            Text n1;
                n1.setFont(font);
            n1.setString(scr1);
                n1.setPosition(250,250);
                n1.setScale(1.5,1.5);
            Text s1;
                s1.setFont(font);
            s1.setString(to_string(sc1));
                s1.setPosition(250,300);
            Text n2;
                n2.setFont(font);
            n2.setString(scr2);
                n2.setPosition(250,400);
                n2.setScale(1.5,1.5);
            Text s2;
                s2.setFont(font);
            s2.setString(to_string(sc2));
                s2.setPosition(250,450);
            Text n3;
                n3.setFont(font);
            n3.setString(scr3);
                n3.setPosition(250,550);
                n3.setScale(1.5,1.5);
            Text s3;
                s3.setFont(font);
            s3.setString(to_string(sc3));
                s3.setPosition(250,600);

            

       
       
        while (highsc.isOpen())
        {
            Event e;
            while (highsc.pollEvent(e))
            {
                if (e.type == Event::Closed)
                    highsc.close();
                if (Keyboard::isKeyPressed(Keyboard::B))
                    return; 
            }


            highsc.draw(back);
            highsc.draw(text);
            highsc.draw(n1);
            highsc.draw(s1);
            highsc.draw(n2);
            highsc.draw(s2);
            highsc.draw(n3);
            highsc.draw(s3);
            highsc.draw(gold);
            highsc.draw(silver);
            highsc.draw(bronze);
            highsc.display();
        }
}