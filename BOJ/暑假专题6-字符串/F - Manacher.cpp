#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <climits>
#include <cstdio>
#include <complex>
#include <numeric>
#include <cassert>
// #define endl '\n'
#define int long long
#define double long double
using namespace std;

vector<int> p;

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
	int pos;//最大回文串的对称轴
	int mx=0;//最大右边界
	int len=s1.size();
	p.resize(len);//回文最长半径数组 p[i]=k 代表在位置i的回文串的最长半径为k
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

char ch;
string ss;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(cin>>ch){
		cin>>ss;
		int len = Manacher(ss);
		if(len < 2){
			cout<<"No solution!"<<endl;
			continue;
		}
		for (int i=0; i<p.size(); i++){
			if(p[i]-1 == len){
				int l = (i-len+1)/2-1; //最大回文子串开始的位置
		   		int r = l+len-1;
				cout<<l<<' '<<r<<endl;
				for (int i=l; i<=r; i++){
					int num = ((ss[i]-'a')-(ch-'a')+26)%26;
					ss[i] = 'a'+num;
					cout<<ss[i];
				}cout<<endl;
				break;
			}
		}
	}
	return 0;
}
