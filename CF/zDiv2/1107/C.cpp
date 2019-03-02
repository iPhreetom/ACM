#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


priority_queue<int> que;
int a[212345];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k;
	cin >> n >> k;
	string s;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	cin >> s;

	int sum = 0;
	que.push(a[0]);
	int index = 1;
	while(index < s.size()) {
		if(s[index]!=s[index-1]){
			for (int i=0; i<k && !que.empty(); i++){
				sum += que.top();
				// cout<<"que.top() = "<<que.top()<<endl;
				que.pop();
			}
			while(!que.empty()){
				// cout<<"que.top() = "<<que.top()<<endl;
				que.pop();
			}
			que.push(a[index]);
		}
		else {
			que.push(a[index]);
		}
		index++;
	}

	for (int i=0; i<k && !que.empty(); i++){
		sum += que.top();
		// cout<<"que.top() = "<<que.top()<<endl;
		que.pop();
	}

	cout << sum << endl;
	return 0;
}
