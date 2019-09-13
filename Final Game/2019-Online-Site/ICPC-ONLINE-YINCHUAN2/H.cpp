// fyt
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <climits>
#include <cstdio>
#include <complex>
#include <numeric>
#include <cassert>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxn = 1112345;
int val[maxn];
int dp[maxn];
int nt[maxn][26];
int n;
string s;

int dfs(int index) {
	if (index == -1) return 0;
	if (dp[index] != -1) return dp[index];

	int mn = 1e18;
	if (s[index] == 'w') {
		mn = min(mn,dfs(nt[index+1]['r'-'a']));
	}
	else if(s[index] == 'r') {
		mn = min(mn,dfs(nt[index+1]['o'-'a']));
	}
	else if(s[index] == 'o') {
		mn = min(mn,dfs(nt[index+1]['n'-'a']));
	}
	else if(s[index] == 'n') {
		mn = min(mn,dfs(nt[index+1]['g'-'a']));
	}
	mn = min(mn,val[index] + dfs(nt[index+1][s[index]-'a']));
	dp[index] = mn;
	return mn;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> s;
	for (int i=0; i<n; i++){
		cin >> val[i];
	}


	for (int i=0; i<n; i++){
		dp[i] = -1;
	}
	for (int i=0; i<26; i++){
		nt[s.size()][i] = -1;
	}

	int sum = 0;
	for (int i=s.size()-1; i>=0; i--) {
		if (s[i] == 'g') {
			sum += val[i];
			dp[i] = sum;
		}

		for (int j=0; j<26; j++){
		    nt[i][j] = nt[i+1][j];
		}
		nt[i][s[i]-'a'] = i;
	}

	if (nt[0]['w'-'a'] == -1) {
		cout << 0 << endl;
	}
	else {
		cout << dfs(nt[0]['w'-'a']) << endl;
	}

	return 0;
}
