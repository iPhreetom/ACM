// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;



const int maxn=1000010;   //字符串长度最大值
int nt[maxn],ex[maxn]; //ex数组即为extend数组
//预处理计算nt数组
void GETnt(const string& str)
{
    int i=0,j,po;
	int len=str.size();
    nt[0]=len;//初始化nt[0]
    while(str[i]==str[i+1]&&i+1<len)//计算nt[1]
    i++;
    nt[1]=i;
    po=1;//初始化po的位置
    for(i=2;i<len;i++)
    {
        if(nt[i-po]+i<nt[po]+po)//第一种情况，可以直接得到nt[i]的值
        nt[i]=nt[i-po];
        else//第二种情况，要继续匹配才能得到nt[i]的值
        {
            j=nt[po]+po-i;
            if(j<0)j=0;//如果i>po+nt[po],则要从头开始匹配
            while(i+j<len&&str[j]==str[j+i])//计算nt[i]
            j++;
            nt[i]=j;
            po=i;//更新po的位置
        }
    }
}
//计算extend数组
void EXKMP(const string& s1,string& s2)
{
    int i=0,j,po,len=s1.size(),l2=s2.size();
    GETnt(s2);//计算子串的nt数组
    while(s1[i]==s2[i]&&i<l2&&i<len)//计算ex[0]
    i++;
    ex[0]=i;
    po=0;//初始化po的位置
    for(i=1;i<len;i++)
    {
        if(nt[i-po]+i<ex[po]+po)//第一种情况，直接可以得到ex[i]的值
        ex[i]=nt[i-po];
        else//第二种情况，要继续匹配才能得到ex[i]的值
        {
            j=ex[po]+po-i;
            if(j<0)j=0;//如果i>ex[po]+po则要从头开始匹配
            while(i+j<len&&j<l2&&s1[j+i]==s2[j])//计算ex[i]
            j++;
            ex[i]=j;
            po=i;//更新po的位置
        }
    }
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		string s;
		cin>>s;
		EXKMP(s,s);
		int sum = 0;
		for (int i=1; i<s.size(); i++){
			if (ex[i] == s.size()-i) sum += ex[i];
			else sum += ex[i]+1;
		}
		cout << sum << endl;
	}
	return 0;
}
