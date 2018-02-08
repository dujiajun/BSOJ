#include<iostream>
#include<cstring>
using namespace std;
int n,m,t,f1[105][105],f2[105][105],a[105][105];
bool vst[105];
int xfind(int x)
{
	int bj=0;
	for(int i=1,j;i<=m;i++)
	if(!vst[i])
	{
		for(j=1;j<=n;j++)if(a[j][i]!=f2[j][x])break;
		if(j>n)return i;
	}
	return -1;
}
bool check()
{
	int p,bj=1;
	for(int i=1,j;i<=m;i++)
	{
		memset(vst,0,sizeof(vst));
		vst[i]=1;bj=1;
		memcpy(a,f1,sizeof(f1));
		for(j=1;j<=n;j++)
		if(a[j][i]!=f2[j][1])for(int k=1;k<=m;k++)a[j][k]=1-a[j][k];
		for(j=2;j<=m;j++)
		{
			p=xfind(j);
			if(p>0){vst[p]=1;continue;}
			break;
		}
		if(j>m)return 1;
	}
	return 0;
}
void sovle()
{
	cin>>n>>m;
	memset(f1,0,sizeof(f1));
	memset(f2,0,sizeof(f2));
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)scanf("%d",&f1[i][j]);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)scanf("%d",&f2[i][j]);
	if(check())printf("YES\n");
	else printf("NO\n");
}
int main()
{
	cin>>t;
	while(t--)sovle();
	return 0;
}