#include<bits/stdc++.h>
#define int long long
#define double long double
#define make(a,b) make_pair(a,b)
using namespace std;


vector<int> arr;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int m,n;
	cin>>m>>n;

	int answer = 1;
	while(answer != 0){
		for(int i=0;i<n;i++){
			cout<<1<<endl;
			fflush(stdout);
			cin>>answer;

			if(answer == 0){
				return 0;
			}
			arr.push_back(answer);
			// cout<<i<<' '<<n<<endl;
		}

		int l = 2;
		int r = m+1;
		int index = 0;

		while(l+1<r){
			int mid = l+(r-l)/2;
			cout<<mid<<endl;
			fflush(stdout);
			cin>>answer;

			if(answer == 0){
				return 0;
			}

			if(answer == 1){
				if(arr[index] == 1){
					l = mid;
				}
				else{
					r = mid;
				}
			}
			else{
				if(arr[index] == 1){
					r = mid;
				}
				else{
					l = mid;
				}
			}
			index++;
			if(index == n)index=0;
		}	
	}
	return 0;
}
