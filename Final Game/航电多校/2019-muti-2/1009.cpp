// fyt
#include<bits/stdc++.h>
// #define int long long
#define double long double
#define endl '\n'
using namespace std;

namespace pam {
	const int N = 3e5+7;
    int t[N][26], fa[N], len[N], rs[N], cnt[N], num[N];
    int sz, n, last;
    int _new(int l) {
        memset(t[sz], 0, sizeof t[0]);
        len[sz] = l; cnt[sz] = num[sz] = 0;
        return sz++;
    }
    void init() {
        rs[n = sz = 0] = -1;
        last = _new(0);
        fa[last] = _new(-1);
    }
    int get_fa(int x) {
        while (rs[n - 1 - len[x]] != rs[n]) x = fa[x];
        return x;
    }
    void ins(int ch) {
        rs[++n] = ch;
        int p = get_fa(last);
        if (!t[p][ch]) {
            int np = _new(len[p] + 2);
            num[np] = num[fa[np] = t[get_fa(fa[p])][ch]] + 1;
            t[p][ch] = np;
        }
        ++cnt[last = t[p][ch]];
    }
}

vector<int> mp;
const int N=300005;
const int C=26;
vector<int> lis;

long long ans;
string str;
int n;

struct Palindrome_Tree
{
    int next[N][C],cnt[N],fail[N],len[N];
    int tot,suf;
	int indexof[N];

	int newnode()
    {
        for (int i=0;i<C;i++)
            next[tot][i]=0;
        cnt[tot]=0,fail[tot]=0;
        return tot++;
    }

	inline bool check(int L,int R) {
	    int mid=L+R>>1;
	    if ((L&1)==(R&1)) return lis[mid<<1]>=R-L+2;
	    return lis[mid<<1|1]>=R-L+1;
	}

	inline bool Check(int L,int R) {
	    int mid=L+R>>1;
	    if (!check(L,mid) || !check(mid+((L&1)!=(R&1)),R)) return false;
	    return true;
	}

    void init()
    {
        tot=0;
        int p;
        len[p=newnode()]=0;
        p=fail[p]=newnode();
        len[p]=-1;
        fail[p]=p;
        suf=0;
    }

    int getfail(int x,int l)
    {
        while (str[l-1-len[x]]!=str[l])
            x=fail[x];
        return x;
    }

    int insert(int x)
    {
        int c=str[x]-'a';
        int p=getfail(suf,x);
        if (!next[p][c])
        {
            int q=newnode();
            len[q]=len[p]+2;
            fail[q]=next[getfail(fail[p],x)][c];
            next[p][c]=q;
        }
        suf=next[p][c];
        cnt[suf]++;
		indexof[suf]=x;
        return suf;
    }

    void calc()
    {
        for (int i=tot-1;i>=0;i--)
        {
            // ans=max(ans,1ll*cnt[i]*len[i]);
			// cout << cnt[i]*len[i] << endl;
            cnt[fail[i]] += cnt[i];
        }

		for (int i=tot-1; i>=0; i--){
			if (len[i]>0) {
				int right = indexof[i]; // 右端点
				int left = right-len[i]+1; // 左端点
				int mid = (left+right)/2; // 中点
				int needlen = mid-left+1; // 应该有的长度
				int center = (left+mid);

				// if (lis[center] >= needlen) mp[len[i]] += cnt[i];
				mp[len[i]] += Check(left,right)*cnt[i];
			}
		}
    }
}t;

string make(string& s) {
    string t = "#";
    for (int i = 0; i < s.size(); i++) {
        t.push_back(s[i]);
        t.push_back('#');
    }
    return t;
}

void manacher(const string& s, vector<int>& d) {
    int n = s.size();
    d.resize(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d[l + r - i], r - i);
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
        d[i] = --k;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
}


signed main(){
	// ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(cin >> str) {
		mp.clear();
		mp.resize(str.size()+1);

		manacher(make(str),lis);
		t.init();
		for (int i=0; i<str.size(); i++){
			t.insert(i);
		}
		int sum = 0;
		t.calc();
		for (int i=0; i<str.size()*2; i++){
			cout << lis[i] << endl;
		}
		for (int i=1; i<mp.size(); i++){
			cout << mp[i] << " \n"[i==mp.size()-1];
		}
	}
	return 0;
}
