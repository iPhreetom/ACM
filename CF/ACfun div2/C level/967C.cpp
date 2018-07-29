// CF 967C stairs and elevators
// 爆搜（贪心） + 二分lower_bound
// 知识点：
// 	使用stl的两个边界函数
// 	漏情况的：bug竟然是，同层的情况没有考虑！

long long st[112345];
long long el[112345];
long long n,m,q,ns,ne,v,x1,x2,y1,y2;

//
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>ns>>ne>>v;

	for(long long i=1;i<=ns;i++){
		cin>>st[i];
	}
	sort(st+1,st+ns+1);
	// for(int i=1;i<=ns;i++){
	// 	cout<<st[i]<<' ';
	// }
	// cout<<endl;

	for(long long i=1;i<=ne;i++){
		cin>>el[i];
	}
	// printf("elevators:");
	sort(el+1,el+ne+1);
	// for(int i=1;i<=ne;i++){
	// 	cout<<el[i]<<' ';
	// }
	// cout<<endl;

	cin>>q;
	while(q--){
		cin>>x1>>y1>>x2>>y2;
		swap(x1,y1);
		swap(x2,y2);
		if(y1 == y2){
			cout<<abs(x1-x2)<<endl;
			continue;
		}
		long long lfst=-1,rtst=-1,lfel=-1,rtel=-1;
		lfst = lower_bound(st+1,st+ns+1,x1)-(st+1);//index
		// cout<<"index:"<<lfst<<endl;
		lfst = st[lfst];// position
		// printf("lf-lf-rt-rt %lld\n",lfst);

		lfel = lower_bound(el+1,el+ne+1,x1)-(el+1);
		lfel = el[lfel];
		// printf("lf-lf-rt-rt %lld\n",lfel);
		//great idea : from 0 begin, and judge if it is zero

		rtst = upper_bound(st,st+ns+1,x1)-(st);//index
		rtst = st[rtst];// position
		// printf("lf-lf-rt-rt %lld\n",rtst);

		rtel = upper_bound(el,el+ne+1,x1)-(el);
		rtel = el[rtel];
		// printf("lf-lf-rt-rt %lld\n",lfel);
		// if it is not exsit
		if(lfst)lfst = abs(x1-lfst) + abs(y2-y1) + abs(x2-lfst);
		else lfst = (1<<30);

		if(lfel)lfel = abs(x1-lfel) + ((abs(y2-y1)-1)/v+1) + abs(x2-lfel);
		else lfel = (1<<30);

		if(rtst)rtst = abs(x1-rtst) + abs(y2-y1) + abs(x2-rtst);
		else rtst = (1<<30);

		if(rtel)rtel = abs(x1-rtel) + ((abs(y2-y1)-1)/v+1) + abs(x2-rtel);
		else rtel = (1<<30);

		long long ans = min(min(lfst,lfel),min(rtst,rtel));
		cout<<ans<<endl;

		/*
		12 12 2 2 3
		1 8
		2 7
		3
		*/
	}

	return 0;
}
// such as 1 2 3 4 5 6 7
// 1 3 5
// 2 4

// 4 7 3 2 1
// 1 3 5
// 2 4
// 2
// 6 2  7 3
// 1 2 3 4
// cout<<lfst<<" "<<lfel<<endl;
