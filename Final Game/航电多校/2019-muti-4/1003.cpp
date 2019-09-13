#include<bits/stdc++.h>
using namespace std;

int T,n,k,L;

int main(){
  for (scanf("%d",&T);T;--T){
      scanf("%d%d",&n,&k);
      L=n/k;
      if(n==1&&k==1){
        printf("yes\n1\n");
        continue;
      }

      if (n==1||(n==k)||((L&1)&&((k&1)==0))){
          printf("no\n");
          continue;
      }

      if ((L&1)&&(L%k!=0)){
          if ((L%k)%2!=0) printf("no\n");
          else {
                printf("yes\n");
                for (int p=1;p<=k;++p){
                     int Pos=p,Res=L%k;
                     for (int i=1;i<=L-Res;++i){
                         printf("%d ",Pos+(i-1)*k);
                         ++Pos;
                         if (Pos>k) Pos=1;
                     }
                     Pos=p;
                     for (int i=L-Res+1;i<=L;++i){
                         printf("%d ",Pos+(i-1)*k);
                         Pos=k-Pos+1;
                     }
                     printf("\n");
                 }
         }
         continue;
      }
      printf("yes\n");
      if (L&1){
        for (int p=1;p<=k;++p){
            int Pos=p;
            for (int i=1;i<=L;++i){
                printf("%d ",Pos+(i-1)*k);
                ++Pos;
                if (Pos>k) Pos=1;
            }
            printf("\n");
        }
      }
      else {
        for (int p=1;p<=k;++p){
            int Pos=p;
            for (int i=1;i<=L;++i){
                printf("%d ",Pos+(i-1)*k);
                Pos=k-Pos+1;
            }
            printf("\n");
        }
      }
  }
  return 0;
}
