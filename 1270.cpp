#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
int a[41],ans[41]={0},f[3001];
int pack(int k)
{
    int i;
    for(i=1;i<=500;i++)f[i]=41;f[0]=0;
    for(i=0;f[i]<=n;i++)
    for(int j=1;j<=k;j++)if(f[i+a[j]]>f[i]+1)f[i+a[j]]=f[i]+1; 
    return i-1;
}
void dfs(int dp)
{
    int i,maxx; 
    if(dp==k)
    {
    	maxx=pack(k);
    	if(maxx>ans[0])
    	{
    		ans[0]=maxx;
    		for(i=1;i<=k;i++)ans[i]=a[i];   
    	}       
    	return;          
    }      
    for(i=a[dp]+1;i<=pack(a[dp])+1;i++){a[dp+1]=i;dfs(dp+1);} 
}
int main()
{
    cin>>n>>k;
    a[1]=1;
    dfs(1);
    for(int i=1;i<=k;i++)cout<<ans[i]<<" ";
    cout<<"\nMAX="<<ans[0];
    return 0;
}