// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

vector<int> lis;
int ans1;
int ans2;
int p1,p2;


void init(){
	for (int i=1; i<=15; i++){
		lis.push_back(pow(i,i));
	}
}

#define ll long long
ll a[20];

inline int main2()
{
	int i,j;
	for(i=1;i<=15;i++)
	{
		a[i]=1;
		for(j=1;j<=i;j++)
			a[i]*=i;
	}

	int n = p1;
	int s=0;
	for(i=1;i<=15;i++)
	{
		if(a[i]<=n)
			s++;
		else
			break;
	}
	ans2 = s;

	return 0;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	init();
	int n;
	for (int j=1; j<=1e18; j++){
		int n = j;
		int num=0;
		for(auto i:lis){
			if(i <= n)num++;
			else break;
		}
		ans1 = num;
		p1 = n;
		main2();
		if(ans1 != ans2){
			cout<<"ans1 = "<<ans1<<endl;
			cout<<"ans2 = "<<ans2<<endl;
			break;
		}
	}

	return 0;
}
