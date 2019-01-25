// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, k;
	cin>>n>>k;

	string name[550];
	int index = 0;
	for (int i=0; i<26; i++){
		for (int j=1; j<=2; j++){
			name[++index].push_back(i+'A');
			name[index].push_back(j+'a');
		}
	}

	index = 1;
	string s;
	vector<string> used;

	cin>>s;
	if(s == "NO") {
		cout<<name[index]<<' ';
		used.push_back(name[index]);
		for (int j=2; j<=k; j++){
			cout<<name[index]<<' ';
			used.push_back(name[index]);
			index++;
		}
	}
	else {
		for (int i=1; i<=k; i++){
			cout<<name[index]<<' ';
			used.push_back(name[index]);
			index++;
		}
	}

	for (int i=k+1; i<=n; i++){
		cin>>s;
		if(s == "NO"){
			cout<<used[i-k]<<' ';
			used.push_back(used[i-k]);
		}
		else{
			cout<<name[index]<<' ';
			used.push_back(name[index]);
			index++;
		}
	}
	return 0;
}
