// 930B Game on string
// 	一句话描述：
// 		头尾相连的字符串处理方法
// 	知识点：
// 		复制自己加在末端，就可以达到头尾相连的效果（而不用穷举）
// 		通过信息量，判断出最小信息量的写法（此题：长度，头尾字符）

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[26][5005][26];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string a;
	cin>>a;

	int len = a.size();
	for(int i=0;i<len;i++){
		a.push_back(a[i]);
	}

	for(int i=0;i<len;i++){
		for(int j=i+1;j<i+len;j++){
			cnt[a[i]-'a'][j-i][a[j]-'a']++;
		}
	}

	int sum=0;
	for(int i=0;i<26;i++){
		int maxn=0;
		for(int j=1;j<len;j++){
			int line=0;
			for(int k=0;k<26;k++){
				if(cnt[i][j][k]==1)line++;
			}
			maxn = max(maxn,line);
		}
		sum+=maxn;
	}

	printf("%.10f\n",(double)sum/len);
	// (double)sum;
	return 0;
}
