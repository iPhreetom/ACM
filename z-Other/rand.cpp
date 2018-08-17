#include<bits/stdc++.h>
#define int long long
using namespace std;
#define random(a,b) ((a)+rand()%((b)-(a)+1))

stringstream ss;

signed main( int argc, char *argv[] )
{
    int seed=time(NULL);
    if(argc > 1)//如果有参数
    {
        ss.clear();
        ss<<argv[1];
        ss>>seed;//把参数转换成整数赋值给seed
    }
    srand(seed);
    //以上为随机数初始化，请勿修改
    //random(a,b)生成[a,b]的随机整数

    //以下写你自己的数据生成代码
    // freopen("data.in","w",stdout);
    // int n = random(1,10);
	// cout<<n<<endl;
    // for (int i=0; i<n; i++){
    //     cout<<random(1,20)<<' ';
    // }
    // cout<<endl;
    // cout<<0<<endl;
    cout<<random(1,112345678)<<' '<<random(1,112345678)<<' '<<random(1,112345678)<<' '<<random(1,112345678)<<' '<<random(1,112345678)<<endl;
    return 0;
}
