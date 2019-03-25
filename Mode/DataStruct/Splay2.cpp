
struct Splay_tree{
    LL sum[N];
    int size[N],pre[N],val[N],tot;
    int ch[N][2],tot1,root,s[N],tot2,cnt[N][2];    //cnt[0]表示的是正数个数，cnt[1]表示的是负数个数
    //debug部分copy from hh
    void Treaval(int x) {
        if(x) {
            Treaval(ch[x][0]);
            printf("结点%2d:左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d ,val = %2c \n",x,ch[x][0],ch[x][1],pre[x],size[x],val[x]);
            Treaval(ch[x][1]);
        }
    }
    void debug() {printf("%d\n",root);Treaval(root);}
    //以上Debug
    inline void NewNode(int &r,int k,int father){
        r=++tot1;
        ch[r][0]=ch[r][1]=0;
        cnt[r][0]=k>0;
        cnt[r][1]=k<0;
        sum[r]=k;
        pre[r]=father;
        size[r]=1;
        val[r]=k;
    }
    inline void Push_Up(int x){
        if(x==0) return ;
        int l=ch[x][0],r=ch[x][1];
        size[x]=size[l]+size[r]+1;
        cnt[x][0]=cnt[l][0]+cnt[r][0]+(val[x]>0);
        cnt[x][1]=cnt[l][1]+cnt[r][1]+(val[x]<0);
        sum[x]=(LL)sum[l]+sum[r]+val[x];
    }
    inline void Init(){
        tot1=tot2=root=tot=0;
        ch[root][0]=ch[root][1]=pre[root]=size[root]=sum[0]=cnt[0][0]=cnt[0][1]=0;
        val[root]=0;
        NewNode(root,0,0);
        NewNode(ch[root][1],0,root);
        Push_Up(ch[root][1]);
        Push_Up(root);
    }
    inline void Rotate(int x,int kind){
        int y=pre[x];
        ch[y][!kind]=ch[x][kind];
        pre[ch[x][kind]]=y;
        if(pre[y])
            ch[pre[y]][ch[pre[y]][1]==y]=x;
        pre[x]=pre[y];
        ch[x][kind]=y;
        pre[y]=x;
        Push_Up(y);
    }
    inline void Splay(int r,int goal){
        while(pre[r]!=goal){
            if(pre[pre[r]]==goal)
                Rotate(r,ch[pre[r]][0]==r);
            else{
                int y=pre[r];
                int kind=(ch[pre[y]][0]==y);
                if(ch[y][kind]==r){
                    Rotate(r,!kind);
                    Rotate(r,kind);
                }
                else{
                    Rotate(y,kind);
                    Rotate(r,kind);
                }
            }
        }
        Push_Up(r);
        if(goal==0) root=r;
    }
    inline void RotateTo(int k, int goal) {
        int x=root;
        while(k!=size[ch[x][0]]+1){
            if (k<=size[ch[x][0]]){
                x=ch[x][0];
            }else{
                k-=(size[ch[x][0]]+1);
                x=ch[x][1];
            }
        }
        Splay(x,goal);
    }
    inline int Get_Kth(int r,int k){
        int t=size[ch[r][0]]+1;
        if(t==k) return r;
        if(t>k) return Get_Kth(ch[r][0],k);
        else return Get_Kth(ch[r][1],k-t);
    }
    inline int Insert(int pos,int k){
        tot++;
        RotateTo(pos,0);
        RotateTo(pos+1,root);
        NewNode(Key_value,k,ch[root][1]);
        Push_Up(ch[root][1]);
        Push_Up(root);
        return Key_value;
    }
    inline void Delete(int r){
        tot--;
        Splay(r,0);
        int pos=size[ch[r][0]];
        RotateTo(pos,0);
        RotateTo(pos+2,root);
        s[tot2++]=Key_value;
        Key_value=0;
        Push_Up(ch[root][1]);
        Push_Up(root);
    }
    //找第n+1个负数的位置
    inline int find(int x,int n){
        int l=ch[x][0],r=ch[x][1];
        if(cnt[l][1]==n&&val[x]<0) {Splay(x,0);return size[ch[root][0]];}
        else if(cnt[l][1]>=n+1) return find(l,n);
        else return find(r,n-cnt[l][1]-(val[x]<0));
    }
    inline void InOrder(int r){
        if(r==0)
            return;
        InOrder(ch[r][0]);
        printf("%d ",val[r]);
        InOrder(ch[r][1]);
    }
    inline void Print(){
        RotateTo(1,0);
        RotateTo(tot+2,root);
        InOrder(Key_value);
        printf("\n");
    }
}
