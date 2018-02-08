#include<iostream>
#include<cstdio>
using namespace std;
struct nc{int to,next;}w[1000005]={0};
int a[30005]={0},n,m,cnt=0,h[30005]={0},nt,r[30005]={0},ans[30005]={0};
void heapdown()
{
	int i=1,t,j;
	while(i*2<=a[0])
	{
		if(a[i*2]<a[i*2+1]||i*2==a[0])j=i*2;else j=i*2+1;
		if(a[i]>a[j]){swap(a[i],a[j]);i=j;}else return;
	}
}
void heapup()
{
	int i=a[0],t;
	while(i>1&&a[i/2]>a[i]){swap(a[i],a[i/2]);i=i/2;}
}
void setheap(int c)
{
	a[0]++;a[a[0]]=c;
	heapup();
}
void del()
{
	a[1]=a[a[0]];a[0]--;
	heapdown();
}
void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&nt);
			cnt++;w[cnt].to=nt;w[cnt].next=h[i];h[i]=cnt;
			r[nt]++;
		}
	}
}
void topsort()
{
	int t=0,x,y;
	for(int i=1;i<=n;i++)
		if(r[i]==0)setheap(i);
	while(a[0])
	{
		t++;x=a[1];
		del();
		ans[0]++;ans[ans[0]]=x;
		for(int i=h[x];i;i=w[i].next)
		{
			y=w[i].to;
			r[y]--;
			if(r[y]==0)setheap(y);
		}
	}
	if(t==n){cout<<n<<endl;for(int i=1;i<=n;i++)cout<<ans[i]<<" ";}
	else cout<<"no solution"<<endl;
}
int main()
{
	init();
	topsort();
	return 0;
}
/*
6
2 2 3
0
2 4 5
0
0
0
*/