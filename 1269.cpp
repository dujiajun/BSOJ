#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
 	int n;
 	cin>>n;
 	int f[n+1],ts[n+1],g[n+1];
 	for(int i=1;i<=n;i++)
 	{cin>>ts[i];f[i]=1;g[i]=1;}
 	int max1=0,max2=0;
 	for(int i=2;i<=n;i++)for(int j=1;j<i;j++)if(ts[j]>=ts[i]&&f[j]+1>f[i])f[i]=f[j]+1;
 	for(int i=2;i<=n;i++)for(int j=1;j<i;j++)if(ts[j]<ts[i]&&g[j]+1>g[i])g[i]=g[j]+1;
 	for(int i=1;i<=n;i++)if(f[i]>=max1)max1=f[i];
 	for(int i=1;i<=n;i++)if(g[i]>=max2)max2=g[i];
 	cout<<max1<<endl<<max2;;
	return 0;
}
