
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <climits>
#include <cstdio>
#include <complex>
#include <numeric>
#include <cassert>
#include<unordered_map>
#define int long long
#define double long double
using namespace std;

// multimap<string,int> mp;
unordered_map<int,int> str_mp;
map<string,int> mp;
vector<string> str;
vector<int> ans;


struct Trie
{
    int next[500010][26],fail[500010],end[500010];
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 26;i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(string &buf,int index)
    {
        int len = buf.size();
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][buf[i]-'A'] == -1)
                next[now][buf[i]-'A'] = newnode();
            now = next[now][buf[i]-'A'];
        }
        end[now]++;
		str_mp[now] = index;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 26;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while( !Q.empty() )
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < 26;i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    int ask(string &buf)
    {
        int len = buf.size();
        int now = root;
        int res = 0;
        for(int i = 0;i < len;i++)
        {
			if(buf[i] > 'Z' || buf[i] < 'A'){
				now = root;
				continue;
			}

            now = next[now][buf[i]-'A'];
            int temp = now;
            while( temp != root )
            {
				if(end[temp]) ans[str_mp[temp]] += end[temp];
                res += end[temp];
                temp = fail[temp];
            }
        }
        return res;
    }
    void debug()
    {
        for(int i = 0;i < L;i++)
        {
            printf("id = %3d,fail = %3d,end = %3d,chi = [",i,fail[i],end[i]);
            for(int j = 0;j < 26;j++)
                printf("%2d",next[i][j]);
            printf("]\n");
        }
    }
};
char buf[1000010];
Trie ac;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n){
		ac.init();
		// mp.clear();
		str_mp.clear();
		ans.clear();
		str.clear();

		for (int i=0; i<n; i++){
			string r;
			cin>>r;
			ac.insert(r,i);
			// cout<<"??"<<endl;
			str.push_back(r);
			ans.push_back(0);
		}
		ac.build();
		string s;
		cin>>s;
		ac.ask(s);

		for (int i=0; i<ans.size(); i++){
		    if(ans[i]){
				cout<<str[i]<<": "<<ans[i]<<endl;
			}
		}
	}

	return 0;
}
