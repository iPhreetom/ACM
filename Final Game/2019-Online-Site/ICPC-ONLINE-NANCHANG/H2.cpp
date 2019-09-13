#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const ll Mod=998244353;

struct Matrix{
    ll M[2][2];
    void clear(){
        for (int i=0;i<2;++i)
         for (int j=0;j<2;++j)
          M[i][j]=0;
    }
    void IE(){
        for (int i=0;i<2;++i)
         M[i][i]=1;
    }
}A,Ans;

Matrix operator*(Matrix a,Matrix b){
      Matrix c;c.clear();
      for (int i=0;i<2;++i)
       for (int j=0;j<2;++j)
        for (int k=0;k<2;++k)
         c.M[i][j]=(c.M[i][j]+a.M[i][k]*b.M[k][j]%Mod)%Mod;
       return c;
}

ll iFbi(ll x){
    if (x==0) return 0;
    if (x==1) return 1;
    x-=1;
    A.M[0][0]=0,A.M[0][1]=2;
    A.M[1][0]=1,A.M[1][1]=3;
    Ans.clear(),Ans.IE();
    for (ll i=1;i<=x;i<<=1){
        if (i&x) Ans=Ans*A,x-=i;
        A=A*A;
    }
    return Ans.M[1][1];
}

signed main(){
    ll q,n,ans,t=0;
	unordered_map<pair<ll,ll>,ll> mp;
	vector<ll> lis;

    scanf("%lld%lld",&q,&n);
    for (int i=1;i<=q;++i){
        ans=iFbi(n);
        n=n^(ans*ans);
        t^=ans;
		if (mp.count(t)!=0) {
			int res = q-i;
			int index = mp[t]; //
			int len = lis.size()-index; //  xunhuanjie 长度
			res %= len;
			cout<<"index = "<<index<<endl;
			cout<<"lis[index] = "<<lis[index]<<endl;
			t = lis[index + res];
			break;
		}
		else {			
			lis.push_back(t);
		}
    }
	for (int i=0; i<lis.size(); i++){
		if (lis[i] == 508141730) {
			cout<<"i = "<<i<<endl;
		}
	}
    printf("%lld",t);
}

// 4123123
// 123123
// 508141730
