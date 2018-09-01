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
    int n = random(5,5);
    int m = random(10,10);
    int k = random(1,10);
    cout<<n<<endl;
    cout<<m<<endl;
    cout<<k<<endl;
    for(int i=1;i<=4;i++){
        cout<<i<<' '<<i+1<<' '<<random(1,10)<<endl;
    }
    for(int i=5;i<=10;i++){
        cout<<random(1,5)<<' '<<random(1,5)<<' '<<random(1,10)<<endl;
    }

    return 0;
}
