#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename... types>
string format(const char *format, types ...args)
{ char buff[256]; sprintf(buff, format, args...); return buff; }

int main(int, char *[])
{
    for (int i = 1; i <= 10; i++) {
        freopen(format("test-%03d.in", i).data(), "w", stdout);
		srand(i);
		cout << 10000 << ' ' << 10000 << '\n';
		vector<string> v;
		unordered_set<string> id;
		while(id.size() < 10000) {
			string str;
			for (int j=0; j<4; j++){
			    str.push_back('A'+rand()%26);
			}
			str.push_back('-');
			for (int j=0; j<4; j++){
			    str.push_back('A'+rand()%26);
			}
			str.push_back('-');
			for (int j=0; j<4; j++){
			    str.push_back('A'+rand()%26);
			}
			str.push_back('-');
			for (int j=0; j<4; j++){
			    str.push_back('0'+rand()%10);
			}
			cout << str << '\n';
			v.push_back(str);
			id.insert(str);
		}
		random_shuffle(v.begin(),v.end());
		for (int i=0; i<1000; i++){
			string str;
			for (int j=0; j<4; j++){
			    str.push_back('A'+rand()%26);
			}
			str.push_back('-');
			for (int j=0; j<4; j++){
			    str.push_back('A'+rand()%26);
			}
			str.push_back('-');
			for (int j=0; j<4; j++){
			    str.push_back('A'+rand()%26);
			}
			str.push_back('-');
			for (int j=0; j<4; j++){
			    str.push_back('0'+rand()%10);
			}
			cout << str << '\n';
		}
		for (int i=0; i<4000; i++){
			cout << v[i] << '\n';
		}
		random_shuffle(v.begin(),v.end());
		for (int i=0; i<4000; i++){
			cout << v[i] << '\n';
		}
		for (int i=0; i<1000; i++){
			string str;
			for (int j=0; j<4; j++){
			    str.push_back('A'+rand()%26);
			}
			str.push_back('-');
			for (int j=0; j<4; j++){
			    str.push_back('A'+rand()%26);
			}
			str.push_back('-');
			for (int j=0; j<4; j++){
			    str.push_back('A'+rand()%26);
			}
			str.push_back('-');
			for (int j=0; j<4; j++){
			    str.push_back('0'+rand()%10);
			}
			cout << str << '\n';
		}
    }
    return 0;
}
