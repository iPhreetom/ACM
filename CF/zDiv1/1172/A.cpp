// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<int> v;
vector<int> que;
int n;

bool check(int mid) {
	// insert mid's zero
	vector<int> book(n+1,0);
	for (int i=0; i<n; i++) {
		book[v[i]]++;
	}

	int cnt = 1;
	int index = 0;
	for (int i=0; i<mid; i++) {
		book [que[i]] ++;
		index++;
	}
	for (int i=0; i<n; i++) {
		if (book[cnt] != 0) {
			if(index<n)book[que[index]]++;
			index++;
			cnt++;
		}
		else {
			return false;
		}
	}
	return true;
}

bool try_it(int mid) {
	vector<int> book(n+1,0);
	for (int i=0; i<n; i++) {
		book[v[i]]++;
	}

	int cnt = mid+1;
	int index = 0;

	for (int i=0; i<n-mid; i++) {
		// cout<<"i = "<<i<<endl;
		if (book[cnt] != 0) {
			if (index<n) book[que[index]]++;
			index++;
			cnt++;
		}
		else {
			return false;
		}
	}
	// cout<<"mid = "<<mid<<endl;
	return true;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i=0; i<n; i++){
		int t;
		cin >> t;
		v.push_back(t);
	}
	for (int i=0; i<n; i++) {
		int t;
		cin >> t;
		que.push_back(t);
	}
	int cnt = 0;
	int lt = 0;
	int rt = n;

	bool flag = false;
	for (int i=n-1; i>=0; i--){
		if (que[i] == 1) {
			flag = true;
		}
		if (i == n-1 && que[i]!=0) {
			continue;
		}
		else if(que[i] != que[i+1]-1) {
			break;
		}
	}
	if (flag) {
		if (try_it(que.back())) {
			cout << n-que.back() << endl;
			return 0;
		}
	}

	while (lt+1 < rt) {
		int mid = lt+(rt-lt)/2;
		if (check(mid)) rt = mid;
		else lt = mid;
	}
	if (check(lt)) {
		cout << lt + n << endl;
	}
	else {
		cout << rt + n << endl;
	}
	return 0;
}
