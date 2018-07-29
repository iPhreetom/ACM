#include<stdio.h>

 char *strassign(char *string,char *stringh){
	printf("请输入一个字符串\n");
  	 scanf("%s",string);
	  return string;
  }
 int strlength(char *string_mark){
  	int i;
  	while(string_mark[i]!='\0') i++;
  	return i;
  }
  int strcompare(char *string_mark,char *string_tom){
  	// int i=0,b=0;
  	//  while(string_mark[i]=string_tom[i])i++;
	 //这里 是比较么？
	 //比较是 == 呀

	  // b=int(string_mark[i])-int(string_tom[i]);
	  //意义不明？

	 int judge;

	 int length1=0, length2=0;


	 whlie( string_mark[length1] != '\0' )length1++;
	 while( string_tom[length2] != '\0')length2++;

	 if(length1 != length2)judge = 0;
	 if(length1 > )

	 return b;


  }
 char *strconnect(char *string_mark,char *string_tom)
 {  int i,m=strlength(string_mark),n=strlength(string_tom);
 	for(i=m;i<m+n;i++)
 	string_mark[i]=string_tom[i-m];
 	return string_mark;
 }
 char *substr(char *sub_string,char *string_mark,int a,int b){
 	int i;
 	for(i=0;i<b;i++)
 	{sub_string[i]=string_mark[a+i-1];}
	 return sub_string;
 }
 char *strcopy(char *string_mark,char *string_tom){
 	int i,n=strlength(string_tom);
 	for(i=0;i<n;i++) string_mark[i]=string_tom[i];
 	return string_mark;
 }
 int  strempty(char *string_mark){
 	printf("串判空，1为非空，0为空:\n");
	int m=strlength(string_mark);
	if(m) return 1; else return 0;
 }
 char *clearstring(char *string_mark){
 	string_mark[0]='\0';
 }
 int index(char *S,char *T,int pos){
 	int m,n,i;char sub[100];
 	if(pos>0){
      n=strlength(S);  m=strlength(T); i=pos;
      while(i<=n-m+1){
        substr(sub,S,i,m);
        if(strcompare(sub,T)!=0) ++i;
        else return i;  //返回子串在主串中的位置
      }//while
   }//if
    return 0;    // S中不存在与T相等的子串
}//Index
char *replace(char *S,char *T,char *V)
  {  int i,j,k,b=strlength(V),a=strlength(T);
   i=index(S,T,1);
   for(j=i+b,k=0;j<i+b+a;k++,j++) S[j+b]=S[i+a];
   for(j=i,k=0;j<i+b;k++,j++) S[j]=V[k];
   return S;
 }


 int main (){
	 char string_mark[100];
	 strassign(string_mark,"my name is mark");//1
	 printf("string_mark的字符串为%s\n", string_mark);
	 char string_tom[100];
	 strassign(string_tom,"my name is tom");
	 printf("string_tom的字符串为%s\n", string_tom);
	 int mark_length;
	 mark_length=strlength(string_mark);//2
	 printf("string_mark长度为%d\n", mark_length);
	 int b=strcompare(string_mark,string_tom);//3
	  if(b>0)printf("string_mark大\n");
	 else if(b<0) printf("string_tom大\n");
	 else printf("string_tom和string_mark一样大\n");
	 strconnect(string_mark,string_tom);//4
	 printf("把二个字符串连接到第一个后为%s\n", string_mark);
	 char sub_string[100];
	 substr(sub_string,string_mark,2,7);//5
	 printf(" string_mark的子串，从第二个开始数7个是%s\n", sub_string);
	 strcopy(sub_string,string_mark);
	 printf("string_mar拷贝到sub_string后为%s\n",sub_string);
	 int a=strempty(sub_string);printf("%d\n",a);
	 clearstring(sub_string);printf("清空后为%s\n",sub_string);
	 int c=index(string_mark,string_tom,1);printf("string_tom子串的位置是%d\n",c);
	 char V[100]={"abcdefg"};
	 replace(string_mark,string_tom,V);
 	return 0;
}
