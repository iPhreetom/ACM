// CF 527C glass carve
// 	一句话描述：
// 		点和边分开处理，STL的删减
// 	知识点：
// 		当对一个矩形切分后，得到的最大面积是最大的两个边的乘积
// 		set的erase(ite)
// 		set.find() 找不到返回end()


// 果然还是Clevel系列是适合我的提高的最棒的系列
#include<bits/stdc++.h>
using namespace std;



int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	unsigned long long i,t,w,h,n,p,l,r;
	char m;

	cin>>w;
	cin>>h>>n;
	multiset<unsigned long long > a,b;
	a.insert(w);a.insert(0);
	b.insert(h);b.insert(0);
	multiset<unsigned long long>::iterator it;

	multiset<unsigned long long> x,y;
	x.insert(w);y.insert(h);
	for(int i=0;i<n;i++){
		cin>>m>>p;
		if(m=='V'){
			a.insert(p);
			it=a.find(p);
			it--;
			l = *(it);
			it++;
			it++;
			r = *(it);
			it = x.find(r-l);
			x.erase(it);
			x.insert(p-l);
			x.insert(r-p);
		}else{
			b.insert(p);
			it=b.find(p);
			it--;
			l=*(it);
			it++;it++;
			r=*(it);
			it = y.find(r-l);
			y.erase(it);
			y.insert(r-p);
			y.insert(p-l);
		}
		auto it = y.end();
		auto it2 = x.end();
		cout<<(*(--it))*(*(--it2))<<endl;
	}
	return 0;
}
