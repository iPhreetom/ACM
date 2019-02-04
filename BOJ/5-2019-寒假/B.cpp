#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int h, k;
	cin >> h >> k;

	int tp = k;
	int sum = 0;

	int cnt = 0;
	int last = tp%2;

	tp = (tp+1)/2;


	while(cnt < h) {
		// cout<<"tp = "<<tp<<endl;
		// cout<<"last = "<<last<<endl;
		if(cnt == h-1) {
			// cout<<"??"<<endl;
			if(last == 0){
				sum += pow(2,cnt+1)-1;
			}
			sum++;
			break;
		}

		if(tp % 2 == 0){// right
			if(last == 0){
				sum += pow(2,cnt+1)-1;
			}
		}
		else{// left
			if(last == 1){
				sum += pow(2,cnt+1)-1;
			}
		}
		cnt++;
		sum++;
		last = tp % 2;
		tp = (tp+1)/2;
	}
	cout<<sum<<endl;
	return 0;
}
