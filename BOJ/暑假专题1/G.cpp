#include<bits/stdc++.h>
// #define int long long
// #define double long double
using namespace std;

double x[51234],w[51234];
int n;
double l,r,boundleft,boundright;

inline bool readdouble(double &ret) {
    int sgn;//浮点的正负
    double bit=0.1;//小数点后的权重
    char c;
    c=getchar();
    if(c==EOF) return false;
    while(c!='-'&&c!='.'&&(c<'0'||c>'9')) c=getchar();//如果输入的既不是整数又不是-号又不是.则跳过
    sgn=(c=='-')?-1:1;//记录符号
    ret=(c=='-')?0:c-'0';//记录初始值
    while((c=getchar())>='0'&&c<='9') ret=ret*10+c-'0';//将输入转换成整数形式
    if(c==' '||c=='\n') {//输入已经停止没有出现小数位
        ret*=sgn;
        return true;
    }
    while((c=getchar())>='0'&&c<='9') ret+=bit*(c-'0'),bit/=10;//小数点后的转换
    ret*=sgn;//加上符号
    return true;
}

inline double sum(double a){
	double ret = 0;
	for(int i=0;i<n;i++){
		ret += w[i]*abs(x[i]-a)*abs(x[i]-a)*abs(x[i]-a);
	}
	return ret;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	// cin>>t;
	scanf("%d",&t);
	for(int q=1;q<=t;q++){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			readdouble(x[i]);
			readdouble(w[i]);
		}

		l = x[0]+(x[n-1]-x[0])/3.0;
		r =  x[0]+(x[n-1]-x[0])/3.0*2.0;
		boundleft = x[0];
		boundright = x[n-1];

		for(int i=0;l<r;i++){
			double lnum = sum(l);
			double rnum = sum(r);
			if(lnum < rnum){
				boundright = r;
				l = boundleft + (boundright-boundleft)/3.0;
				r = boundleft + (boundright-boundleft)/3.0*2.0;
			}else{
				boundleft = l;
				l = boundleft + (boundright-boundleft)/3.0;
				r = boundleft + (boundright-boundleft)/3.0*2.0;
			}
			// else {
			// 	boundleft = l;
			// 	boundright = r;
			// 	l = boundleft + (boundright-boundleft)/3;
			// 	r = boundleft + (boundright-boundleft)/3*2;
			// }
		}
		// cout<<"Case #"<<q<<": "<<(long long)(sum(r)+0.5)<<endl;
		printf("Case #%d: %lld\n",q,(long long)(min(sum(l),sum(r))+0.5));
	}
	return 0;
}
