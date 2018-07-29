
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

long long l[312345],r[312345],f;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	string a;
	while(n--){
		cin>>a;
		bool ok = 1;
		long long rt=0,lt=0;
		ll cnt=0;

		for(int i=0;i<a.size();i++){
			if(a[i] == '(')lt++;
			else if(lt!=0){
				lt--;
			}
			else{
				ok=0;
				cnt++;
			}
		}

		if(cnt==0 && ok && rt == lt)f++;
		else{
			if(lt==0){
				r[cnt]++;
			}
			else{
				if(cnt==0){
					l[lt]++;
				}
			}
		}
	}
	long long ans =0;
	for(int i=0;i<312345;i++){
		ans += l[i]*r[i];
	}

	ans+=f*f;
	cout<<ans<<endl;
	return 0;
}
