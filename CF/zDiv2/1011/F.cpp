// CF 1011 F
// 	一句话描述：
// 		先后序DFS
// 	知识点：
// 		模拟异或操作
// 	碎碎念：
// 		想到保存每一个输入（IN）对最终答案是否会有影响，
// 		那么就可以讨论，当前值为XX时，其孩子是否对最终答案有影响
// 		所以先算出值
// 		然后算出是否影响即可
#include<bits/stdc++.h>
#define int long long
#define double long double
#define mp(a,b) make_pair(a,b)

#define fori(x) for(int i=0;i<(x);i++)
#define forj(x) for(int j=0;j<(x);j++)
#define for1i(x) for(int i=1;i<=(x);i++)
#define for1j(x) for(int j=1;j<=(x);j++)

#define all(x) (x).begin(),(x).end()

#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define sz(x) ((int)(x).size())

#define fi first
#define se second
const double eps= 1e-8;
const double pi = acos(-1.0);

using namespace std;

int dp[1123456];

struct node{
	int val=0;
	int type;
	int v;
	int u;
	vector<int> son;
};

vector<node> arr(1123456);

void dfsval(int n){
	for(int i=0;i<arr[n].son.size();i++){
		dfsval(arr[n].son[i]);
	}

	if(arr[n].type == 1){
		arr[n].val = (arr[arr[n].son[0]].val&arr[arr[n].son[1]].val);
	}
	if(arr[n].type == 2){
		arr[n].val = (arr[arr[n].son[0]].val|arr[arr[n].son[1]].val);
	}
	if(arr[n].type == 3){
		arr[n].val = (arr[arr[n].son[0]].val^arr[arr[n].son[1]].val);
	}
	if(arr[n].type == 4){
		arr[n].val = !arr[arr[n].son[0]].val;
	}

}

void dfsans(int n){
	dp[n] = 1;
	if(arr[n].type == 1){
		if(arr[arr[n].son[0]].val == 0 && arr[arr[n].son[1]].val == 1){
			dfsans(arr[n].son[0]);
		}
		else if(arr[arr[n].son[0]].val == 1 && arr[arr[n].son[1]].val == 0){
			dfsans(arr[n].son[1]);
		}
		else if(arr[arr[n].son[0]].val == 1 && arr[arr[n].son[1]].val == 1){
			for(int i=0;i<arr[n].son.size();i++){
				dfsans(arr[n].son[i]);
			}
		}
	}

	if(arr[n].type == 2){
		if(arr[arr[n].son[0]].val == 0 && arr[arr[n].son[1]].val == 0){
			for(int i=0;i<arr[n].son.size();i++){
				dfsans(arr[n].son[i]);
			}
		}
		else if(arr[arr[n].son[0]].val == 0 && arr[arr[n].son[1]].val == 1){
			dfsans(arr[n].son[1]);
		}
		else if(arr[arr[n].son[0]].val == 1 && arr[arr[n].son[1]].val == 0){
			dfsans(arr[n].son[0]);
		}
	}

	if(arr[n].type == 3){
		for(int i=0;i<arr[n].son.size();i++){
			dfsans(arr[n].son[i]);
		}
	}

	if(arr[n].type == 4){
		dfsans(arr[n].son[0]);
	}
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string str;
		cin>>str;
		if(str[0] == 'A'){
			int v,u;
			cin>>v>>u;
			arr[i].son.push_back(v);
			arr[i].son.push_back(u);
			arr[i].type = 1;
		}else if(str[0] == 'O'){
			int v,u;
			cin>>v>>u;
			arr[i].son.push_back(v);
			arr[i].son.push_back(u);
			arr[i].type = 2;
		}else if(str[0] == 'X'){
			int v,u;
			cin>>v>>u;
			arr[i].son.push_back(v);
			arr[i].son.push_back(u);
			arr[i].type = 3;
		}else if(str[0] == 'N'){
			int v,u;
			cin>>v;
			arr[i].son.push_back(v);
			arr[i].type = 4;
		}else {
			int v,u;
			cin>>v;
			arr[i].type = 5;
			arr[i].val = v;
		}
	}
	dfsval(1);
	dfsans(1);
	for(int i=1;i<=n;i++){
		if(arr[i].type == 5){
			cout<<((arr[1].val)^(dp[i]));
		}
	}
	cout<<endl;
	return 0;
}
