// 小小错误 与 心理影响
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll o1,o2;
ll t1,t2;
ll th1,th2;
ll f1,f2;
ll m1,m2;
ll s1,s2;
ll l1,l2;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	ll n;
	cin>>n;

	for(int i=0;i<n;i++){
		string t;
		cin>>t;
		if(t.size() == 1){
			if(t == "M")m1++;
			if(t == "S")s1++;
			if(t == "L")l1++;
		}
		if(t.size() == 2){
			if(t == "XS")t1++;
			if(t == "XL")t1--;
		}
		if(t.size() == 3){
			if(t == "XXS")th1++;
			if(t == "XXL")th1--;
		}
		if(t.size() == 4){
			if(t == "XXXS")f1++;
			if(t == "XXXL")f1--;
		}
	}
	for(int i=0;i<n;i++){
		string t;
		cin>>t;
		if(t.size() == 1){
			if(t == "M")m2++;
			if(t == "S")s2++;
			if(t == "L")l2++;
		}
		if(t.size() == 2){
			if(t == "XS")t2++;
			if(t == "XL")t2--;
		}
		if(t.size() == 3){
			if(t == "XXS")th2++;
			if(t == "XXL")th2--;
		}
		if(t.size() == 4){
			if(t == "XXXS")f2++;
			if(t == "XXXL")f2--;
		}
	}

	ll ans = (abs(l1-l2)+abs(s2-s1)+abs(m1-m2))/2 + abs(t1-t2)/2 + abs(th1-th2)/2 + abs(f1-f2)/2;
	cout<<ans<<endl;
	return 0;
}
