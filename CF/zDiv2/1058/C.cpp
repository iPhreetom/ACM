// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define edl '\n'
using namespace std;

int n;
string s;
int lt = 0;
int rt = 1;

int sum = 0;
int suml = 0;
int sumr = 0;

bool ed = 0;
bool ok = 0;

bool force(){
	int num = 0;
	for(int i=lt+1;i<rt;i++){
		num+=s[i]-'0';
		if(i == rt - 1 && num < sum && num != 0){
			return 0;
		}
		if(num > sum){
			return 0;
		}
		if(num == sum){
			num = 0;
		}
	}
	return true;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>s;
	rt = n-1;
	suml = s[lt]-'0';
	sumr = s[rt]-'0';

	while(!ed){
		// cout<<"lt = "<<lt<<' ';
		// cout<<"rt = "<<rt<<endl;
		if(lt < rt - 1){
			if(suml < sumr){
				lt++;
				suml += s[lt]-'0';
			}
			else if(sumr < suml){
				rt--;
				sumr += s[rt]-'0';
			}
			else if(sumr == suml){
				sum = sumr;
				if(force()){
					ok = 1;
					ed = 1;
				}
				else{
					lt++;
					suml += s[lt]-'0';
				}
			}
		}
		else{
			if(suml == sumr){
				ok = 1;
				ed = 1;
			}
			break;
		}
	}

	if(ok)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
