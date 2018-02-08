#include<iostream>
#include<cstring>
using namespace std;
const int INF=0x7fffffff;
int f[3][205][205]={0},d[205][205]={0},a[1005]={0},n,l,ans=INF;
int main()
{
	cin>>l>>n;
	for(int i=1;i<=l;i++)
	for(int j=1;j<=l;j++)scanf("%d",&d[i][j]);
	for(int i=1;i<=n;i++)cin>>a[i];
   	memset(f[0],0x2f,sizeof(f[0]));
   	f[0][2][3]=f[0][3][2]=0;
   	a[0]=1;
   	for(int i=1;i<=n;i++)
   	{  
   	  	memset(f[i%2],0x2f,sizeof(f[i%2]));
      	for(int j=1;j<=l;j++)
        for(int k=1;k<=l;k++)
        {  
           	if(j==k||j==a[i-1]||k==a[i-1])continue;
           	f[i%2][j][k]=min(f[i%2][j][k],f[(i-1)%2][j][k]+d[a[i-1]][a[i]]);
           	f[i%2][j][a[i-1]]=min(f[i%2][j][a[i-1]],f[(i-1)%2][j][k]+d[k][a[i]]);
           	f[i%2][k][a[i-1]]=min(f[i%2][k][a[i-1]],f[(i-1)%2][j][k]+d[j][a[i]]);
        }
   	}
   	for(int i=1;i<=l;i++)
    for(int j=1;j<=l;j++)ans=min(ans,f[n%2][i][j]);
    cout<<ans<<endl;
	return 0;
}