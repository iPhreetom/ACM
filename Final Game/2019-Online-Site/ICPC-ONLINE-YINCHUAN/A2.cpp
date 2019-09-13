// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n,p,q,m;
unsigned int sa,sb,sc;
unsigned int rng61() {
	sa ^= sa<<16;
	sa ^= sa>>5;
	sa ^= sa<<1;
	unsigned int t = sa;
	sa = sb;
	sb = sc;
	sc ^= t^sa;
	return sc;
}

unsigned long long ans = 0;
unsigned long long cnt = 0;
stack<unsigned long long> st1,st2;

void PUSH(int v) {
	cnt++;
	st2.push(v);
	if (st1.empty() || v>=st1.top()) {
		st1.push(v);
	}
	ans ^= (st1.top()*cnt);
}

void POP() {
	cnt++;
	if (!st2.empty()) {
		unsigned long long tp = st2.top();
		st2.pop();
		if (st1.top() == tp) st1.pop();
		if (!st1.empty()) {
			ans ^= (cnt*st1.top());
		}
	}
}

void gen() {
	cin >> n >> p >> q >> m >> sa >> sb >> sc;
	for (int i=1; i<=n; i++){
		if (rng61()%(p+q)<p) PUSH(rng61()%m+1);
		else POP();
	}
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	for (int i=1; i<=T; i++) {
		while(!st1.empty())st1.pop();
		while(!st2.empty())st2.pop();
		ans = 0;
		cnt = 0;
		gen();
		cout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}
