
 // qdd on Nov 24, 2018

#include <bits/stdc++.h>
using namespace std;

int n;
string s, t;
map<string, int> mp;

void init() {
    mp["bool"] = 1;
    mp["char"] = 1;
    mp["int"] = 4;
    mp["long long"] = 8;
    mp["__int128"] = 16;
    mp["float"] = 4;
    mp["double"] = 8;
    mp["long double"] = 16;
}

long long solve() {
    cin >> n;
    long long ret = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "long") {
            s.push_back(' ');
            cin >> t;
            s += t;
        }
        int sz = mp[s];
        cin >> s;
        int j = 0;
        for (; j < s.size(); j++) {
            if (s[j] == '[') {
                j++;
                break;
            }
        }
        if (j == s.size()) {
            ret += sz;
        } else {
            int len = 0;
            for (; j < s.size(); j++) {
                if (s[j] == ']') break;
                len = len * 10 + s[j] - '0';
            }
            ret += sz * len;
        }
    }
    return (ret + 1023) / 1024;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    init();
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": " << solve() << '\n';
    }
    return 0;
}
