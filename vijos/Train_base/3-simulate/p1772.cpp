#include<bits/stdc++.h>
#define int long long
using namespace std;




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int ar[] = {1,2,3,4,5,6,7,8,9};
	while(next_permutation(ar,ar+9)){
		int a,b,c,i=0;
		a = ar[i++]*100 + ar[i++]*10 + ar[i++];
		c = ar[i++]*100 + ar[i++]*10 + ar[i++];
		b = ar[i++]*100 + ar[i++]*10 + ar[i++];
		if(b == a*2 && c == a*3){
			cout<<a<<' '<<b<<' '<<c<<'\n';
		}
	}

	return 0;
}
