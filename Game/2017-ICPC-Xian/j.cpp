// genius
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    for(int i=1 ; i<100 ;i++){
        cout<<((i)^(i+1))<<' ';
    }

    cout<<endl;
    cout<<endl;


    for(int i=1 ; i<100 ;i++){
        cout<<((i)^(i+1)^(i+2))<<' ';
    }

    cout<<endl;
    cout<<endl;

    for(int i=1 ; i<100 ;i++){
        cout<<((i)^(i+1)^(i+2)^(i+3))<<' ';
    }

    cout<<endl;
    cout<<endl;

    for(int i=1 ; i<100 ;i++){
        cout<<((i)^(i+1)^(i+2)^(i+3)^(i+4))<<' ';
    }

    cout<<endl;
    cout<<endl;

    for(int i=1 ; i<100 ;i++){
        cout<<((i)^(i+1)^(i+2)^(i+3)^(i+4)^(i+5))<<' ';
    }
    return 0;
}

