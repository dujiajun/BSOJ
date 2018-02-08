#include<iostream>
#include<cstring>
using namespace std;
int a[201][201]={0},f[201]={0},q[201]={0},n,m;
void bfs(int i)
{
	int op=0,cl=1,k;
	memset(q,0,sizeof(q));
	q[1]=i;f[i]=1;
	cout<<i<<" ";
	while(op<cl)
	{
		op++;k=q[op];
		for(int j=1;j<=n;j++)
		{
			if(a[k][j]==1&&f[j]==0)
			{
				cout<<j<<" ";f[j]=1;cl++;q[cl]=j;
			}
		}
	}
}
int main()
{
	int k,j;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{cin>>j>>k;a[j][k]=1;a[k][j]=1;}
	cin>>k;
	bfs(k);
	return 0;
}
/*
8 10
1 4
1 5
1 6
2 6 
2 7
3 5
3 4
3 7
5 7
5 8
7
*/