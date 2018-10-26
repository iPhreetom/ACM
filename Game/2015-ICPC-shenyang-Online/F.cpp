// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
char x[1123456];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	/*int t;
	cin>>t;
	for(int c=1;c<=t;c++){
		string s,f;
		int ans = 0;

		cin>>s;

		bool allf = 1;
		int p = 0;
		for (int i=0; i<s.size(); i++){
			if(s[i] == 'c'){
				allf = 0;
				p = i;
				break;
			}
		}

		if(allf){
			ans = (s.size()+1)/2;
		}
		else{
			bool can = 1;
			ans = 0;
			f = s.substr(0,p);
			s = s.substr(p);
			s += f;
			// cout<<"s = "<<s<<endl;
			for (int i=0; i<s.size(); i++){
				if(s[i] == 'c'){
					int num = 0;
					for (int j=i+1; j<s.size(); j++){
						if(s[j] == 'c')break;
						else num++;
					}
					if(num <= 1)can = 0;
					else ans++;
				}
			}

			if(can == 0){
				ans = -1;
			}
		}

		cout << "Case #" << c << ": " << ans << endl;
	}
	*/

	int TT;
	cin >> TT;
	for(int T = 1; T <= TT; T++)
	{
		cin >> x;
		int ccnt = 0, fcnt = 0, cf = -2123456, s = 1;
		for(int i = 0; i < strlen(x); i++)
		{
			if(x[i] != 'c' && x[i] != 'f')
			{
				s = 0;
				break;
			}
			if(x[i] == 'c')
			{
				if(cf == 0 || cf == 1)
				    s = 0;
				ccnt++;
				cf = 0;
				continue;
			}
			cf++;
			fcnt++;
		}
		for(int i = 0; i < strlen(x); i++)
		{
			if(x[i] == 'c')
			    break;
			cf++;
		}
		if(cf == 0 || cf == 1)
		    s = 0;

		cout << "Case #" << T << ": ";
		if(s == 0)
		    cout << -1 << endl;
		else
		{
			if(ccnt == 0)
			    cout << (fcnt + 1) / 2 << endl;
			else
			    cout << ccnt << endl;
		}
	}
	return 0;
}
