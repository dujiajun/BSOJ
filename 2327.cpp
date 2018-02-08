#include<iostream>
#include<iomanip> 
using namespace std;
int n,INF=0x7fffffff/2;
double len,maxv,permile,fee,dis[55],prc[55],f[55],ans=INF;
void init()
{
	cin>>len>>maxv>>permile>>fee>>n;
	for(int i=1;i<=n;i++)
		{cin>>dis[i]>>prc[i];prc[i]/=100;}
}
void dp()
{
	for(int i=1;i<=n;i++)f[i]=INF;
	f[0]=fee;
	for(int i=1;i<=n;i++)
		for(int j=i-1;j>=0;j--)
		{
			if(dis[i]-dis[j]>maxv*permile)break;
			if(dis[i]-dis[j]>maxv*permile/2)
				f[i]=min(f[i],f[j]+prc[i]*(dis[i]-dis[j])/permile+2);
		}	
	for(int i=n;i>=0;i--)
	{
		if(len-dis[i]>maxv*permile)break; 
		ans=min(ans,f[i]);
	}		
	cout<<fixed<<setprecision(2)<<ans;
}
int main()
{
	init();
	dp();
	return 0;
}