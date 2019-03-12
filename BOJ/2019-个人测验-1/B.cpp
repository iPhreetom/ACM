#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string a,b;
	cin >> a >> b;
	int ans1 = 0;
	int ans2 = 0;
	map<char,int> mpa,mpb;

	for (int i=0; i<a.size(); i++) {
		mpa[a[i]]++;
	}
	for (int i=0; i<b.size(); i++) {
		mpb[b[i]]++;
	}

	int num = a.size();
	for (int i=0; i<a.size(); i++) {
		if(mpb[a[i]] != 0) {
			ans1++;
			mpb[a[i]]--;
			mpa[a[i]]--;
			num--;
		}
		else {
			if(a[i] >= 'a' && a[i] <= 'z') {
				char ch = 'A' + (a[i]-'a');
				if(mpb[ch] > 0 && (mpb[ch]-mpa[ch]) > 0) {
					ans2++;
					mpb[ch]--;
					mpa[a[i]]--;
					num--;
				}
			}
			else {
				char ch = 'a' + (a[i]-'A');
				if(mpb[ch] > 0 && (mpb[ch]-mpa[ch]) > 0) {
					ans2++;
					mpb[ch]--;
					mpa[a[i]]--;
					num--;
				}
			}
		}
	}



	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}
