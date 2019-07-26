#include<bits/stdc++.h>
#define int long long
using namespace std;




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	// cout<<(int)'0'<<' '<<(int)'A'<<endl;
	string a;
	string b;
	int n;
	int step=0;
	int na,mb;

	cin>>n;
	cin>>a;

	for(int i=0;i<=31;i++){
		// cout<<a<<endl;
		if(i == 31){
			cout<<"Impossible!"<<endl;
			return 0;
		}
		else{
			// check
			for(int j=0;j<=a.size();j++){
				if(j == a.size()){
					cout<<"STEP="<<i<<endl;
					return 0;
				}
				if(a[j] != a[a.size()-j-1]){
					break;
				}
			}

			// init()
			na = 0;
			b = a;
			reverse(b.begin(),b.end());

			// from n to 10
			for(int i=0;i<a.size();i++){
				na += ((a[i]>='0' && a[i]<='9')? a[i]-'0':a[i]-'A'+10)*pow(n,i);
				na += ((b[i]>='0' && b[i]<='9')? b[i]-'0':b[i]-'A'+10)*pow(n,i);
			}

			// 10 to n
			a.clear();
			while(na){
				a.push_back( (na%n <= 9)?(na%n)+'0':(na%n-10)+'A');
				na/=n;
			}
			reverse(a.begin(),a.end());
		}
	}

	return 0;
}
