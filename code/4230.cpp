#include<iostream>
#include<cstring>
#include<iostream>
using namespace std;
int n,d,v[55][15],b[500005],f[15];
int main()
{
	cin>>n>>d>>f[0];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=d;j++)cin>>v[i][j];
	for(int i=1;i<=d;i++)
	{
		for(int j=0;j<=f[i-1];j++)b[j]=0;
		for(int j=1;j<=n;j++)
		if(v[j][i+1]>=v[j][i]&&v[j][i]<=f[i-1])
		{
			for(int k=v[j][i];k<=f[i-1];k++)
			b[k]=max(b[k],b[k-v[j][i]]+v[j][i+1]);
		}
		for(int j=0;j<=f[i-1];j++)f[i]=max(f[i],f[i-1]+b[j]-j);
	}
	cout<<f[d]<<endl;
	return 0;
}