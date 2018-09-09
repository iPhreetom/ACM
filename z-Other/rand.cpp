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
    cout<<2<<endl;
    cout<<random(-100,100)<<endl;
    int r = random(0,100);
    cout<<r<<endl;
    cout<<random(-100,r)<<endl;

    for(int i=0;i<2;i++){
        for (int j=0; j<3; j++){
            cout<<random(-100,100)<<' '<<random(-100,100)<<' '<<random(0,1)<<endl;
        }
    }
    return 0;
}
