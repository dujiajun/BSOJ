#include<iostream>
#include<cstdio>
using namespace std;
struct person{int t,to,st;}a[20000];
int n,m,k,d[2000]={0},lt[2000]={0},sum[2000]={0},art[2000]={0},nt[2000],ans=0;
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<n;i++)scanf("%d",&d[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].t,&a[i].st,&a[i].to);
		lt[a[i].st]=max(a[i].t,lt[a[i].st]);
		sum[a[i].to]++;
	}
	for(int i=1;i<n;i++)
	{
		art[i+1]=max(art[i],lt[i])+d[i];
		sum[i+1]+=sum[i];
	}
	for(int i=1;i<=m;i++)ans+=art[a[i].to]-a[i].t;
	while(k--)
	{
		nt[n]=n;
		for(int i=n;i>1;i--)
		{
			if(lt[i]>=art[i])nt[i-1]=i;
			else nt[i-1]=nt[i];
		}
		int maxx=0,pos=-1;
		for(int i=1;i<n;i++)
		{
			if(!d[i])continue;
			int num=sum[nt[i]]-sum[i];
			if(num>maxx){maxx=num;pos=i;}
		}
		if(pos==-1)break;
		ans-=maxx;
		d[pos]--;
		for(int i=pos+1;i<=nt[pos];i++)art[i]--;
	}
	cout<<ans<<endl;
	return 0;
}