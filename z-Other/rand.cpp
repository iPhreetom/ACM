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
    cout<<1000<<endl;
    int q = 1000;
    while(q--){
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                int t = random(1,4);
                if(t % 4 == 0)cout<<'C';
                else if(t % 4 == 1)cout<<'T';
                else if(t % 4 == 2)cout<<'Z';
                else cout<<'.';
            }
            cout<<endl;
        }
    }

    return 0;
}
