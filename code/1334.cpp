#include<iostream>
using namespace std;
int main()
{
	int n,m,a[101]={0},i,t,k;
	while(cin>>n>>m)
	{
	 	for(i=1;i<=n;i++)cin>>a[i];
	 	i=0;t=0;k=0;
	 	while(k<n)
 	 	{
		  	i++;
 	  		if(i==n+1)i=1;
 	  		if(a[i]!=0)t++;
 	  		if(t==m){cout<<i<<" ";m=a[i];k++;a[i]=0;t=0;}	 	
	 	}
	   	cout<<endl;
    }
    return 0;
}
