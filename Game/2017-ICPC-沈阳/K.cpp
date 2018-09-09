#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int maxn=505;
int a[maxn];

signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int ans=max(a[n-1]-a[1],a[n-2]-a[0]);
        ans-=n-2;
        cout<<ans<<endl;
    }
    return 0;
}
