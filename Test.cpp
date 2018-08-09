#include<cstdio>
#include<cstring>
#include<iostream>
// using namespace std;

int t,n,m,x,y,ans;
unsigned long long hash[1010][1010],mi[1010],p[1010],q[1010],f[1010];
char s[300];
void getfail()
{ int i,j=0;
  memset(f,0,sizeof(f));
  for(i=2;i<=y;i++)
  { while(j && p[i]!=p[j+1])
     j=f[j];
    if(p[i]==p[j+1])
     j++;
    f[i]=j;
  }
}
void find(int pos)
{ int i,j=0;
  for(i=1;i<=m;i++)
   q[i]=hash[pos+x][i]-hash[pos][i]*mi[x];

  for(i=1;i<=m;i++)
  { while(j && q[i]!=p[j+1])
     j=f[j];
    if(q[i]==p[j+1])
     j++;
    if (j==y)
    { ans++;
      j=f[j];
    }
  }
}
int main()
{ int i,j;
  scanf("%d",&t);
  while(t--)
  { scanf("%d%d",&n,&m);
    memset(p,0,sizeof(p));
    mi[0]=1;ans=0;
    for(i=1;i<=n;i++)
    { scanf("%s",s+1);
      for(j=1;j<=m;j++)
       hash[i][j]=hash[i-1][j]*2333+s[j];
      mi[i]=mi[i-1]*2333;
    }
    scanf("%d%d",&x,&y);
    for(i=1;i<=x;i++)
    { scanf("%s",s+1);
      for(j=1;j<=y;j++)
       p[j]=p[j]*2333+s[j];
    }

    for (int i=0; i<=y; i++){
        std::cout<<p[i]<<' ';
    }std::cout<<'\n';

    getfail();
    for(i=0;i<=n-x;i++)
     find(i);
    printf("%d\n",ans);
  }
}
