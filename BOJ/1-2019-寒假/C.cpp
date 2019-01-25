// fyt

// anthoer solution
	// digit .
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

set<int> s;
int w,k;

void test() {
	set<int> s;
	s.insert(4);
	for (int i=2; i<=6; i++){
		int val = pow(w,i);
		queue<int> que;
		for(auto i: s) {
			que.push(val);
			que.push(val+i);
			que.push(val-i);
		}
		if(val > 1e9) {
			break;
		}
		while(!que.empty()){
			s.insert(que.front());
			que.pop();
		}
		cout<<s.size()<<endl;
	}
	for(auto i:s){
		cout<<i<<endl;
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> w >> k;
	int tp = 2e9+1;
	if(w == 2 || w == 3 || k == 1){
		cout<<"YES"<<endl;
		return 0;
	}

	// s.insert(1);
	if(w == 4) {
		s.insert(16);

		for (int i=3; i<=20; i++){
			int val = pow(w,i);
			queue<int> que;
			for(auto i: s) {
				if(val <= 1e9){
					que.push(val);
					que.push(val+i);
					que.push(val-i);
				}
				else{
					if(val - i <= 1e9){
						que.push(val-i);
					}
				}
			}
			while(!que.empty()){
				s.insert(que.front());
				que.pop();
			}
			if(val > 1e9) {
				break;
			}
			cout<<s.size()<<endl;
		}

		if(s.count(k) != 0) {
			cout<<"YES"<<endl;
		}
		else if(s.count(k+1) != 0) {
			cout<<"YES"<<endl;
		}
		else if(s.count(k-1) != 0) {
			cout<<"YES"<<endl;
		}
		else if(s.count(k+4) != 0) {
			cout<<"YES"<<endl;
		}
		else if(s.count(k-4) != 0) {
			cout<<"YES"<<endl;
		}
		else if(s.count(k+3) != 0) {
			cout<<"YES"<<endl;
		}
		else if(s.count(k+5) != 0) {
			cout<<"YES"<<endl;
		}
		else if(s.count(k-5) != 0) {
			cout<<"YES"<<endl;
		}
		else if(s.count(k-3) != 0) {
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	else{
		s.insert(w);
		for (int i=2; i<=100; i++){
			int val = pow(w,i);
			queue<int> que;
			for(auto i: s) {
				que.push(val);
				que.push(val+i);
				que.push(val-i);
			}
			while(!que.empty()){
				s.insert(que.front());
				que.pop();
			}
			if(val > 1e9) {
				break;
			}
		}
		if(s.count(k) != 0) {
			cout<<"YES"<<endl;
		}
		else if(s.count(k+1) != 0) {
			cout<<"YES"<<endl;
		}
		else if(s.count(k-1) != 0) {
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}

	// int mx = 0;
	// for(auto i:s){
	// 	mx = max(mx,i);
	// }
	// cout<<"mx = "<<mx<<endl;
	// for(auto i:s){
	// 	cout<<i<<endl;
	// }



	return 0;
}
// 1 4 16
// 3 5
