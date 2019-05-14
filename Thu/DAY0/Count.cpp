#include<iostream>
#include<cstdio>
#define int long long
using namespace std;

int count[26];

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;
	while(cin >> s){
		for (int i=0; i<s.size(); i++) {
			if(isalpha(s[i])){
				count[toupper(s[i]) - 'A'] ++;
			}
		}
	}

	for (int i=0; i<26; i++) {
	    if (count[i]) {
			cout << (char)('A'+i) << ": " << count[i] << endl;
		}
	}
	return 0;
}
