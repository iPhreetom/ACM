#include <bits/stdc++.h>
#define int long long
using namespace std;

#define ENABLE_DOUBLE_HASH

typedef long long LL;
typedef unsigned long long ULL;

const int x = 135;
const int N = 1e6 + 10;
const int p1 = 1e9 + 7, p2 = 1e9 + 9;
ULL xp1[N], xp2[N], xp[N];

void init_xp() {
    xp1[0] = xp2[0] = xp[0] = 1;
    for (int i = 1; i < N; ++i) {
        xp1[i] = xp1[i - 1] * x % p1;
        xp2[i] = xp2[i - 1] * x % p2;
        xp[i] = xp[i - 1] * x;
    }
}
struct String {
	string tep;
    char s[N];
    int length, subsize;
    bool sorted;
    ULL h[N], hl[N];
	ULL res1, res2;

    ULL hash() {
        length = strlen(s);
        ULL res1 = 0, res2 = 0;
        h[length] = 0;  // ATTENTION!
        for (int j = length - 1; j >= 0; --j) {
        #ifdef ENABLE_DOUBLE_HASH
            res1 = (res1 * x + s[j]) % p1;
            res2 = (res2 * x + s[j]) % p2;
            h[j] = (res1 << 32) | res2;
        #else
            res1 = res1 * x + s[j];
            h[j] = res1;
        #endif
        }
		for (int i=0; i<length/2; i++){
			swap(h[i],h[length-i-1])
		}
        return h[length-1];
    }

    // 获取子串哈希，左闭右开区间
    ULL get_substring_hash(int left, int right) const {
        int len = right - left;
    #ifdef ENABLE_DOUBLE_HASH
        // get hash of s[left...right-1]
        unsigned int mask32 = ~(0u);
        ULL left1 = h[left] >> 32, right1 = h[right] >> 32;
        ULL left2 = h[left] & mask32, right2 = h[right] & mask32;
        return (((left1 - right1 * xp1[len] % p1 + p1) % p1) << 32) |
               (((left2 - right2 * xp2[len] % p2 + p2) % p2));
    #else
        return h[left] - h[right] * xp[len];
    #endif
    }

	void add(const string &sub) {
		strcat(s,sub.c_str());
		for (int j = length; j <= length-1+sub.size(); j++) {
		#ifdef ENABLE_DOUBLE_HASH
			res1 = (res1 * x + s[j]) % p1;
			res2 = (res2 * x + s[j]) % p2;
			h[j] = (res1 << 32) | res2;
		#else
			res1 = res1 * x + s[j];
			h[j] = res1;
		#endif
		}
		length += sub.size();
		tep += sub;
	}

    void init(const char *t) {
        length = strlen(t);
        strcpy(s, t);
		tep = t;
    }
};


int nowbegin[212345];
string mp[212345];

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    init_xp();  // DON'T FORGET TO DO THIS!
	int n;
	cin >> n;

	String *S = new String;
	String *T = new String;
	string tp;
	cin >> tp;
	mp[1] = tp;
	S->init(tp.c_str());
	S->hash();
	int index = 0;


	for (int Q=2; Q<=n; Q++){
		cin >> mp[Q];
		tp = mp[Q];
		T->init(tp.c_str());
		T->hash();
		bool f = 0;
		for (int& i=index; i<S->tep.size(); i++){
			ULL val2 = T->get_substring_hash(0,min((int)S->tep.size()-i, (int)tp.size()));
			ULL val = S->get_substring_hash(i,min((int)S->tep.size(), i+(int)tp.size()));
			if (val == val2) {
				f = 1;
				if (S->tep.size() > i+tp.size()) {
					nowbegin[Q] = tp.size();
				}
				else {
					nowbegin[Q] = (int)S->tep.size() - i;
					index = 0;
					S->add(tp.substr(nowbegin[Q]));
					swap(S,T);
				}
				break;
			}
		}
		if (!f) {
			S->add(tp.substr(nowbegin[Q]));
			index = 0;
			swap(S,T);
		}
	}
	string ans;
	for (int i=1; i<=n; i++){
		cout<<"nowbegin[i] = "<<nowbegin[i]<<endl;
		for (int j=nowbegin[i]; j<mp[i].size(); j++){
			ans.push_back(mp[i][j]);
		}
	}
	cout << ans << endl;
}
