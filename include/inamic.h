class Inamic:public Obiect
{

public:

    int dmg;
    int hp;
    short direction;
    long nextattatcktime;
    long lastadtime;


    void render();
    void update();
    void ad(int,int,int,int);

    vector <int> x,y,tip,destinatie,lastattacktime;

    Inamic()
    {
        width=height=55;
        nextattatcktime=1500;
        direction=1;
        hp=15;
    }


}pc;



void Inamic::ad(int tip,int x,int y,int xDestinatie=0)
{

    pc.tip.push_back(tip);
    pc.x.push_back(x);
    pc.y.push_back(y);
    pc.lastattacktime.push_back(0);
    pc.destinatie.push_back(xDestinatie);

}

void Inamic::update()
{

    int i;

    for( i = 0 ; i < pc.x.size() ; i++ )
    {
        switch( pc.tip[i] )
        {

            case 1:
            case 2: pc.x[i]-=4; break;
            case 3:
                if(pc.x[i]>game.x-pc.width-30)
                    pc.x[i]--;
                else
                {
                    switch(pc.direction)
                    {
                    case 0:
                        pc.y[i]-=3;

                        break;

                    case 1:
                        pc.y[i]+=3;

                        break;
                    }

                    if(pc.y[i]<5 || pc.y[i] > game.y-5-pc.height)
                        pc.direction=1-pc.direction;

                    if(clock() - pc.lastattacktime[i] > 400)
                    {
                        glont.ad(pc.x[i],pc.y[i]+pc.height/2,2);
                        pc.lastattacktime[i]=clock();
                    }
                }
                break;
            case 4:
                if(clock() - pc.lastattacktime[i] > pc.nextattatcktime)
                {
                    glont.ad(pc.x[i],pc.y[i]+pc.height/2,2);
                    pc.lastattacktime[i] = clock();
                }
                if(pc.x[i] > pc.destinatie[i])
                    pc.x[i]-=2;
                break;

        }

        for(int j = 0; j < glont.x.size() ; j++ )
            if(!glont.t[j])
                if(glont.x[j] > pc.x[i] && glont.x[j] < pc.x[i]+pc.width && glont.y[j] > pc.y[i] && glont.y[j] < pc.y[i]+pc.height)
                {
                    if(pc.tip[i] == 3 && pc.hp)
                    {
                        hp--;
                        glont.x.erase(glont.x.begin()+j);
                        glont.y.erase(glont.y.begin()+j);
                        glont.t.erase(glont.t.begin()+j);
                    }

                    else
                    {
                        pc.x.erase(pc.x.begin()+i);
                        pc.y.erase(pc.y.begin()+i);
                        pc.tip.erase(pc.tip.begin()+i);
                        pc.lastattacktime.erase(pc.lastattacktime.begin()+i);
                        pc.destinatie.erase(pc.destinatie.begin()+i);
                        glont.x.erase(glont.x.begin()+j);
                        glont.y.erase(glont.y.begin()+j);
                        glont.t.erase(glont.t.begin()+j);
                    }

                    eu.kills++;
                }


        if( eu.x + eu.width > pc.x[i] && eu.x < pc.x[i] + pc.width && eu.y + eu.height > pc.y[i] && eu.y < pc.y[i] + pc.height )
        {
            pc.x.erase(pc.x.begin()+i);
            pc.y.erase(pc.y.begin()+i);
            pc.tip.erase(pc.tip.begin()+i);
            pc.lastattacktime.erase(pc.lastattacktime.begin()+i);
            pc.destinatie.erase(pc.destinatie.begin()+i);
            eu.hp--;
        }

        if(pc.x[i] < -pc.width)
        {

            pc.x.erase(pc.x.begin()+i);
            pc.y.erase(pc.y.begin()+i);
            pc.tip.erase(pc.tip.begin()+i);
            pc.lastattacktime.erase(pc.lastattacktime.begin()+i);
            pc.destinatie.erase(pc.destinatie.begin()+i);
            i--;
            eu.hp--;

        }
    }

}

void Inamic::render()
{

    int i;

    for( i = 0 ; i < pc.x.size() ; i++ )
        switch(pc.tip[i])
        {
            case 1:
                showImg(pinkmonster,renderer,pc.x[i],pc.y[i],pc.width,pc.height);
                break;

            case 2:
                showImg(greenmonster,renderer,pc.x[i],pc.y[i],pc.width,pc.height);
                break;

            case 3:
                showImg(focamonster,renderer,pc.x[i],pc.y[i],pc.width,pc.height);
                break;

            case 4:
                showImg(ozn,renderer,pc.x[i],pc.y[i],pc.width,pc.height);
                break;
        }

}
