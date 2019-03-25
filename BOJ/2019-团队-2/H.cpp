// fyt
#include<bits/stdc++.h>
#define int unsigned long long
#define double long double
#define endl '\n'
using namespace std;

map<int,int> mp;

void get_case(int a ,int b) {
	// one : a
	// zero: b
	a = a-b;
	bool odd = 1;
	int val = 1;
	int cnt = a+b;

	for (int i=1; i<=a-1; i++){
		val <<= 1;
		val += 1;
	}
	val <<= b;
	mp[val] = 1;


	while (1) {
		if (odd) {
			cnt += a;
			if(cnt > 63) {
				break;
			}
			for (int i=1; i<=a; i++){
				val <<= 1;
				val += 1;
			}
		}
		else {
			cnt += b;
			if(cnt > 63) {
				break;
			}
			val <<= b;
		}
		// if(a == 1 && b==1) {
		// 	cout<<"val = "<<val<<endl;
		// }
		mp[val] = 1;
		odd = !odd;
	}
}
void get_num() {
	get_case(1, 0);
	for (int i=2; i<=63; i++){
		for (int j = 1; j <= i-1; j++) {
			get_case(i, j);
		}
	}
}
void update_num() {
	int cnt = 0;
	for (auto &i : mp) {
		i.second = ++cnt;
	}
}

void create_all() {
	for (int i=1; i<=63; i++){
		for (int j=1; j<=i; j++){

		}
	}
}

void query() {
	int a,b;
	cin >> a >> b;
	if (a == 0) {
		if(b == 0) {
			cout << 0 << endl;
		}
		else {
			if(mp.count(b) == 0) {
				mp[b] = 0;
				auto index = mp.lower_bound(b);
				index--;
				cout << index->second << endl;
			}
			else {
				cout << mp[b] << endl;
			}
		}
	}
	else {
		int mx;
		int mn;

		if(mp.count(b) == 0) {
			mp[b] = 0;
			auto index = mp.lower_bound(b);
			index--;
			mx = index->second;
			mp.erase(b);
		}
		else {
			mx = mp[b];
		}

		if(mp.count(a) == 0) {
			mp[a] = 0;
			auto index = mp.lower_bound(a);
			index++;
			mn = index->second;
		}
		else {
			mn = mp[a];
		}

		if(mx >= mn) {
			cout << mx - mn + 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
}
void query2() {
	int a,b;
	cin >> a >> b;
	if(a==0) {
		if(b==0){
			cout << 0 << endl;
		}
		else {
			auto j = mp.begin();
			for(auto i : mp){
				if(i.first == b){
					cout << i.second << endl;
					return ;
				}
				else {
					if(i.first > b){
						cout << j->second << endl;
						return ;
					}
				}
				j++;
			}
		}
	}
	else {
		int mn , mx;

		auto j = mp.begin();
		bool ok = 1;
		for(auto i : mp){
			if(i.first == b){
				mx = i.second;
				break;
			}
			else {
				if(i.first > b) {
					mx = j->second;
					break;
				}
			}
			if(ok){
				ok = !ok;
			}
			else {
				j++;
			}
		}

		for(auto i:mp) {
			if(i.first == a){
				mn = i.second;
				break;
			}
			else {
				if(i.first > a) {
					// cout<<"i.first = "<<i.first<<endl;
					mn = i.second;
					break;
				}
			}
		}

		if(mx >= mn) {
			cout << mx - mn +1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	// int a = 1;
	// a <<= 63;
	// cout<<"a = "<<a<<endl;
	// 9223372036854775808
	get_num();
	update_num();
	// create_all();
	// for(auto i:mp){
	// 	cout << i.first << endl;
	// 	string ans;
	// 	int t = i.first;
	// 	while(t>0){
	// 		if(t&1){
	// 			ans.push_back('1');
	// 		}
	// 		else {
	// 			ans.push_back('0');
	// 		}
	// 		t>>=1;
	// 	}
	// 	reverse(ans.begin(),ans.end());
	// 	cout<<ans<<endl;
	// }
	// cout<<"mp.size() = "<<mp.size()<<endl;
	// 3497

	query2();
	return 0;
}
