#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll,ll> > a,b;
ll n,m;
ll sa,sb;
bool f = 0;
int key = -1;

int play = 0;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>m;
	for(int i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		// if(y>x)swap(x,y);
		a.push_back(make_pair(x,y));
	}

	for(int i=0;i<m;i++){
		ll x,y;
		cin>>x>>y;
		// if(y>x)swap(x,y);
		b.push_back(make_pair(x,y));
	}

	for(int i=0;i<n;i++){
		int solve1 = 0,solve2=0;
		key = -1;
		for(int j=0;j<m;j++){
			if(b[j].first == a[i].first && b[j].second != a[i].second){
				if(key == -1){
					key = a[i].first;
				}
				else{
					if(key != b[j].first){
						f = 1;
					}
				}
			}
			if(b[j].first != a[i].first && b[j].second == a[i].second){
				if(key == -1){
					key = b[j].second;
				}
				else{
					if(key != a[i].second){
						f = 1;
					}
				}
			}
			if(b[j].first != a[i].second && b[j].second == a[i].first){
				if(key == -1){
					key = a[i].first;
				}
				else{
					if(key != a[i].first){
						f = 1;
					}
				}
			}
			if(b[j].first == a[i].second && b[j].second != a[i].first){
				if(key == -1){
					key = b[j].first;
				}
				else{
					if(key != b[j].first){
						f = 1;
					}
				}
			}
		}

		if(f){
			cout<<-1<<endl;
			return 0;
		}
		else{

			// from a to find b
			// may many case
			for(int j=0;j<m;j++){
				if(key == a[i].first){
					if(b[j].first == a[i].first && b[j].second != a[i].second){

						// b 是否能够确定key
						int find1 = 0,find2 = 0;
						int keyb = -1;
						for(int k=0;k<n;k++){
							if(b[j].first == a[k].first && b[j].second != a[k].second){
								if(keyb == -1){
									keyb = a[k].first;
								}
								else{
									if(keyb != b[j].first){
										f = 1;
									}
								}
							}
							if(b[j].first == a[k].second && b[j].second != a[k].first){
								if(keyb == -1){
									keyb = b[j].first;
								}
								else{
									if(keyb != b[j].first){
										f = 1;
									}
								}
							}
						}

						if(!f && keyb == key){
							play++;
						}
						else f = 1;
					}
					if(b[j].first != a[i].second && b[j].second == a[i].first){
						// b 是否能够确定key
						int find1 = 0,find2 = 0;
						int keyb = -1;
						for(int k=0;k<n;k++){
							if(b[j].first != a[k].first && b[j].second == a[k].second){
								if(keyb == -1){
									keyb = a[k].second;
								}
								else{
									if(keyb != b[j].second){
										f = 1;
									}
								}
							}
							if(b[j].first != a[k].second && b[j].second == a[k].first){
								if(keyb == -1){
									keyb = b[j].second;
								}
								else{
									if(keyb != b[j].second){
										f = 1;
									}
								}
							}
						}
						if(!f && keyb == key){
							play++;
						}
						else f = 1;
					}
				}
				if(key == a[i].second){
					if(b[j].first != a[i].first && b[j].second == a[i].second){
						// b 是否能够确定key
						int find1 = 0,find2 = 0;
						int keyb = -1;
						// from b find in a
						for(int k=0;k<n;k++){
							// 当b的第二个为
							if(b[j].first != a[k].first && b[j].second == a[k].second){
								if(keyb == -1){
									keyb = a[k].second;
								}
								else{
									if(keyb != b[j].second){
										f = 1;
									}
								}
							}
							if(b[j].first != a[k].second && b[j].second == a[k].first){
								if(keyb == -1){
									keyb = b[j].second;
								}
								else{
									if(keyb != b[j].second){
										f = 1;
									}
								}
							}
						}

						if(!f){
							play++;
						}
						else f = 1;
					}
					if(b[j].first == a[i].second && b[j].second != a[i].first){
						// b 是否能够确定key
						int find1 = 0,find2 = 0;
						int keyb = -1;
						for(int k=0;k<n;k++){
							if(b[j].first != a[k].first && b[j].second == a[k].second){
								if(keyb == -1){
									keyb = a[k].second;
								}
								else{
									if(keyb != b[j].second){
										f = 1;
									}
								}
							}
							if(b[j].first != a[k].second && b[j].second == a[k].first){
								if(keyb == -1){
									keyb = b[j].second;
								}
								else{
									if(keyb != b[j].second){
										f = 1;
									}
								}
							}
						}
						if(!f){
							play++;
						}
						else f = 1;
					}
				}
			}
		}
	}

	if(!f){
		if(play == 1){
			cout<<1<<endl;
		}
		if(play > 1){
			cout<<0<<endl;
		}
		if(play == 0){
			cout<<-1<<endl;
		}
	}
	else{
		cout<<-1<<endl;
	}
	return 0;
}
