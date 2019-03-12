int m,f[210];
long long n;

struct Matrix
{
    long long a[110][110];
    void init()
    {
      memset(a,0,sizeof(a));
      for(int i=0;i<m;i++) a[i][i]=1;
    }
};

Matrix mul(Matrix a,Matrix b)
{
    Matrix ans;
    for(int i=0;i<m;i++) for(int j=0;j<m;j++)
    {
       ans.a[i][j]=0;
       for(int k=0;k<m;k++){ans.a[i][j]+=a.a[i][k]*b.a[k][j]%mod;ans.a[i][j]%=mod;}
       //ans.a[i][j]%=mod;
    }
    return ans;
}

Matrix add(Matrix a,Matrix b)
{
    int i,j,k;
    Matrix ans;
    for(i=0;i<m;i++) for(j=0;j<m;j++)
    {
       ans.a[i][j]=a.a[i][j]+b.a[i][j];
       ans.a[i][j]%=mod;
    }
    return ans;
}

Matrix pow(Matrix a,long long p)
{
    Matrix ans;
    ans.init();
    while(p)
    {
      if(p%2!=0) ans=mul(ans,a);
      p>>=1;a=mul(a,a);
    }
    return ans;
}
