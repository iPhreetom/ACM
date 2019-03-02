#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

vector<int> v;
int cnt[1123456];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k,m;
	cin >> n >> k >> m;

	int sum = 0;
	for (int i=1; i<=n; i++){
		int t;
		cin >> t;
		v.push_back(t);
		sum += t;
	}
	double ans = (double)sum/n;
	sort(v.rbegin(),v.rend());
	int index = 0;

	while(m > 0) {
		if(v.size() == 1) {
			if(cnt[0] < k){
				v[0] ++;
				cnt[0] ++;
				sum ++;
			}
			else break;
		}
		else {
			double up = sum;
			double down = v.size();
			if(cnt[index] == k){
				++index;
			}
			if(index >= v.size()){
				break;
			}
			double now = (up+1)/down;
			double now2 = (up-v.back())/(down-1);
			cout<<"now = "<<now<<endl;
			cout<<"now2 = "<<now2<<endl;
			if(now > now2) {
				cnt[index]++;
				v[index]++;
				sum++;
			}
			else {
				sum -= v.back();
				v.pop_back();
			}
		}
		m--;
	}
	double up = sum;
	double down = v.size();
	cout << fixed << setprecision(12) << up/down << endl;

	return 0;
}
