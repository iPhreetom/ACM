#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,p;
    cin>>t;
    while(t--)
    {
        cin>>p;
        for(int i=0;i<p;i++)
        {
            for(int j=0;j<p;j++)
            {
                if(j)cout<<" "<<(i+j)%p;
                else cout<<(i+j)%p;
            }
            cout<<endl;
        }
        for(int i=0;i<p;i++)
        {
            for(int j=0;j<p;j++)
            {
                if(j)cout<<" "<<(i+j)%p;
                else cout<<(i+j)%p;
            }
            cout<<endl;
        }
    }
}
