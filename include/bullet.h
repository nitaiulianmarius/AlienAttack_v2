class Bullet:public Obiect
{
public:

    void update();
    void render();
    void ad(int,int,int);

    vector <int> x,y,t;

    Bullet()
    {
        width=10;
        height=5;
    }

}glont;



void Bullet::ad(int x,int y,int t=0)
{

    glont.t.push_back(t);
    glont.x.push_back(x);
    glont.y.push_back(y);

}

void Bullet::update()
{

    int i;

    for( i = 0; i < glont.x.size() ; i++)
    {
        reload:
        switch( glont.t[i] )
        {

        case 0: // glontul meu

            glont.x[i] += 12;

            break;

        case 2: // glont inamic
            glont.x[i] -= 8;

            break;
        }

        if(glont.x[i] > game.x || glont.x[i] < 0)
        {

            glont.x.erase(glont.x.begin()+i);
            glont.y.erase(glont.y.begin()+i);
            glont.t.erase(glont.t.begin()+i);

        }

    }


}

void Bullet::render()
{

    int i;

    for( i = 0 ; i < glont.x.size() ; i++ )
        if(!glont.t[i])
            showImg(bullet,renderer,glont.x[i],glont.y[i],glont.width,glont.height);
        else
            showImg(bulletpc,renderer,glont.x[i],glont.y[i],glont.width,glont.height);


}
