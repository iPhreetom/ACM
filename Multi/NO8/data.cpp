#include<bits/stdc++.h>
#define int long long
using namespace std;
#define random(a,b) ((a)+rand()%((b)-(a)+1))

stringstream ss;

signed main( int argc, char *argv[] )
{
	freopen("in.txt","w",stdout);
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
    // int t = random(1,1);
	int t = 10;
	cout<<t<<endl;
	while(t--){
		int n = random(60000,100000);
		cout<<n<<endl;
		int q = random(60000,100000);
		cout<<q<<endl;

		for (int i=0; i<n; i++){
			cout<<random(1,(1123456789))<<' ';
		}cout<<endl;

		for (int i=0; i<q; i++){
			cout<<random(1,n)<<' '<<random(1,1123456789)<<endl;
		}cout<<endl;
	}

    return 0;
}
