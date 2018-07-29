#include<bits/stdc++.h>
using namespace std;

int pay[26];//已经处理过的花费
int place_min[26];
int book[25][200];//只有位置的记录
int cost[25][25][2];//每一个位置的花费最小值？
int n,m;
string s[25];
string c[25];
int a[25][25];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	memset(book,0,sizeof(book));
	memset(cost,0,sizeof(cost));


	for(int i=0;i<n;i++){
		cin>>s[i];
		c[i] = s[i];
		for(int j=0;j<m;j++){
			book[j][ s[i][j] ]++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j =0;j<m;j++){
			cin>>a[i][j];
		}
	}


	int ans = 0;
	for(int i=0;i<n;i++){
		//先搜索全部是否合格
		cout<<endl<<endl;
		cout<<i<<endl;
		cout<<ans<<endl;
		/*
		bug1:
			第一次更新后，不再更新
		*/
		for(int i=0;i<n;i++){
			cout<<s[i]<<endl;
		}
		cout<<endl;
		// cout<<ans<<endl;

		bool ok = 0;
		for(int j=0;j<m;j++){
			if(book[j][s[i][j]] == 1){
				ok = 1;
				break;
			}
		}

		line:
		if(ok){
			// cout<<"???"<<endl;
			pay[i] = 0;
		}
		else{//主要部分
			//一行的处理
			int mn = 99999999;
			int index = 0;

			//找到最小值
			//确定每个位置的最小花费
			for(int j=0;j<m;j++){
				int othercost = 0;
				for(int k=0;k<n;k++){
					if(k == i)continue;
					if(s[k][j] == s[i][j]){
						othercost += a[k][j];
						othercost -= pay[i];
					}
				}
				if(othercost > a[i][j]){
					cost[i][j][0] = a[i][j];
				}
				else{
					cost[i][j][1] = othercost;
				}

				if(mn > max(cost[i][j][0],cost[i][j][1])){
					mn = max(cost[i][j][0],cost[i][j][1]);
					index = j;
				}
				//get the min cost place and value
			}
			// printf("--%d %d xxxx \n",i,mn);

			//begin to choose
			//mn是这一行的花费
			pay[i] = mn;
			if(cost[i][index][1] != 0){
				//需要处理
				for(int i2=0;i2<n;i2++){
					if(i2 == i)continue;
					//用index
					int j = index;
					if(s[i2][j] == s[i][j]){
						for(int q='a';q<='z';q++){
							//选取一个没有出现过的数字
							if(book[j][q] == 0){
								book[j][q] = 1;
								book[j][s[i][j]]--;
								s[i2][j] = q;
								break;
							}
						}
						//当某一行等于xx的时候才需要处理
						//处理的方式是:把该行的值，减去
						//而

						//返还修改
						if(s[i2] != c[i2]){
							for(int q=0;q<m;q++){
								if(s[i2][q] != c[i2][q]){
									book[q][s[i2][q]]--;
									book[q][c[i2][q]]++;
								}
							}
							//并且处理pay
							ans -= pay[i2];
							//减去原有的花费
							pay[i2] = a[i2][index];
							ans += pay[i2];//加上新增的花费
							goto line;
						}

						// printf("在xx内的花费 : %d\n",ans);
					}

				}
			}
			else{
				//cost[i][index][1] == 0
				//修改的是自身
				// cout<<"????"<<endl;
				ans += mn;
				pay[i] = mn;
				for(int k='a';k<='z';k++){
					if(book[index][k] == 0){
						book[index][k] = 1;
						book[index][s[i][index]]--;
						s[i][index] = k;
						break;
					}
				}
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}
