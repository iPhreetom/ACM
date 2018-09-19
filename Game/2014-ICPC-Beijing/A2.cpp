#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

// struct POINT
// {
//     int t,x;
// }p[11000];
//
// bool cmp(POINT A,POINT B)
// {
//     return A.t<B.t;
// }

vector<pair<int,int> > p(11000);

int n;

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	cout<<fixed<<setprecision(2);
    int cas=1;
    int T_T;
    // scanf("%d",&T_T);
	cin>>T_T;
    while(T_T--)
    {
        // scanf("%d",&n);
		cin>>n;
        for(int i=0;i<n;i++)
        {
            int a,b;
			cin>>a>>b;
			p[i] = make_pair(a,b);
        }
        sort(p.begin(),p.begin()+n);

        double speed=0;
        for(int i=1;i<n;i++)
        {
            double X=abs(p[i].second-p[i-1].second)*1.0;
            speed=max(speed,X/(p[i].first-p[i-1].first));
        }
		cout<<"Case #"<<cas++<<": ";
		cout<<speed<<endl;
    }
    return 0;
}
// ？？？？
