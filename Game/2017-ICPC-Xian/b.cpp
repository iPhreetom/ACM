// genius
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[212345];
int b[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n,k;
        int ans = 0;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        int index = n-1;
        for(int i=0;i<n;i++){
            while(1){
                if(index < 0)break;
                else if(a[i] + b[index] < k)index--;
                else {ans++;index--;break;}
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
