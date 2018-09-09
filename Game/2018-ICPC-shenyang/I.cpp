#include<bits/stdc++.h>
using namespace std;


struct Trie
{
    int next[500010][2],fail[500010],end[500010];
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 2;i++)
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
            if(next[now][buf[i]-'0'] == -1)
                next[now][buf[i]-'0'] = newnode();
            now = next[now][buf[i]-'0'];
        }
        end[now]++;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 2;i++)
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
            for(int i = 0;i < 2;i++)
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
            now = next[now][buf[i]-'0'];
            int temp = now;
            while( temp != root )
            {
                res += end[temp];
                // end[temp] = 0;
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
            for(int j = 0;j < 2;j++)
                printf("%2d",next[i][j]);
            printf("]\n");
        }
    }
};
Trie ac;


int main(){
	// printf("%c",33);
	int tt;cin>>tt;
	while(tt--){
		int len,n;
		map<string,char> mp;
		string s,bits,finals,out;

		cin>>len>>n;
		for(int i=0;i<n;i++){
			int ch;string code;
			cin>>ch>>code;
			mp[code] = (char)ch;
		}

		cin>>s;
		for(char ch:s){
			int num;
			string b;
			if(ch <= '9' && ch>= '0'){
				num = ch-'0';
			}
			else{
				if(ch <= 'Z' && ch >= 'A')
					num = 10 + (ch-'A');
				if(ch <= 'z' && ch >= 'a'){
					num = 10 + (ch-'a');
				}
			}
			while(num || b.size() < 4){
				if(num&1 == 1)b.push_back('1');
				else b.push_back('0');
				num>>=1;
			}
			reverse(b.begin(), b.end());
			bits += b;
		}
		// cout<<bits<<endl;

		for(int i=8;i<bits.size();i+=9){
			int num=0;
			string b;
			for(int j=i-8;j<i;j++){
				if(bits[j] == '1')num++;
				b.push_back(bits[j]);
			}
			if(num % 2 == 1 && bits[i] == '0'){
				finals += b;
			}
			if(num % 2 == 0 && bits[i] == '1'){
				finals += b;
			}
		}
		// cout<<finals<<endl;
		// cout<<finals<<endl;
		// ac.init();
		// for(auto i:mp){
		// 	string t = i.first;
		// 	cout<<"t = "<<t<<endl;
		// 	ac.insert(t);
		// }
		// ac.build();

		string c;
		for(auto i:finals){
			c.push_back(i);
			if(mp.count(c) != 0){
				// cout<<"c = "<<c<<endl;
				// cout<<"mp[c] = "<<mp[c]<<endl;
				out.push_back(mp[c]);
				c.clear();
			}
			if(out.size() == len)break;
		}
		cout<<out<<endl;
	}
	return  0;
}
