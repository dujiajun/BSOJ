#include<iostream>
#include<cstring>
using namespace std;
int n,m,f[205][205],q[205],vst[205],prt[205],ans,tmp;
bool bfs_find()
{
	memset(vst,0,sizeof(vst));
	int l=0,r=1,x=0;
	q[1]=1;vst[1]=1;prt[1]=-1;
	while(l<r)
	{
		l++;
		x=q[l];
		for(int i=1;i<=n;i++)
		if(f[x][i]>0&&!vst[i])
		{
			r++;
			q[r]=i;
			prt[i]=x;
			vst[i]=1;
			if(i==n)return 1;
		}
	}
	return 0;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)cin>>f[i][j];
	while(bfs_find())
	{
		tmp=1<<29;
		for(int i=n,j=prt[i];j>0;i=j,j=prt[i])tmp=min(tmp,f[j][i]);
		ans+=tmp;
		for(int i=n,j=prt[i];j>0;i=j,j=prt[i]){f[j][i]-=tmp;f[i][j]+=tmp;}
	}
	cout<<ans<<endl;
	return 0;
 } 
 /*
5 4
1 2 40
1 4 20
2 4 20
2 3 30
3 4 10
 */