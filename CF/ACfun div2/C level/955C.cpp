#include<bits/stdc++.h>
// #include<cstdio>
// #include<cstdlib>
#include<windows.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

vector<ll> num;
set<pll> se;


void init(){
	num.push_back(1);
	for(int i=2;i<=(ll)1e6;i++){
		ll t = i*i;
		if(sqrt(i)*sqrt(i) != i)
		while(t <= ((ll)1e18)/i){
			t*=i;
			num.push_back(t);
		}
		cout<<i<<endl;
	}
	sort(num.begin(),num.end());
	num.erase(unique(num.begin(),num.end()),num.end());
}


void init2(){
	auto t1 = GetTickCount();
	se.insert(make_pair(1,0));
	for(int i=2;i<=(ll)1e6;i++){
		ll t = 1ll*i*i*i;
		if(se.count(make_pair(t,0)) == 0){
			while(t <= ((ll)1e18)/i){
				se.insert(make_pair(t,0));
				t*=i;
			}
			// cout<<i<<endl
			// cout<<se.size()<<endl;
		}
		// auto t2 = GetTickCount();
		// cout<<(t2-t1)*1.0/1000<<endl;
		//
		// if(se.size()>112345){
		// 	cout<<se.size()<<endl;
		// 	cout<<(t2-t1)*1.0/1000<<endl;
		// }
		// if((t2-t1)*1.0/1000 > 1){
		// 	cout<<se.size()<<endl;
		// 	break;
		// }
	}
	ll count=0;
	for(auto i:se){
		i.second = count++;
	}
}

// void test5()
// {
//     DWORD t1,t2;
//     t1 = GetTickCount();
//     // foo();//dosomethisng
// 	for(register ll i=0;i<10000000000;i++);
//     t2 = GetTickCount();
//     printf("Use Time:%fms\n",(t2-t1)*1.0/1000);
// }

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	init2();
	// test5();
	ll q;
	cin>>q;

	while(q--){
		ll l,r;
		cin>>l>>r;
		// cout<<sqrt(r)-sqrt(l-1)+(upper_bound(num.begin(),num.end(),r)-lower_bound(num.begin(),num.end(),l))<<endl;
		cout<<sqrt(r)-sqrt(l-1)+(se.upper_bound(make_pair(r,0))->second-se.lower_bound(make_pair(l,0))->second)<<endl;
	}

	return 0;
}
