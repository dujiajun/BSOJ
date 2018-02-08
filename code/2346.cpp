#include<iostream>
#include<cmath>
using namespace std;
int n,a[100]={0},b[100]={0};
int s1=0;
int check(int i,int j)
{
	int x,t=1,s,k;
   	if(i==1)return 1; 
  	s=a[i-1]+j;
  	for(k=2;k<=sqrt(s);k++)
	  if(s%k==0){t=0;break;}
   	if(i==n)
   	{
		s=a[1]+j;
    	for(k=2;k<=sqrt(s);k++)
			if(s%k==0){t=0;break;}
	}
  	return t; 
}
void dfs(int dp)
{
	if(dp>n)
	{
		s1++;
		for(int i=1;i<=n;i++)cout<<a[i]<<" ";
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++)
		if(b[i]==0&&check(dp,i)==1)
		{
			a[dp]=i;
			b[i]=1;
			dfs(dp+1);
			b[i]=0;
		}
}

int main()
{
	cin>>n;
	dfs(1);
	if(s1==0)cout<<"NO";
	return 0;
}