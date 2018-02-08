#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int t=0,ans[105],num[105]={0},n;
void solve(int x)
{  
	for(int i=2;i*i<=x;i++)
    if(x%i==0)
    {  
		ans[++t]=i;
	   	while(x%i==0){num[t]++;x=x/i;}
	}
   	if(x!=1){ans[++t]=x;num[t]=1;}
}
int main()
{
   	while(cin>>n)
   	{  
   		memset(num,0,sizeof(num));t=0;
		solve(n);
		cout<<ans[1];
		for(int i=2;i<=num[1];i++)cout<<"*"<<ans[1];
      	for(int i=2;i<=t;i++)
        for(int j=1;j<=num[i];j++)cout<<"*"<<ans[i];
      	cout<<endl;
   	}
   	return 0;
}