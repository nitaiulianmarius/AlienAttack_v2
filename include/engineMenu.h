#include "button.h"

int xMouse,yMouse;

 struct Menu
 {

     int x,y;
     bool run;
     char state[30];

     void init();
     void loadData();
     void render();
     void update();
     void createButtons();
     void changeState();

     Menu()
     {
         run=true;
         x=480;
         y=360;
         strcat( state ,"menuState" );
     }

}menu;

void Menu::loadData()
{

    loadImg(backgroundmenu,renderer,"data/images/backgroundmenu.jpg");

    loadImg(button[b_start],renderer,"data/images/button/start.jpg");
    loadImg(button[b_optins],renderer,"data/images/button/options.jpg");
    loadImg(button[b_exit],renderer,"data/images/button/exit.jpg");

}

void Menu::init()
{

    initSDL("Alien attack v2 - Menu",x,y,window,renderer);
    menu.loadData();
    menu.createButtons();

}

void Menu::createButtons()
{

    butonCreate(1,140,100,200,40,"data/images/button/start.jpg");
    butonCreate(2,140,150,200,40,"data/images/button/options.jpg");
    butonCreate(3,140,200,200,40,"data/images/button/exit.jpg");

}

void Menu::render()
{

    showImg(backgroundmenu,renderer,0,0,menu.x,menu.y);

    if(!strcmp(menu.state ,"menuState"))
        butonRenderAll(renderer,1,3);

    if(!strcmp(menu.state ,"optionsState"))
        butonRenderAll(renderer,1,2);

    SDL_RenderPresent(renderer);
    SDL_UpdateWindowSurface(window);

}

void Menu::update()
{

    while(SDL_PollEvent(&event))
        if(event.type == SDL_QUIT)
            menu.run=false;


    if(event.type == SDL_MOUSEBUTTONDOWN)
        if(event.button.button == SDL_BUTTON_LEFT)
        {

            xMouse=event.button.x;
            yMouse=event.button.y;

            menu.changeState();
            xMouse=-1;

        }



}

void Menu::changeState()
{

    if( !strcmp(menu.state, "menuState") )
    {

        if( butonClick(1, xMouse, yMouse) )
        {
            strcpy(menu.state, "startState");
            menu.run=false;
        }

        if(butonClick(2, xMouse, yMouse) )
        {
            strcpy(menu.state, "optionsState");
            butonCreate(1,140,100,200,40,"data/images/button/soundon.jpg");
            butonCreate(2,140,150,200,40,"data/images/button/back.jpg");
        }

        if(butonClick(3, xMouse, yMouse) )
            menu.run=false;

    }


}
