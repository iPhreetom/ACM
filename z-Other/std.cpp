#include<stdio.h>
#include<queue>
#include<iostream>
#include<string.h>
using namespace std;
    int main() {
        int t;
        scanf("%d",&t);
        for(int p=1;p<=t;p++){
            int n;
            scanf("%d",&n);
            int m;
            scanf("%d",&m);
            int arr[205][205];
            memset(arr,0,sizeof(arr));
            queue<int> q;
            int temp;
            for(int i=0;i<m;i++){
                scanf("%d",&temp);
                q.push(temp%13);
            }
            for(int i=0;i<5*n;i++){
                if(q.empty())
                    break;
                arr[i/5][q.front()]++;
                q.pop();
            }
            int nowcard=0,nowplayer=0;
            for(int i=3;i<=15;i++){
                if(arr[0][i%13] != 0){
                    nowcard=i%13;
                    arr[0][i%13]--;
                    break;
                }
            }
            int lastplayer=0;
            while(true){
                nowplayer=(nowplayer+1)%n;
                if(lastplayer==nowplayer){
                    for(int i=0;i<n;i++){
                        if(q.empty())
                            break;
                        arr[(nowplayer+i)%n][q.front()]++;
                        q.pop();
                    }
                    for(int i=3;i<=15;i++){
                        if(arr[nowplayer][i%13]!=0){
                            nowcard=i%13;
                            arr[nowplayer][i%13]--;
                            break;
                        }
                    }
                } else if(nowcard!=2){
                    if(arr[nowplayer][(nowcard+1)%13]!=0){
                        arr[nowplayer][(nowcard+1)%13]--;
                        lastplayer=nowplayer;
                        nowcard=(nowcard+1)%13;
                    } else if(arr[nowplayer][2]!=0){
                        arr[nowplayer][2]--;
                        lastplayer=nowplayer;
                        nowcard=2;
                    }
                }
                int sum=0;
                for(int i=0;i<13;i++){
                    sum+=arr[nowplayer][i];
                }
                if(sum==0)
                    break;
            }
            cout<<"Case #"<<p<<":"<<endl;
            for(int i=0;i<n;i++){
                int sum=arr[i][0]*13;
                for(int j=1;j<13;j++){
                    sum+=arr[i][j]*j;
                }
                if(sum == 0){
                    cout<<"Winner"<<endl;
                } else{
                    cout<<sum<<endl;
                }
            }
    }
} 
