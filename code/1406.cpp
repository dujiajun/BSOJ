#include<iostream>
#include<algorithm>
using namespace std;
int n,m,prt[10000],maxx=0;
struct node{int a,b,v;}q[10000];
bool cmp(node x,node y){return x.v<y.v;}
int getfather(int x)
{
	if(prt[x]==x)return x;
	prt[x]=getfather(prt[x]);
	return prt[x];
}
void kruscal()
{
	int t1,t2,k=0;
	for(int i=1;i<=n;i++)prt[i]=i;
	for(int i=1;i<=m;i++)
	{
		t1=getfather(q[i].a);
		t2=getfather(q[i].b);
		if(t1!=t2)
		{
			prt[t1]=t2;k++;
			maxx=max(maxx,q[i].v);
			if(k==n-1)break;
		}
	}
}
void init()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>q[i].a>>q[i].b>>q[i].v;
}
int main()
{
	init();
	sort(q+1,q+m+1,cmp);
	kruscal();
	cout<<n-1<<" "<<maxx;
	return 0;
}
/*
4 5
1 2 3
1 4 5
2 4 7
2 3 6
3 4 8
*/