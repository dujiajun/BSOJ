#include<iostream>
using namespace std;
struct carpet{int x,y,ly,lx;}a[10005];
int n,x,y,num=-1;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y>>a[i].lx>>a[i].ly;
	cin>>x>>y;
	for(int i=1;i<=n;i++)
		if(x>=a[i].x&&x<=a[i].x+a[i].lx&&y>=a[i].y&&y<=a[i].y+a[i].ly)num=i;
	cout<<num;
	return 0;
}