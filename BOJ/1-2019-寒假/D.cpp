// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


vector<int> v;
vector<int> s;
int n, m;


bool check(int timeslimite) {
	int index = 0;
	int target = s[index];
	// cout<<"____"<<endl;

	for (int i=0; i<n; i++){

		int sum = timeslimite;
		int position = v[i];
		bool exist_left = 0;
		int now = 0;

		target = s[index];

		if((index < m) && (position > target)) {
			exist_left = 1;
			if(position - target <= sum) {
				now = (position - target);
				while((index < m) && (position > target)) {
					index++;
					target = s[index];
				}
			}
		}

		if(exist_left) {
			position = v[i];
			target = s[index];

			while(index < m) {
				int distance = abs(target - position);
				int mn = min(2*now + distance, 2*distance + now);
				if(mn <= sum) {
					index++;
					target = s[index];
				}
				else break;
			}
		}
		else{
			position = v[i];
			target = s[index];

			while(index < m) {
				int distance = abs(target - position);
				if(distance <= sum) {
					sum -= distance;
					position = target;
					index++;
					target = s[index];
				}
				else break;
			}
		}
	}

	if(index >= m) {
		return 1;
	}
	else{
		return 0;
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		int h;
		cin>>h;
		v.push_back(h);
	}

	for (int i=1; i<=m; i++){
		int p;
		cin>>p;
		s.push_back(p);
	}

	sort(v.begin(),v.end());
	sort(s.begin(),s.end());

	int l = 0;
	int r = 1e18;
	while(l + 1 < r) {
		int mid = l + (r-l)/2;
		if(check(mid)) r = mid;
		else l = mid;
	}

	if(check(l)) {
		cout<<l<<endl;
	}
	else{
		cout<<r<<endl;
	}
	return 0;
}
