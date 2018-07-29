// CF 526C MOMO and candy
// 一句话描述
// 	贪心证明与优化（典型题目）
// 知识点：
// 	当贪心TLE时，怎么办：
// 		把贪心写短一点，然后DEBUG
// 		试图减小历遍的N值
//当质量大的（单位价值高）时：取尽量多的质量大的 -与- 去质量大的与质量小的一起（拼满）
//当质量小的比较好时，毫无疑问取XX

// w1/h1 >= w2/h2 1-小
// w1*h2 >= w2*h1 则取小
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	register long long c,h1,h2,w1,w2;
	cin>>c>>h1>>h2>>w1>>w2;
	//10 h:3 5  w: 2 3

	if(w1 == w2){
		if(h1 >= h2){
			cout<<c/w1*h1<<endl;
		}
		else{
			cout<<c/w2*h2<<endl;
		}
	}
	else{
		if(w1 < w2){
			swap(w1,w2);
			swap(h1,h2);
		}

		if(w1*h2 <= h1*w2){
			// big is good
			// cout<<"dd"<<endl;
			register long long val1 = (c/w1)*h1;
			register long long n = c/w1;

			register long long val2,n2;

			for(register long long i=0;i<=n;i++){

				n2 = (c - w1*(n-i) ) / w2;

				val2 = (n-i)*h1 + h2*n2;

				val1 = max(val1,val2);

				if(n2*w2 + (n-i)*w1 == c && i!=0)break;
			}
			cout<<val1<<endl;
		}
		else{
			// cout<<"dd"<<endl;
			register long long val1 = (c/w1)*h1;
			register long long n = c/w1;
			// cout<<val1<<endl;
			register long long val2,n2;

			for(register long long i=n;i>=0;i--){

				n2 = (c - w1*(n-i) ) / w2;
				// cout<<n2<<endl;

				val2 = (n-i)*h1 + h2*n2;

				val1 = max(val1,val2);

				if(n2*w2 + (n-i)*w1 == c && i!=0)break;
			}
			cout<<val1<<endl;
		}
	}

	return 0;
}
