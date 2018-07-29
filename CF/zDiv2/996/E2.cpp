// CF 996 leaving the bar
// 	一句话描述：
// 		贪心与几何，题解是巧妙的 贪心随记算法
// 	知识点：
// 		当贪心有可能失败时
// 			通过随机化，多次贪心，试图得到正解
// 		这个思路和【多次迭代找近似解】相似
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 100;

struct node {
  int id;
  ll x, y;
} data[maxn];

int ans[maxn];

int main()
{
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld %lld", &data[i].x, &data[i].y);
        data[i].id = i;
    }

    while(true) {
        ll tmp = 0;
        ll prex = data[1].x, prey = data[1].y;
        ans[data[1].id] = 1;

        ll t1, t2;
        for(int i = 2; i <= n; i++) {
            ll tx1 = prex - data[i].x;
            ll ty1 = prey - data[i].y;
            t1 = tx1 * tx1 + ty1 * ty1;

            ll tx2 = data[i].x + prex;
            ll ty2 = data[i].y + prey;
            t2 = tx2 * tx2 + ty2 * ty2;

             if(t1 < t2) {
                ans[data[i].id] = -1;
                prex = tx1;
                prey = ty1;
            }
            else {
                ans[data[i].id] = 1;
                prex = tx2;
                prey = ty2;
            }
    	}

	//     printf("%lld\n", tmp);
	    if(min(t1, t2) <= 2250000000000LL) {
	        break;
	    }
	    else {
	        random_shuffle(data + 1, data + n + 1);
	    }
	}

    for(int i = 1; i <= n; i++)
        printf("%d%c", ans[i], i == n ? '\n' : ' ');
}
