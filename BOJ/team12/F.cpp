
#include<bits/stdc++.h>
using namespace std;

long long n;
long long val = 0;
long long c[5123];
long long preo[5123];
long long prec[5123];
long long preoc[5123];
long long pre = 0;
long long ad = 0;
long long ado= 0;
long long ans;
bool book[5123];
string a;
string b;
vector<long long> onez;
vector<long long> zone;

struct node{
	int c;
	int fr;
	int to;
};

bool cmp(node &a,node &b){
	if(a.c == b.c){
		int av = a.fr*10 - a.to;
		int bv = b.fr*10 - b.to;
		return av > bv;
		// if(a.fr == 1 && a.to == 0)return 1;
		// if(a.fr == 1 && a.to == 1)return 1;
		// if(a.fr == 0 && a.to == 1)return 1;
		return 1;
	}
	else{
		return a.c < b.c;
	}
}
node arr[5123];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i].c;
	}
	cin>>a>>b;
	for(int i=0;i<n;i++){
		arr[i].c = arr[i].c;
		arr[i].fr = a[i]-'0';
		arr[i].to = b[i]-'0';
	}
	sort(arr,arr+n,cmp);
	// for(int i=0;i<n;i++){
	// 	cout<<arr[i].c<<' '<<arr[i].fr<<arr[i].to<<endl;
	// }cout<<endl;
	// 10 + 5 + 5 + 10 + 15
	// 10+ 5 + 10 + 15

	// 预处理
	for(int i=0;i<n;i++){
		if(i == 0){
			if(arr[i].fr==0 && arr[i].to == 1){
				prec[i] = arr[i].c;
			}
			if(arr[i].fr == 1 && arr[i].to == 0){
				preo[i] = 1;
				preoc[i] = arr[i].c;
			}
		}
		else{
			if(arr[i].fr==0 && arr[i].to == 1){
				prec[i] = prec[i-1]+arr[i].c;
			}
			else {
				prec[i] = prec[i-1];
			}
			if(arr[i].fr == 1 && arr[i].to == 0){
				preo[i] = preo[i-1]+1;
			}
			else {
				preo[i] = preo[i-1];
				preoc[i] = preoc[i-1]+arr[i].c;
			}
		}
	}
	// cout<<preo[n-1]<<endl;
	// cout<<prec[n-1]<<endl;

	for(int i=0;i<n;i++){
		if(arr[i].fr == 1){
			val += arr[i].c;
			if(arr[i].to == 0){
				onez.push_back(arr[i].c);
			}
			else{
				// 判断是否需要加入
				long long save = (preo[i]+pre)*arr[i].c;
				long long cost = (prec[i]+ad) + arr[i].c + (preoc[i]+ado);
				if(save > cost){
					pre++;
					ad += arr[i].c;
					ado += arr[i].c;
					onez.push_back(arr[i].c);
					zone.push_back(arr[i].c);
				}
			}
		}
		// 5
		// 3 3 4 5 6
		// 10101
		// 01010
		/*
		5 5 2 6 1 5 01110 10011
		5 5 5 5 5 5 01110 10011
		*/

		else{// arr[i].fr == 0
			if(arr[i].to == 1){
				zone.push_back(arr[i].c);
			}
		}
	}
	// cout<<val<<endl;
	sort(zone.begin(),zone.end());
	sort(onez.begin(),onez.end());
	// cout<<zone[0]<<onez[0]<<endl;
	for(int i=onez.size()-1;i>=0;i--){
		val-=onez[i];
		ans += val;
	}
	// cout<<ad<<endl;
	// cout<<ado<<endl;
	for(int i=0;i<zone.size();i++){
		val+=zone[i];
		ans += val;
	}
	cout<<ans<<endl;
	return 0;
}
