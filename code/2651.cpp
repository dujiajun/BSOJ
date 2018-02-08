#include<iostream>
using namespace std;
const int MAXN=200001;
struct tree{int a,b,c;}t[MAXN*4+5];
int ll,rr,n,f[200001]={0},ans=0,deco,p;
void Build(int v,int L,int R)
{
	t[v].a=L;t[v].b=R;
	if(L==R)return;
	int mid=(L+R)/2;
	Build(v*2,L,mid);
	Build(v*2+1,mid+1,R);
}
void Insert(int v,int L,int R)
{
	if(R<t[v].a||t[v].b<L)return;
	if(L<=t[v].a&&t[v].b<=R){t[v].c++;return;}
	Insert(v*2,L,R);
	Insert(v*2+1,L,R);
}
void Find(int v,int L,int R)
{
	if(R<t[v].a||t[v].b<L)return;
	ans+=t[v].c;
	Find(v*2,L,R);
	Find(v*2+1,L,R);
}
int main()
{
	int tt=100000;
	cin>>deco>>n;
	Build(1,0,2*tt);
	for(int i=1,br,bl,co;i<=n;i++)
	{
		cin>>bl>>br>>co;
		Insert(1,bl+tt,br+tt-1);
	}
	cin>>p;
	Find(1,p+tt,p+tt);
	cout<<ans;
	return 0;
}
/*
1 4
2 6 2
1 5 3
3 4 2
7 8 4
*/