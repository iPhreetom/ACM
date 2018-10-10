#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

string s;
int a,b;
vector<int> pre;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	// vector<int> aa = {1,2,3};
	// for (int i=0; i<123123123; i++){
	//     if(lower_bound(aa.begin(),aa.end(),i) == aa.end()){
	// 		break;
	// 	}
	// 	cout<<lower_bound(aa.begin(),aa.end(),i) - aa.begin()  <<endl;
	// }
	// return 0;
	//
	getline(cin,s);
	cin>>a>>b;

	for (int i=0; i<s.size(); i++){
		if(s[i] == ' '){
			pre.push_back(i+2);
		}
	}
	pre.push_back(s.size()+1);

	cout<<s<<endl;
	for (int i=0; i<s.size(); i++){
	    cout<<i%10;
	}cout<<endl;

	for(int len = a;len <= b;len++){

		int tp = len+1;
		int sum = pre[0];

		while(1){

			int p = lower_bound(pre.begin(),pre.end(),tp)-pre.begin();
			if(p == pre.size()){
				break;
			}
			else{
				sum += pre[p+1]-pre[p];
				tp = len + pre[p] + 1;
			}

			cout<<"sum = "<<sum<<endl;
			cout<<"p = "<<p<<endl;
		}
		cout<<sum-1<<endl;

		cout<<endl;
	}
	return 0;
}
