// CF 976C nested segment
// 线段贪心
// 知识点：
// 	用vector + pair 保存排序前的rank，并且排序
// 	pair的比较是先first 后 second
#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>,int>> a(312345);
int n;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int l,r;
	for(int i=0;i<n;i++){
		cin>>l>>r;
		a[i] = make_pair(make_pair(l,r),i+1);
	}
	sort(a.begin(),a.begin()+n);
	for(int i=0;i<n-1;i++){
		if(a[i].first.second >= a[i+1].first.second){
			cout<<a[i+1].second<<' '<<a[i].second<<endl;
			return 0;
		}
		else{
			if(a[i].first.first == a[i+1].first.first && a[i].first.second <= a[i+1].first.second){
				cout<<a[i].second<<' '<<a[i+1].second<<endl;
				return 0;
			}
		}
	}
	cout<<"-1 -1"<<endl;
	return 0;
}
/*
#include"bits/stdc++.h"
using namespace std;

int n, i, a, b;
vector<pair<pair<int, int>, int>> v;

int main() {
    cin>> n;

    for(i = 0; i < n; i ++){
        cin>> a >> b;
        v.push_back(make_pair(make_pair(a, b), i + 1));
    }
    sort(v.begin(), v.end());

    for(i = 0; i < n - 1; i ++){
        if(v[i + 1].first.second <= v[i].first.second){
            cout<< v[i + 1].second << " " << v[i].second << "\n";
            return 0;
        }else if(v[i].first.first == v[i + 1].first.first && v[i].first.second <= v[i + 1].first.second){
            cout<< v[i].second << " " << v[i + 1].second << "\n";
            return 0;
        }
    }
    cout<< "-1 -1\n";
}
*/
