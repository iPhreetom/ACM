#include<bits/stdc++.h>
#define double long double
using namespace std;



int n,x;
multiset<int> a;
multiset<int> b;
multiset<int> c;
int arr[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>x;
	int ok = 0;

	for(int i=0;i<n;i++){
		int t;
		cin>>arr[i];
		t=arr[i];
		if(a.count(t) != 0){
			ok = 1;
		}
		a.insert(t);
	}

	if(ok != 0){
		cout<<"0"<<endl;
		return 0;
	}

	bool three = 0;
	for(int i=0;i<n;i++){
		if((arr[i]&x) == arr[i]){
			if(a.count(arr[i]&x) >= 2){
				ok = 2;
			}
		}
		else if(a.count(arr[i]&x) != 0){
			ok = 2;
		}
		if(b.count(arr[i]&x) != 0)three = 1;
		b.insert(arr[i]&x);
	}

	if(ok == 2){
		cout<<1<<endl;
		return 0;
	}
	if(three){
		cout<<2<<endl;
		return 0;
	}
	cout<<-1<<endl;
	return 0;
}
