#include<iostream>
#include<cmath>
using namespace std;
struct tree{int a,b,c;}t[10005*4];
struct sq{int x1,x2,y1,y2,c;}a[105];
int A,B,N,x[10005]={0},p[10005]={0},ans[10005]={0};
void Build(int v,int l,int r)
{
	t[v].a=l;t[v].b=r;t[v].c=0;
	if(l+1==r)return;
	int mid=(l+r)/2;
	Build(v*2,l,mid);
	Build(v*2+1,mid,r);
}
void Insert(int v,int j)
{
	if(a[j].y1>=t[v].b||a[j].y2<=t[v].a)return;
   	if(t[v].c>0)return;
	if(a[j].y1<=t[v].a&&a[j].y2>=t[v].b&&t[v].c!=-1){t[v].c=a[j].c;return;}
	Insert(v*2,j);
	Insert(v*2+1,j);
	t[v].c=-1;
}
void Find(int v,int i)
{
	if(t[v].c==0)return;
	if(t[v].c>0)
	{
		ans[t[v].c]+=(t[v].b-t[v].a)*(p[i+1]-p[i]);
		t[v].c=0;
		return;
	}
	Find(v*2,i);
	Find(v*2+1,i);
	t[v].c=0;
}
int main()
{
	cin>>A>>B>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2>>a[i].c;
		x[a[i].x1]=1;x[a[i].x2]=1;
	}
	for(int i=0;i<=A;i++)if(x[i])p[++p[0]]=i;
	Build(1,0,B);
	for(int i=1;i<p[0];i++)
	{
		for(int j=N;j>=1;j--)
		if(a[j].x1<=p[i]&&a[j].x2>p[i])Insert(1,j);
		Find(1,i);
	}
	ans[1]=A*B;
	for(int i=2;i<=10000;i++)ans[1]-=ans[i];
	for(int i=1;i<=10000;i++)if(ans[i])cout<<i<<" "<<ans[i]<<endl;
	return 0;
}
/*
20 20 3
2 2 18 18 2
0 8 19 19 3
8 0 10 19 4
*/