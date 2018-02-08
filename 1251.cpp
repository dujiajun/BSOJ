#include<iostream>
using namespace std;
int n,a[20][20]={0},b[20][20]={0},c[20]={0},cir[300]={0},times=0,num=0;
void bfs(int i)
{
	for(int j=1;j<=n;j++)
	if(a[i][j]==1&&b[i][j]==0)
	{
		b[i][j]=1;
		b[j][i]=1;
		bfs(j);
	}
	times++;
	cir[times]=i;
}
int main()
{
	int k;
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		cin>>a[i][j];
		if(a[i][j]==1)c[i]++;
	}
	for(int i=n;i>=1;i--)
		if(num%2==1){num++;k=i;}
	if(!(num==0||num==2)){cout<<"No solution!"<<endl;return 0;}
	if(num==0)bfs(1);
	if(num==2)bfs(k);
	for(int i=times;i>1;i--)cout<<cir[i]<<"->";
	cout<<cir[1];
	return 0;
}