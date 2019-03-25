#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pir pair<int,int>
const int N=1e9+10;
bool vis[N];
int st=123456789,ed=876543219;
int go[4]= {-2,-1,1,2},a[10];
int get_num()
{
    int sum=0;
    for(int i=0; i<9; i++)
    {
        sum*=10;
        sum+=a[i];
    }
    return sum;
}
int main()
{
    queue<pir>q;
    mem(vis,0);
    q.push(make_pair(st,0));//pair中存的是当前状态和所需步数
    vis[st]=1;
    while(!q.empty())
    {
        int x=q.front().first,step=q.front().second;
        int cnt=8,now;
        q.pop();
        while(x)
        {
            if(x%10==9)
                now=cnt;//找到当前空位的位置
            a[cnt--]=x%10;//把当前状态存进a数组
            x/=10;
        }
        for(int i=0; i<4; i++)
        {
            swap(a[now],a[(now+go[i]+9)%9]);
            int val=get_num();
            if(!vis[val])
            {
                vis[val]=1;
                if(val==ed)
                {
                    printf("ans=%d\n",step+1);
                    return 0;
                }
                q.push(make_pair(val,step+1));
            }
            swap(a[now],a[(now+go[i]+9)%9]);
        }
    }
    return 0;
}
