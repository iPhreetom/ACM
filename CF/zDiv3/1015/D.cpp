#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

vector<int> p;
int n,k,s;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k>>s;
	if(k > s || (n-1)*k < s){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
		int dis = 0;
		bool one = 0;
		int now = 1;
		for (int i=0; i<k; i++){
			if(i == k-1){
				int mv = s - dis;
				if(mv <= 0){
					dis = 0;
					break;
				}
				if(now + mv <= n){
					p.push_back(now+mv);
				}
				else{
					p.push_back(now-mv);
				}
				dis += mv;
				break;
			}// 特判

			if(s-dis-(n-1) < k-i-1){
				if(!one){
					if(now == n){
						p.push_back(n-(s - dis - (k-i-1)));
						now = (n-(s - dis - (k-i-1)));
					}
					else{// now = 1
						p.push_back((s - dis - (k-i-1))+1);
						now = (s - dis - (k-i-1))+1;
					}
					dis += (s - dis - (k-i-1));
					one = 1;
				}
				else{
					if(now != 1){
						p.push_back(now-1);
						now--;
						dis++;
					}
					else{
						p.push_back(now+1);
						now++;
						dis++;
					}
				}
			}
			else{
				dis += n-1;
				if(now == 1){
					p.push_back(n);
					now = n;
				}
				else{
					p.push_back(1);
					now = 1;
				}
			}


		}
		if(dis != s){
			int tq = 1;
			for (int i=0; i<100000000; i++){
			    tq++;
			}
			cout<<tq<<endl;
		}
		for (int i=0; i<p.size(); i++){
			cout<<p[i]<<' ';
		}cout<<endl;
	}
	return 0;
}
