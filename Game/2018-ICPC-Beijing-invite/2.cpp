#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

struct Trie
{
    int next[100][26],fail[100],end[100];
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
    void insert(string &buf)
    {
        int len = buf.size();
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][buf[i]-'a'] == -1)
                next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        end[now]++;
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
    int query(string &buf)
    {
        int len = buf.size();
        int now = root;
        int res = 0;
        for(int i = 0;i < len;i++)
        {
            now = next[now][buf[i]-'a'];
            int temp = now;
            while( temp != root )
            {
                res += end[temp];
                end[temp] = 0;
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
Trie ac[11];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n){
		for (int i=1; i<=n; i++){
			ac[i].init();
		}

		string s;
		vector<string> arr;
		for (int i=1; i<=n; i++){
			cin>>s;
			s += s;
			arr.push_back(s);
		}

		auto cmp = [](string& a,string& b){return a.size() < b.size();};
		sort(arr.begin(),arr.end(),cmp);


		for (int i=0; i<arr.size(); i++){
		    cout<<arr[i]<<' ';
		}cout<<endl;
		for (int i=1; i<=n; i++){
			string s = arr[i-1];

			vector<string> tarr;
			for (int j=0; j<s.size()/2; j++){
				string tp = s.substr(j,s.size()/2);
				tarr.push_back(tp);
			}

			while(tarr[0].size() > 0){
				for (int j=0; j<tarr.size(); j++){
					ac[i].insert(tarr[j]);
				}
				for (int j=0; j<tarr.size(); j++){
					tarr[j].pop_back();
				}
			}

			ac[i].build();
		}

		string b = arr[0];
		vector<string> a;
		for(int i=0;i<b.size()/2;i++){
			a.push_back(b.substr(i,b.size()/2));
		}
		sort(a.begin(),a.end());

		bool flag = 1;
		while(flag){
			for (int i=0; i<a.size(); i++){
				int sum = 0;
				for (int j=2; j<=n; j++){
				    sum += ac[j].query(a[i])?1:0;
				}

				if(sum == n-1){
					cout<<a[i]<<endl;
					flag = 0;
					break;
				}
			}

			if(a[0].size() == 1){
				cout<<0<<endl;
				break;
			}

			for (int i=0; i<a.size(); i++){
				a[i].pop_back();
			}
		}
	}
	return 0;
}
