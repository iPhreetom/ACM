#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

string mp[1123];
int draw[1123][1123];
vector<int> ans;
int n,m;

bool dfsup(int ii,int jj,int len){
	if(ii >= n)return 0;
	// cout<<ii+1<<' '<<jj+1<<' '; cout<<"len = "<<len<<endl;
	bool ok = 1;
	for (int i=0; i<=len; i++){
		if(ii-i < 0 || i+ii >= n || jj+i >= m || jj-i < 0)return 0;
		if(draw[ii][jj+i] == 1 || draw[ii-i][jj] == 1 || draw[ii+i][jj] == 1 || draw[ii][jj-i] == 1)ok = 0;//cout<<"len = "<<i<<endl;
	}

	if(ok){
		for (int i=0; i<=len; i++){
			draw[i+ii][jj] = 2;
			draw[ii-i][jj] = 2;
			draw[ii][jj+i] = 2;
			draw[ii][jj-i] = 2;
		}
		ans.push_back(ii+1);
		ans.push_back(jj+1);
		ans.push_back(len);

		return 1;
	}
	else return dfsup(ii+1,jj,len+1);
}

bool dfsdown(int ii,int jj,int len){
	if(ii < 0)return 0;

	bool ok = 1;
	for (int i=0; i<=len; i++){
		if(ii-i < 0 || i+ii >= n || jj+i >= m || jj-i < 0)return 0;
		if(draw[ii][jj+i] == 1 || draw[ii-i][jj] == 1 || draw[ii+i][jj] == 1 || draw[ii][jj-i] == 1)ok = 0;//cout<<"len = "<<i<<endl;
	}

	if(ok){
		for (int i=0; i<=len; i++){
			draw[i+ii][jj] = 2;
			draw[ii-i][jj] = 2;
			draw[ii][jj+i] = 2;
			draw[ii][jj-i] = 2;
		}
		ans.push_back(ii+1);
		ans.push_back(jj+1);
		ans.push_back(len);

		return 1;
	}
	else return dfsdown(ii-1,jj,len+1);
}

bool dfsleft(int ii,int jj,int len){
	if(jj < 0)return 0;

	bool ok = 1;
	for (int i=0; i<=len; i++){
		if(ii-i < 0 || i+ii >= n || jj+i >= m || jj-i < 0)return 0;
		if(draw[ii][jj+i] == 1 || draw[ii-i][jj] == 1 || draw[ii+i][jj] == 1 || draw[ii][jj-i] == 1)ok = 0;//cout<<"len = "<<i<<endl;
	}

	if(ok){
		for (int i=0; i<=len; i++){
			draw[i+ii][jj] = 2;
			draw[ii-i][jj] = 2;
			draw[ii][jj+i] = 2;
			draw[ii][jj-i] = 2;
		}
		ans.push_back(ii+1);
		ans.push_back(jj+1);
		ans.push_back(len);

		return 1;
	}
	else return dfsleft(ii,jj-1,len+1);
}

bool dfsright(int ii,int jj,int len){
	if(jj >= m)return 0;

	bool ok = 1;
	for (int i=0; i<=len; i++){
		if(ii-i < 0 || i+ii >= n || jj+i >= m || jj-i < 0)return 0;
		if(draw[ii][jj+i] == 1 || draw[ii-i][jj] == 1 || draw[ii+i][jj] == 1 || draw[ii][jj-i] == 1)ok = 0;//cout<<"len = "<<i<<endl;
	}

	if(ok){
		for (int i=0; i<=len; i++){
			draw[i+ii][jj] = 2;
			draw[ii-i][jj] = 2;
			draw[ii][jj+i] = 2;
			draw[ii][jj-i] = 2;
		}
		ans.push_back(ii+1);
		ans.push_back(jj+1);
		ans.push_back(len);

		return 1;
	}
	else return dfsright(ii,jj+1,len+1);
}

bool cant(int i,int j){
	if(dfsup(i+1,j,1)){

	}else if(dfsdown(i-1,j,1)){

	}else if(dfsleft(i,j-1,1)){

	}else if(dfsright(i,j+1,1)){

	}else {
		return 1;
	}

	return 0;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>m;
	for (int i=0; i<n; i++){
		cin>>mp[i];
		for (int j=0; j<m; j++){
			if(mp[i][j] == '.'){
				draw[i][j]=1;
			}
	    }
	}

	for (int i=0; i<n; i++){
	    for (int j=0; j<m; j++){
	        if(draw[i][j] == 0){
				if(cant(i,j)){
					cout<<"-1"<<endl;
					return 0;
				}
			}
	    }
	}

	if(ans.empty()){
		cout<<0<<endl;
		return 0;
	}
	cout<<ans.size()/3<<endl;
	for (int i=0; i<ans.size(); i+=3){
	    cout<<ans[i]<<' '<<ans[i+1]<<' '<<ans[i+2]<<'\n';
	}
	for (int i=0; i<n; i++){
	    for (int j=0; j<m; j++){
	        cout<<draw[i][j]<<' ';
	    }cout<<endl;
	}
	return 0;
}
