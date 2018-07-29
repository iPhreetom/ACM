#include<bits/stdc++.h>
using namespace std;


unsigned long long n,t;
vector<pair<unsigned long long,unsigned long long> > a;

bool cmp(pair<unsigned long long , unsigned long long> q , pair<unsigned long long , unsigned long long> p){
	if(q.second == p.second)return q.first > p.first;
	else return q.second < p.second;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		a.push_back(make_pair(t,0));
	}

	for(int i=0;i<n;i++){
		t = a[i].first;
		while(a[i].first % 3 == 0 && a[i].first != 0){
			a[i].first /= 3;
			a[i].second++;
		}
		a[i].first = t;
	}

	sort(a.begin(),a.end(),cmp);
	for(int i=n-1;i>=0;i--){
		if(i == n-1){
			cout<<a[i].first;
		}
		else{
			cout<<' '<<a[i].first;
		}
	}
	cout<<endl;
	return 0;
}
