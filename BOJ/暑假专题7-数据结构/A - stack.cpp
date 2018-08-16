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
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(1){
		int n,t,ans=0;
		int top_index;
		int index2;
		stack<int> st;
		vector<int> arr;

		cin>>n;
		if(n == 0)break;
		for (int i=0; i<n; i++){
			cin>>t;
			arr.push_back(t);
			while(!st.empty() && t < arr[st.top()]){
				if(st.size() == 1){
					ans = max(ans,i*arr[st.top()])
				}
				else{
					int index = st.top();
					st.pop();
					if(index2 == 0){
						index2 = 
					}
				}

				st.pop();


				ans = max(t * (i-index+1),ans);
				ans = max(arr[index] * (i-index),ans);
				if(st.empty()){
					ans = max(ans,i*arr[index]);
				}
			}
			st.push(i);
			top_index = i;
		}
		while(!st.empty()){
			int index = st.top();
			t = arr[index];
			st.pop();
			if(st.empty()){
				ans = max(ans,n*t);
			}
			ans = max(t * (top_index-index+1),ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}
