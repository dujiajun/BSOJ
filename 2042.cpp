#include<iostream>
using namespace std;
const int MAXN=60001;
struct tree{int a,b,c,s;}t[MAXN*4+5];
int L,R,c,s,r,N,minn;
void Build(int v,int L,int R)
{
	t[v].a=L,t[v].b=R,t[v].s=s,t[v].c=0;
	if(L==R)return;
	int mid=(L+R)/2;
	Build(v*2,L,mid);
	Build(v*2+1,mid+1,R);
}
void Ask(int v)
{
	if(L>t[v].b||R<t[v].a)return;
	if(L<=t[v].a&&R>=t[v].b){minn=min(t[v].s,minn);return;}
	if(t[v].c>0)
	{
		t[2*v].s-=t[v].c;t[2*v+1].s-=t[v].c;
		t[2*v].c+=t[v].c;t[2*v+1].c+=t[v].c;
		t[v].c=0;
	}
	Ask(2*v);
	Ask(2*v+1);
	t[v].s=min(t[2*v].s,t[2*v+1].s);
}
void Modify(int v)
{
	if(L>t[v].b||R<t[v].a)return;
	if(L<=t[v].a&&R>=t[v].b){t[v].s-=N;t[v].c+=N;return;}
	if(t[v].c>0)
	{
		t[2*v].s-=t[v].c;t[2*v+1].s-=t[v].c;
		t[2*v].c+=t[v].c;t[2*v+1].c+=t[v].c;
		t[v].c=0;
	}
	Modify(v*2);
	Modify(v*2+1);
	t[v].s=min(t[2*v].s,t[2*v+1].s);
}
int main()
{
	cin>>c>>s>>r;
	Build(1,1,c);
	for(int i=1;i<=r;i++)
	{
		scanf("%d%d%d",&L,&R,&N);R--;minn=1<<29;
		Ask(1);
		if(minn>=N){printf("YES\n");Modify(1);}
		else printf("NO\n");
	}
	return 0;
}