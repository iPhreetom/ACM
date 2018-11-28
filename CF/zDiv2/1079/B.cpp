#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// handle 称号（把手）
// asterisk 星号
// row 行
// column 列

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	if(s.size() <= 20){
		cout<<1<<' '<<s.size()<<endl;
		cout<<s<<endl;
	}
	else{
		int len = s.size();
		int row = len/20 + 1;
		int column = 0;
		if(len % 20 == 0){
			row--;
			column = len/row;
		}
		else{
			if(len % row == 0){
				column = len/row;
			}
			else{
				column = len/row + 1;
			}
		}
		cout<<row<<' '<<column<<endl;
		int dif = row*column - len;
		int left = 0;
		for (int i=1; i<=row; i++){
			// cout<<"left = "<<left<<endl;
			if(dif == 0){
				cout<<s.substr((i-1)*column-left,column)<<endl;
			}
			else{
				cout<<s.substr((i-1)*column-left,column-1);
				cout<<'*';
				cout<<endl;
				dif--;
				left++;
			}
		}
	}
	return 0;
}
// 12345123451234512345
