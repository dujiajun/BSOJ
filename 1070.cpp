#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int count=0,n,m,a[50],p[2000],sum=0;
int f[10005]={0};
void getit()
{
	int k=0;
	for(int i=2;i<=sqrt(10000);i++)
	for(int j=i*i;j<=10000;j+=i)f[j]=1;
	for(int i=2;i<=10000;i++)if(!f[i])p[++k]=i;			
}
void check(int sum)                 
{
	if(sum<=10000&&!f[sum])count++;
	else 
	{
		for(int i=1;p[i]*p[i]<=sum;i++)if(sum%p[i]==0)return;
		count++;	 	
	}		
}
void DFS(int step,int num)
{
	if(step>m)check(sum);	
	else for(int i=num+1;i<=n-m+step;i++)
	{
		sum+=a[i];
		DFS(step+1,i);             
		sum-=a[i];	    	
	} 	
} 
int main()
{
	cin>>n>>m;
	getit();
	for(int i=1;i<=n;i++)cin>>a[i];
	DFS(1,0);
	cout<<count;
	return 0;	
}