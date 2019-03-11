SDL_Texture *buttonImg;

class Button
{
    public:
    int x,y;
    int id;
    int w,h;
    char text[30];


}buton[100];


void butonCreate(int Id,int x,int y,int lx,int ly,char *text)
{
    buton[Id].x=x;
    buton[Id].y=y;
    buton[Id].id=Id;
    buton[Id].w=lx;
    buton[Id].h=ly;
    strcpy(buton[Id].text,text);

}

void butonRender(SDL_Renderer *&g_pRenderer,int id)
{

    showImg(button[id],g_pRenderer,buton[id].x,buton[id].y,buton[id].w,buton[id].h);

}

void butonRenderAll(SDL_Renderer *&g_pRenderer,int nri, int nrf)
{
    for(int i=nri;i<=nrf;i++)
        butonRender(g_pRenderer,i);
}

bool butonClick(int id,int x,int y)
{

    if(buton[id].x < x && x < buton[id].x + buton[id].w )
        if(buton[id].y < y && y < buton[id].y + buton[id].h )
            return true;

    return false;

}
