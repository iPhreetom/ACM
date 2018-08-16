#include<bits/stdc++.h>
using namespace std;
int T,n,k,ans,pos=-1;
char buf[60000000];
#define getchar_() buf[++pos]
inline int read(){
    register char c=getchar_();register int num=0;int sign=1;
    while(!isdigit(c)){if(c=='-')sign=-1;if(c==0)return -1;c=getchar_();}
    do{(num*=10)+=c-'0';c=getchar_();}while(isdigit(c));
    return sign*num;
}

int v[6];
vector<pair<int,int> > a[6];
int num[112345];
int c[112345][6];

int main(){
    // freopen("in.txt","r",stdin);
    fread(buf,1,sizeof(buf),stdin);
    T=read();
    while(T--){
		for (int i=0; i<6; i++){
			a[i].clear();
		}
        ans=0;
		n=read();k=read();
		memset(num,0,sizeof(num));
		memset(v,0,sizeof(v));

        for(int i=1;i<=k;i++){
            v[i]=read();
        }

        for(int i=1;i<=n;i++){
            for (int j=1; j<=k; j++){
				a[j].push_back(make_pair(read(),i));
			}
			for (int j=1; j<=k; j++){
			    c[i][j]=read();
			}
        }

		for (int j=1; j<=k; j++){
		    sort(a[j].begin(),a[j].end());
		}
		int point[6] = {0,0,0,0,0,0};
		while(1){
			bool update= 0;
			for (int j=1; j<=5; j++){
				for (int &i=point[j]; i<a[j].size(); i++){
					if(v[j] >= a[j][i].first){
						num[a[j][i].second]++;
						if(num[a[j][i].second] == k){
							update = 1;
							ans++;
							for(int q=1;q<=5;q++){
								v[q] += c[a[j][i].second][q];
							}
						}
					}
					else{
						break;
					}
				}
			}
			if(!update)break;
		}
        printf("%d\n",ans);
        printf("%d",v[1]);
        for (int i=2; i<=k; i++){
            printf(" %d",v[i]);
        }
        printf("\n");
    }
}
