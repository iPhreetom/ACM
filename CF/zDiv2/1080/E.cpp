// 给你一个矩阵
//
// 问你有多少个 “good”的子矩阵
// 	选择子矩阵后，每一行可以重新排序
// 	排序后，使得每一行每一列都是回文串
#include<bits/stdc++.h>
#define double long double
using namespace std;

string s[255];
map<vector<int>,int> mp;
int a[255][255][27];
int cnt = 1;

vector<int> init(vector<int> &v) {
	// cout<<"v.size() = "<<v.size()<<endl;
	vector<int> v1;
	v1.push_back(-2123123);
	v1.push_back(1);

	int len=v.size();
	for(int i=0;i<len;i++) {
		v1.push_back(v[i]);
		v1.push_back(1);
	}
	return v1;
}
vector<int> p;//回文最长半径数组 p[i]=k 代表在位置i的回文串的最长半径为k
int Manacher(vector<int> &v) {
	vector<int> v1 = init(v);
	int mx=0;//最大右边界
	int pos;//最大回文串的对称轴
	int len=v1.size();
	p.clear();
	p.resize(len,0);
	int res=0;
	for(int i=1;i<len;i++) {
		if(mx>i){//i在mx左边
			p[i]=min(p[2*pos-i],mx-i);
		} else { //i在mx右边 必须一个个匹配
			p[i]=1;
		}
		while(v1[i-p[i]] == v1[i+p[i]]){
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
	int n,m;
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>s[i];
		s[i].insert(0,"0");
	}
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			for(int d=1; d<=26; d++){
				a[i][j][d] = a[i][j-1][d];
			}
			a[i][j][ s[i][j]-'a'+1 ]++;
		}
	}

	long long ans = 0;
	for (int i=1; i<=m; i++){
		for (int j=i; j<=m; j++){
			vector<int> v;
			// 计算每一行的该部分
			for(int line=1; line<=n; line++){
				int odd = 0;
				vector<int> ca;
				for(int d=1;d<=26;d++){
					int tp = a[line][j][d] - a[line][i-1][d];
					ca.push_back(tp);
					if(tp&1)odd++;
				}
				if(odd > 1){
					if(!v.empty()){
						Manacher(v);
						for (int i=0; i<p.size(); i++){
							// cout<<"p[i] = "<<p[i]<<endl;
							ans += p[i]/2;
						}
						v.clear();
					}
				}
				else{
					// 把字符转化成特征数
					if(mp[ca] == 0){
						mp[ca] = ++cnt;
						v.push_back(cnt);
					}
					else{
						v.push_back(mp[ca]);
					}
				}
			}
			if(!v.empty()){
				Manacher(v);
				for (int i=0; i<p.size(); i++){
					ans += p[i]/2;
				}
			}
			// 通过v得到了特征数 数组
		}
	}
	cout<<ans<<endl;
	return 0;
}
