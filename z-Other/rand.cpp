#include <bits/stdc++.h>
#define int long long
using namespace std;
#define random(a, b) ((a) + rand() % ((b) - (a) + 1))

stringstream ss;

signed main(int argc, char *argv[]) {
    // freopen("data.in","w",stdout);
    int seed = time(NULL);
    if (argc > 1) //如果有参数
    {
        ss.clear();
        ss << argv[1];
        ss >> seed; //把参数转换成整数赋值给seed
    }
    srand(seed);
    ///////////////////////////////////////
    cout<<1<<endl;
    int n = random(2,13);
    cout<<n<<endl;

    vector<int> v;
    vector<int> s;
    for (int i=1; i<=n; i++){
        v.push_back(i);
    }
    random_shuffle(v.begin(),v.end());

    s.push_back(v.back());
    v.pop_back();
    for (int i=0; i<n-1; i++){
        cout<<v.back()<<' ';
        // cout<<"v.size() = "<<v.size()<<endl;

        random_shuffle(s.begin(),s.end());

        cout<<s.back()<<endl;
        s.push_back(v.back());
        v.pop_back();
    }
    return 0;
}
