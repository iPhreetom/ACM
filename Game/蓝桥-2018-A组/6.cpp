#include<bits/stdc++.h>
using namespace std;

int count(string &a) {
	int num = 0;
	int h = (a[0]-'0')*10 + a[1]-'0';
	int m = (a[3]-'0')*10 + a[4]-'0';
	int s = (a[6]-'0')*10 + a[7]-'0';
	num = s + m*60 + h*3600;
	return num;
}

string getnum(int t) {
	string s;
	if(t == 0) {
		s = "00";
	}
	else if(t < 10) {
		s = "0";
		s.push_back(t+'0');
	}
	else {
		while(t > 0) {
			s.push_back((t%10)+'0');
			t/=10;
		}
		reverse(s.begin(),s.end());
	}
	return s;
}

string gettime(int t) {
	int h = t/3600;
	t -= h*3600;
	int m = t/60;
	t -= m*60;
	int s = t;
	string rt = getnum(h);
	rt.push_back(':');
	rt += getnum(m);
	rt.push_back(':');
	rt += getnum(s);
	return rt;
}

int main () {
	int n;
	cin>>n;
	while(n--){
		string a;
		string ae;
		string b;
		string be;
		cin >> a >> ae;

		int go = 0;
		int back = 0;

		if (ae.back() == ')') {
			ae.pop_back();
			if(ae.back() == '1') go += 3600*24;
			else if(ae.back() == '2')  go += 3600*48;
			ae.pop_back();
			ae.pop_back();
			ae.pop_back();
		}
		go += count(ae);
		go -= count(a);

		cin >> b >> be;
		if (be.back() == ')') {
			be.pop_back();
			if(be.back() == '1') back += 3600*24;
			else if(ae.back() == '2')  back += 3600*48;
			be.pop_back();
			be.pop_back();
			be.pop_back();
		}
		back += count(be);
		back -= count(b);

		int ans = (go+back)/2;
		cout << gettime(ans) << endl;
	}
}
