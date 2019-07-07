#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

string toString(int i) {
    string ret;
    while(i > 0) {
        ret.push_back('0'+i%10);
        i/=10;
    }
    if (ret.size() == 1)ret.push_back('0');
    reverse(ret.begin(),ret.end());
    return ret;
}
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string name = "19-07-";
    vector<string> week = {"W1","W2","W3","W4","W5","W6","W7"};
    int index = 0;
    for (int i=1; i<=31; i++) {
        string file = name + toString(i) + "-" + week[index] + "__[]";
        index++;
        index %= (int)week.size();
        fstream out;
        out.open(file,ios::out);
        out << "Should I do? How to do. --" << i << " day" <<  endl;
        out.close();
    }
    return 0;
}
