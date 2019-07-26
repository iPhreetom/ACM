#include<bits/stdc++.h>
#define int long long
using namespace std;




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	string s;
	int a,b;
	char c,d;
	int e;

	int sum = 0;
	int maxn = 0;
	string name;

	for(int i=0;i<n;i++){
		int it=0;
		cin>>s>>a>>b>>c>>d>>e;

		if(e){
			if(a>80)it+=8000;
			// cout<<s<<endl;
		}

		if(c == 'Y'){
			if(b > 80){
				it+=850;
			}
		}

		if(b>80){
			if(a>85)it+=4000;
		}

		if(a>90)it+=2000;

		if(d == 'Y'){
			if(a>85)it+=1000;
		}

		if(it > maxn){
			name = s;
			maxn = it;
		}
		sum+=it;
	}
	cout<<name<<endl;
	cout<<maxn<<endl;
	cout<<sum<<endl;
	return 0;
}
