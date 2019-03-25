// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int exgcd(int a,int b,int &x,int &y){
    if (b==0){
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;

	vector<pair<int,int>> v;
	for (int i=0; i<n; i++){
	    int t;
		cin >> t;
		v.push_back(make_pair(0,t));
	}
	for (int i=0; i<n; i++){
	    int t;
		cin >> t;
		v[i].first = t;
	}
	sort(v.begin(),v.end());

	return 0;
}
