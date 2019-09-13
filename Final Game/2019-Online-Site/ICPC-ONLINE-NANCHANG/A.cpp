// fyt
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int MAXN = 1.5e8+10;
bool vis[MAXN];
int prime[MAXN];

int tot = 0;
void get_prime() {
    for (int i = 2; i < MAXN; i++) {
        if (!vis[i]) prime[tot++] = i;
        for (int j = 0; j < tot; j++) {
            int d = i * prime[j];
            if (d >= MAXN) break;
            vis[d] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

signed main(){
    get_prime();

    int mx = 0;
    int cnt = 0;
    vector<int> lis;
    for (int i=1; i<tot; i++){
        lis.push_back(prime[i]);
        lis.push_back(prime[i]*2);
        lis.push_back(prime[i]*3);
        lis.push_back(prime[i]*5);
        lis.push_back(prime[i]*7);
        lis.push_back(prime[i]*11);
        lis.push_back(prime[i]*13);
    }

    sort(lis.begin(),lis.end());

    for (int i=1; i<lis.size() && lis[i]<MAXN; i++){
        mx = max(mx, (lis[i]-lis[i-1]));
    };
    cout<<"mx = "<<mx<<endl;

	return 0;
}
