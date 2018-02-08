#include<iostream>
#include<cmath>
using namespace std;
const int INF=1<<29;
int f[3000],num[3000]={0},t=0,n,m1,m2,ans=INF,s,bj,fm,fx,ci;
void predo(int n,int m)
{
	int k=sqrt(n);
	for(int i=2;i<=k;i++)
	if(n%i==0)
	{
		f[++t]=i;
 		while(n%i==0){num[t]++;n=n/i;}
	}
 	if(n!=1){f[++t]=n;num[t]++;}
 	for(int i=1;i<=t;i++)num[i]=num[i]*m;
	}
int main()
{
	cin>>n>>m1>>m2;
 	predo(m1,m2);
 	for(int i=1;i<=n;i++)
	{
		cin>>s;
		bj=0;fx=-INF;
		for(int j=1;j<=t;j++)
		{
			if(s%f[j]){bj=1;break;}
			ci=0;
			while(s%f[j]==0){ci++;s=s/f[j];}
			if(num[j]%ci==0)fm=num[j]/ci;
 			else fm=num[j]/ci+1;
			fx=max(fx,fm);
		}
		if(bj)continue;
		ans=min(ans,fx);
	}
	if(m1==1)cout<<0<<endl;
 	else if(ans==INF)cout<<-1<<endl;
 	else cout<<ans<<endl;
 	return 0;
}