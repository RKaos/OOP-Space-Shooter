#include"game.h"

Game::Game(){
p=new Player("img/PNG/playerShip2_blue.png");
bg_texture.loadFromFile("img/background.jpg");
background.setTexture(bg_texture);
background.setScale(2, 1.5);
}

void Game::start_game(){
    srand(time(0));
    RenderWindow window(VideoMode(780, 780), title);
    Window menu;
    Clock clock;
    Level level;
    float timer=0;
    float temp_timer=0;  
    float temp_timer2=0;    float temp_timer18=0;
    float temp_timer3=0;    float temp_timer19=0;
    float temp_timer4=0;    float temp_timer20=0;
    float temp_timer5=0;    float temp_timer21=0;
    float temp_timer6=0;    float temp_timer22=0;
    float temp_timer7=0;    float temp_timer23=0;
    float temp_timer8=0;    float temp_timer24=0;
    float temp_timer9=0;    float temp_timer25=0;
    float temp_timer10=0;   float temp_timer26=0;
    float temp_timer11=0;   float temp_timer27=0;
    float temp_timer12=0;   float temp_timer28=0;
    float temp_timer13=0;   float temp_timer29=0;
    float temp_timer14=0;   float temp_timer30=0;
    float temp_timer15=0;   float temp_timer31=0;
    float temp_timer16=0;   float temp_timer32=0;
    float temp_timer17=0;   float temp_timer33=0;
         
    Font font;
    font.loadFromFile("img/MADEINFINITY PERSONALUSE-Regular.otf");
    Text text;
    text.setFont(font);
    text.setString("Score:");
    text.setPosition(10,10);
    text.setScale(1.5,1.5);
    Text scr_text;
    scr_text.setFont(font);
    scr_text.setPosition(140,25);
    Text lif_text;
    lif_text.setFont(font);
    lif_text.setString("Lives:");
    lif_text.setPosition(20,720);
    Text lvl_text;
    lvl_text.setFont(font);
    lvl_text.setString("Level:");
    lvl_text.setPosition(575,20);
    lvl_text.setScale(1.5,1.5);
    Text lvl_text2;
    lvl_text2.setFont(font);
    lvl_text2.setPosition(700,20);
    lvl_text2.setScale(1.5,1.5);

    addon *Addon[4];
    float ptimer[4];
    Addon[0] = new pwr;
    Addon[1] = new fir;
    Addon[2] = new life;
    Addon[3] = new danger;
    for(int i=0;i<4;++i)
    Addon[i]->c=0;
    Enemy *enem[10];
    Enemy *enem2[12];
    int esize;
    Enemy *mon[2];
    Enemy *drag;
    drag = new Dragon;
    drag->c=0;
    Enemy *drag2;
    drag2 = new Dragon;
    drag2->c=0;

    mon[0]= new Monster;
    mon[1]= new Monster;
    mon[0]->c=0;
    mon[1]->c=0;
    string s = "r";
    string sb = "r";


    int dhitL=0;
    int dhit=0;
    int dhitR=0;
    int dfire=0;
    int dfire2=0;
    int dcheck=false;
    int dcheck2=false;
    int dragdest=false;
    int dragdest2=false;
    int mcheck=false;
    int mcheck2=false;
    bool moncheck=false;
    bool moncheck2=false;
    int mondest=false;
    int mondest2=false;
    int pwri=0;
    int r=0,q=0;
    int i=0;
    int lvl=1;

    while (window.isOpen())
    {
        {
        float time = clock.getElapsedTime().asSeconds(); 
        clock.restart();
        timer += time;  
        for(int i=0;i<4;++i)
        ptimer[i]+=time;
 	Event e;
        while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close(); //close the game                        	    
        }
          
	if (Keyboard::isKeyPressed(Keyboard::Left) && p->shipc) //If left key is pressed
            p->move("l");    // Player will move to left
	if (Keyboard::isKeyPressed(Keyboard::Right) && p->shipc) // If right key is pressed
            p->move("r");  //player will move to right
	if (Keyboard::isKeyPressed(Keyboard::Up) && p->shipc) //If up key is pressed
            p->move("u");    //playet will move upwards
	if (Keyboard::isKeyPressed(Keyboard::Down) && p->shipc) // If down key is pressed
            p->move("d");  //player will move downwards
                else if (e.key.code == Keyboard::P)      //pressing P key to pause game and display a window
                {
                  RenderWindow menu(VideoMode(780, 780), "Pause");
                   
                   while (menu.isOpen())
                   {
                          Sprite back;
                          Texture tex;
                          tex.loadFromFile("img/black_pause.jpg");
                          back.setTexture(tex);
                          back.setPosition(0,0);

                      Event m;
                      while (menu.pollEvent(m))
                      {
                         if (m.type == Event::Closed)                  
                         menu.close();                           
                          if (m.type == Event::KeyPressed) {           
                         if (m.key.code == Keyboard::R)       
                     {  menu.close();
                      } 
                    else if (m.key.code == Keyboard::U)      //shortcut for closing both the pause window and game window
                   {
                    menu.close();
                    window.close();    
                   } 
                      }
                   }
                   menu.draw(back);
                   menu.display();
                }
                
            }
    if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right) && p->shipc)
        {   
            p->tex.loadFromFile("img/PNG/playerShip2_blue_r1.png");    //tilt right png load
            p->sprite.setTexture(p->tex);
        }
	else if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left) && p->shipc)
        {   
            p->tex.loadFromFile("img/PNG/playerShip2_blue_l1.png");    //tilt left png load
            p->sprite.setTexture(p->tex);
        }
    else{
            p->tex.loadFromFile("img/PNG/playerShip2_blue.png");       //normal png load
            p->sprite.setTexture(p->tex);           
    }    
	if (Keyboard::isKeyPressed(Keyboard::Space) && p->shipc){ // If Space key is pressed
        if(!i){
            if(p->pwrc && !pwri)
            p->pwr_fire(i,pwri);  //player will shoot with power up add if he has one
            else
            p->fire(i);  //player will shoot
        }
            if(i){
        if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left) && p->shipc)
        r=1;
        else if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right) && p->shipc)
        q=1;
    }
    }
            
	////////////////////////////////////////////////
	/////  Call your functions here            ////

//////////////////wrap around///////////////////////////////////
    p->check_boundary();

        if(p->pwrc)
        temp_timer8+=time;
    if(temp_timer8>5){
        p->pwrc=0;
        temp_timer8=0;
    }
//////////////////////////////////////////////////////////////////////////

//////////////////spaceship bullet movement///////////////////////////////////
    if(i && pwri)
        p->pwr_move(i,pwri);
    else if(i){
        if (r)
            p->b->move(i,r,q);
        else if (q)
            p->b->move(i,r,q);
        else
            p->b->move(i,r,q);
    }
//////////////////////////////////////////////////////////////////////////

//////////////////dropping add ons///////////////////////////////////
for(int i=0;i<4;++i){
    if(ptimer[i]>Addon[i]->pt && !Addon[i]->c){
        if(i==0){
            Addon[i]= new pwr;
        }
        if(i==1){
            Addon[i]= new fir;
        }
        if(i==2){
            Addon[i]= new life;
        }
        if(i==3){
            Addon[i]= new danger;
        }
    ptimer[i]=0;
    Addon[i]->pt=rand()%15+1;
    }
}
if(Addon[3]->sprite.getPosition().y>=780 && !Addon[3]->scradd){
p->score+=5;
Addon[3]->scradd=1;
}
for(int i=0;i<4;++i)
    if(Addon[i]->c)
        Addon[i]->move();

if(p->shipc)
p->addon_check(Addon);
//////////////////////////////////////////////////////////////////////////

//////////////////ship destroyed delay///////////////////////////////////
    if(!p->shipc){
                temp_timer4 += time;  
        if(temp_timer4>1){
            temp_timer4=0;
            p->lives--;
            if(dhitL || dhit){
            p->sprite.setPosition(p->sprite.getPosition().x-70,p->sprite.getPosition().y);
            dhit=0;dhitL=0;
            }
            if(dhitR){
            p->sprite.setPosition(p->sprite.getPosition().x+70,p->sprite.getPosition().y);
            dhitR=0;
            }
            p->shipc=1;
        }
    }
//////////////////////////////////////////////////////////////////////////

    if(dcheck && dfire==1){
        p->drag_hitL(drag);
        dhitL=1;
    }
    if(dcheck && dfire==2){
        p->drag_hit(drag);
        dhit=1;
    }
    if(dcheck && dfire==3){
        p->drag_hitR(drag);
        dhitR=1;
    }
    if(dcheck2 && dfire2==1){
        p->drag_hitL(drag2);
        dhitL=1;
    }
    if(dcheck2 && dfire2==2){
        p->drag_hit(drag2);
        dhit=1;
    }
    if(dcheck2 && dfire2==3){
        p->drag_hitR(drag2);
        dhitR=1;
    }

    if(mcheck || mcheck2)
        p->mon_hit(mon);

/////////////////////////////////////////////////////////////////////
///////////////////////////// Level 1 and level 2 ////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
if(lvl==1 || lvl==2 || lvl==3 || lvl==4 || lvl==5 || lvl==6){
    if(timer<0.1 && lvl==1){
    level.lvl_1(enem);
    }
    if(lvl==2){
    temp_timer6+=time;
    if(temp_timer6<0.01){
        level.lvl_2(enem);
    }
    }
    if(lvl==3){
    temp_timer12+=time;
    if(temp_timer12<0.01){
        level.lvl_3(enem);
    }
    }
    if(lvl==4){
temp_timer22+=time;
if(temp_timer22<10){
    temp_timer9+=time;
    if(temp_timer9<0.1)
    mon[0] = new Monster(200,0);
    mcheck=1;
    if(mon[0]->c){
    if(s=="r")
    mon[0]->moveR(s);
    if(s=="l")
    mon[0]->moveL(s);
    }
        if(temp_timer9>0.1)
    if(mon[0]->c){
    temp_timer10+=time;
    if(temp_timer10>2)
    if(mon[0]->c){
        sb=s;
        mon[0]->fire();
        mon[0]->bc=1;
        temp_timer10=0;
    }
}
    
    if(temp_timer9>0.1)
    if(mon[0]->bc || moncheck){
    temp_timer11+=time;
            if(temp_timer11>2 && temp_timer11<4.5){
        mon[0]->bc=0;
        if(temp_timer11>4)
    temp_timer11=0;
    moncheck=1;
        }
    }
    if(mon[0]->bc){
    if(sb=="r")
    mon[0]->b->moveR(sb);
    if(sb=="l")
    mon[0]->b->moveL(sb);
    }
}
else{
    mondest=1;
    mcheck=0;
}
}
    if(lvl==4 && mondest){
    temp_timer13+=time;
    if(temp_timer13<0.01){
        p->score+=40;
        level.lvl_4(enem,mon);
    }
    }
    if(lvl==5){
    temp_timer14+=time;
    if(temp_timer14<0.01){
        level.lvl_5(enem);
    }
    }
if(lvl==6){
    temp_timer28+=time;
    if(temp_timer28<5){
    temp_timer33+=time;
    if(temp_timer33<0.1)
    drag = new Dragon;
    dcheck=1;
    if(drag->c){
        temp_timer27+=time;
        if(temp_timer27>0.75){
            if(p->sprite.getPosition().x<260){
            drag->fireL();
            dfire=1;
            }

            if(p->sprite.getPosition().x>260 && p->sprite.getPosition().x<470){
            drag->fire();
            dfire=2;
            }

            if(p->sprite.getPosition().x>470){
            drag->fireR();
            dfire=3;
            }

            temp_timer27=0;
        }
    }
}
else{
    dragdest=1;
    dcheck=0;
}
}
    if(lvl==6 && dragdest){
    temp_timer15+=time;
    if(temp_timer15<0.01){
        p->score+=50;
        level.lvl_6(enem,drag);
    }
    }
/////////////////////////////////////alpha bomb////////////////////////////////
            temp_timer += time;
            if(temp_timer>5){
    for(int i=0;i<4;++i)
        if(enem[i]->c){
        enem[i]->fire();
        enem[i]->bc=1;
        temp_timer=0;
            }
    }
    for(int i=0;i<4;++i)
        if(enem[i]->bc){
        enem[i]->b->move();
        }
///////////////////////////////////////beta bomb//////////////////////////////
            temp_timer2 += time;
            if(temp_timer2>3){
    for(int i=4;i<7;++i)
        if(enem[i]->c){
        enem[i]->fire();
        enem[i]->bc=1;
        temp_timer2=0;
            }
    }
    for(int i=4;i<7;++i)
        if(enem[i]->bc)
        enem[i]->b->move();
////////////////////////////////////////gamma bomb///////////////////////////////
            temp_timer3 += time;
            if(temp_timer3>2){
    for(int i=7;i<10;++i)
        if(enem[i]->c){
        enem[i]->fire();
        enem[i]->bc=1;
        temp_timer3=0;
            }
    }
    for(int i=7;i<10;++i)
        if(enem[i]->bc)
        enem[i]->b->move();
///////////////////////////////////////////////////////////////////////////

/////////////////////checking spaceship fire with enemy/////////////////
if(pwri)
p->pwr_hit(i,enem,10);
///////////////////////////////////////////////////////////////////

/////////////////////checking spaceship fire with enemy/////////////////
else
p->hit(i,enem,10);
///////////////////////////////////////////////////////////////////

/////////////////////checking enemy bomb with spaceship/////////////////
p->ehit(enem,10);
///////////////////////////////////////////////////////////////////

/////////////////////checking enemy and spaceship collision/////////////////
p->col(enem,10);
///////////////////////////////////////////////////////////////////

/////////////////////////////Adding scores//////////////////////////////
	for(int i=0;i<10;++i)
		if(!enem[i]->c && !enem[i]->scradd){
            int temp_lvl=0;
            if(lvl>=1 && lvl<=3)
            temp_lvl=1;
            if(lvl>=4 && lvl<=6)
            temp_lvl=2;
        p->score+=enem[i]->score*(temp_lvl);
        enem[i]->scradd=1;
        }
///////////////////////////////////////////////////////////////////////
    
/////////////////////////////////level complete check//////////////////////////////////
if(!dcheck || dragdest)
if(!mcheck || mondest){
if(p->lvl_check(enem,10)){
    temp_timer5+=time;
    if(temp_timer5>2){
        lvl++;
        temp_timer5=0;
    }
}
}

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////LEVEL 3///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////


if(lvl==7 || lvl==8 || lvl==9 || lvl==10){
    if(lvl==7){
    temp_timer16+=time;
    if(temp_timer16<0.01){
        level.lvl_7(enem,enem2);
    }
    }
    if(lvl==8){
    temp_timer21+=time;
    if(temp_timer21<0.01){
        level.lvl_8(enem2);
    }
    }
/////////////////////////////////////Dragon///////////////////////////////////////////
if(lvl==9){
    temp_timer29+=time;
    if(temp_timer29<5){
    temp_timer30+=time;
    if(temp_timer30<0.1)
    drag2 = new Dragon;
    dcheck2=1;
    if(drag2->c){
        temp_timer31+=time;
        if(temp_timer31>0.75){
            if(p->sprite.getPosition().x<260){
            drag2->fireL();
            dfire2=1;
            }

            if(p->sprite.getPosition().x>260 && p->sprite.getPosition().x<470){
            drag2->fire();
            dfire2=2;
            }

            if(p->sprite.getPosition().x>470){
            drag2->fireR();
            dfire2=3;
            }
            temp_timer31=0;
        }
    }
}
else{
    dragdest2=1;
    dcheck2=0;
}
}
//////////////////////////////////////////////////////////////////////
    if(lvl==9  && dragdest2){
    temp_timer32+=time;
    if(temp_timer32<0.01){
        p->score+=50;
        level.lvl_9(enem2);
    }
    }
///////////////////////////////////////Monster////////////////////////////////
    if(lvl==10){
temp_timer23+=time;
if(temp_timer23<10){
    temp_timer24+=time;
    if(temp_timer24<0.1)
    mon[0] = new Monster(200,0);
    mcheck2=1;
    if(mon[0]->c){
    if(s=="r")
    mon[0]->moveR(s);
    if(s=="l")
    mon[0]->moveL(s);
    }
        if(temp_timer24>0.1)
    if(mon[0]->c){
    temp_timer25+=time;
    if(temp_timer25>2)
    if(mon[0]->c){
        sb=s;
        mon[0]->fire();
        mon[0]->bc=1;
        temp_timer25=0;
    }
}
    
    if(temp_timer24>0.1)
    if(mon[0]->bc || moncheck2){
    temp_timer26+=time;
            if(temp_timer26>2 && temp_timer26<4.5){
        mon[0]->bc=0;
        if(temp_timer26>4)
    temp_timer26=0;
    moncheck2=1;
        }
    }
    if(mon[0]->bc){
    if(sb=="r")
    mon[0]->b->moveR(sb);
    if(sb=="l")
    mon[0]->b->moveL(sb);
    }
}
else{
    mondest2=1;
    mcheck2=0;
}
}
if(mondest2 && !mon[0]->scradd){
    p->score+=40;
    mon[0]->scradd=1;
}
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////alpha bomb////////////////////////////////
            temp_timer18 += time;
            if(temp_timer18>5){
    for(int i=0;i<3;++i)
        if(enem2[i]->c){
        enem2[i]->fire();
        enem2[i]->bc=1;
        temp_timer18=0;
            }
    }
    for(int i=0;i<3;++i)
        if(enem2[i]->bc){
        enem2[i]->b->move();
        }
///////////////////////////////////////beta bomb//////////////////////////////
            temp_timer19 += time;
            if(temp_timer19>3){
    for(int i=3;i<8;++i)
        if(enem2[i]->c){
        enem2[i]->fire();
        enem2[i]->bc=1;
        temp_timer19=0;
            }
    }
    for(int i=3;i<8;++i)
        if(enem2[i]->bc)
        enem2[i]->b->move();
////////////////////////////////////////gamma bomb///////////////////////////////
            temp_timer20 += time;
            if(temp_timer20>2){
    for(int i=8;i<12;++i)
        if(enem2[i]->c){
        enem2[i]->fire();
        enem2[i]->bc=1;
        temp_timer20=0;
            }
    }
    for(int i=8;i<12;++i)
        if(enem2[i]->bc)
        enem2[i]->b->move();
///////////////////////////////////////////////////////////////////////////

/////////////////////checking spaceship fire with enemy/////////////////
if(pwri)
p->pwr_hit(i,enem2,12);
///////////////////////////////////////////////////////////////////

/////////////////////checking spaceship fire with enemy/////////////////
else
p->hit(i,enem2,12);
///////////////////////////////////////////////////////////////////

/////////////////////checking enemy bomb with spaceship/////////////////
p->ehit(enem2,12);
///////////////////////////////////////////////////////////////////

/////////////////////checking enemy and spaceship collision/////////////////
p->col(enem2,12);
///////////////////////////////////////////////////////////////////

//////////////////////////////Adding scores/////////////////////////////////////////////
	for(int i=0;i<12;++i)
		if(!enem2[i]->c && !enem2[i]->scradd){
        p->score+=enem2[i]->score*(3);
        enem2[i]->scradd=1;
        }
///////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////level complete check//////////////////////////////////
if(!dcheck2 || dragdest2)
if(!mcheck2 || mondest2)
if(p->lvl_check(enem2,12)){
    temp_timer17+=time;
    if(temp_timer17>2){
        lvl++;
        temp_timer17=0;
    }
}
///////////////////////////////////////////////////////////////////////////////////////

}



/////////////////////////////////file handling//////////////////////////////////
if (p->lives == 0 || lvl == 11) {
    bool srcheck=false;
    int scr = p->score;
    string pname;
    cout<<"Enter Player name: ";
    cin>>pname;
    string nam = pname;
    ifstream score("score.txt");
    ofstream temptxt("temp.txt");
    int count = 0;
    string line;
    int scr2;
    if (score.is_open() && temptxt.is_open()) {
        // Count the number of score entries
        while (getline(score, line)) {
            count++;
        }
        count /= 2;
score.close();
ifstream score("score.txt");
        // Read each score entry and write it to the output file
        for (int i = 0; i < count; ++i) {
            score>>line;   //Reading name;
            score >> scr2; // Reading score

            if (scr2 < scr && !srcheck) {
                temptxt << nam << endl << scr << endl;
                srcheck=true;
            }
            temptxt << line << endl << scr2 << endl;
        }
        if(!srcheck)
                            temptxt << nam << endl << scr << endl;

        // Close the input and output files
        score.close();
        temptxt.close();

        // Replace the old score file with the new one
        remove("score.txt");
        rename("temp.txt", "score.txt");
    }
    else {
        cout << "Error opening score file." << endl;
    }
    return;
}
///////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

	window.clear(Color::Black); //clears the screen
	window.draw(background);  // setting background


////////////////////////////fire add on time/////////////////////////////////////////
    if(p->firc)
        temp_timer7+=time;
    if(temp_timer7>5){
        p->firc=0;
        temp_timer7=0;
    }
    if(i && p->firc){
            p->b->tex.loadFromFile("img/PNG/Lasers/fire_laser.png");
		    p->b->sprite.setTexture(p->b->tex);
            window.draw(p->b->sprite);
    }
/////////////////////////////////////////////////////////////////////
////////////////////////////power up add on display/////////////////////////////////////////
    else if(i && pwri){
    for(int i=0;i<7;++i)
    if(p->pwrb[i]->c)
    window.draw(p->pwrb[i]->sprite);
    }
    if(p->pwrc){
    p->shield.setPosition(p->sprite.getPosition().x-8,p->sprite.getPosition().y-20);
    window.draw(p->shield);
    }
//////////////////////////////////////////////////////////////////////////////////
    else if(i)
    window.draw(p->b->sprite);  // bullet display
    if(p->shipc)  
	window.draw(p->sprite);   // setting player on screen
       
        for(int i=0;i<4;++i){
            if(Addon[i]->c){
            window.draw(Addon[i]->sprite);  // setting add-ons on screen
            }
        }

///////////////////////////Dragon display//////////////////////////////////////////
if(dcheck){
if(drag->bc)
window.draw(drag->b->sprite);
if(drag->c)
window.draw(drag->sprite);
}
if(dcheck2){
if(drag2->bc)
window.draw(drag2->b->sprite);
if(drag2->c)
window.draw(drag2->sprite);
}
///////////////////////////////////////////////////////////////////////////


///////////////////////////Monster display//////////////////////////////////////////
if(mcheck){
if(mon[0]->c)
window.draw(mon[0]->sprite);
    if(mon[0]->bc){
    window.draw(mon[0]->b->sprite);  //setting enemy bombs on screen
    }
}
if(mcheck2){
if(mon[0]->c)
window.draw(mon[0]->sprite);
        if(mon[0]->bc){
        window.draw(mon[0]->b->sprite);  //setting enemy bombs on screen
        }
}
/////////////////////////////////////////////////////////////////////

///////////////////////////Enemies display//////////////////////////////////////////
if(lvl==1 || lvl==2 || lvl==3 || lvl==4 || lvl==5 || lvl==6){
    for(int i=0;i<10;++i)
        if(enem[i]->bc)
        window.draw(enem[i]->b->sprite);  //setting enemy bombs on screen
    for(int i=0;i<10;++i){
        if(enem[i]->c){
            window.draw(enem[i]->sprite);  //setting enemies on screen
        }
    }
}
if(lvl==7 || lvl==8 || lvl==9){
    for(int i=0;i<12;++i)
        if(enem2[i]->bc)
        window.draw(enem2[i]->b->sprite);  //setting enemy bombs on screen
    for(int i=0;i<12;++i){
        if(enem2[i]->c){
            window.draw(enem2[i]->sprite);  //setting enemies on screen
        }
    }
}
/////////////////////////////////////////////////////////////////////
    p->life_check();
	window.draw(p->lif_sprite);   // setting player lives on screen

    scr_text.setString(to_string(p->score));
    window.draw(scr_text);
    window.draw(lif_text);
    window.draw(lvl_text);
    window.draw(text);

    int disp_lvl=0;
    if(lvl>=1 && lvl<=3)
    disp_lvl=1;
    if(lvl>=4 && lvl<=6)
    disp_lvl=2;
    if(lvl>=7 && lvl<=10)
    disp_lvl=3;
    lvl_text2.setString(to_string(disp_lvl));
    window.draw(lvl_text2);

	window.display();  //Displying all the sprites
    }

}
}