#include "bullet.h"

class Player:public Obiect
{

public:

    int v;
    int dmg;
    int hp;
    int kills;
    short direction;
    long lastattacktime;
    long nextattatcktime;

    LTexture killsText;

    vector <int *> power;

    void render();
    void update();
    void renderHeal();

    Player()
    {
        x=10;
        y=150;
        v=5;
        width=height=40;
        direction=0;
        nextattatcktime=190;
        kills=0;
        hp=5;
    }


}eu;



void Player::update()
{

    if(eu.direction)
    {

        if(eu.direction==1)
            if(eu.y<eu.v)
                eu.y=0;
            else
                eu.y-=eu.v;

        if(eu.direction==2)
            if(eu.y>game.y-eu.v-eu.height)
                eu.y=game.y-eu.height;
            else
                eu.y+=eu.v;

        if(eu.direction==3)
            if(eu.x<eu.v)
                eu.x=0;
            else
                eu.x-=eu.v;

        if(eu.direction==4)
            if(eu.x>game.x/2-eu.v-eu.width-1)
                eu.x=game.x/2-eu.v-eu.width;
            else
                eu.x+=eu.v;

        direction=0;
    }

    for(int i=0; i< glont.x.size() ; i++)
        if(glont.t[i]==2 && eu.x < glont.x[i] && eu.x + eu.width > glont.x[i] + glont.width && eu.y < glont.y[i] && eu.y + eu.height > glont.y[i] + glont.height)
        {
            glont.x.erase(glont.x.begin()+i);
            glont.y.erase(glont.y.begin()+i);
            glont.t.erase(glont.t.begin()+i);
            eu.hp--;
        }

}

void Player::renderHeal()
{
    switch(eu.hp)
    {
    case 5:
        showImg(heal,renderer,70,game.y+2,15,15);

    case 4:
        showImg(heal,renderer,53,game.y+2,15,15);

    case 3:
        showImg(heal,renderer,36,game.y+2,15,15);

    case 2:
        showImg(heal,renderer,19,game.y+2,15,15);

    case 1:
        showImg(heal,renderer,2,game.y+2,15,15);
    }
}

void Player::render()
{
    showImg(player,renderer,eu.x,eu.y,eu.width,eu.height);
}
