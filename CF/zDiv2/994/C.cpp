#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

set<pair<int,int> > sq1;
set<pair<int,int> > sq2;


int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int x1,y1,x2,y2,x3,y3,x4,y4;
	int xl,xr,yu,yd;

	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

	xl = min(x1,min(x2,min(x3,x4)));
	xr = max(x1,max(x2,max(x3,x4)));

	yd = min(y1,min(y2,min(y3,y4)));
	yu = max(y1,max(y2,max(y3,y4)));


	for(int i=yd;i<=yu;i++){
		for(int j=xl;j<=xr;j++){
			sq1.insert(make_pair(j,i));
			// printf("(%d,%d) ",j,i);
		}
		// cout<<endl;
	}


	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

	xl = min(x1,min(x2,min(x3,x4)));
	xr = max(x1,max(x2,max(x3,x4)));

	yd = min(y1,min(y2,min(y3,y4)));
	yu = max(y1,max(y2,max(y3,y4)));

	for(int les = 0;les<=(xr-xl)/2;les++){
		for(int i=xl+les;i<=xr-les;i++){
			// printf("(%d,%d) ",i,(yu+yd)/2 - les);
			if(sq1.count(make_pair(i,(yu+yd)/2 - les))!=0){
				cout<<"YES"<<endl;
				return 0;
			}

			if(sq1.count(make_pair(i,(yu+yd)/2 + les))!=0){
				cout<<"YES"<<endl;
				return 0;
			}
		}
		// cout<<endl;
	}

	cout<<"NO"<<endl;

	return 0;
}
