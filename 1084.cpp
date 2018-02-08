#include<iostream>
using namespace std;
int n,k,f[301]={0},ans=100000;
int main()
{
	cin>>n;
	f[0]=0;f[1]=1;
	for(int i=1;i<=300;i++)
	{
		f[i]=f[i-1]+1;
		for(int j=2;j<=i;j++) 
		if(i%j==0)f[i]=min(f[i],f[i/j]+5+(j-1)*2);
	}
	
	for(int i=n;i<=300;i++)ans=min(f[i],ans);
	cout<<ans;
	return 0;
} 