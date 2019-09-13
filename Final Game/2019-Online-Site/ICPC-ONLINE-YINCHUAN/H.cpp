#include<iostream>
#include<algorithm>
#include<stack>
#include<cstdio>
#include<map>
#include<queue>
#include<cstring>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
int a[maxn];
int cnt,rt;
struct Node
{
    int f;
    vector<int>d,ch;
    void init(int fa,int x)//f是该节点的父亲？ x是当前的结点拥有的值？
    {
        f=fa;
        d.clear(),ch.clear();
        d.push_back(x);//当前节点拥有多少的所有的值
    }
}tr[maxn];
void ins(int p,int x)//(1,x)
{
//    cout<<"rt:"<<rt<<endl;
    if(tr[p].d.size()==3)//代表有三个元素？？ 也就是当前节点插满了不能再插进元素了
    {
        int f=tr[p].f;//父亲是谁
        vector<int>cpy_d,cpy_ch;
        cpy_d.swap(tr[p].d),cpy_ch.swap(tr[p].ch);//swap ??  这时候cop_d 和cpy_ch拥有了ty[p].d和ty[p].ch的内容 而这两个变为空？
        if(p==rt)//如果p和rt相等？？代表已经是根节点了 上面没有结点
        {
            //相当于中间结点往上提 0 1 2三个结点 中间的自然是1  变为其它两个节点的父亲
            tr[rt=++cnt].init(0,cpy_d[1]);//新的结点  父亲变为0 插入d[1]?


            tr[++cnt].init(rt,cpy_d[0]);//新的结点 父亲变为rt 插入d[0]? 相当于成为左儿子
            tr[p].init(rt,cpy_d[2]);//原来的结点父亲是rt 只剩下d[2]? 相当于成为右儿子
            tr[rt].ch.push_back(cnt),tr[rt].ch.push_back(p);//把这两个结点加入到他们的父亲节点的孩子中
            if(cpy_ch.size())//如果当前节点有孩子 自然孩子也需要进行操作
            {
                //左边两个分到左边 右边两个分到右边  大概是为了平衡吧。。。
                tr[cnt].ch.push_back(cpy_ch[0]),tr[cpy_ch[0]].f=cnt;//原来的左儿子自然也就成为现在左儿子的左儿子了
                tr[cnt].ch.push_back(cpy_ch[1]),tr[cpy_ch[1]].f=cnt;//为什么把1也归为左儿子的儿子？
                tr[p].ch.push_back(cpy_ch[2]),tr[cpy_ch[2]].f=p;//为什么把2 3归为右儿子的儿子？
                tr[p].ch.push_back(cpy_ch[3]),tr[cpy_ch[3]].f=p;
//                cout<<cpy_ch[0]<<" "<<cpy_ch[1]<<" "<<cpy_ch[2]<<" "<<cpy_ch[3]<<endl;
            }
            p=rt;//现在的根节点已经变为rt了
        }
        else//不是根节点  上面有节点
        {
            tr[p].init(f,cpy_d[0]);//左边结点
            tr[++cnt].init(f,cpy_d[2]);//新建右边结点
            tr[f].d.push_back(cpy_d[1]);//把中间结点提上去
            sort(tr[f].d.begin(),tr[f].d.end());//提上元素之后显然要排序
            tr[f].ch.push_back(cnt);//多加了个孩子
            for(int i=tr[f].ch.size()-1;i>1;i--)//？？为什么要交换？ 懂了 因为你要保证孩子也是有序的呀 所以要把新插入的结点换到p之后
            {
                if(tr[f].ch[i-1]!=p) swap(tr[f].ch[i-1],tr[f].ch[i]);
                else break;
            }
            if(cpy_ch.size())
            {
                tr[p].ch.push_back(cpy_ch[0]),tr[cpy_ch[0]].f=p;
                tr[p].ch.push_back(cpy_ch[1]),tr[cpy_ch[1]].f=p;
                tr[cnt].ch.push_back((cpy_ch[2])),tr[cpy_ch[2]].f=cnt;
                tr[cnt].ch.push_back(cpy_ch[3]),tr[cpy_ch[3]].f=cnt;
            }
            p=f;
        }
    }

//    cout<<"*"<<tr[p].d.size()<<endl;
    //保证当前节点只有两个元素??错的 会有三个
    if(tr[p].ch.size()==0)//没有孩子?? 也就不需要在孩子中进行比较和插入了 直接放进去即可
    {
        tr[p].d.push_back(x);//作为本节点的元素
        sort(tr[p].d.begin(),tr[p].d.end());//你必须保证里面的有序的 所有每次插入元素都需要排序？？？

    }
    else//有孩子 插入元素就必须和孩子比较了
    {
        if(x<tr[p].d[0]) ins(tr[p].ch[0],x);//如果x<第一个元素 那么很显然 肯定要插入到做儿子中 （因为元素是有序的）所以递归左儿子
        else if(x>tr[p].d[tr[p].d.size()-1]) ins(tr[p].ch[tr[p].ch.size()-1],x);//如果大于最后一个元素 显然是插到右孩子中的 递归右儿子
        else//不比第一个小 不比最后一个大 则肯定插入到中间
        {
            for(int i=1;i<tr[p].d.size();i++)//遍历中间元素
                if(x<tr[p].d[i]) {ins(tr[p].ch[i],x);break;}//小于谁就插入到谁的孩子中
        }
    }
}
void dfs(int p)
{
    for(int i=0;i<tr[p].d.size();i++)
        printf("%d%c",tr[p].d[i],i==tr[p].d.size()-1?'\n':' ');
    for(int i=0;i<tr[p].ch.size();i++) dfs(tr[p].ch[i]);
}
int main()
{
    int T;
    cin>>T;
    int ca=1;
    while(T--)
    {
        int N;
        cin>>N;
        for(int i=1;i<=N;i++) cin>>a[i];
        cnt=rt=1,tr[rt].init(0,a[1]); //第一个点的父亲为0 拥有元素a[1]
        for(int i=2;i<=N;i++) ins(rt,a[i]);//rt不是一直是1吗？
        printf("Case #%d:\n", ca++);
        dfs(rt);
    }
    return 0;
}
