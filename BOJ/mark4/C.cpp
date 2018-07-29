// 简单题是快速思考，快速实现的地方，思路越是清晰，写的越快

#include<bits/stdc++.h>
using namespace std;

int ans[26];
int index[26];
int book[26];
int first[26];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a;
	cin>>a;
	for(int i=0;i<26;i++){
		ans[i] = 9999999;
	}
	for(int i=0;i<a.size();i++){
			if(book[a[i]-'a']==0){
				book[a[i]-'a'] = 1;
				ans[a[i]-'a'] = max(i-index[a[i]-'a']+1,(int)(a.size()-i));
				index[a[i]-'a'] = i;
				first[a[i]-'a'] = i+1;
			}
		else{
			ans[a[i]-'a'] = max(max(first[a[i]-'a'],i-index[a[i]-'a']),(int)(a.size()-i));
			first[a[i]-'a'] = max(first[a[i]-'a'],i-index[a[i]-'a']);
			index[a[i]-'a'] = i;
		}
		// ans[a[i]-'a'] = max(min(ans[a[i]-'a'],i-index[a[i]-'a']+1),(int)(a.size()-i));
		//
		// index[a[i]-'a'] = i;
	}
	int res = 99999999;
	for(int i=0;i<26;i++){
		if(ans[i]!=9999999){
			// cout<<ans[i]<<endl;
			res = min(res,ans[i]);
		}
	}
	cout<<res<<endl;

	return 0;
}
