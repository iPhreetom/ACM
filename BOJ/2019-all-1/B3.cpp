// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,x,y;
	cin >> n >> x >> y;
	for (int i=0; i<n; i++){
		int val;
		cin >> val;
		int lt = 0;
		int rt = 1e18;
		while(lt<rt){
			int mid = (lt+rt)/2;
			int cntx = mid/y;
			int cnty = mid/x;
			if (cntx+cnty>=val) rt=mid;
			else lt=mid+1;
		}
		int cntx = lt%y;
		int cnty = lt%x;
		if (!cntx && !cnty) cout << "Both" << endl;
		else if (!cntx) cout << "Vanya" << endl;
		else cout << "Vova" << endl;
	}
	return 0;
}
