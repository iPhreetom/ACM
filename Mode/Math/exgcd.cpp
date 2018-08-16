int exgcd(int a,int b,int &x,int &y){
    int result = a;
    if(b == 0){
        x = 1;
        y = 0;
    }
    else{
        result = exgcd(b,a%b,y,x);
        y -= (a/b)*x;
    }
    return result;
}
