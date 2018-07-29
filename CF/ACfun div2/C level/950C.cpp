// CF 950C 0 and 1
// 	一句话描述：
// 		使用二分查找模拟
// 	知识点：
		// upper_bound
		// 	在STL所有容器中都可以使用
		// 	set 和 map，这些非连续内存的upper_bound
		// 		需要使用xx.upper_bound（）的方法
		// 		否则复杂度on
// 		earse
// 			可以先earse，然后继续用ite
// 			保证不会被earase不会被忘记
// 		list
// 			list 的插入和删除都是o(1)的
// 			list 不支持sort
// 			list 支持upper_bound

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

string a;
string b;
vector<vector<ll> > ans(212345);
string res[212345];
ll index = 0;
set<ll> zero;
set<ll> one;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	// set<ll> se;

	// for(int i=1;i<1000;i++){
	// 	se.insert(i);
	// }
	// auto i = lower_bound(se.begin(),se.end(),23);
	// cout<<*i<<endl;
	// auto j = upper_bound(se.begin(),se.end(),23);
	// cout<<*j<<endl;

	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]=='1')one.insert(i+1);
		else zero.insert(i+1);
	}

	// for(int i=0;i<a.size();i++){
	// 	if(a[i]=='1')one.push_back(i+1);
	// 	else zero.push_back(i+1);
	// }

	// sort(zero.begin(),zero.end());
	// sort(one.begin(),one.end());

	// if(a.size()>123456)cout<<one.size()<<endl;
	bool ok = 1;

	while(!zero.empty() && !one.empty()){
		auto i = zero.begin();
		auto j = one.begin();

		while(1){
			// j = upper_bound(one.begin(),one.end(),*i);
			j = one.upper_bound(*i);

			if(j == one.end()){
				ans[index++].push_back(*i);
				zero.erase(i);
				break;
			}
			else{
				ans[index].push_back(*i);
				zero.erase(i);

				i = upper_bound(zero.begin(),zero.end(),*j);
				// i = zero.upper_bound(*j);

				ans[index].push_back(*j);
				one.erase(j);

				if(i == zero.end()){
					cout<<-1<<endl;
					// break;
					return 0;
				}
			}
		}
	}

	// if(a.size()>123456)cout<<a.size()<<endl;

	if(zero.empty() && !one.empty())ok=0;
	if(ok){
		if(!zero.empty()){
			// if(zero.size()>1234)cout<<zero.size()<<endl;
			for(auto i:zero){
				ans[index++].push_back(i);
			}
		}
		cout<<index<<endl;
		for(int i=0;!ans[i].empty();i++){
			cout<<ans[i].size()<<' ';
			for(int j=0;j<ans[i].size();j++){
				cout<<ans[i][j]<<' ';
			}
			cout<<'\n';
		}
	}
	else{
		cout<<-1<<endl;
	}


	// bool ok=1;
	// bool find = 0;
	//
	// while(ok && (!a.empty() || !b.empty())){
	// 	for(int i=0;i<a.size();i++){
	// 		if(find == 0){
	// 			if(a[i]=='0'){
	// 				find = 1;
	// 				ans[index].push_back(i);
	// 			}
	// 			else{
	// 				ok = 0;
	// 			}
	// 		}
	// 		else{
	// 			if(a[i]=='1'){
	//
	// 			}
	// 			else{
	// 				b.push_back(a[i]);
	// 			}
	// 		}
	// 	}
	// }
	return 0;
}
