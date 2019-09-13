#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,ans,S,ds[900202];
ll L[300202],R[320002],q[900202];

int main(){
    scanf("%lld",&n);
    for (int i=1;i<=n;++i){
        scanf("%lld%lld",&L[i],&R[i]);
        L[i]*=2,R[i]*=2;
        q[++q[0]]=L[i],q[++q[0]]=R[i];
        q[++q[0]]=(L[i]+R[i])/2;
        S+=R[i]-L[i];
    }
	
    sort(q+1,q+q[0]+1);
    q[0]=unique(q+1,q+q[0]+1)-q-1;
    for (int i=1;i<=n;++i){
        int l,r,mid;
        l=lower_bound(q+1,q+q[0]+1,L[i])-q;
        r=lower_bound(q+1,q+q[0]+1,R[i])-q;
        mid=lower_bound(q+1,q+q[0]+1,(R[i]+L[i])/2)-q;
        ds[r]--;
        ds[mid]+=2;
        ds[l]--;
    }
    ll Nowss=S,d=0;ans=0;
    for (int i=q[0];i>=1;--i){
        if (i<q[0]) Nowss+=2*d*(q[i+1]-q[i]);
        if (S-Nowss>ans) ans=S-Nowss;
        d+=ds[i];
    }
    printf("%lld",ans/2);
}
