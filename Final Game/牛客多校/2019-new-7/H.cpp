#include<iostream>
#include<cstdio>
#include<cstring>
int A,B,C;
typedef long long ll;

// 记忆化状态
ll dp[33][2][2][2][2];

// 被动转移
ll dfs(int pos,bool ua,bool ub,bool uand,bool uxor) {
	// pos 当前在数字中的下标
	// ua 符号
	// ub 符号
	// uand 且 是否满足
	// uxor 抑或和 是否满足

    if(pos<0) return 1;
    if(dp[pos][ua][ub][uand][uxor]!=-1) return dp[pos][ua][ub][uand][uxor];
	// 记忆化

    int a=1,b=1,c1=1,c2=0;
    if(ua) a=A>>pos&1;
	if(ub) b=B>>pos&1;
	// 如果ua代表着贴着边界的的话，说明a还需要判断这一位是否为1
	// 如果ua == 0， 表示不贴合边界， 那么 a=1 就可以随意选？

    if(uand) c1=C>>pos&1; // uand=1 代表着，这一位还需要判断, 否则可以当作c1=1处理
    if(uxor) c2=C>>pos&1; // uxor=1 代表着，这一位还需要判断，否则可以当作c2=0处理

    ll ans=0;
	// 统计答案

	// 如果a=1，代表这一位，在A中有两个选择，
	// 如果b=1，同理
    for(int i=0;i<=a;i++)
		for(int j=0;j<=b;j++) {
	        if((i&j)>c1) continue; // 如果uand贴着走，说明有可能c1=0
	        if((i^j)<c2) continue; // 如果uxor贴着走，说明这一位可能c2=0, 随机选的话，c2=0, so (i^j)never samller than c2

			// pos-1，from high to lower position
			// ua=1 > not free to chose  // and  i is a means we along with the edge(equal value) again
			// ub and jb is equal
			// uand=1 > not free to chose // and (i&j)==c1 means i&j chose one together, and the c1 is 1 too
				// we want to count the situation x&y smaller c, so if c1 is 1 and i&j is 1, we along the "equal edge", we are not free
			// uxor=1 > not free to chose // and (x^j)==c2 means i^j==1 and c2 is 1, we along the side
				// we want xor is greater than c, so if i^j is 1 and c2 is zero, it meets our requirement
	        ans += dfs(pos-1,ua&&i==a,ub&&j==b,uand&&(i&j)==c1,uxor&&(i^j)==c2);
	    }
    return dp[pos][ua][ub][uand][uxor]=ans;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&A,&B,&C);
        memset(dp,-1,sizeof(dp));
        ll ans=dfs(30,1,1,1,1);
        ans-=std::max(0,A-C+1);
        ans-=std::max(0,B-C+1);
        printf("%lld\n",1LL*A*B-ans);
    }
    return 0;
}
