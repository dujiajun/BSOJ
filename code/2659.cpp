#include<iostream>
using namespace std;
const int MAXN=60005;
struct tree{int a,b,c,s;}t[MAXN*4+5];
int n,m,x,y,z;
void Build(int v,int l,int r)
{
	t[v].a=l;t[v].b=r;t[v].c=0;t[v].s=0;
	if(l==r)return;
	int mid=(l+r)/2;
	Build(v*2,l,mid);
	Build(v*2+1,mid+1,r);
}
void Insert(int v,int l,int r)
{
	if(t[v].a>r||t[v].b<l)return;
	if(t[v].c==1)return;
	if(t[v].a>=l&&t[v].b<=r)
	{
		t[v].c=1;t[v].s=t[v].b-t[v].a+1;
		return;
	}
	if(t[v].c==-1)
	{
		t[v].c=0;
		t[v*2].c=-1;t[v*2+1].c=-1;
		t[v*2].s=0;t[v*2+1].s=0;
	}
	Insert(v*2,l,r);
	Insert(v*2+1,l,r);
	t[v].s=t[v*2].s+t[v*2+1].s;
}
void Delete(int v,int l,int r)
{
	if(t[v].a>r||t[v].b<l)return;
	if(t[v].c==-1)return;
	if(t[v].a>=l&&t[v].b<=r)
	{
		t[v].c=-1;t[v].s=0;return ;
	}
	if(t[v].c==1)
	{
		t[v].c=0;
		t[v*2+1].c=1;t[v*2].c=1;
		t[v*2+1].s=t[v*2+1].b-t[v*2+1].a+1;t[v*2].s=t[v*2].b-t[v*2].a+1;
	}
	Delete(v*2,l,r);
	Delete(v*2+1,l,r);
	t[v].s=t[v*2+1].s+t[v*2].s;
}
int main()
{
	cin>>n>>m;
	Build(1,1,n-1);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&z,&x,&y);y--;
		if(z==1)Insert(1,x,y);
		else Delete(1,x,y);
	}
	cout<<t[1].s;
	return 0;
}
/*
10 5
1 2 8
2 3 6
1 1 10
2 4 7
1 1 5
*/