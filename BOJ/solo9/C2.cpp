#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


int a[512345];
int n;
int sum = 0;
bool vis[512345];	
int front = 0;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum += a[i];
	}
	if(sum % 3 != 0){
		cout<<0<<endl;
		return 0;
	}


	if(sum == 0){
		int eq=0;
		for(int i=0;i<n;i++){
			front += a[i];
			if(front == 0){
				eq++;
			}
		}

		// cout<<eq<<endl;
		if(eq <= 2){
			cout<<0<<endl;
		}else{
			eq--;
			cout<<eq*(eq-1)/2<<endl;
		}
	}
	else{
		int l=0,r=0;
		int index1;
		int index2;

		for(int i=0;i<n-2;i++){
			l += a[i];
			if(l == sum/3){
				index1 = i;
				break;
			}
		}
		// special judge
		if(l > sum/3 ){
			cout<<0<<endl;
			return 0;
		}

		for(int i=n-1;i>index1;i--){
			r += a[i];
			if(r == sum/3){
				index2 = i;
				break;
			}
		}
		// special judge
		if(r > sum/3){
			cout<<0<<endl;
			return 0;
		}
		// cout<<"--"<<endl;

		int way1,way2;
		way1 = way2 = 1;

		int t = 0;
		for(int i=index1+1;i<index2-1;i++){
			t += a[i];
			if(t == 0){
				vis[i] = 1;
				for(int j=i-1;j>=0;j--){
					if(vis[j]!=1)vis[j]=1;
					else break;
				}
				way1++;
			}
		}

		t = 0;
		int ans = 0;
		bool first = 1;
		for(int i=index2-1;i>index1+1;i--){
			t += a[i];
			if(t == 0){
				way2++;
				if(vis[i] == 1 && first){
					ans += way1*(way2-1);
					first = 0;

					way2 = 1;
					way1--;

					ans += way1*way2;
				}
				else if(vis[i] == 1){
					way1--;
					ans += way1*way2;
				}
			}
		}
		if(first)ans+=way1*way2;
		// cout<<way1*way2<<endl;
		// for(int i=0;i<n;i++)cout<<vis[i]<<' ';cout<<endl;
		cout<<ans<<endl;
		// cout<<"--"<<endl;
	}
	return 0;
}
