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
    cout<<1<<endl;
    int n = random(4,4);
    cout<<n<<endl;
    for (int i=0; i<n; i++){
        cout<<random(1,5)<<' '<<random(1,5)<<' '<<random(1,10)<<endl;
    }

    return 0;
}
