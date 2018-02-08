#include<iostream>
#include<cstdio>
using namespace std;
int n,m,d[5001],map[5001][5001]={0},q[100001],s[5001]={0};
void init()
{
	int x,y,z;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(map[x][y]==0)map[x][y]=z;
		else if(z<map[x][y])map[x][y]=z;
	}
}
bool SPFA()
{
	int l=0,r=1,i,j;
	q[1]=1;s[1]=1;d[1]=0;
	for(i=2;i<=n;i++)d[i]=0x7fffffff/2;
	while(l<r)
	{
		l++;i=q[l];s[i]=0;
		for(j=1;j<=n;j++)
			if(map[i][j]!=0&&d[j]>d[i]+map[i][j])
			{
				d[j]=d[i]+map[i][j];
				if(s[j]==0){r++;q[r]=j;s[j]=1;}
			}
	}
	return true;
}
int main()
{
	init();
	if(SPFA())cout<<d[n];
	return 0;
}