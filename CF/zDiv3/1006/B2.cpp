#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,k;
int a[212345];
map<int,int> mp;
int last;
vector<int> ans;
set<int> s;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>k;

	for(int i=0;i<n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}

	int cnt = k;
	int chongfu = 0;
	int val = 0;

	for(auto i = mp.rbegin();cnt && i!=mp.rend();i++){
		s.insert(i->first);
		if(i->second < cnt){
			cnt -= i->second;
		}
		else{
			chongfu = i->second-cnt;
			val = i->first;
			cnt = 0;
		}
	}

	int c = 0;
	int sum = 0;
	int mx = 0;
	for(int i=0;i<n;i++){
		if(chongfu){
			c++;
			mx = max(mx,a[i]);
			if(s.count(a[i]) != 0){
				if(a[i] == val){
					chongfu--;
				}
				else{
					ans.push_back(c);
					sum += mx;
					mx = 0;
					c = 0;
				}
			}
		}
		else{
			c++;
			mx = max(mx,a[i]);
			if(s.count(a[i]) != 0){
				ans.push_back(c);
				sum += mx;

				mx = 0;
				c = 0;
			}
		}
	}
	cout<<sum<<endl;

	for(int i=0;i<ans.size();i++){
		if(i == ans.size()-1){
			cout<<n<<endl;
		}
		else{
			cout<<ans[i]<<' ';
			n-=ans[i];
		}
	}
	return 0;
}
