// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

string s;
vector<int> v;
int a[112345];
int d[112345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int nn;
	cin>>nn;
	for(int kk=1;kk<=nn;kk++){
		v.clear();
		memset(d,0,sizeof(d));
		int sum = 0;
		int index = 0;
		int num = 1;

		cin>>s;
		s.push_back('x');
		reverse(s.begin(),s.end());

		for (int i=1; i<s.size(); i++){
			if(s[i] != s[i-1]){
				v.push_back(num);
				num = 1;
				index++;
				d[i] = index;
			}
			else{
				d[i] = d[i-1];
				num++;
			}
		}
		v.push_back(num);
		//
		// for (int i=0; i<v.size(); i++){
		//     cout<<v[i]<<' ';
		// }cout<<endl;
		for (int i=1; i<v.size(); i++){
			sum += v[i]*v[i];
		}
		int mx = sum ;
		for (int i=2; i<v.size(); i++){
			if(v[i] == 1 && i != v.size()-1){
				mx = max(mx,sum - v[i]*v[i] - v[i-1]*v[i-1] - v[i+1]*v[i+1] + (v[i]+v[i-1]+v[i+1])*(v[i]+v[i-1]+v[i+1]));
			}
			mx = max(mx,(sum - v[i]*v[i] - v[i-1]*v[i-1] + (v[i-1]-1)*(v[i-1]-1) + (v[i]+1)*(v[i]+1)));
			mx = max(mx,(sum - v[i]*v[i] - v[i-1]*v[i-1] + (v[i-1]+1)*(v[i-1]+1) + (v[i]-1)*(v[i]-1)));
		}
		cout<<"Case #"<<kk<<": ";
		cout<<mx<<endl;
	}
	return 0;
}
