// CF 980C posterized
// 贪心
// 寻找最优解法
// 知识点：
// 	观察数据范围的方法
// 	贪心的证明，策略是否正确：一般方法：静下来HACK一波自己的贪心，看是否有漏洞
using namespace std;

int n,t,k,chose;
int book[256];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	for(int i=0;i<256;i++){
		book[i]=-1;
	}
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>t;
		if(i == 0){
			if(book[t]!=-1){
				cout<<book[t];
			}
			else{
				for(int j=t;j>=t-k;j--){
					// cout<<j<<endl;
					if(j == t-k || j == -1 ){
						j++;
						chose = j;
						for(int q=j;q<=t;q++){
							book[q] = chose;
						}
						// cout<<"asdf"<<endl;
						break;
					}
					else{
						if( book[j]!=-1 ){
							int len =0;
							for(int q=j;q>=0;q--){
								if(book[q] == book[j])len++;
								else break;
							}
							if(len + t-j <= k){
								for(int q=t;q>=j;q--){
									book[q] = book[j];
								}
							}
							else{
								j++;
								for(int q=j;q<=t;q++){
									book[q]=j;
								}
							}
							break;
						}
					}
				}
				cout<<book[t];
			}
		}
		else{
			if(book[t]!=-1){
				cout<<' '<<book[t];
			}
			else{
				for(int j=t;j>=t-k;j--){
					if(j == t-k || j == -1 ){
						j++;
						chose = j;
						for(int q=j;q<=t;q++){
							book[q] = chose;
						}

						break;
					}
					else{
						if( book[j]!=-1 ){
							int len =0;
							for(int q=j;q>=0;q--){
								if(book[q] == book[j])len++;
								else break;
							}
							if(len + t-j <= k){
								for(int q=t;q>=j;q--){
									book[q] = book[j];
								}
							}
							else{
								j++;
								for(int q=j;q<=t;q++){
									book[q]=j;
								}
							}
							break;
						}
					}
				}
				cout<<' '<<book[t];
			}
		}
	}
	cout<<endl;
// cout<<book[2]<<endl;
	return 0;
}
