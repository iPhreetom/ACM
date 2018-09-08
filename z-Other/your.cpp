#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
ll n;
ll priA[maxn]; //分解质因数的各项

int main() {
    scanf("%I64d", &n);
    ll p = n;
    int t = 0;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            n /= i; t++; priA[t] = i; i--;
        }
    }
    priA[t + 1] = n;
    printf("%I64d = ", p);
    for(int i = 1; i <= t; i++) printf("%I64d * ", priA[i]);
    printf("%I64d\n", priA[t + 1]);
}
