#include "conio.h"
#include "iostream.h"
#include "windows.h"
#include "vector.h"
#include "include/SDLengine.h"
#include "fstream.h"

#define key(x) GetAsyncKeyState(x)

SDL_Event event;
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *background,*backgroundmenu,*player,*bullet,*bulletpc,*pinkmonster,*greenmonster,*focamonster,*ozn,*heal;
SDL_Texture *button[10];
Mix_Music *backgroundSound;

#define b_start 1
#define b_optins 2
#define b_exit 3

#include "include/engine.h"

int main(int argc,char *argv[])
{

    menu.init();

    while(menu.run)
    {

        menu.update();
        menu.render();
        SDL_Delay(50);

    }
    SDL_Quit();

    if(!strcmp(menu.state,"startState"))
        game.start();

}
