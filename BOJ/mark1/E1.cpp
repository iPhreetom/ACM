#include<bits/stdc++.h>
using namespace std;

long long a[1000005];
long long fin[1000005];
vector<long long> ans;
long long n,k;
long long index0 = 1;
long long eated_left = 0;

void solve(){
	long long ifin;//正在比对f[ifin]
	long long l=0,r;//从l（含）,到r内，取准备开始

	long long sum=0;

	//check
	for(long long i=0;i<n;i++){
		sum += a[i];
	}
	for(long long i=k-1;i>=0;i--){
		sum -= fin[i];
	}
	if(sum != 0){
		cout<<"NO"<<endl;
		return ;
	}

	for(long long i=0;i<k;i++){
		sum  = 0;

		for(long long j=l;j<n;j++){//find
			sum += a[j];

			if(sum > fin[i]){
				cout<<"NO"<<endl;
				return ;
			}

			if(sum == fin[i]){
				// printf("sum %d\n",sum);
				r = j;// j is 3
				if(r == l){
					l++;
					break;//直接找到就过去
				}
				else{
				 	long long same = a[l];
					long long mx = -1;

					//判断所有元素是否相等
					//先找到最大值
					for(long long q=l;q<=r;q++){
						if(mx < a[q])mx = a[q];
						if(a[q] != same)same = -1;
					}
					// printf("l: %d r: %d mx:%d\n",l,r,mx);

					if(same != -1){
						cout<<"NO"<<endl;
						return ;
					}

					long long eated_right = 0;
					//先左后右原则
					if(a[l] != mx){
						for(long long q=l;q<=r;q++){
							if(a[q] == mx){
								for(long long c=l;c<q;c++){
									//注意，左边被吃点了多少个,下表就减对应数字
									//注意：我们是从0开始读的下表
									ans.push_back(q + index0 - eated_left);
									ans.push_back(-2);//-1表示向右 -2表示向左
									eated_left++;
								}

								for(long long c=0;c<(r-q);c++){
									ans.push_back(q + index0 - eated_left);
									ans.push_back(-1);
									eated_right++;
								}
								break;
							}
						}
					}

					//先右后左原则
					else{
						for(long long q=l;q<=r;q++){
							if(a[q] != mx){
								q -= 1;
								// printf("now : %d\n",eated_left);
								for(long long c=0;c<(r-q);c++){
									ans.push_back(q + index0 - eated_left);
									ans.push_back(-1);
									eated_right++;
								}

								for(long long c=l;c<q;c++){
									//注意，左边被吃点了多少个,下表就减对应数字
									//注意：我们是从0开始读的下表
									ans.push_back(q + index0 - eated_left);
									ans.push_back(-2);//-1表示向右 -2表示向左
									eated_left++;
								}
								break;
							}
						}
					}
					eated_left += eated_right;
				}
				//final
				l = j+1;
				break;
			}

			if(sum < fin[i]){
				continue;
			}
		}
	}

	bool ap = 0;
	cout<<"YES"<<endl;
	for(long long i=0;i<ans.size();i++){
		if(ap){
			if(ans[i] == -1){
				cout<<" R\n";
			}
			else{
				cout<<" L\n";
			}
		}
		else{
			cout<<ans[i];
		}
		ap = !ap;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>k;
	for(long long i=0;i<k;i++){
		cin>>fin[i];
	}

	solve();
	return 0;
}
