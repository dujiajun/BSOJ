#include<iostream>
using namespace std;
const int MAXN=1000001;
long long el[MAXN]={0},p[MAXN]={0},pr[MAXN]={0},k=0,n;
void Euler()
{
	p[1]=1;
	for(int i=2;i<MAXN;i++)
	{
		if(!p[i]){pr[++k]=i;el[i]=i-1;}
		for(int j=1;j<=k&&pr[j]*i<MAXN;j++)
		{
			long long t=i*pr[j];
			p[t]=1;
			if(i%pr[j]==0){el[t]=el[i]*pr[j];break;}
			else el[t]=el[i]*(pr[j]-1);
		}
	}
}
int main()
{
	Euler();
	for(int i=1;i<MAXN;i++)el[i]+=el[i-1];
	el[1]=1;
	while(1)
	{
		cin>>n;
		if(n==0)break;
		cout<<el[n]<<endl;
	}
	return 0;
}