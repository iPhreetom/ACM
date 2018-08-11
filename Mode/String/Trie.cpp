
struct Node
{
    Node *next[26];//Trie中每个节点的各个子节点
    Node *fail;//失配指针
    int cnt;//是否为单词的最后一个节点
};
Node *root;
char s[55];

void Init(Node *root)
{
    root->cnt = 0;
    root->fail = NULL;
    for(int i = 0;i <=26;i ++)
        root->next[i] = NULL;
}

void Build_tree(char *s)
{
    Node *p = root,*q;
    int len = strlen(s);
    for(int i = 0;i < len;i ++)
    {
        int c = s[i] - 'a';
        if(p->next[c] == NULL)
        {
            q = (Node *)malloc(sizeof(Node));
            Init(q);
            p->next[c] = q;
        }
        p = p->next[c];
    }
    p->cnt++;
}

void Get_fail()
{
    Node *p = root,*son,*temp;//son儿子节点，temp父亲节点
    queue<Node *> que;
    que.push(p);//将根节点放入队列
    while(!que.empty())
    {
        temp = que.front();que.pop();
        for(int i = 0;i < 26;i ++)
        {
            son = temp->next[i];//儿子节点是根据父亲节点的支配指针来进行转移的
            if(son != NULL)
            {
                if(temp == root)
                    son->fail = root;
                else
                {
                    /*
                    依次回溯其父亲节点失败指针指向节点的子节点，如果这些子节点中包含有和当前节点相同的节点
                    那么当前节点的父亲节点的失败指针就指向这个相同的节点
                    因为失配指针指向：
                    以当前节点为字符串的最后一个节点，后缀相同的最长字符串的最后一个字符！！！！
                    */
                    p = temp->fail;//得到父亲节点的支配指针指指向哪里
                    while(p)
                    {
                        if(p->next[i])//当这个失败指针指向的节点存在和当前节点相同的节点是，失败指针指向这个节点
                        {
                            son->fail = p->next[i];
                            break;
                        }
                        p = p->fail;//继续向上找失败指针
                    }
                    if(!p)
                        son->fail = root;//没有合适的失败指针，就指向根节点
                }
                que.push(son);
            }
        }
    }
}

void Query(char *txt)
{
    /**
    匹配过程包含两种情况：
    1) 从当前节点沿着一条路径可以到达的目标字符，只需要沿着该路径走向下一个节点继续匹配即可，
    2) 当前节点不匹配，则去当前节点失败指针所指向的字符串继续匹配，匹配过程随着指针指向root结束
    **/
    int ans = 0;
    int len = strlen(txt);//s表示寻找的字符串
    Node *p = root,*temp;
    for(int i = 1;i < len;i ++)
    {
        int c = txt[i] - 'a';
        //由失配指针回溯查找，判断s[i]是否存在于Trie树中
        while(p->next[c]==NULL && p != root)//直到找到一个适配的字符串
            p = p->fail;
        p = p->next[c];
        if(!p)//如果指针为空，则没有与之匹配的字符
            p = root;
        temp = p;
        while(temp != root)//我们这个字符串的部分还可以组成一个模式串！
        {
            if(temp->cnt >= 0)
            {
                ans += temp->cnt;
                temp->cnt = -1;
            }
            else//节点已经被访问过了，直接退出循环！
                break;
            temp = temp->fail;
        }
    }
    printf("%d\n",ans);
}
