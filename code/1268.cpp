#include<iostream>
#include<iomanip>
using namespace std;
double d1,cst=0,per,tot,c,dis[1001]={0},p[1001]={0},gas=0;
int n;
void init()
{
    cin>>d1>>c>>per>>p[0]>>n;
	dis[n+1]=d1;dis[0]=0;
    for(int i=1,x;i<=n;i++)cin>>x>>dis[i]>>p[i];
    for(int i=n+1;i>=0;i--)
	if(dis[i]-dis[i-1]>per*c){cout<<"No solution";exit(0);}
}
void solve()
{
    int i=0,tt;
    while(i<=n)
    {
		for(tt=i+1;tt<=n+1;tt++)if(p[tt]<p[i])break;
       	if(dis[tt]-dis[i]>per*c)
       	{
         	cst+=(c-gas)*p[i];
         	gas=c-(dis[i+1]-dis[i])/per;
         	i++;
         	continue;
       	}
       	if(gas*per>=dis[tt]-dis[i])
       	{
         	gas-=(dis[tt]-dis[i])/per;
         	i=tt;
         	continue;
       	}
       	cst+=((dis[tt]-dis[i])/per-gas)*p[i]; 
       	gas=0;
       	i=tt;
    }
}
int main()
{  
    init();
    solve();
    cout<<fixed<<setprecision(2)<<cst;
    return 0;
}
/*
275.6 11.9 27.4 2.8 2
1 102.0 29
2 220.0 2.2
*/