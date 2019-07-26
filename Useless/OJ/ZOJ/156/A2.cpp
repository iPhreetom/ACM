#include<iostream>
#include<iomanip>
#include<bits/stdc++.h>
#define int long long

using namespace std;
signed main()
{
	vector<int> v;
    const int n = 64;
    const int m = 2 * n-1;
    int arr[n + 1][m] = { 0 };
    for (int i = 0; i < n; i++)
    {
        arr[i][n - i- 1] = 1;
        arr[i][n + i -1] = 1;
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = n - i + 1; j < n-2+i; j = j + 2)
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
    }
    int p;
    for (int i = 0; i < n; i++)
    {
		int ans = 0;
        for (int j = 0; j < n - i - 1; j++)
            cout << "    ";
        p = 1;
        for (int j = n - i - 1; p < i + 2; j = j + 2)
        {
            cout << setw(4) << arr[i][j]%2 << "    ";
			if(arr[i][j]%2)ans++;
            p = p + 1;
        }
		cout << "   =   " << ans ;
        cout << endl;
		v.push_back(ans);
    }

	set<int> s;
	s.insert(1);
	s.insert(2);

	for (int i=0; i<v.size(); i++){
	    cout<<v[i]<<endl;
		if(s.count(v[i]) == 0) {
			s.insert(v[i]);
			cout<<"_____________________________" <<endl;
		}
	}
    return 0;
}
