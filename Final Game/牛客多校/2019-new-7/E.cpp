// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


int X[412345],Y[412345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	int A[3],B[3],C[3],M[3];
	cin >> X[1] >> X[2] >> A[1] >> B[1] >> C[1] >> M[1];
	cin >> Y[1] >> Y[2] >> A[2] >> B[2] >> C[2] >> M[2];
	vector<int> l;
	vector<int> r;
	vector<int> lis;
	l.push_back(min(X[1],Y[1])+1);
	r.push_back(max(X[1],Y[1])+1);
	l.push_back(min(X[2],Y[2])+1);
	r.push_back(max(X[2],Y[2])+1);
	lis.push_back(l[0]);
	lis.push_back(l[1]);
	
	for (int i=3; i<=n; i++){
		X[i] = (A[1]*X[i-1]+B[1]*X[i-1]+C[1])%M[1];
		Y[i] = (A[2]*Y[i-1]+B[2]*Y[i-1]+C[2])%M[2];
		l.push_back(min(X[i],Y[i])+1);
		r.push_back(max(X[i],Y[i])+1);
	}
	return 0;
}
