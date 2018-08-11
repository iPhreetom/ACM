// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


multimap<string,int> mp;

signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    mp.insert(make_pair("aa",1));
    mp.insert(make_pair("aa",1));
    mp.insert(make_pair("aa",1));
    cout<<mp.count("aa ")<<endl;

    for(auto i:mp){
        cout<<i.first<<endl;
    }

    auto p = mp.equal_range("aa");
    for(auto i = p.first;i!=p.second;i++){
        cout<<i->first<<endl;
    }
    return 0;
}
