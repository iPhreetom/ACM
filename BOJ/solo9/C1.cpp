#include<bits/stdc++.h>
using namespace std;
const int Inf=1e9+7;

typedef pair<int,int>pi;
//pi 是pair

int dp[1<<20];
//状压dp的大小


int n,m;
int cost[22][22],sum[22][22],code[22][22];
char s[22][22];
//保存每个位置的元素

vector<pi>V;
//pair 的数组

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",s[i]);
	//利用s保存字符串

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&cost[i][j]);
			//利用cost 保存消耗

    for(int i=0;i<m;i++)
    {//先历遍每一列
        for(int j=0;j<n;j++)
        {//然后对于一个位置（列），历遍每一行
            int maxx=-1;
			//想要找到最大值，于是maxx保存

            for(int k=0;k<n;k++)
            {// 对于某一行，历遍其他的行进行对比
                if(s[k][i]!=s[j][i])continue;
				//如果某一行的字符 和 这一行不同，就跳过

                maxx=max(maxx,cost[k][i]);
				//用maxx 保存 这个字符，在这一列中的最大消耗

                sum[j][i]+=cost[k][i];
				// sum表示，在第j行，的第i个位置（列），总消耗为SUM

                code[j][i]|=(1<<k);
				//二进制处理后，得到 code[j][i]
				// 第j行，第i个位置，与k（第k行）的二进制值，进行或处理
				// 或 0-1 = 1 / 1-1 = 1 / 0-0 = 0 ?? >>>>>>>>>>>>>

            }
            sum[j][i]-=maxx;
			//总和减去在这之中的最大消耗

        }
    }
    for(int i=1;i<(1<<n);i++)//2^n
    {
        dp[i]=Inf;
        int low=__builtin_ctz(i);
		//low = i 后零的个数

        for(int j=0;j<m;j++)
        {
            dp[i]=min(dp[i^(1<<low)]+cost[low][j],dp[i]);
            dp[i]=min(dp[(i^code[low][j])&i]+sum[low][j],dp[i]);
        }
    }
    printf("%d\n",dp[(1<<n)-1]);
}
