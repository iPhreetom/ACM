#include<stdio.h>
#include<string.h>
int sg2[1<<20],visit[21];

int getsg2(int sta)
{
    memset(visit,0,sizeof(visit));

    for(int i = 19 ; i > 0 ; i --)
    {
        if(sta & (1 << i))
        {
            for(int j = i - 1 ; j >= 0 ; j --)
            {
                if(sta & (1 << j))continue;
                int step = sta ^ ( 1 << i) ^ ( 1 << j);
                visit[sg2[step]] = 1;
                break;
            }
        }
    }
    //因为一个局面最多动20个棋子导致20个局面，所以sg2值一定小于等于20
    for(int i = 0 ; i <= 20 ; i ++)
        if(!visit[i]) return i;
    return 0;
}


int qmain()
{
    for(int i = 0 ; i < (1<<20) ; i ++)
        sg2[i] = getsg2(i);
    return 0;
}
