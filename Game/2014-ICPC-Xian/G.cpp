// fyt

// 补题名单++
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

string init(string &s) {
	string s1="$#";
	int len=s.size();
	for(int i=0;i<len;i++) {
		s1+=s[i];
		s1+="#";
	}
	return s1;
}

int Manacher(string &s) {
	string s1=init(s);
	int mx=0;//最大右边界
	int pos;//最大回文串的对称轴
	int len=s1.size();
	vector<int> p(len);//回文最长半径数组 p[i]=k 代表在位置i的回文串的最长半径为k
	int res=0;
	for(int i=1;i<len;i++) {
		if(mx>i){//i在mx左边
			p[i]=min(p[2*pos-i],mx-i);
		} else { //i在mx右边 必须一个个匹配
			p[i]=1;
		}
		while(s1[i-p[i]]==s1[i+p[i]]){
			p[i]++;
		}
		if(i+p[i]>mx) { //更新maxright 最大回文串对称轴位置
			pos=i;
			mx=pos+p[i];
		}
		res=max(res,p[i]-1);
	}
	return res;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;
	cin>>tt;
	for(int cc=1;cc<=tt;cc++){
		int ans = 0;

		string a,b;
		cin>>a>>b;


		cout<<"Case #"<<cc<<": "<<ans;
	}
	return 0;
}
