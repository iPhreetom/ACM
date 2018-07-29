#include<bits/stdc++.h>
using namespace std;

vector<vector<long long> > a(112345);
vector<vector<long long> > b(112345);

long long n,k,ans1=-1,ans2=-1,mx=-1,tp;
long long a1,a2;

void find(){
	bool not1 = 1;
	for(int i=0;i<n;i++){
		if(not1 && a[ans1][0] == b[i][0] && a[ans1][1] == b[i][1] && a[ans1][2] == b[i][2]){
			a1 = i;
			not1 = 0;
		}
		else{
			if(a[ans2][0] == b[i][0] && a[ans2][1] == b[i][1] && a[ans2][2] == b[i][2]){
				a2 = i;
			}
		}
	}
	cout<<2<<endl;
	cout<<a1+1<<' '<<a2+1<<endl;
}

bool cmp(long long a, long long b){
	return a>b;
}

bool cmp2(vector<long long> a,vector<long long> b){
	if(a[0] == b[0]){
		if(a[1] == b[1]){
			return a[2]>b[2];
		}
		else{
			return a[1]>b[1];
		}
	}
	else{
		return a[0]>b[0];
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for(int i=0;i<n;i++){
		a[i].resize(3);
		b[i].resize(3);
		cin>>a[i][0]>>a[i][1]>>a[i][2];

		sort(&a[i][0],&a[i][0]+3,cmp);

		b[i] = a[i];

		if(mx < a[i][2]){
			ans1 = i;
			mx = a[i][2];
		}
	}
	// cout<<"mx:"<<mx<<endl;

	if(n == 1){
		cout<<1<<endl;
		cout<<ans1+1<<endl;
	}
	else{
		sort(a.begin(),a.begin()+n,cmp2);

		for(int i=1;i<n;i++){
			if(a[i-1][0] == a[i][0]){
				if(a[i-1][1] == a[i][1]){
					// mx = max(mx,a[i-1][2]+a[i][2]);
					if(mx < min(a[i][1],a[i-1][2]+a[i][2])){
						mx = min(a[i][1],a[i-1][2]+a[i][2]);
						ans1 = i-1;
						ans2 = i;
					}
				}
			}
			if(a[i][0] < mx)break;
		}
		if(ans2 != -1){
			find();
		}
		else{
			cout<<1<<endl;
			cout<<ans1+1<<endl;
		}
	}
	// for(int i=0;i<n;i++){
	// 	cout<<a[i][0]<<a[i][1]<<a[i][2]<<endl;
	// }

	return 0;
}

//接下来把正解当作，一个对拍的程序，来搞事情
//比如，哦我们可以使用ｅａｃｈ　命令行参数来获得脚本语言的厉害指出＝＝
