// fty
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const int maxn = 1e5+5;
int head[maxn]; // 起点编号 ——> 空间位置
int ver[maxn]; // 空间位置 ——> 重点编号
int nt[maxn]; // 空间位置 ——> 下一个空间位置
int edge[maxn]; // 空间位置 ——> 值
int tot; // 空间位置递增

void add(int x,int y,int v){// 在头部插入
	nt[++tot] = head[x] , head[x] = tot;
	ver[tot] = y;
	edge[tot] = v;
}

int Scan()
{   //  输入外挂
    int res = 0, flag = 0;
    char ch;
    if ((ch = getchar()) == '-')
    {
        flag = 1;
    }
    else if(ch >= '0' && ch <= '9')
    {
        res = ch - '0';
    }
    while ((ch = getchar()) >= '0' && ch <= '9')
    {
        res = res * 10 + (ch - '0');
    }
    return flag ? -res : res;
}

void Out(int a)
{   //  输出外挂
    if (a < 0)
    {
        putchar('-');
        a = -a;
    }
    if (a >= 10)
    {
       Out(a / 10);
    }
    putchar(a % 10 + '0');
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	return 0;
}
