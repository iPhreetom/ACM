// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const int M = 10005;

/* *suffix array *倍增算法  O(n*logn)
*待排序数组长度为n,放在0~n-1中，在最后面补一个0
*da(str ,n+1,sa,Rank,height,  ,   );//注意是n+1;
*例如： *n   = 8;
*num[]   = { 1, 1, 2, 1, 1, 1, 1, 2, $ };注意num最后一位为0，其他大于0
*Rank[]  = { 4, 6, 8, 1, 2, 3, 5, 7, 0 };Rank[0~n-1]为有效值，Rank[n]必定为0无效 值
*sa[]    = { 8, 3, 4, 5, 0, 6, 1, 7, 2 };sa[1~n]为有效值，sa[0]必定为n是无效值
*height[]= { 0, 0, 3, 2, 3, 1, 2, 0, 1 };height[2~n]为有效值 * */

const int MAXN=110010;
int t1[MAXN],t2[MAXN],c[MAXN];
int Rank[MAXN],height[MAXN];
char str[MAXN];
int r[MAXN];
int sa[MAXN];
int num,n,ans;
//求SA数组需要的中间变量，不需要赋值
//待排序的字符串放在s数组中，从s[0]到s[n-1],长度为n,且最大值小于m,
//除s[n-1]外的所有s[i]都大于0，r[n-1]=0
//函数结束以后结果放在sa数组中

bool cmp(int *r,int a,int b,int l)
{
    return r[a] == r[b] && r[a+l] == r[b+l];
}

void da(char *str,int *sa,int *Rank,int *height,int n,int m)
{
    n++;
    int i, j, p, *x = t1, *y = t2;     //第一轮基数排序，如果s的最大值很大，可改为快速排序
    for(i = 0; i < m; i++)c[i] = 0;
    for(i = 0; i < n; i++)c[x[i] = str[i]]++;
    for(i = 1; i < m; i++)c[i] += c[i-1];
    for(i = n-1; i >= 0; i--)sa[--c[x[i]]] = i;
    for(j = 1; j <= n; j <<= 1)
    {
        p = 0;         //直接利用sa数组排序第二关键字
        for(i = n-j; i < n; i++)y[p++] = i;//后面的j个数第二关键字为空的最小
        for(i = 0; i < n; i++)if(sa[i] >= j)y[p++] = sa[i] - j;         //这样数组y保存的就是按照第二关键字排序的结果
        //基数排序第一关键字
        for(i = 0; i < m; i++)c[i] = 0;
        for(i = 0; i < n; i++)c[x[y[i]]]++;
        for(i = 1; i < m; i++)c[i] += c[i-1];
        for(i = n-1; i >= 0; i--)sa[--c[x[y[i]]]] = y[i];        //根据sa和x数组计算新的x数组
        swap(x,y);
        p = 1;
        x[sa[0]] = 0;
        for(i = 1; i < n; i++)
            x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        if(p >= n)
            break;
        m = p;//下次基数排序的最大值
    }
    int k = 0;
    n--;
    for(i = 0; i <= n; i++)
        Rank[sa[i]] = i;
    for(i = 0; i < n; i++)
    {
        if(k)
            k--;
        j = sa[Rank[i]-1];
        while(str[i+k] == str[j+k])
            k++;
        height[Rank[i]] = k;
    }
}


int is_ok(int len) //如果失败返回0，成功返回最后一个位置
{
    int temp=1,pos=-1,re_pos=-1;
    for(int i=2; i<=n; i++)
        if(height[i] >= len)
            temp++,re_pos=max(re_pos,sa[i-1]),re_pos=max(re_pos,sa[i]);
        else
        {
            if(temp >= num)
                pos=max(pos,re_pos);//因为不排除pos和re_pos都是符合条件的，那么如果都符合条件那么就肯定要取最大的
            temp=1,re_pos=-1;
        }
    if(temp >= num)
        pos=max(pos,re_pos);
    if(pos==-1)
        return 0;
    else
        return pos;
}

int find_ans()
{
    int l=1,r=n-num+1,mid,pos=-1,temp;
    ans=-1;
    while(l<=r)
    {
        mid=(l+r)>>1;
        temp=is_ok(mid);
        if(temp!=0)
            pos=temp,ans=mid,l=mid+1;
        else
            r=mid-1;
    }
    if(pos!=-1)
        printf("%d %d\n",ans,pos);
    else
        printf("none\n");
    return 0;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	return 0;
}
