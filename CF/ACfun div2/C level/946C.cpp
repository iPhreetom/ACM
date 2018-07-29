#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

string a,b;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>a;

	char ch = 'a';
	// bool choose_a = 0;
	for(int i=0;i<a.size();i++){
		// if(choose_a)
		if(a[i] <= ch && ch != 'z'+1){
			a[i] = ch++;
		}
	}
// 3*10^7 == 156ms
// 1560ms == 3*10^8
	if(ch == ('z'+1)){
		cout<<a<<endl;
	}
	else{
		cout<<-1<<endl;
	}

	return 0;
}
