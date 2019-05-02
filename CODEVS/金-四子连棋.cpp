// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

bool vis[(int)5e7];
bool judge(vector<string> &mp) {
	for (int i=1; i<=4; i++){
	    if((mp[i][1] == mp[i][2]) && (mp[i][3] == mp[i][4]) && (mp[i][1] == mp[i][3])) {
			return true;
		}
	}
	for (int i=1; i<=4; i++){
	    if((mp[1][i] == mp[2][i]) && (mp[3][i] == mp[4][i]) && (mp[1][i] == mp[3][i])) {
			return true;
		}
	}
	if((mp[1][1] == mp[2][2]) && (mp[3][3] == mp[4][4]) && (mp[1][1] == mp[3][3])) {
		return true;
	}
	if((mp[1][4] == mp[2][3]) && (mp[3][2] == mp[4][1]) && (mp[1][3] == mp[3][2])) {
		return true;
	}
	return false;
}
int to_hash(vector<string> &mp) {
	int ret = 0;
	int base = 1;
	for (int i=1; i<=4; i++){
	    for (int j=1; j<=4; j++){
			if(mp[i][j] == 'O'){
				ret += base*0;
			} else if (mp[i][j] == 'B') {
				ret += base*1;
			} else if (mp[i][j] == 'W') {
				ret += base*2;
			}
			base*=3;
	    }
	}
	return ret;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	vector<string> root(5);
	for (int i=1; i<=4; i++){
	    cin >> root[i];
		root[i] = "#"+root[i];
	}

	queue<vector<string> > que1;
	queue<vector<string> > que2;
	bool switcher = 1;
	int cnt = 0;
	que1.push(root);
	while (!que1.empty() || !que2.empty()) {
		if (switcher) {
			while (!que1.empty()) {
				auto &mp = que1.front();
				if (judge(mp)) {
					for (int i=1; i<=4; i++){
					    cout << mp[i] << endl;
					}
					cout << cnt << endl;
					return 0;
				}
				for (int i=1; i<=4; i++){
				    for (int j=1; j<=4; j++){
				        if (mp[i][j] == 'O') {
							int val = 0;
							if(i != 1) {
								// shang
								swap(mp[i][j],mp[i-1][j]);
								val = to_hash(mp);
								if(!vis[val]){
									que2.push(mp);
									vis[val] = 1;
								}
								swap(mp[i][j],mp[i-1][j]);
								// zuo
								if (j != 1) {
									swap(mp[i-1][j-1],mp[i][j]);
									int val = to_hash(mp);
									if(!vis[val]){
										que2.push(mp);
										vis[val] = 1;
									}
									swap(mp[i-1][j-1],mp[i][j]);
								}
								// you
								if (j != 4) {
									swap(mp[i-1][j+1],mp[i][j]);
									val = to_hash(mp);
									if(!vis[val]){
										que2.push(mp);
										vis[val] = 1;
									}
									swap(mp[i-1][j+1],mp[i][j]);
								}
							}
							if(i != 4) {
								// xia
								swap(mp[i+1][j],mp[i][j]);
								val = to_hash(mp);
								if(!vis[val]){
									que2.push(mp);
									vis[val] = 1;
								}
								swap(mp[i+1][j],mp[i][j]);
								// zuo
								if (j != 1) {
									swap(mp[i+1][j-1],mp[i][j]);
									int val = to_hash(mp);
									if(!vis[val]){
										que2.push(mp);
										vis[val] = 1;
									}
									swap(mp[i+1][j-1],mp[i][j]);
								}
								// you
								if (j != 4) {
									swap(mp[i+1][j+1],mp[i][j]);
									val = to_hash(mp);
									if(!vis[val]){
										que2.push(mp);
										vis[val] = 1;
									}
									swap(mp[i+1][j+1],mp[i][j]);
								}
							}
							if (j != 1) {
								swap(mp[i][j-1],mp[i][j]);
								int val = to_hash(mp);
								if(!vis[val]){
									que2.push(mp);
									vis[val] = 1;
								}
								swap(mp[i][j-1],mp[i][j]);
							}
							if (j != 4) {
								swap(mp[i][j+1],mp[i][j]);
								val = to_hash(mp);
								if(!vis[val]){
									que2.push(mp);
									vis[val] = 1;
								}
								swap(mp[i][j+1],mp[i][j]);
							}
						}
				    }
				}
				que1.pop();
			}
		}
		else {
			while (!que2.empty()) {
				auto &mp = que2.front();
				if (judge(mp)) {
					for (int i=1; i<=4; i++){
					    cout << mp[i] << endl;
					}
					cout << cnt << endl;
					return 0;
				}
				for (int i=1; i<=4; i++){
					for (int j=1; j<=4; j++){
						if (mp[i][j] == 'O') {
							int val = 0;
							if(i != 1) {
								// shang
								swap(mp[i][j],mp[i-1][j]);
								val = to_hash(mp);
								if(!vis[val]){
									que1.push(mp);
									vis[val] = 1;
								}
								swap(mp[i][j],mp[i-1][j]);
								// zuo
								if (j != 1) {
									swap(mp[i-1][j-1],mp[i][j]);
									int val = to_hash(mp);
									if(!vis[val]){
										que1.push(mp);
										vis[val] = 1;
									}
									swap(mp[i-1][j-1],mp[i][j]);
								}
								// you
								if (j != 4) {
									swap(mp[i-1][j+1],mp[i][j]);
									val = to_hash(mp);
									if(!vis[val]){
										que1.push(mp);
										vis[val] = 1;
									}
									swap(mp[i-1][j+1],mp[i][j]);
								}
							}
							if(i != 4) {
								// xia
								swap(mp[i+1][j],mp[i][j]);
								val = to_hash(mp);
								if(!vis[val]){
									que1.push(mp);
									vis[val] = 1;
								}
								swap(mp[i+1][j],mp[i][j]);
								// zuo
								if (j != 1) {
									swap(mp[i+1][j-1],mp[i][j]);
									int val = to_hash(mp);
									if(!vis[val]){
										que1.push(mp);
										vis[val] = 1;
									}
									swap(mp[i+1][j-1],mp[i][j]);
								}
								// you
								if (j != 4) {
									swap(mp[i+1][j+1],mp[i][j]);
									val = to_hash(mp);
									if(!vis[val]){
										que1.push(mp);
										vis[val] = 1;
									}
									swap(mp[i+1][j+1],mp[i][j]);
								}
							}
							if (j != 1) {
								swap(mp[i][j-1],mp[i][j]);
								int val = to_hash(mp);
								if(!vis[val]){
									que1.push(mp);
									vis[val] = 1;
								}
								swap(mp[i][j-1],mp[i][j]);
							}
							if (j != 4) {
								swap(mp[i][j+1],mp[i][j]);
								val = to_hash(mp);
								if(!vis[val]){
									que1.push(mp);
									vis[val] = 1;
								}
								swap(mp[i][j+1],mp[i][j]);
							}
						}
					}
				}
				que2.pop();
			}
		}
		cout<<"que1.size() = "<<que1.size()<<endl;
		cout<<"que2.size() = "<<que2.size()<<endl;
		switcher = !switcher;
		cnt++;
	}
	return 0;
}
