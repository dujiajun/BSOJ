#include<iostream>
using namespace std;
const int MAXN=200001;
struct tree{int a,b,d,c,lc,rc;}t[MAXN*4+5];
int ll,rr,n,f[200001]={0},ans=0,deco;
void Build(int v,int L,int R)
{
	t[v].a=L;t[v].b=R;
	if(L==R)return;
	int mid=(L+R)/2;
	Build(v*2,L,mid);
	Build(v*2+1,mid+1,R);
}
void Insert(int v,int L,int R,int Co)
{
	if(R<t[v].a||t[v].b<L)return;
	if(L<=t[v].a&&t[v].b<=R)
	{t[v].lc=t[v].rc=t[v].c=Co;t[v].d=1;return;}
	if(t[v].c>0)
	{
		t[v*2].lc=t[2*v].rc=t[v*2].c=t[v].c;
		t[v*2+1].lc=t[2*v+1].rc=t[v*2+1].c=t[v].c;
		t[v*2].d=t[v*2+1].d=1;
		t[v].c=-1;
	}
	Insert(v*2,L,R,Co);
	Insert(v*2+1,L,R,Co);
	t[v].lc=t[v*2].lc;t[v].rc=t[v*2+1].rc;
	t[v].d=t[v*2].d+t[v*2+1].d;
	if(t[v*2].rc==t[v*2+1].lc)t[v].d--;
}
int main()
{
	int tt=100000;
	cin>>deco>>n;
	Build(1,0,2*tt-1);
	t[1].lc=t[1].rc=t[1].c=deco;t[1].d=1;
	for(int i=1,br,bl,co;i<=n;i++)
	{
		cin>>bl>>br>>co;
		Insert(1,bl+tt,br+tt-1,co);
	}
	cout<<t[1].d;
	return 0;
}
/*
1 4
2 6 2
1 5 3
3 4 2
7 8 4
*/