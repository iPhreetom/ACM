#include<bits/stdc++.h>
using namespace std;

long long n,m,a[(int)1e5 + 5],b[(int)1e5+5];

bool check(long long t){
    for(int i=0;i<n;i++){
        b[i] = a[i];
    }
    // printf("\n");
    long long np = 0;

    long long p=t;
    for(int i=n-1;i>=0;i--){
        if(b[i]){
            p -= (i+1);
            if(p <= 0)return 0;
            if(np > m)return 0;

            while(p > 0 && i >= 0){
                if(p > b[i]){
                    // printf("people: %d , nowplace: %d , restlife : %d\n",np,i,p);
                    p -= b[i];
                    i--;
                }
                else{
                    // printf("people: %d , nowplace: %d , restlife : %d\n",np,i,p);
                    b[i] -= p;
                    i++; // wrong ans
                    np++;
                    p = t;
                    break; // wrong ans
                }
            }
        }
    }

    if(np < m){
        return 1;
    }
    else{
        if(np == m){
            if(p == t)return 1;
            else return 0;
        }
        else{
            return 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);

    cin>>n>>m;
    for(int i;i<n;i++){
        cin>>a[i];
    }

    long long mid, l = 0,r = 1000000000000000000;// wa
    while(l + 1 < r){
        mid = l +(r-l)/2 ; // TL
        if(check(mid))r = mid;
        else l = mid;
    }

    if(check(l)){
        cout<<l<<endl;
    }
    else{
        cout<<r<<endl;
    }
    return 0;
}
