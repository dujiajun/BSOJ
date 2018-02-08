#include<iostream>
using namespace std;
const int M=0xffff;
int a[105]={0},f[10005]={0},b[105]={0},m,n,p,i,j;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)cin>>b[i];
	for(i=1;i<=m;i++)f[i]=M; 
	f[0]=0;
	for(j=1;j<=n;j++)
		if(b[j]>=m/a[j])
			for(i=a[j];i<=m;i++)f[i]=min(f[i],f[i-a[j]]+1);
		else 
		{
			p=1;
			while(p<b[j])
			{
				for(i=m;i>=p*a[j];i--)
					f[i]=min(f[i],f[i-p*a[j]]+p);
				b[j]=b[j]-p;
				p=p*2;
			}
			for(i=m;i>=b[j]*a[j];i--)
				f[i]=min(f[i],f[i-b[j]*a[j]]+b[j]);
		}
	for(i=1;i<=m;i++)
		if(f[i]==M)cout<<-1<<endl;
		else cout<<f[i]<<endl;
	return 0;
}