// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int l1,r1,t1;
	int l2,r2,t2;
	cin>>l1>>r1>>t1;
	cin>>l2>>r2>>t2;


	int a1,b1,a2,b2;
	a1 = r1-l1+1;
	b1 = (l1+t1-1) - (r1 + 1) + 1;

	a2 = r2-l2+1;
	b2 = (l2+t2-1) - (r2 + 1) + 1;

	int dif = __gcd(a1+b1,a2+b2);
	int ans = 0;


	if(l1 > l2){
		swap(l1,l2);
		swap(r1,r2);
		swap(t1,t2);
		a1 = r1-l1+1;
		b1 = (l1+t1-1) - (r1 + 1) + 1;

		a2 = r2-l2+1;
		b2 = (l2+t2-1) - (r2 + 1) + 1;
	}
	if( (l2-l1) % dif == 0){
		cout<<min(a1,a2)<<endl;
		return 0;
	}

	int move = (l2-l1)/dif;
	l1 += move*dif;

	ans = max(ans , min(a1-(l2-l1),a2));

	l1 += dif;
	ans = max(ans , min(a2-(l1-l2),a1));

	cout<<ans<<endl;

	return 0;
}
