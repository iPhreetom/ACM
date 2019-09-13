// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

inline char getit(int n) {
	if (n < 10) return n+'0';
	else return n-10+'a';
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	int casen = 1;
	while (T--) {
		string s;
		int num[9];
		memset(num,0,sizeof(num));
		string que[9];
		cin >> s;
		for (int i=0; i<s.size(); i+=16){
			for (int j=i; j<i+16; j+=4){
				int val = 0;
				int base = 1;
				for (int k=j+3; k>=j; k--) {
					val += (s[k]-'0')*base;
					base *= 2;
				}
				que[i/16].push_back(getit(val));
			}
		}

		int mx = 0;
		bool pre = 0;
		int cnt = 0;
		for (int i=0; i<9; i++){
		    while(que[i].size() > 1 && *que[i].begin()=='0') {
				que[i].erase(0,1);
			}

			if (que[i].size() == 1 && que[i][0] == '0') {
				if (pre) cnt++;
				else {
					cnt = 1;
					mx = max(mx,cnt);
					pre = 1;
				}
			}
			else {
				if (pre) {
					// cout<<"cnt = "<<cnt<<endl;
					mx = max(cnt,mx);
					for (int j=i-1; j>=i-cnt;j--) {
						num[j] = cnt;
					}
					pre = 0;
					cnt = 0;
				}
			};
		}


		// output
		if (mx < 2) {
			string ans;
			for (int i=0; i<8; i++){
				if (i != 0) ans += ":"+que[i];
				else ans += que[i];
			}
			cout << "Case #" << casen << ": ";
			casen++;
			cout << ans << endl;
		}
		else {
			vector<pair<int,string>> st;
			while (true) {
				bool has = 0;
				int mx = 0;
				for (int i=0; i<8; i++) {
					if (num[i]>=2)has = true;
					mx = max(num[i],mx);
				}
				if(!has){
					break;
				}


				bool vis[9];
				memset(vis,0,sizeof(vis));
				for (int i=7; i>=0; i--){
					if(num[i] == mx) {
						for(int j=i;j>=i-mx+1;j--){
							vis[j] = 1;
							num[j] = 0;
						}
						break;
					}
				}

				string ans;
				bool f = 1;
				bool fv = 1;
				for (int i=0; i<8; i++){
					if (vis[i]) {
						if (fv) {
							ans+="::";
							f = 1;
							fv = 0;
						}
					}
					else {
						if (f) {
							ans+=que[i];
							f = 0;
						}
						else {
							ans+=":"+que[i];
						}
					}
				}
				st.push_back(make_pair(ans.size(),ans));
			}

			sort(st.begin(),st.end());
			cout << "Case #" << casen << ": ";
			casen++;
			cout << st[0].second << endl;
			// cout<<"v.size() = "<<st.size()<<endl;
			// for (int i=0; i<8; i++){
			// 	cout<<que[i]<<' ';
			// }cout<<endl;
			// for (int i=0; i<8; i++){
			// 	cout<<num[i]<<' ';
			// }cout<<endl;
			// for (int i=0; i<8; i++){
			// 	cout<<vis[i]<<' ';
			// }cout<<endl;
		}


	}
	return 0;
}

// 4
// 00001111000011110000111100001111000000000000000000000000000000000000000000000000000000000001111000000000000000000000000000000000
// 11110000000000010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000010010001101000101011001111000100110101011000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000010010001100000000000000000000000000000000000000000000000001000101011001111000100110101011
// 2:2:0:0
// 2:2::
//
// 2:0:0:2
// 2::2
