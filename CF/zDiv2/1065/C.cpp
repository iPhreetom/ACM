// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<int> a;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int k;
	cin>>k;

	for (int i=0; i<n; i++){
		int t;
		cin>>t;
		a.push_back(t);
	}

	for (int i=1; i<a.size(); i++){
		if(a[i-1] != a[i]){
			break;
		}
		else{
			if(i == a.size() - 1){
				cout<<0<<endl;
				return 0;
			}
		}
	}


	sort(a.rbegin(),a.rend());

	int sum = 0;
	int ans = 0;
	int num = 1;
	int last = a[0];

	for (int i=1; i<a.size(); i++){

		int tp = last - a[i];
		tp *= i;

		if(sum + tp >= k || i == a.size()-1){
			int sub = 0;

			for (int j=1; j<=last-a[i]; j++){
				if(j*i > k){
					sub = i*(j-1);
					break;
				}
				if(j == last-a[i]){
					sub = i*j;
				}
			}
			// cout<<"sub = "<<sub<<endl;

			for (int j=1; j<=last-a[i]; j++){
				if(j*i + sum > k){
					tp -= (j-1)*i;
					break;
				}
				if(j == last-a[i]){
					tp -= j*i;
				}
			}

			sum = tp;
			ans++;

			while(sum >= k){
				// cout<<"sum = "<<sum<<endl;
				ans++;
				sum -= sub;
			}
			if(i == a.size()-1){
				if(sum){
					ans++;
				}
			}
		}
		else{
			sum += tp;
		}


		last = a[i];
	}

	cout<<ans<<endl;
	return 0;
}
