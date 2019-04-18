#include<bits/stdc++.h>
using namespace std;


signed main() {
    int t;
    cin >> t;
    while(t--) {
		vector<int> lt;
		vector<int> rt;
		vector<char> val;
		int cnt = 0;

        int n,b,f;
        cin >> n >> b >> f;

		string ask;
        if (n<16) {
			for (int i=0; i<n/2; i++) {
				ask.push_back('0');
			}
			for (int i=n/2; i<n; i++) {
				ask.push_back('1');
			}
			lt.push_back(0);
			rt.push_back(n/2-1);
			val.push_back('0');
			lt.push_back(n/2);
			rt.push_back(n-1);
			val.push_back('1');
		}
		else {
			bool one = 0;
			int cnt = 0;
			for (int i=0; i<n; i+=16) {
				lt.push_back(cnt*16);
				rt.push_back(min((cnt+1)*16,n));
				val.push_back(one?'1':'0');
				one = !one;
				cnt++;
			}
		}
		set<int> ans;
		for (int c=1; c<=5; c++) {
			cout << ask << endl;
			string feedback;
			cin >> feedback;

			vector<int> ltn;
			vector<int> rtn;
			vector<char> valn;
			bool one = 0;
			int index = 0;
			for (int i=0; i<val.size(); i++) {
			    for (int j=lt[i]; j<=rt[i]; j++) {
					cout << "j = " << j << endl;
					cout << "index = " << index << endl;
			        if(feedback[index] != val[i]) {
						if(lt[i] == rt[i]) {
							ans.insert(i);
							ltn.push_back(lt[i]);
							rtn.push_back(rt[i]);
							valn.push_back(one?'1':'0');
							one = !one;
						}
						else {
							ltn.push_back(lt[i]);
							rtn.push_back((lt[i]+rt[i])/2-1);
							valn.push_back(one?'1':'0');
							one = !one;
							ltn.push_back((lt[i]+rt[i])/2);
							ltn.push_back(rt[i]);
							valn.push_back(one?'1':'0');
							one = !one;
						}
						break;
					}
					else {
						index++;
						if(j == rt[i]) {
							ltn.push_back(lt[i]);
							rtn.push_back(rt[i]);
							valn.push_back(one?'1':'0');
							one = !one;
						}
					}
			    }
			}
			cout << "ltn.size() = " << ltn.size() << endl;
			lt = ltn;
			cout << "lt.size() = " << lt.size() << endl;
			for (int i=0; i<lt.size(); i++) {
			    cout << lt[i] << ' ';
			}
			cout << endl;
			rt = rtn;
			val = valn;
			if(ans.size() == b)break;
		}
		for (auto i:ans){
			cout << i+1 << ' ';
		}
		cout << endl;
		int v; cin >> v;
		if (v) continue;
		else break;
    }
	return 0;
}
