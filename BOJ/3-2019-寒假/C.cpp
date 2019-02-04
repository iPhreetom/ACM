// fyt
#include<bits/stdc++.h>
#include<unordered_set>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

string s;
string abc;
int k;
set<pair<int,int>> st;

bool bad(int i) {
	if(abc[ s[i]-'a' ] == '0') return 1;
	return 0;
}



signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>s>>abc>>k;

	// int last = -1;
	// for (int i=0; i<s.size(); i++){
	// 	if(bad(i)) {
	// 		cnt ++;
	// 	}
	// 	sub.push_back(s[i]);
	//
	// 	if(cnt > k) {
	// 		for (;;){
	// 			sub.pop_front();
	// 			last++;
	// 			if(bad(last)) {
	// 				cnt--;
	// 				break;
	// 			}
	// 		}
	// 	}
	//
	// 	if(cnt == k) {
	// 		getsub();
	// 	}
	// }

	for (int i=0; i<s.size(); i++){
		int cnt = 0;
		int seed = 1000543273;
		int num = 0;
		int seed2 = 131313131;
		int num2 = 0;
		for (int j=i; j<s.size(); j++){
			if(bad(j))cnt++;
			if(cnt > k)break;

		    num = num*seed + s[j];
			num %= 1304461099;
		    num2 = num2*seed2 + s[j];
			num2 %= 1000000007;
			st.insert(make_pair(num,num2));
		}
	}
	cout<<st.size()<<endl;
	return 0;
}
