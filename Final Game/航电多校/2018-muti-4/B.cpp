#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LL long long
// #define Mod 1000000007
// #define P 1000000007
const int Mod = 1e9+7;
const int P = 1e9+7;
const int MAXN = 100017

struct info{
	int a,b,id,bl;
}s[MAXN];

ll ans[MAXN];
ll w[MAXN],inv[MAXN];

ll C(int r,int l)
{
    if (r<l) return 0;
	return w[r]*inv[l]%Mod*inv[r-l]%Mod;
}

bool cmp(info x,info y){
	if (x.bl!=y.bl) return x.b<y.b;
    if (x.bl&1)  return x.a < y.a;
    return x.a > y.a;
	// else if (x.bl==y.bl&&x.a<y.a) return true;
    // else if (x.a == y.a && x.id < y.id) return true;
	// return false;
}

// bool cmp(query a,query b)
// {
//     if (a.block!=b.block) return a.l<b.l;
//     if (a.block&1) return a.r<b.r;
// 	return a.r>b.r;
// }

int main(){
  ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

  const int N = MAXN;

  w[0]=1;w[1]=1;inv[1]=1; inv[0]=1;
for (int i=2;i<N;i++)
{
	w[i]=w[i-1]*i%P;
	inv[i]=inv[P%i]*(P-P/i)%P;
}
for (int i=2;i<N;i++) inv[i]=inv[i-1]*inv[i]% P;
ll KK=sqrt(100000);
ll T,Ni=2;
Ni=inv[2];

cin >> T;
  for (int i=1;i<=T;++i){
    cin >> s[i].a >> s[i].b;
  	s[i].id=i;s[i].bl=s[i].b/KK;
  }

  int l=1,r=1;
  long long k=2;
  sort(s+1,s+T+1,cmp);
  for (int i=1;i<=T;++i){
      while (r<s[i].b){
          k=(k+C(l,r+1))%Mod;
          ++r;
      }
	while (r>s[i].b){
        k=(k-C(l,r)+Mod)%Mod;
        --r;
    }
  	while (l<s[i].a){
        k=(2*k-C(l,r)+Mod)%Mod;
        ++l;
    }
    while (l>s[i].a){
        k=(k+C(l-1,r))*Ni%Mod;
        --l;
    }

	ans[s[i].id]=k;
  }
  for(int i=1;i<=T;++i){
      cout << ans[i] << endl;
  }
  return 0;
}
