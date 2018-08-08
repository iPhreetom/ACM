#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int t;
int n,m,k,p,q,r,mod;
int a[10000009];

inline bool readint(int &num)
{
        char in;bool IsN=false;
        in=getchar();
        if(in==EOF) return false;
        while(in!='-'&&(in<'0'||in>'9')) in=getchar();
        if(in=='-'){ IsN=true;num=0;}
        else num=in-'0';
        while(in=getchar(),in>='0'&&in<='9'){
                num*=10,num+=in-'0';
        }
        if(IsN) num=-num;
        return true;
}



signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		deque<pair<int,int>> que;

		readint(n);
		readint(m);
		readint(k);
		readint(p);
		readint(q);
		readint(r);
		readint(mod);

		for(int i=1;i<=k;i++){
			cin>>a[i];
		}
		for(int i=k+1;i<=n;i++){
			a[i] = (a[i-1]*p%mod + q*i%mod + r)%mod;
		}

		int mx = 0;
		int cnt = 0;
		int A=0;
		int B=0;
		mx = -1;

		for(int i=n-m+1;i<=n;i++){
			if(a[i] > mx){
				mx = a[i];
				cnt++;
				que.push_back({a[i],i});
			}
		}
		A += (mx^(n-m+1));
		B += (cnt^(n-m+1));


		for(int i=n-m;i>=1;i--){
			if(i+m == que.back().second){
				que.pop_back();
				cnt--;
				mx = que.back().first;
			}

			// cout<<"--11"<<endl;

			if(a[i] < que.front().first){
				que.push_front({a[i],i});
			}
			else if(a[i] == que.front().first){
				que.pop_front();
				que.push_front({a[i],i});
			}else{
				while(!que.empty() && que.front().first<a[i]){
					que.pop_front();
					cnt--;
				}
				que.push_front({a[i],i});
				cnt++;
			}
			A += (mx^i);
			B += (cnt^i);


		}
		// cout<<A<<' '<<B<<endl;
		printf("%lld %lld\n",A,B);
	}
	return 0;
}
// 1
// 10 6 10 5 5 5 5
// 0 0 0 0 0 0 0 0 0 0
