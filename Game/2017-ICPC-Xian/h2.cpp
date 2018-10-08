// genius
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
int a[112345], b[112345];

multiset<int> s;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n,k;
        s.clear();

        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        int ans = 0;
        int index = 0;
        int l = 0, cnt = 0;

        while(index != n){
            if(s.size() < k){
                a[index]+=ans;
                s.insert(a[index++]);
            }
            if(s.size() == k){
                int mn = *s.begin();//, del = 0;
                while(!s.empty() && s.count(mn) != 0){
                    s.erase(s.find(a[l++]));
                }
                ans += mn - ans;
            }
        }
        cout << ans << endl;
    }

	return 0;
}

