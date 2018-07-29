#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int book[2123];
int book2[2123];
int book3[2123];
int book4[2123];
int n;
string a;
int l,r;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	// cout<<'a'-''<<endl;
	cin>>n;
	cin>>a;

	for(int i=0;i<n;i++){
		book[a[i]-'A']++;
	}

	for(int i=0;i<2123;i++){
		book3[i] = book4[i] = book2[i] = book[i];
	}

	for(int i=0;i<n;i++){
		if(book[a[i]-'A'] == 1){
			l = i;
			break;
		}
		else{
			book[a[i]-'A']--;
		}
	}


	for(int i=0;i<l;i++){
		book2[a[i]-'A']--;
	}

	for(int i=n-1;i>=0;i--){
		if(book2[a[i]-'A'] == 1){
			r = i;
			break;
		}
		else{
			book2[a[i]-'A']--;
		}
	}

	// cout<<r-l+1<<endl;
	int ans = r-l+1;

	for(int i=l-1;i>=0;i--){
		book[a[i]-'A']++;
		book2[a[i]-'A']++;
		while(book2[a[r]-'A'] > 1){
			book2[a[r]-'A']--;
			r--;
		}
		ans = min(ans,r-i+1);
	}
	cout<<ans<<endl;




	//
	// for(int i=n-1;i>=0;i--){
	// 	if(book3[a[i]-'A'] == 1){
	// 		r = i;
	// 		break;
	// 	}
	// 	else{
	// 		book3[a[i]-'A']--;
	// 	}
	// }
	//
	//
	// for(int i=n-1;i>r;i--){
	// 	book4[a[i]-'A']--;
	// }
	//
	// for(int i=0;i<n;i++){
	// 	if(book4[a[i]-'A'] == 1){
	// 		l = i;
	// 		break;
	// 	}
	// 	else{
	// 		book4[a[i]-'A']--;
	// 	}
	// }
	// // cout<<r-l+1<<endl;
	// ans = min(ans,r-l+1);
	// cout<<ans<<endl;
	// // cout<<l<<" "<<r<<endl;
	return 0;
}
