#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	string s;
	string ans;
	int cnt = 0;



	cin>>n;
	cin>>s;
	s = '^' + s;

	s.push_back('#');
	s.push_back('%');

	for (int i=1; i<s.size()-2; i++){
		if(s[i+1] == s[i]) {
			cnt++;
			if(s[i+1] == s[i+2]) {
				// ans.push_back(s[i]);
				if(s[i+1] == 'R') {
					// ans.push_back('G');
					s[i+1] = 'G';
				}
				else if(s[i+1] == 'B') {
					// ans.push_back('G');
					s[i+1] = 'G';
				}
				else if(s[i+1] == 'G') {
					// ans.push_back('R');
					s[i+1] = 'R';
				}
				i++;
			}
			else{
				if(s[i+1] == 'R') {
					if(s[i-1] == 'G') {
						// ans.push_back('B');
						s[i] = 'B';
					}
					else{
						// ans.push_back('G');
						s[i] = 'G';
					}
				}
				else if(s[i+1] == 'B') {
					if(s[i-1] == 'G') {
						// ans.push_back('R');
						s[i] = 'R';
					}
					else{
						// ans.push_back('G');
						s[i] = 'G';
					}
				}
				else if(s[i+1] == 'G') {
					if(s[i-1] == 'B') {
						// ans.push_back('R');
						s[i] = 'R';
					}
					else{
						// ans.push_back('B');
						s[i] = 'B';
					}
				}
			}
		}
		else {
			// ans.push_back(s[i]);
		}
	}

	cout<<cnt<<endl;
	// cout<<ans<<endl;
	cout<<s.substr(1,n)<<endl;
	return 0;
}
