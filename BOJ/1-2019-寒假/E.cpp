// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

map<int,int> left_son;
map<int,int> right_son;
set<int> s;
map<int,int> ans;
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	vector<int> v;
	int n;
	int t;

	cin>>n;
	cin>>t;
	s.insert(t);
	for (int i=2; i<=n; i++){
		cin>>t;
		s.insert(t);
		v.push_back(t);

		auto index = s.find(t);
		auto jndex = s.find(t);


		if ( index == s.begin() ) {

			index++;
			int val = *index;
			if(val > t) {
				if(right_son[val] == 0){
					right_son[val] = t;
					ans[t] = val;
				}
			}
			else {
				if(left_son[val] == 0){
					left_son[val] = t;
					ans[t] = val;
				}
			}
		}
		else {
			index++;
			if(index != s.end()){
				int val = *index;
				if(val > t) {
					if(right_son[val] == 0){
						right_son[val] = t;
						ans[t] = val;
					}
				}
				else {
					if(left_son[val] == 0){
						left_son[val] = t;
						ans[t] = val;
					}
				}
			}

			jndex--;
			int val2 = *jndex;
			if(val2 > t) {
				if(right_son[val2] == 0){
					right_son[val2] = t;
					ans[t] = val2;
				}
			}
			else {
				if(left_son[val2] == 0){
					left_son[val2] = t;
					ans[t] = val2;
				}
			}
		}
	}

	for(auto i:v){
		cout<<ans[i]<<' ';
	}cout<<endl;
	return 0;
}
