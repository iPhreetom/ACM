// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


signed main(){
	int T;
	scanf("%d",&T);
	while (T--) {
		int n;
		scanf("%d",&n);
		priority_queue<double> que;
		for (int i=0; i<n; i++){
			double t;
			scanf("%lf",&t);
			que.push(t);
		}
		double ans = que.top();
		long double zero = (1-que.top());
		que.pop();
		while(!que.empty()) {
			double temp = zero*(que.top())+ans*(1-que.top());
			if (temp > ans) {
				zero *= (1-que.top());
				ans = temp;
			}
			que.pop();
		}
		printf("%.9f\n",ans);
	}
	return 0;
}
