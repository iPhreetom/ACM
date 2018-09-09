int anc[250005][25];
int fa[250005];
vector <int > tree[555];
int deep[250005];

void dfs(int x)
{
    anc[x][0]=fa[x];
    for (int i=1;i<=22;i++)
    {
        anc[x][i]=anc[anc[x][i-1]][i-1];//倍增思想的体现。不妨在纸上试着画一棵树，脑补一下QWQ
    }

    for (int i=0;i<tree[x].size();i++)
    {
        if (tree[x][i]!=fa[x])
        {
            int y=tree[x][i];
            fa[y]=x;//记录父亲节点
            deep[y]=deep[x]+1;//记录深度
            dfs(y);
        }
    }
}

// 从一个点开始建树 并加上lca标记 tree为节点fa为父节点anc为倍增标记（值为倍增父节点的点号）
//
// （根节点开始的dfs）

int lca(int x,int y)//查询最近公共祖先
{
    if (deep[x]<deep[y]) swap(x,y);//我们希望X是较深的点。

    for (int i=22;i>=0;i--)//这个循环在完成第一步。
    {
        if (deep[y]<=deep[anc[x][i]]) //不可以丢掉“=“哦Q^Q
        {
            x=anc[x][i];
        }
    }

    if (x==y) return x;//如果Y是X的祖先，就可以直接返回结果了。

    for (int i=22;i>=0;i--)
    {
        if (anc[x][i]!=anc[y][i]) //第二步。
        {
            x=anc[x][i];
            y=anc[y][i];
        }
    }

    return anc[x][0];//注意第二步IF语句的条件。
}
