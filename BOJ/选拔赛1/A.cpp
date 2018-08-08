#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;



vector<int> arr;
int n;
string a;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>a;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		arr.push_back(t);
	}
	sort(arr.begin(),arr.end());
	reverse(arr.begin(),arr.end());

	int len = a.size();
	bool findit = 0;
	for(int i=0;i<len && !findit;i++){
		int mini=i;
		for(int j=0;j<n;j++){
			if(i+arr[j]>=len)continue;
			if(a[i+arr[j]]<a[mini])mini=i+arr[j];
		}
		if(mini!=i){
			swap(a[i],a[mini]);
			findit = 1;
		}
	}


	if(findit == 0){
		for(int i=0;i<len;i++){
			for(int j=0;j<n;j++)
			{
				if(i+arr[j]>=len)continue;
				if(a[i]==a[i+arr[j]]){
					findit = 1;
					break;
				}
			}
		}

		if(findit){
			cout<<a<<endl;
		}
		else{
			swap(a[len-1] ,a[len - arr[n-1] -1]);
			cout<<a<<endl;
		}
	}
	else{
		cout<<a<<endl;
	}
	return 0;
}
