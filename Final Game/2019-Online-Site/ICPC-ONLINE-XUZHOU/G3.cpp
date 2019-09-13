// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

// "aba" => "#a#b#a#"
string make(string& s) {
    string t = "#";
    for (int i = 0; i < s.size(); i++) {
        t.push_back(s[i]);
        t.push_back('#');
    }
    return t;
}

void manacher(string& s, vector<int>& d) {
    int n = s.size();
    d.resize(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d[l + r - i], r - i);
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
        d[i] = --k;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
}

int pre[712345][27];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;
	cin >> s;

	vector<int> len;
	string ns = make(s);
	manacher(ns,len);

	for (int i=0; i<27; i++){
		pre[0][i] = -1;
	}

	for (int i=1; i<ns.size(); i++){
		for (int j=0; j<26; j++){
			pre[i][j] = pre[i-1][j];
		}
		if (i%2 == 1) {
			int index = (i-1)/2;
			pre[i][s[index]-'a'] = i;
		}
	}

	int ans = 0;
	for (int i=1; i<ns.size(); i++){
		if (i%2 == 0) {
			int leftpoint = i - (len[i]/2) - (len[i]/2-1);
			for (int j=0; j<26; j++) {
				if (pre[i][j] != -1) {
					int lt = pre[i][j];

				}
			}
		}

		if(i%2 == 1){

		}
	}
	return 0;
}
