#include<bits/stdc++.h>
#define int long long
using namespace std;


vector<int> gre;
vector<int> red;
vector<int> blu;
vector<int> arr;
vector<pair<int,char> > redp;
vector<pair<int,char> > blup;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int n;
	cin>>n;

	int t;
	char c;
	int sum=0;
	int sum1=0;

	for(int i=0;i<n;i++){
		cin>>t>>c;
		if(c== 'G'){
			if(!gre.empty())sum += t-gre.back();
			gre.push_back(t);
			redp.push_back(make_pair(t,'G'));
			blup.push_back(make_pair(t,'G'));
		}
		if(c == 'R'){
			if(!red.empty())sum1 += t-red.back();
			red.push_back(t);
			redp.push_back(make_pair(t,'R'));
		}
		if(c == 'B'){
			if(!blu.empty())sum1 += t-blu.back();
			blu.push_back(t);
			blup.push_back(make_pair(t,'B'));
		}
	}

	int index = 0;
	int len = gre.size();

	if(gre.size()==0){
		cout<<sum1<<endl;
		return 0;
	}
	else{
		// cout<<sum<<endl;
		int mx = 0;
		bool first=1;

		if(redp[0].second == 'G')first = 0;
		for(int i=1;i<redp.size();i++){
			if(redp[i].second == 'R'){
				sum += redp[i].first - redp[i-1].first;
				mx = max(mx,redp[i].first - redp[i-1].first);
			}
			else{
				sum += redp[i].first - redp[i-1].first;
				mx = max(mx,redp[i].first - redp[i-1].first);
				if(first){
					first = 0;
				}
				else{
					sum -= mx;
				}
				mx = 0;
			}
		}
		// cout<<sum<<endl;

		first = 1;
		mx = 0;
		if(blup[0].second == 'G')first = 0;
		for(int i=1;i<blup.size();i++){
			if(blup[i].second == 'B'){
				sum += blup[i].first - blup[i-1].first;
				mx = max(mx,blup[i].first - blup[i-1].first);
			}
			else{
				sum += blup[i].first - blup[i-1].first;
				mx = max(mx,blup[i].first - blup[i-1].first);
				if(first){
					first = 0;
				}
				else{
					sum -= mx;
				}
				mx = 0;
			}
		}
	}
	cout<<sum<<endl;

	return 0;
}
