// genius
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    double a,b;
    while(cin>>a>>b){
        cout<<fixed<<setprecision(5);
        cout<<a/(a+b)<<endl;
    }
	return 0;
}

