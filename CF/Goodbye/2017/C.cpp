#include<bits/stdc++.h>
#define int long long
using namespace std;




priority_queue<pair<double,double> > que;
set<pair<double,double> > s;

int n;
vector<double> arr;
double r;
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>r;
	double xt;
	for(int i=0;i<n;i++){
		cin>>xt;

		if(!s.empty()){
			double yt=r;
			for(auto i = s.rbegin();i!=s.rend();i++){
				if( abs((*i).second - xt) <= 2*r ){
					yt = max(yt, (*i).first + sqrt(4*r*r - (abs((*i).second)-xt)*(abs((*i).second)-xt)) );
				}
			}
			s.insert(make_pair(yt,xt));
			cout<<fixed<<setprecision(9)<<yt<<endl;
		}
		else{
			s.insert(make_pair(r,xt));
			cout<<fixed<<setprecision(9)<<r<<endl;
		}
	}


	return 0;
}
