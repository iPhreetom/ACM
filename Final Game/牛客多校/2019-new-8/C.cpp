// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<int> ans[1123][5];

int mp[1234][1123];
map<int,int> num;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for (int i=1; i<=10; i++){
		num[pow(2,i)]=i;
	}

	int n;
	cin >> n;
	if (n == 2) {
		cout << "1 1" << endl;
		cout << "1 -1" << endl;
		return 0;
	}

	int sz = n/4;

	int cnt = 0;
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++){
			for (size_t k = 0; k < n/4; k++) {
				if (j == cnt) ans[i][j].push_back(-1);
				else ans[i][j].push_back(1);
			}
		}
		cnt++;
	}

	for (int i=4; i<n; i++) {
		for (int j=0; j<4; j++){
			if (ans[i-4][j][0] == -1) {
				int len = 0;
				for (size_t k = 0; k < ans[i-4][j].size(); k++) {
					if (ans[i-4][j][k] == -1) len++;
				}
				len /= 2;
				while(ans[i][j].size() < ans[i-4][j].size()) {
					for (size_t k = 0; k < len; k++) {
						ans[i][j].push_back(-1);
					}
					for (size_t k = 0; k < len; k++) {
						ans[i][j].push_back(1);
					}
				}
			}
			else {
				int len = 0;
				for (size_t k = 0; k < ans[i-4][j].size(); k++) {
					if (ans[i-4][j][k] == 1) len++;
				}
				len /= 2;
				while(ans[i][j].size() < ans[i-4][j].size()) {
					for (size_t k = 0; k < len; k++) {
						ans[i][j].push_back(1);
					}
					for (size_t k = 0; k < len; k++) {
						ans[i][j].push_back(-1);
					}
				}
			}
		}
	}

	for (int i=0; i<n; i++){
		for (int j=0; j<4; j++){
		    for (size_t k = 0; k < n/4; k++) {
				cout << (ans[i][j][k]==-1?8:ans[i][j][k]) << ((j*n/4+k==n-1)?'\n':' ');
		    }
		}
	}

	for (size_t p = 0; p < n; p++) {
		for (size_t q = p+1; q < n; q++) {
			int sum = 0;
			for (int i=0; i<4; i++){
				for (int j=0; j<n/4; j++){
					sum += ans[p][i][j]*ans[q][i][j];
				}
			}
			if(sum!=0){cout<<"i = "<<p<<endl;cout<<"j = "<<q<<endl;cout<<"sum = "<<sum<<endl;}
		}
	}
	return 0;
}
