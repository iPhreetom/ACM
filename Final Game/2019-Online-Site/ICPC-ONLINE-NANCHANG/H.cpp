// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

typedef long long ll;

const int M_SZ = 2;
using Mat = array<array<ll, M_SZ>, M_SZ>;

#define rep2 for (int i = 0; i < M_SZ; i++) for (int j = 0; j < M_SZ; j++)

void zero(Mat& a) { rep2 a[i][j] = 0; }
void one(Mat& a) { rep2 a[i][j] = (i == j); }

Mat mul(const Mat& a, const Mat& b, ll p) {
    Mat ans; zero(ans);
    rep2 if (a[i][j]) for (int k = 0; k < M_SZ; k++) {
        (ans[i][k] += a[i][j] * b[j][k]) %= p;
    }
    return ans;
}

Mat qk(Mat a, ll b, ll p) {
    Mat ans; one(ans);
    for (; b; b >>= 1) {
        if (b & 1) ans = mul(a, ans, p);
        a = mul(a, a, p);
    }
    return ans;
}
#undef rep2

const int mod = 998244353;


signed main(){
	// ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	Mat a;
	zero(a);
	a[0][0] = 0;
	a[1][0] = 1;

	Mat bs;
	zero(bs);
	bs[0][0] = 3;
    bs[0][1] = 2;
	bs[1][0] = 1;
	bs[1][1] = 0;

    int q;
    cin >> q;
    int n;
    cin >> n;

    int ans = 0;
    for (int i=0; i<q; i++) {
        cout<<"i = "<<i<<endl;
        cout<<"n = "<<n<<endl;
        cout<<"ans = "<<ans<<endl;
        if (n == 0) {
            ans ^= 0;
            n = n^0;
        }
        else if (n == 1) {
            ans ^= 1;
            n = n^1;
        }
        else {
            Mat temp = qk(bs,n-1,mod);
            a = mul(temp,a,mod);
            int now = a[0][0];
            ans ^= now;
            n ^= (now*now);
        }
    }
    cout<<"n = "<<n<<endl;
    cout << ans << endl;
	return 0;
}
