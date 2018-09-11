#include<bits/stdc++.h>
using namespace std;

string s1,s2,s3;
char ans;

bool ff(char c1,char c2,char c3) {
    if(c1 == c2 && c1 == c3 && c1 !='.')
        return true;
    return false;
}

bool f() {
    if(ff(s1[0],s1[1],s1[2])){
        ans = s1[0];
        return true;
    }
    if(ff(s2[0] ,s2[1] ,s2[2])){
        ans = s2[0];
        return true;
    }
    if(ff(s3[0] ,s3[1], s3[2])){
        ans = s3[0];
        return true;
    }
    if(ff(s1[0] , s2[0] , s3[0])){
        ans = s1[0];
        return true;
    }
    if(ff(s1[1] , s2[1] , s3[1])){
        ans = s1[1];
        return true;
    }
    if(ff(s1[2] , s2[2] , s3[2])){
        ans = s1[2];
        return true;
    }
    if(ff(s1[0] , s2[1] , s3[2])){
        ans = s1[0];
        return true;
    }
    if(ff(s1[2] , s2[1] , s3[0])){
        ans = s1[2];
        return true;
    }
    return false;
}

int main(){

    ios_base::sync_with_stdio(0);
    int T;cin>>T;
    while(T--) {
        cin>>s1>>s2>>s3;
        if(f()) {
            cout<<ans<<endl;
        } else {
            cout<<"ongoing"<<endl;
        }

    }
    return 0;
}
