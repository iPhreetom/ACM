#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

vector<int> p;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int q;
	cin>>q;
	
	string s,t;
	cin>>s>>t;
	string c1,c2;
	c1 = s;
	c2 = t;
	sort(c1.begin(),c1.end());
	sort(c2.begin(),c2.end());

	if(c1 != c2){
		cout<<-1<<endl;
		return 0;
	}

	int index = 0;
	int cnt = 0;
	while(s != t){
		for(int i=0;i<t.size();i++){
			for(int j=i;j<t.size();j++){
				if(s[j] == t[i]){
					if(i != j){
						int l = i;
						int r = j;
						while(t[l] != s[l]){
							cnt++;
							swap(s[r-1],s[r]);
							p.push_back(r);
							r--;
						}
					}
					break;
				}
			}
		}
	}
	cout<<cnt<<endl;
	for(int i : p)cout<<i<<' ';cout<<endl;
	return 0;
}
