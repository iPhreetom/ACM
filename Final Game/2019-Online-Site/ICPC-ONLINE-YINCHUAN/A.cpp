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

int ans = 0;
int cnt = 0;
void PUSH(priority_queue<int> &que, int v) {
	cnt++;
	ans ^= (cnt*v);
	que.push(v);
}

void POP(priority_queue<int> &que) {
	cnt++;
	if (!que.empty()) {
		que.pop();
		if (!que.empty()) ans ^= (que.top()*cnt);
	}
}

void gen(priority_queue<int> &que) {
	cin >> n >> p >> q >> m >> sa >> sb >> sc;
	for (int i=1; i<=n; i++){
		if (rng61()%(p+q)<p)
			PUSH(que,rng61()%m+1);
		else POP(que);
	}
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	for (int i=1; i<=T; i++) {
		priority_queue<int> que;
		ans = 0;
		cnt = 0;
		gen(que);
		cout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}
