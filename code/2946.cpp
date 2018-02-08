#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,x[2005]={0},y[2005]={0},x1[1005]={0},Y1[1005]={0},x2[1005]={0},y2[1005]={0},vst[1005][1005]={0},ans=0;
void Hello______________________________World(long long a[],long long b[],long long c[])
{
	long long t[2005]={0},k=1;
	while(k<=a[0])
	{
		t[++t[0]]=a[k];
		while(a[k+1]==a[k]&&k<a[0])k++;
		k++;
	}
	memset(a,0,sizeof(a));
	memcpy(a,t,sizeof(t));
	for(int i=1;i<=n;i++)
	for(int j=1;j<=t[0];j++)if(t[j]==b[i]){b[i]=j;break;}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=t[0];j++)if(t[j]==c[i]){c[i]=j;break;}
}
void figure______out()
{
	for(int i=n;i>=1;i--)
	for(int j=x1[i];j<x2[i];j++)
	for(int k=Y1[i];k<y2[i];k++)
	if(!vst[j][k])
	{
		ans+=abs(x[j+1]-x[j])*abs(y[k+1]-y[k]);
		vst[j][k]=1;
	}
	cout<<ans;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x1[i]>>Y1[i]>>x2[i]>>y2[i];
		x[++x[0]]=x1[i];x[++x[0]]=x2[i];
		y[++y[0]]=Y1[i];y[++y[0]]=y2[i];
	}
	sort(x+1,x+x[0]+1);
	sort(y+1,y+y[0]+1);
	Hello______________________________World(x,x1,x2);
	Hello______________________________World(y,Y1,y2);
	figure______out();
	return 0;
}
/*
3
1 1 4 3
2 -1 3 2
4 0 5 2
*/
