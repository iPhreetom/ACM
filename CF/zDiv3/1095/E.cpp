#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int pre[1123456];
int suf[1123456];

// 显然，这道题要O（n）的做
// 	检查，翻转一个后，这个字符串是否合法
// 	用一个 lt 保存，在这一位之前有多少个带匹配的左括号
// 	用一个 rt 保存，在这一位之前有多少个右括号
// 	前缀时检查是否出现了必须匹配的情况，然后用bool保存是否可以更改获得答案
// 结论：
// 	如果原序列合法，那么为0
// 	如果不能够更改，那么为0
// 	如果能够更改，那么一定在前缀或者后缀中

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;

	bool change = 0;
	int lt = 0;
	int rt = 0;
	int ans = 0;

	for (int i=0; i<s.size(); i++){
		if(s[i] == '(') {
			lt++;
		}
		else {
			if(lt == 0) {
				if(!change) {
					change = 1;
					lt ++;
					ans = rt + 1;
				}
				else {
					cout << 0 << endl;
					return 0;
				}
			}
			else {
				rt ++;
				lt --;
			}
		}
	}
	if(lt == 0) {
		cout << ans << endl;
		return 0;
	}

	change = 0;
	rt = 0;
	lt = 0;
	ans = 0;
	for (int i=n-1; i>=0; i--){
		if(s[i] == ')') {
			rt++;
		}
		else {
			if(rt == 0) {
				if(!change) {
					change = 1;
					rt ++;
					ans = lt + 1;
				}
				else {
					cout << 0 << endl;
					return 0;
				}
			}
			else {
				rt --;
				lt ++;
			}
		}
	}
	if(rt == 0) {
		cout << ans << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}
