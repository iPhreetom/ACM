// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


int mp[5];
int ans[5];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;

	string a,b;
	cin >> a >> b;


	for (int i=0; i<n; i++){
	    if(a[i] == '1' && b[i] == '1') mp[2]++;
		else if(a[i] == '1' && b[i] == '0') mp[1]++;
		else if(a[i] == '0' && b[i] == '0') mp[0]++;
		else mp[3]++;
	}
	// for (int i=0; i<5; i++){
	//     cout<<mp[i]<<' ';
	// }cout<<endl;



	auto output = [&](){
		int cnt = 0;
		for (int i=0; i<n; i++){
		    if(a[i] == '1' && b[i] == '1' && ans[2] > 0) {
				ans[2] --;
				cout << i+1 << ' ';
			}
			else if(a[i] == '1' && b[i] == '0' && ans[1] > 0) {
				ans[1] --;
				cout << i+1 << ' ';
			}
			else if(a[i] == '0' && b[i] == '0' && ans[0] > 0) {
				ans[0] --;
				cout << i+1 << ' ';
			}
			else if(a[i] == '0' && b[i] == '1' && ans[3] > 0) {
				ans[3] --;
				cout << i+1 << ' ';
			}
		}
		cout << endl;
	};
	for (int i=0; i<= mp[2]; i++){
		for (int j=0; j<= mp[1] && (i+j)<=(n/2); j++){
			for (int k = max(0,(n/2)-(i+j)); k <= mp[0]; k++) {
				int num = i+j+k;
				if(num > n/2)break;
				else {
					int h = n/2 - (i+j+k);
					// cout<<"h = "<<h<<endl;
					// cout<<"mp[3] = "<<mp[3]<<endl;
					if(h > mp[3])continue;
					else {
						int now = i+j;
						int op = (mp[2]-i) + (mp[3]-h);
						// cout<<"now = "<<now<<endl;
						// cout<<"op = "<<op<<endl;
						// cout<<"h = "<<h<<endl;
						if(now == op) {
							ans[2] = i;
							ans[1] = j;
							ans[0] = k;
							ans[3] = h;
							output();
							return 0;
						}
					}
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
