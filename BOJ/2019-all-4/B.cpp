// fyt
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

bool vis[10];
int n,m;
int len1,len2;
int ans = 0;

string front,back;
string sn,sm;

void dfsn(int index) {
	if (index == len1+1) {
		ans++;
		return;
	}

	for (int i=0; i<7; i++){
		if (!vis[i]) {
			vis[i] = 1;
			front[index-1] = (char)(i+'0');
			if (front <= sn) dfsn(index+1);

			front[index-1] = '0';
			vis[i] = 0;
		}
	}
}

void dfsm(int index) {
	if (index == len2+1) {
		dfsn(1);
		return;
	}

	for (int i=0; i<7; i++){
		if (!vis[i]) {
			vis[i] = 1;
			back[index-1] = (char)(i+'0');
			if (back <= sm) dfsm(index+1);
			back[index-1] = '0';
			vis[i] = 0;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);


	cin >> n >> m;
	int temp = n-1;
	if(temp==0)sn.push_back('0');
	while(temp>0) {
		sn.push_back((char)(temp%7+'0'));
		temp/=7;
	}

	temp = m-1;
	if(temp==0)sm.push_back('0');
	while(temp>0) {
		sm.push_back((char)(temp%7+'0'));
		temp/=7;
	}

	reverse(sn.begin(),sn.end());
	reverse(sm.begin(),sm.end());
	len1 = sn.size();
	len2 = sm.size();

	for (int i=0; i<sn.size(); i++){
		front.push_back('0');
	}
	for (int i=0; i<sm.size(); i++){
		back.push_back('0');
	}

	dfsm(1);
	cout << ans << endl;
	return 0;
}
