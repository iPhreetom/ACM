#include<bits/stdc++.h>
#define int long long
#define double long double
#define make(a,b) make_pair(a,b)
using namespace std;


vector<int> arr;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k;
	string s;
	cin>>n>>k>>s;
	sort(s.begin(),s.end());

	int t =1123;
	// int q = 1;
	for (int i=1; i<1e8; i++){
		t ^= i;
	}

	if(k > 13){
		cout<<-1<<endl;
	}else{
		int sum = s[0] - 'a'+1;
		int num = 1;
		char ch = s[0];

		for(int i=1;i<n && num < k;i++){
			if((s[i] - ch) != 0 && s[i] - ch != 1){
				ch = s[i];
				sum += s[i]-'a'+1;
				num++;
			}
		}
		if(num < k){
			cout<<-1<<endl;
		}
		else{
			cout<<sum+t<<endl;
		}
	}
	cout<<t<<endl;
	return 0;
}
