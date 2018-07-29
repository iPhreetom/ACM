#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	// for(int i=2;i<100;i++){
	// 	bool ok = 1;
	// 	for(int j=2;j<=sqrt(i);j++){
	// 		if(i%j == 0)ok=0;
	// 		// if(j == sqrt(i))cout<<i<<" ";
	// 	}
	// 	if(ok)cout<<i<<" ";
	// }
	// return 0;
	// // ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	// vector<string> ans;
	// string s;
	// while(cin>>s){
	// 	ans.push_back(s);
	// }
	//
	// vector<ll> out;
	// for(int i=0;i<ans.size();i++){
	// 	if(ans[i] == "yes"){
	// 		cout<<9<<endl;
	// 		out.push_back(9);
	// 	}
	// 	else{
	// 		cout<<100<<endl;
	// 		out.push_back(100);
	// 	}
	// }
	// cout<<"composite"<<endl;
	// fflush(stdout);
	vector<ll> a = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
					// 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53
	int com=0;

	for(int i=0;i<a.size();i++){
		cout<<a[i]<<endl;
		fflush(stdout);

		string s;
		cin>>s;
		if(s == "yes"){
			if(a[i]*a[i] <= 100){
				cout<<a[i]*a[i]<<endl;
				fflush(stdout);
				cin>>s;
				if(s == "yes"){
					cout<<"composite"<<endl;
					fflush(stdout);
					return 0;
				}
				else{
					com++;
				}
			}
			else{
				com++;
			}
		}
	}
	if(com >= 2){
		cout<<"composite"<<endl;
		fflush(stdout);
	}
	else{
		cout<<"prime"<<endl;
		fflush(stdout);
	}
	return 0;
}
