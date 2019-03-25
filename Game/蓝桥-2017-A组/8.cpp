// 动态规划 + __gcd
#include<bits/stdc++.h>
using namespace std;


// int gcd(int a,int b){
//     if(b == 0) return a;
//     return gcd(b,a%b);
// }

const int len = 11234;
bool vis[len];
int cnt = 0;

int main () {
	int n;
	cin >> n;
	vector<int> v;
	int com = 0;
	for (int i=0; i<n; i++) {
	    int t;
		cin >> t;
		if(com == 0)com = t;
		else com = __gcd(com, t);
		v.push_back(t);
	}

	if(com != 1){
		cout << "INF" << endl;
	}
	else {
		for (int i=0; i<v.size(); i++) {
		    vis[v[i]] = 1;
		}
		for (int i=1; i<len; i++) {
			for (int j=0; j<v.size(); j++) {
				if(i - v[j] > 0 && vis[i-v[j]]) {
					vis[i] = 1;
					break;
				}
			}
		}
		for (int i=1; i<len; i++) {
			if(!vis[i])cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
