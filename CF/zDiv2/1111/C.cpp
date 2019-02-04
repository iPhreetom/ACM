#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,k,a,b;
vector<int> v;
multiset<int> s;

int bitfind(int l,int r) {
	int lt = lower_bound(v.begin(),v.end(),l)-v.begin();
	int rt = upper_bound(v.begin(),v.end(),r)-v.begin();
	// cout<<"l = "<<l<<endl;
	// cout<<"r = "<<r<<endl;
	// cout<<"lt = "<<lt<<endl;
	// cout<<"rt = "<<rt<<endl;
	if(lt == k) {
		return a;
		// no ele in l-r
	}
	else{
		if(v[lt] > r) {
			// no ele in l-r
			return a;
		}
		else {
			if(r > l){
				int mid = (l+r)/2;
				return min(b*(rt-lt)*(r-l+1) , bitfind(l,mid) + bitfind(mid+1,r));
			}
			else { // l==r
				return b*(rt-lt);
			}
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> k >> a >> b;
	for (int i=1; i<=k; i++){
	    int t;
		cin >> t;
		s.insert(t);
		v.push_back(t);
	}
	sort(v.begin(),v.end());

	int ans = bitfind(1,(1ll<<n));
	cout << ans << endl;
	return 0;
}
// 30 6 1 1
// 1 2 3 4 5 6


// vector<int> a;
// a.push_back(4);
// a.push_back(5);
// a.push_back(5);
// a.push_back(5);
// a.push_back(6);
// a.push_back(6);
// a.push_back(6);
// a.push_back(7);
// cout<<"lower_bound(a.begin(),a.end(),)-a.begin() = "<<lower_bound(a.begin(),a.end(),9)-a.begin()<<endl;
// cout<<"ur_bound(a.begin(),a.end(),)-a.begin() = "<<upper_bound(a.begin(),a.end(),9)-a.begin()<<endl;
// cout<<"ur_bound(a.begin(),a.end(),)-a.begin() = "<<upper_bound(a.begin(),a.end(),5)-a.begin()<<endl;
// cout<<"ur_bound(a.begin(),a.end(),)-a.begin() = "<<upper_bound(a.begin(),a.end(),3)-a.begin()<<endl;
