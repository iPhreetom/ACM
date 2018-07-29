
#include<bits/stdc++.h>
using namespace std;

double x,y;
double lx=0,ly=0;
double cx,cy;
long long n;
string ch;
double cut;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>x>>y>>n;
	cx = x/2;
	cy = y/2;

	int less = 0;
	int wx = -1;
	int wy = -1;

	for(int i=0;i<n;i++){
		cin>>ch>>cut;
		// cout<<cx<<' '<<cy<<endl;
		if(ch == "H"){
			if(wy == -1){
				if(cut >= y){}
				else{
					if(cut == cy){
						wy = cut;
					}
					else{
						if(cut > cy){
							y = cut;
							cy = (ly+y)/2;
						}
						else{
							ly = cut;
							cy = (ly+y)/2;
						}
					}
				}
			}
			else{// == -1
				if(cut >= cy){
					y = wy;
					cy = (ly+y)/2;
					wy = -1;
				}
				else{
					ly = wy;
					cy = (ly+y)/2;
					wy = -1;
				}
			}
		}
		else{
			if(wx == -1){
				if(cut >= x){}
				else{
					if(cut == cx){
						wx = cut;
					}
					else{
						if(cut > cx){
							x = cut;
							cx = (lx+x)/2;
						}
						else{
							lx = cut;
							cx = (lx+x)/2;
						}
					}
				}
			}
			else{// ！= -1
				if(cut >= cx){
					x = wx;
					cx = (lx+x)/2;
					wx =-1;
				}
				else{
					lx = wx;
					cx = (lx+x)/2;
					wx =-1;
				}
			}
		}


		cout<<y<<' '<<ly<<"  --   "<<x<<' '<<lx<<endl;
		if(wx != -1){
			if(wy != -1){
				cout<<(int)((y-ly)*(x-lx)/4)<<endl;
			}
			else{
				cout<<(int)((y-ly)*(x-lx)/2)<<endl;
			}
		}
		else{
			cout<<(int)((y-ly)*(x-lx))<<endl;
		}

	}

	return 0;
}
