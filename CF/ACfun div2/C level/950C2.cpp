// CF 950C 0 and 1

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

vector<vector<ll> > ans(212345);
ll index = 0;
set<ll> zero;
set<ll> one;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string a;
	cin>>a;

	for(int i=0;i<a.size();i++){
		if(a[i]=='1')one.insert(i+1);
		else zero.insert(i+1);
	}

	while(!one.empty() && !zero.empty()){
		auto i = zero.begin();
		auto j = one.begin();

		while(true){
			j = one.upper_bound(*i);

			if(j == one.end()){
				ans[index++].push_back(*i);
				zero.erase(i);
				break;
			}
			else{
				ans[index].push_back(*i);
				zero.erase(i);

				i = zero.upper_bound(*j);

				ans[index].push_back(*j);
				one.erase(j);

				if(i == zero.end()){
					cout<<-1<<endl;
					return 0;
				}
			}
		}
	}
	if(!one.empty()){
		cout<<-1<<endl;
		return 0;
	}
	else{
		if(!zero.empty()){
			for(auto i:zero){
				ans[index++].push_back(i);
			}
		}

		cout<<index<<endl;
		for(int i=0;i<index;i++){
			cout<<ans[i].size()<<' ';
			for(int j=0;j<ans[i].size();j++){
				cout<<ans[i][j]<<' ';
			}
			cout<<endl;
		}
	}
	return 0;
}
