#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

string s,t;
int one = 0;
int zero = 0;
int ans = 0;
int hs[1123456][2];
int prebs[1123456][2];
int mod[2] = {2333333333,2333333357};
int bs[2] =  {1313131313,1331131133};

void count_number(){
	for (int i=0; i<s.size(); i++){
		if(s[i] == '0'){
			zero++;
		}
	}
	one = s.size() - zero;
}
void getHush(){
	hs[0][0] = hs[0][1] = 0;
	for (int i=1; i<=t.size(); i++){
		for (int j=0; j<2; j++){
		    hs[i][j] = (hs[i-1][j]*bs[j] + (t[i-1]-'0'+1))%mod[j];
		}
	}

	prebs[0][0] = prebs[0][1] = 1;
	for (int i=1; i<1123456; i++){
		for (int j=0; j<2; j++){
			prebs[i][j] = (prebs[i-1][j]*bs[j])%mod[j];
		}
	}
}
void check(int len1,int len2){
	int l = 0;
	int hash1[2] = {-1,-1};
	int hash2[2] = {-1,-1};
	bool can = 1;
	for (int i=0; i<s.size(); i++){
		if(s[i] == '1'){
			if(hash1[0] == -1){
				for (int j=0; j<2; j++){
					hash1[j] =	((hs[l+len1][j] - hs[l][j]*prebs[len1][j]%mod[j])%mod[j] + mod[j])%mod[j];
				}
			}
			else{
				int now[2];
				for (int j=0; j<2; j++){
					now[j] = ((hs[l+len1][j] - hs[l][j]*prebs[len1][j]%mod[j])%mod[j] + mod[j])%mod[j];
					if(now[j] != hash1[j]){
						can = 0;
						break;
					}
				}
			}
			l += len1;
		}
		else{
			if(hash2[0] == -1){
				for (int j=0; j<2; j++){
					hash2[j] =	((hs[l+len2][j] - hs[l][j]*prebs[len2][j]%mod[j])%mod[j] + mod[j])%mod[j];
				}
			}
			else{
				int now[2];
				for (int j=0; j<2; j++){
					now[j] = ((hs[l+len2][j] - hs[l][j]*prebs[len2][j]%mod[j])%mod[j] + mod[j])%mod[j];
					if(now[j] != hash2[j]){
						can = 0;
						break;
					}
				}
			}
			l += len2;
		}
	}

	if(hash1[0] == hash2[0] && hash1[1] == hash2[1])can = 0;
	// cout<<"len1 = "<<len1<<endl;
	// cout<<"hash1[0] = "<<hash1[0]<<endl;
	// cout<<"len2 = "<<len2<<endl;
	// cout<<"hash2[0] = "<<hash2[0]<<endl;
	// cout<<endl;
	if(can)ans++;
}
void force(){
	if(one > zero){
		for (int i=1; i<=t.size()-1; i++){
			int len1 = one*i;
			if(len1 >= t.size()){
				break;
			}
			if((t.size()-len1) % zero != 0){
				continue;
			}
			int len2 = (t.size()-len1)/zero;
			// try to force check()
			check(i,len2);
		}
	}
	else{
		for (int i=1; i<=t.size()-1; i++){
			int len2 = zero*i;
			if(len2 >= t.size()){
				break;
			}
			if((t.size()-len2) % one != 0){
				continue;
			}
			int len1 = (t.size()-len2)/one;
			// try to force check()
			check(len1,i);
		}
	}
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>s>>t;
	count_number();
	getHush();
	force();
	cout<<ans<<endl;
	return 0;
}
