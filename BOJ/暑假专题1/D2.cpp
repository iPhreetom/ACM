
#include<cstdio>

using namespace std;



int vis[2010];

int flag,deep,n;



void dfs(int pos)

{

    int t;

    if(pos>deep || (vis[pos]<<(deep-pos))<n || flag) return;

    if(vis[pos]==n)

    {

        flag=1;

        return;

    }

    for(int i=1;i<=pos;i++)

    {

        if(flag) return;

        t=vis[pos]+vis[i];

        if(t>0 && t<2000)

        {

            vis[pos+1]=t;

            dfs(pos+1);

        }

        t=vis[pos]-vis[i];

        if(t>0 && t<2000)

        {

            vis[pos+1]=t;

            dfs(pos+1);

        }

    }

}



int main()

{

    while(scanf("%d",&n)&&n)

    {

        deep=0,flag=0;

        vis[1]=1;

        while(!flag)

        {

            deep++;

            dfs(1);

        }

        printf("%d\n",deep-1);

    }

    return 0;

}
