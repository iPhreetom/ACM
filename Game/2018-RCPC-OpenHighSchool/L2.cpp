// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t,n,a,b,k;
	cin>>t>>n>>a>>b>>k;
	int ans = 0;
	int numa = (n+1)/2;
	int numb = n/2;

	int sum = numa*a+numb*b;
	int maxp = sum/k;
	// maxp is ok , so we can just distribute the place to the student who is't attend k class
	// it is seem like a math problem, and I don't think it has a very intutive conclusion
	// oplus, I get a intuitive force solution to solve this proberm
	// let us sort the day, the odd week in the front, and the even week in the back
	// and form a a*numa rectangle and a b*numb rectangle.
	// putting them together, and regard them like a empty frame
	// then , we regard a people as a 1*k rectangle, we put it in the frame,
	// if the 1*k can't be put in the rectangle, we can split it into 1*x and 1*(k-x)
	// and this is the best way to distribute the student to the class
	//
	// we can using division, to O(1) fill one line,
	// but if the height is 1e9, we still get 1e9*O(1)
	// so, we can also, get the……
	// but wait, because they are two rectangle, when we fill the low big rectangle,
	// we put the 1*k into the higher and shorter part,
	// we can't splite the 1*k into 1*x and 1*(k-x) !!!!!
	// Oh god, I want to enjoy my dinner, farewell friends T_T

	return 0;
}
