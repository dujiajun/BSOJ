#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int w[101]={0},f[100005]={0},vst[100005];
int main()
{
	int tot,n;
	cin>>tot>>n;
	int m=tot;
	f[0]=1;
	for(int i=1;i<=n;i++){cin>>w[i];}
	for(int i=1;i<=n;i++)
		for(int j=tot;j>=w[i];j--)
		{
			f[j]+=f[j-w[i]];
			if(f[j-w[i]])vst[j]=i;
		}
	if(f[tot]==0)cout<<0<<endl;
	if(f[tot]==1)
		for(int i=1;i<=n;i++)
		{
			if(m<=0)cout<<i<<" ";
			 else if(f[m-w[i]]==1)m-=w[i];
			 else cout<<i<<" ";
		}
	if(f[tot]>=2)cout<<-1<<endl;
	return 0;
}