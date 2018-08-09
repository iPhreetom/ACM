
#include <stdio.h>

#include <cstring>

#include <iostream>

#include <algorithm>

using namespace std;



const int maxn = 2e6+10;

char str[maxn];//初始字符串

char s[maxn<<1];//构造的新字符串

int p[maxn<<1]; //以s[i]为中心的最长回文子串的最右端到s[i]的位置的长度

int pos;//记录回文字符串中心位置



int mannacher(char *ss){

    int len=strlen(ss);

    int t=0;

    s[t++]='@';//防止数组越界

    //构造新字符串

    s[t++]='#';

    for (int i=0; i<len; i++){

        s[t++]=ss[i];

        s[t++]='#';

    }



    s[t]=0;

    int mx=0,id=0,ans=0;



    for (int i=0;i<t;i++){

        if (mx>i) p[i]=min(p[2*id-i],mx-i);

        else p[i]=1;

        while(s[i+p[i]]==s[i-p[i]]) p[i]++;

        if (i+p[i]>mx){

            mx=i+p[i];

            id=i;

        }

        if(p[i]-1>ans){

            ans=p[i]-1;

            pos=i;

        }

    }

    return ans; //最长回文串长度

}



int main(){

    char c,a[2];

    while(~scanf("%s %s",a,str)){

        c=a[0];

        int len=mannacher(str);//字符串s的最长回文子串长度

        if (len<2) printf("No solution!\n");

        else {

            int start=(pos-len+1)/2-1; //最大回文子串开始的位置

            int e=start+len-1;         //最大回文子串结束的位置

            printf("%d %d\n",start,e);

            int diff=c-'a';

            for (int i=start;i<=e;i++)

                (str[i]-'a'>=diff)?printf("%c",str[i]-diff):printf("%c",str[i]+26-diff);

            printf("\n");

        }

    }

    return 0;

}
