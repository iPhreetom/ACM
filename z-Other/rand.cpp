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
    int n = random(2,5);
    int l = (n-1)*5 + 1;
    int m = random(l,20000);
    cout<<n<<endl;
    cout<<m<<endl;
    for (int i=0; i<m; i++){
        cout<<random(1,13)<<' ';
    }
    cout<<endl;
    return 0;
}
