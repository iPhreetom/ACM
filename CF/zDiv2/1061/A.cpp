// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

/*------------------------qdd's debugger------------------------*/
#define dbg(x) cerr << #x << " = ", dprint(x), cerr << endl
void dprint(string s) { cerr << '"' << s << '"'; }
template<class T> void dprint(T x) { cerr << x; }
template<class T1, class T2> void dprint(pair<T1, T2> p) { cerr << "("; dprint(p.first); cerr << ", "; dprint(p.second); cerr << ")"; }
template<template<class...> class T, class t> void dprint(T<t> v) { bool first = true; cerr << "{"; for (auto it : v) { if (!first) cerr << ", "; first = false; dprint(it); } cerr << "}"; }
template<class T1, class T2> void dprint(map<T1, T2> v) { bool first = true; cerr << "{"; for (auto it : v) { if (!first) cerr << ", "; first = false; dprint(it); } cerr << "}"; }
template<class T> void dprint(priority_queue<T> q) { cerr << "{"; while (!q.empty()) { dprint(q.top()); cerr << (q.size() > 1 ? ", " : ""); q.pop(); } cerr << "}"; }
template<class T> void dprint(priority_queue<T, vector<T>, greater<T> > q) { cerr << "{"; while (!q.empty()) { dprint(q.top()); cerr << (q.size() > 1 ? ", " : ""); q.pop(); } cerr << "}"; }
template<class T> void dprint(queue<T> q) { cerr << "{"; while (!q.empty()) { dprint(q.front()); cerr << (q.size() > 1 ? ", " : ""); q.pop(); } cerr << "}"; }
template<class T> void dprint(stack<T> q_) { stack<T> q; while (!q_.empty()) { q.push(q_.top()); q_.pop(); } cerr << "{"; while (!q.empty()) { dprint(q.top()); cerr << (q.size() > 1 ? ", " : ""); q.pop(); } cerr << "}"; }
/*------------------------qdd's debugger------------------------*/



signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	cout<<(m+n-1)/n<<endl;
	return 0;
}
