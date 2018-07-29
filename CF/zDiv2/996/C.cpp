#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

int n,k;
int mp[55][55];
vector<int> p;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;

	bool all = 1;

	for(int i=1;i<=4;i++){
		for(int j=1;j<=n;j++){
			cin>>mp[i][j];
			if(i == 2){
				if(mp[i][j]==mp[i-1][j])all=0;
			}
			if(i == 4){
				if(mp[i][j]==mp[i-1][j])all=0;
			}
		}
	}

	if(all && k == 2*n){
		cout<<-1<<endl;
		return 0;
	}

	int ans  = 0;
	int f = 0;

	while(f != k){

		// cout<<endl;
		// for(int i=1;i<=4;i++){
		// 	for(int j=1;j<=n;j++){
		// 		cout<<mp[i][j]<<' ';
		// 	}cout<<endl;
		// }

		// 2
		int i = 2,j;
		for(int j=1;j<n;j++){
			if(mp[i][j]!=0){
				if(mp[i][j] == mp[i-1][j]){
					ans++;
					f++;
					p.push_back(mp[i][j]);
					p.push_back(i-1);
					p.push_back(j);
					mp[i][j]=0;
				}
				else{
					if(mp[i][j+1] == 0){
						ans++;
						p.push_back(mp[i][j]);
						p.push_back(i);
						p.push_back(j+1);
						mp[i][j+1]=mp[i][j];
						mp[i][j]=0;
					}
				}
			}
		}

		// 2 - end
		i=2,j=n;
		if(mp[i][j] != 0){
			if(mp[i][j] == mp[i-1][j]){
				ans++;
				f++;
				p.push_back(mp[i][j]);
				p.push_back(i-1);
				p.push_back(j);
				mp[i][j]=0;
			}
			else{
				if(mp[i+1][j] == 0){
					ans++;
					p.push_back(mp[i][j]);
					p.push_back(i+1);
					p.push_back(j);
					mp[i+1][j]=mp[i][j];
					mp[i][j]=0;
				}
			}
		}

		// 3
		i = 3,j;
		for(int j=n;j>1;j--){
			if(mp[i][j]!=0){
				if(mp[i][j] == mp[i+1][j]){
					ans++;
					f++;
					p.push_back(mp[i][j]);
					p.push_back(i+1);
					p.push_back(j);
					mp[i][j]=0;
				}
				else{
					if(mp[i][j-1] == 0){
						ans++;
						p.push_back(mp[i][j]);
						p.push_back(i);
						p.push_back(j-1);
						mp[i][j-1]=mp[i][j];
						mp[i][j]=0;
					}
				}
			}
		}

		// 3 - end
		i=3,j=1;
		if(mp[i][1] != 0){
			if(mp[i][j] == mp[i+1][j]){
				ans++;
				f++;
				p.push_back(mp[i][j]);
				p.push_back(i+1);
				p.push_back(j);
				mp[i][j]=0;
			}
			else{
				if(mp[i-1][j] == 0){
					ans++;
					p.push_back(mp[i][j]);
					p.push_back(i-1);
					p.push_back(j);
					mp[i-1][j]=mp[i][j];
					mp[i][j]=0;
				}
			}
		}
	}

	cout<<ans<<endl;
	for(int i=0;i<p.size();i+=3){
		cout<<p[i]<<' '<<p[i+1]<<' '<<p[i+2]<<endl;
	}
	return 0;
}
