#include<stdio.h>
int main()
{
	int n,a[10000],i,b=-1,c,l,k,j=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)

	if(a[i]>a[i+1])
	{
		b=i;
		break;
	}

	if(b!=-1)
	{
		while(a[b]==a[b-1]){ b--;}
    	for(i=n-1;i>0;i--)
    		if(a[i]<a[i-1])
    	    {
        		c=i;
        		break;
        	}
        while(a[c]==a[c+1]){c++;}
        for(i=0;i<=(c-b)/2;i++)
        {
        	l=a[i+b];
        	a[i+b]=a[c-i];
        	a[c-i]=l;
    	}
    	for(i=0;i<n-1;i++)
        	if(a[i]>a[i+1])
        	{
        	   printf("no");
        	   j=-1;
        	   break;
            }
        if(j!=-1)
        {
        	printf("yes\n");
        	printf("%d %d",b+1,c+1);
    	}
    }
    else
    {
    	printf("yes\n");
    	printf("1 1");
	}
}
