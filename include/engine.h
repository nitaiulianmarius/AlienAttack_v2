int _in,state,exitg,timeexit;



class gameEngine
{
public:

    int x,y;
    DWORD startalgorithm,stopalgorithm;
    bool run;


    void loadData();
    void start();

    void handleEvents();
    void update();
    void render();
    void verifExitGame();

    void setFPS(int fps);


    gameEngine()
    {
        x=720;
        y=360;
        run=true;
    }


}game;

#include "obiect.h"
#include "player.h"
#include "inamic.h"
#include "engineMenu.h"


void gameEngine::setFPS(int fps)
{
    int _time = game.startalgorithm - game.stopalgorithm;

    if(1000/fps > _time)
        SDL_Delay(1000/fps-_time);

}


void gameEngine::loadData()
{

    loadImg(background,renderer,"data/images/background.png");
    loadImg(player,renderer,"data/images/player.png");
    loadImg(bullet,renderer,"data/images/bullet.png");
    loadImg(bulletpc,renderer,"data/images/bulletpc.png");
    loadImg(pinkmonster,renderer,"data/images/pinkmonster.png");
    loadImg(greenmonster,renderer,"data/images/greenmonster.png");
    loadImg(focamonster,renderer,"data/images/focamonster.png");
    loadImg(ozn,renderer,"data/images/ozn.png");
    loadImg(heal,renderer,"data/images/heal.png");

    loadSound(backgroundSound,"data/music/background.mp3");

}


void gameEngine::update()
{


    game.verifExitGame();


    switch( state )
    {
        case 0:

        if( _in < 30 )
            if(clock() - pc.lastadtime > 1000)
            {
                pc.ad(rand()%2+1,game.x,rand()%(game.y-pc.height));
                pc.lastadtime=clock();
                _in++;
            }

        if( _in == 30 )
        {
            state = 1;
            _in = 0;
        }

        break;

        case 1:

        if( _in < 30 )
            if(clock() - pc.lastadtime > 1200)
            {
                pc.ad(4,game.x,rand()%(game.y-pc.height),rand()%(game.x/4)+game.x/2);
                pc.lastadtime=clock();
                _in++;
            }

        if( _in == 30 )
        {
            state = 2;
            _in = 0;
        }

        break;

        case 2:

        if(_in < 1)
        {
            pc.ad(3,game.x,10);
            _in++;
        }

        break;
    }

    if(!exitg)
    {
        eu.update();
        pc.update();
    }
    glont.update();

}

void gameEngine::render()
{

    showImg(background,renderer,0,0,game.x,game.y+20);

    eu.render();
    eu.renderHeal();
    pc.render();
    glont.render();


    SDL_RenderPresent(renderer);
    SDL_UpdateWindowSurface(window);


}



void gameEngine::handleEvents()
{

    if(key(VK_UP)) eu.direction=1;
    if(key(VK_DOWN)) eu.direction=2;
    if(key(VK_LEFT)) eu.direction=3;
    if(key(VK_RIGHT)) eu.direction=4;

    while(SDL_PollEvent(&event))
        switch( event.type )
        {
            case SDL_QUIT:
                game.run=false;

            case SDL_KEYDOWN:

                switch( event.key.keysym.sym )
                {
                case SDLK_ESCAPE: game.run=false; break;

                    case SDLK_SPACE:

                        if(clock()-eu.lastattacktime > eu.nextattatcktime)
                        {

                            glont.ad(eu.x+eu.width,eu.y+eu.height/2);
                            eu.lastattacktime=clock();

                        }

                        break;
                }

        }


}

void gameEngine::start()
{

    initSDL("Alien attack v2",game.x,game.y+20,window,renderer);
    game.loadData();
    srand(time(NULL));
    playSound(backgroundSound);


    while(game.run)
    {
        game.startalgorithm=clock();
        game.handleEvents();
        game.update();
        game.render();
        game.stopalgorithm=clock();
        game.setFPS(60);
    }

}



void gameEngine::verifExitGame()
{


    if(eu.hp<=0)
    {
        if(!exitg)
            exitg=1,timeexit=clock();

        if( exitg && clock() - timeexit > 2000 )
        {
            ofstream f("stat.vbs");
            f<<"a=msgbox( \"Your stat :   "<<eu.kills<<" hits\",64,\"Alien Attack v2 - game over\")";
            f.close();
            game.run=false;
            SDL_Quit();
            system("stat.vbs");
            remove("stat.vbs");
            system("exit");
        }
    }

    if( state==2 &&  pc.hp<=0 )
    {
        if(!exitg)
            exitg=1,timeexit=clock();

        if( exitg && clock() - timeexit > 2000 )
        {
            ofstream f("stat.vbs");
            f<<"a=msgbox( \"Your stat :   "<<eu.kills<<" hits\",64,\"Alien Attack v2 - WIN !\")";
            f.close();
            game.run=false;
            SDL_Quit();
            system("stat.vbs");
            remove("stat.vbs");
            system("exit");
        }
    }


}
