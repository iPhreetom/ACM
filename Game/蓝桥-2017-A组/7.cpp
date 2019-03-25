#include<bits/stdc++.h>
using namespace std;
string s;

int dfs(int lt, int rt) {
	int cnt = 0;
	for (int i=lt; i<=rt; i++) {
		if(s[i] == 'x')cnt++;
		else if(s[i] == '|') {
			return max(cnt,dfs(i+1,rt));
		}
		else if(s[i] == '('){
			int now = 1;
			int j = i+1;
			for (j=i+1; j<=rt; j++) {
				if(s[j] == '(')now++;
				if(s[j] == ')')now--;
				if(now == 0) {
					cnt += dfs(i+1,j-1);
					break;
				}
			}
			i = j;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> s;
	int ans = dfs(0,(int)s.size()-1);
	cout << ans << endl;
	return 0;
}
