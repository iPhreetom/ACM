#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


vector<int> a(2123);
int mp[305][305];
int father[305];
vector<priority_queue<int,vector<int>,greater<int>>> arr(305);

void init(){
	for(int i=0;i<305;i++){
		father[i] = i;
	}
}

int findfather(int a){
	int root = a;
	while(father[root] != root){
		root = father[root];
	}

	while(father[a] != a){
		int t = father[a];
		father[a] = root;
		a = t;
	}

	return root;
}

void unit(int a,int b){
	int fathera = findfather(a);
	int fatherb = findfather(b);

	father[fathera] = fatherb;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	init();

	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	string s;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=1;j<=n;j++){
			if(s[j-1] == '1'){
				unit(i,j);
				findfather(i);
				findfather(j);
			}
		}
	}

	for(int i=1;i<=n;i++){
		findfather(i);
	}

	for(int i=1;i<=n;i++){
		arr[father[i]].push(a[i]);
	}

	// for(int i=0;i<n;i++){
	// 	if(arr[father[a[i]]].size() != 0){
	// 		while(!arr[father[a[i]]].empty()){
	// 			cout<<arr[father[a[i]]].top()<<' ';
	// 			arr[father[a[i]]].pop();
	// 		}cout<<endl;
	// 	}
	// }

	for(int i=1;i<=n;i++){
		if(i!=n){
			cout<<arr[father[i]].top()<<' ';
			arr[father[i]].pop();
		}
		else{
			cout<<arr[father[i]].top()<<endl;
		}
	}
	return 0;
}
