#include<iostream>
using namespace std;
int n,m,t,map[85][85][11]={0},used[85][11];
struct st{int x,step;}a[10001];
void init()
{
	int x,y;
	cin>>n>>m>>t;
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>x>>y;
			map[x][y][i]=map[y][x][i]=1;
		}
	}
	for(int i=1;i<=t;i++)
	for(int j=1;j<=n;j++)map[j][j][i]=1;
}
void solve()
{
	int head=1,tail=1,tt=0;
	a[head].x=1;a[head].step=0;used[head][0]=1;
	while(head<=tail)
	{
		tt=(a[head].step+1)%t;
		if(tt==0)tt=t;
		for(int i=0;i<=n;i++)
		{
			if(map[a[head].x][i][tt]&&!used[i][tt])
			{
				tail++;
				a[tail].x=i;
				a[tail].step=a[head].step+1;
				used[i][tt]=1;
				if(i==0){cout<<a[tail].step;return;}
			}
		}
		head++;
	}
	cout<<"Poor Z4!"<<endl;
}
int main()
{
	init();
	solve();
	return 0;
} 
/*
4 5 2
1 2
1 3
1 4
2 0
4 0

1 3
1 3
2 3
4 3
3 0
*/ 