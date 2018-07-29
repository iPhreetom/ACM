// CF 703C road and bus
// 思维（暴力枚举）,枚举点的【计算几何】
// 知识点：
// 	枚举点，判断是否符合条件或者找到最大最小值
// 	探寻精度方法：
// 		在计算机几何没有cout!!!!

#include<bits/stdc++.h>
using namespace std;

int n;
double w,v,u;
double x[11234],y[11234];
double ee = 0;
double t,ans;

bool check(){
	bool lf=1,rt=1;
	for(int i=0;i<n;i++){
		double t = y[i]/u;
		if(x[i] - t*v < ee)lf = 0;
		else if(x[i]-t*v > ee)rt=0;
	}
	return (lf || rt);
}

bool ck(int i){
	for(int j=0;j<n;j++){
		if(y[j] < y[i]){
			if(x[j] - t*v > 0 || x[j]-t*v>1e-9){
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>w>>v>>u;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}


	if(check()){
		printf("%.10lf\n",w/u);
	}
	else{
		ans=w/u-ee;
		for(int i=0;i<n;i++){
			t = x[i]/v;
			double mx=-1e10 , mn=1e10;
			if(!ck(i)){
				continue;
			}
			else{
				double distance = min(u*t,y[i]);
				ans = max(ans,t + (w-distance)/u);
			}
			// ans = max(ans,)
			// for()
		}
		printf("%.10lf\n",ans);
	}

	return 0;
}
