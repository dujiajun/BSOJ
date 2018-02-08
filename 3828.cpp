#include<iostream>
using namespace std;
const int zero[2]={0,1<<29};
int n,a[100005],g[100005],ans=1;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int k=0;k<=1;k++)
	{
		g[0]=1;g[g[0]]=zero[k];
		for(int i=1;i<=n;i++)
		{
			if(g[0]==1)
			{
				g[++g[0]]=a[i];
				ans=max(ans,g[0]-1);
				continue;
			}
			if(g[g[0]]>g[g[0]-1])
			{
				if(a[i]<g[g[0]])g[++g[0]]=a[i];
				if(a[i]>g[g[0]])g[g[0]]=a[i];
				ans=max(ans,g[0]-1);
				continue;
			}
			if(g[g[0]]<g[g[0]-1])
			{
				if(a[i]>g[g[0]])g[++g[0]]=a[i];
				if(a[i]<g[g[0]])g[g[0]]=a[i];
				ans=max(ans,g[0]-1);
				continue;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}