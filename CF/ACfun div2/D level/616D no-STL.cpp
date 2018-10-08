	// fyt

	// 运用 STL 或者 直接使用 桶排序思想   O（N）暴力统计出现次数
	#include<bits/stdc++.h>
	#define int long long
	#define double long double
	#define endl '\n'
	using namespace std;

	int a[512345];
	int num[1123456];
	int sum;

	signed main(){
		ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
		int n,k;
		int mx = 0;
		int p = 1;

		cin>>n>>k;
		for (int i=1; i<=n; i++){
			cin>>a[i];
		}

		int l=1;
		int r=1;
		for (int i=1; i<=n; i++){
			r = i;
			// mp[a[i]]++;
			num[a[i]]++;
			if(num[a[i]] == 1){
				sum++;
			}

			if(sum > k){
				while(sum > k && l < r){
					// mp[a[l]]--;
					num[a[l]]--;
					if(num[a[l]] == 0){
						sum--;
					}
					l++;
				}
			}
			else{
				if(r-l+1 > mx){
					mx = r-l+1;
					p = l;
				}
			}
		}

		cout<<p<<' '<<p+mx-1<<endl;
		return 0;
	}
