#include"player.h"

Player::Player(std::string png_path)
{
shield_tex.loadFromFile("img/PNG/Effects/shield1.png");
shield.setTexture(shield_tex);
shield.setScale(0.75,0.75);
tex.loadFromFile(png_path);
sprite.setTexture(tex);
x=340;y=700;
sprite.setPosition(x,y);
sprite.setScale(0.75,0.75);
lives=3;
pwrc=0;
firc=0;
lifc=0;
danc=0;
score=0;
}
void Player::fire(int &i)
{
b = new Bullet("img/PNG/Lasers/laserBlue08.png", sprite.getPosition().x, sprite.getPosition().y);
i=1;
}
void Player::move(std::string s){
float delta_x=0,delta_y=0;
if(s=="l")
	delta_x=-1;
else if(s=="r")
	delta_x=1;
if(s=="u")
	delta_y=-1;
else if(s=="d")
	delta_y=1;

delta_x*=speed;
delta_y*=speed;

sprite.move(delta_x, delta_y);
}

////////////////// function for wrap around///////////////////////////////////
void Player::check_boundary()
{
	if (sprite.getPosition().x < -35)
		sprite.setPosition(735, sprite.getPosition().y);
	if (sprite.getPosition().x > 735)
		sprite.setPosition(-35, sprite.getPosition().y);
	if (sprite.getPosition().y > 700)
		sprite.setPosition(sprite.getPosition().x, 700);
	if (sprite.getPosition().y < 0)
		sprite.setPosition(sprite.getPosition().x, 700);
}
//////////////////////////////////////////////////////////////////////////

//////////////////checking spaceship fire with enemy///////////////////////////////////
void Player::hit(int &i, Enemy **enem, int size){
for(int j=0;j<size;++j)
	if(i && (enem[j]->c))
	{
		int bx = b->sprite.getPosition().x;
		int by = b->sprite.getPosition().y;
		int ex = enem[j]->sprite.getPosition().x;
		int ey = enem[j]->sprite.getPosition().y;
		if ((by <= ey + 30 && by >= ey - 30) && (bx >= ex + enem[j]->xtrx1 && bx <= ex + enem[j]->xtrx2))
		{
			if(!firc)
			i = 0;
			enem[j]->c = 0;
		}
	}
}
//////////////////////////////////////////////////////////////////////////

/////////////////////checking enemy bomb with spaceship/////////////////
void Player::ehit(Enemy **enem, int size){
for(int i=0;i<size;++i)
{
	if(enem[i]->bc){
		int ebx = enem[i]->b->sprite.getPosition().x;
		int eby = enem[i]->b->sprite.getPosition().y;
		int pbx = sprite.getPosition().x;
		int pby = sprite.getPosition().y;
		if (ebx >= pbx - 10 && ebx <= pbx + 80)
			if (eby >= pby - 10 && eby <= pby + 10)
				if(!pwrc)
				shipc = 0;
	}
}
}
//////////////////////////////////////////////////////////////////////////

/////////////////////checking spaceship enemy collision/////////////////
void Player::col(Enemy **enem, int size){
for(int i=0;i<size;++i)
		if(enem[i]->c)
		{
		int ex = enem[i]->sprite.getPosition().x;
		int ey = enem[i]->sprite.getPosition().y;
		int pbx = sprite.getPosition().x;
		int pby = sprite.getPosition().y;
		if(((pbx>=ex+enem[i]->xtrx1 && pbx<=ex+enem[i]->xtrx2) && (pby>=ey-50 && pby<=ey+50)) || ((pbx+70>=ex+enem[i]->xtrx1 && pbx+70<=ex+enem[i]->xtrx2) && (pby>=ey-50 && pby<=ey+50))){
			if(!pwrc)
			shipc=0;
			enem[i]->c=0;
			}
		}
}
//////////////////////////////////////////////////////////////////////////

////////////////////////////////Checking Monster hit with spaceship/////////////////////////////////
void Player::mon_hit(Enemy **mon){
	if(mon[0]->bc){
		int ebx = mon[0]->b->sprite.getPosition().x;
		int eby = mon[0]->b->sprite.getPosition().y;
		int pbx = sprite.getPosition().x;
		int pby = sprite.getPosition().y;
		if (ebx+100 >= pbx && ebx+130 <= pbx+110)
				if(!pwrc)
				shipc = 0;	
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////Checking Dragon hit with spaceship/////////////////////////////////////////////
void Player::drag_hitL(Enemy *drag){
		if(drag->c)
		{
		int pbx = sprite.getPosition().x;
		int pby = sprite.getPosition().y;


		if((((pbx>=250 && pbx<=291) && (pby>=455 && pby<=495)) || ((pbx+70>=250 && pbx+70<=291) && (pby>=455 && pby<=495)))
		|| (((pbx>=220 && pbx<=275) && (pby>=497 && pby<=525)) || ((pbx+70>=220 && pbx+70<=275) && (pby>=497 && pby<=525)))
		|| (((pbx>=185 && pbx<=237) && (pby>=525 && pby<=563)) || ((pbx+70>=185 && pbx+70<=237) && (pby>=525 && pby<=563))) 
		|| (((pbx>=155 && pbx<=223) && (pby>=565 && pby<=590)) || ((pbx+70>=155 && pbx+70<=223) && (pby>=565 && pby<=590))) 
		|| (((pbx>=132 && pbx<=210) && (pby>=590 && pby<=620)) || ((pbx+70>=132 && pbx+70<=210) && (pby>=590 && pby<=620))) 
		|| (((pbx>=110 && pbx<=164) && (pby>=635 && pby<=668)) || ((pbx+70>=110 && pbx+70<=164) && (pby>=635 && pby<=668))) 
		|| (((pbx>=87 && pbx<=148) && (pby>=669 && pby<=700)) || ((pbx+70>=87 && pbx+70<=148) && (pby>=669 && pby<=700))) ){
			if(!pwrc)
			shipc=0;
			}
		}
}


void Player::drag_hit(Enemy *drag){
	if(drag->bc){
		int ebx = drag->b->sprite.getPosition().x;
		int eby = drag->b->sprite.getPosition().y;
		int pbx = sprite.getPosition().x;
		int pby = sprite.getPosition().y;
		if (400 >= pbx && 420 <= pbx+110){
				if(!pwrc)
				shipc = 0;	
		}
	}
}


void Player::drag_hitR(Enemy *drag){
		if(drag->c)
		{
		int pbx = sprite.getPosition().x;
		int pby = sprite.getPosition().y;


		if((((pbx>=480 && pbx<=520) && (pby>=455 && pby<=495)) || ((pbx+70>=480 && pbx+70<=520) && (pby>=455 && pby<=495)))
		|| (((pbx>=515 && pbx<=565) && (pby>=497 && pby<=520)) || ((pbx+70>=515 && pbx+70<=565) && (pby>=497 && pby<=520)))
		|| (((pbx>=535 && pbx<=585) && (pby>=530 && pby<=563)) || ((pbx+70>=535 && pbx+70<=585) && (pby>=530 && pby<=563))) 
		|| (((pbx>=560 && pbx<=615) && (pby>=565 && pby<=585)) || ((pbx+70>=560 && pbx+70<=615) && (pby>=565 && pby<=585))) 
		|| (((pbx>=575 && pbx<=644) && (pby>=590 && pby<=620)) || ((pbx+70>=575 && pbx+70<=644) && (pby>=590 && pby<=620))) 
		|| (((pbx>=610 && pbx<=680) && (pby>=635 && pby<=674)) || ((pbx+70>=610 && pbx+70<=680) && (pby>=635 && pby<=674))) 
		|| (((pbx>=635 && pbx<=700) && (pby>=662 && pby<=700)) || ((pbx+70>=635 && pbx+70<=700) && (pby>=662 && pby<=700))) ){
			if(!pwrc)
			shipc=0;
			}
		}
}
/////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////Add ons check//////////////////////////////////
void Player::addon_check(addon ** Addon){
	for(int i=0;i<4;++i){
		if(Addon[i]->c){
		int ax = Addon[i]->sprite.getPosition().x;
		int ay = Addon[i]->sprite.getPosition().y;
		int pbx = sprite.getPosition().x;
		int pby = sprite.getPosition().y;
		if (ax >= pbx-25  && ax <= pbx + 80)
			if (ay >= pby -30 && ay <= pby + 30){
				Addon[i]->c=0;
				if(i==0 && !firc)
				pwrc=1;
				if(i==1 && !pwrc)
				firc=1;
				if(i==2)
				lifc=1;
				if(i==3)
				danc=1;
			}
		ao_feature();
		}

	}
}
//////////////////////////////////////////////////////////////////////////

///////////////////////////////powerup addon function///////////////////////////////////////////
void Player::pwr_fire(int &i, int &pwri){
	for(int i=0;i<7;++i)
	pwrb[i] = new Bullet("img/PNG/Lasers/laserBlue08.png", sprite.getPosition().x, sprite.getPosition().y);
	i=1;
	pwri=1;
}

void Player::pwr_move(int &i, int &pwri){
	double dx=-1,dy=-0.4;
	bool x=false;
	for(int i=0;i<7;++i){
				if(pwrb[i]->c){
			dx *= 1;
     		dy *= 1;
		}
		dx+=0.25;
		if(std::abs(dy)>1 || x){
		dy=dy+0.2;
		x=true;
		}
		else
		dy=std::abs(dy-0.2)*(-1);

    pwrb[i]->sprite.move(dx, dy);
	}
    if(pwrb[0]->sprite.getPosition().y<0){
     i=0;
    pwri=0;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////power up hit with enemies/////////////////////////////////////////
void Player::pwr_hit(int &i, Enemy **enem, int size){
for(int j=0;j<size;++j)
	if(i && (enem[j]->c))
	{
		int ex = enem[j]->sprite.getPosition().x;
		int ey = enem[j]->sprite.getPosition().y;
		for(int k=0;k<7;++k)
		if(pwrb[k]->c){
		int bx = pwrb[k]->sprite.getPosition().x;
		int by = pwrb[k]->sprite.getPosition().y;
		if ((by <= ey + 30 && by >= ey - 30) && (bx >= ex + enem[j]->xtrx1 && bx <= ex + enem[j]->xtrx2))
		{
			if(!firc)
			pwrb[k]->c = 0;
			enem[j]->c = 0;
		}
		}
	}
}
//////////////////////////////////////////////////////////////////////////


/////////////////////////////////add_on feature check//////////////////////////////////
void Player::ao_feature(){
	if(pwrc){}
	if(firc){}

	if(lifc){
		lifc=0;
		lives++;
	}

	if(danc){
		if(!pwrc)
		shipc=0;
		danc=0;
	}
}
////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////lives sprite//////////////////////////////////////
void Player::life_check(){
	if(lives==0)
lif_tex.loadFromFile("img/PNG/UI/numeral0.png");
	if(lives==1)
lif_tex.loadFromFile("img/PNG/UI/numeral1.png");
	if(lives==2)
lif_tex.loadFromFile("img/PNG/UI/numeral2.png");
	if(lives==3)
lif_tex.loadFromFile("img/PNG/UI/numeral3.png");
	if(lives==4)
lif_tex.loadFromFile("img/PNG/UI/numeral4.png");
	if(lives==5)
lif_tex.loadFromFile("img/PNG/UI/numeral5.png");
	if(lives==6)
lif_tex.loadFromFile("img/PNG/UI/numeral6.png");
	if(lives==7)
lif_tex.loadFromFile("img/PNG/UI/numeral7.png");
	if(lives==8)
lif_tex.loadFromFile("img/PNG/UI/numeral8.png");
	if(lives==9)
lif_tex.loadFromFile("img/PNG/UI/numeral9.png");
lif_sprite.setTexture(lif_tex);
lif_sprite.setPosition(100,733);
lif_sprite.setScale(1,1);

}
////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////level complete check//////////////////////////////////
bool Player::lvl_check(Enemy **enem,int size){
	bool check=false;
	for(int i=0;i<size;++i){
		if(!enem[i]->c)
			check=true;
		else{
			check=false;
			break;
		}	
	}
	return check;
}
//////////////////////////////////////////////////////////////////////////