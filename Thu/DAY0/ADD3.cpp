#include<iostream>
#include<cstdio>
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	setvbuf(stdin, new char[1<<20], _IOFBF, 1<<20);
	setvbuf(stdout, new char[1<<20], _IOFBF, 1<<20);
	int n;
	scanf("%d",&n);
	while(n--){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",a+b);
	}
	return 0;
}
