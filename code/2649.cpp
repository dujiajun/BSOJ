#include<iostream>
using namespace std;
const int MAXN=200001;
struct tree{int a,b,c;}t[MAXN*4+5];
int ll,rr,n,f[200001]={0},ans=0;
void Build(int v,int L,int R)
{
	t[v].a=L;t[v].b=R;t[v].c=0;
	if(L==R)return;
	int mid=(L+R)/2;
	Build(v*2,L,mid);
	Build(v*2+1,mid+1,R);
}
void Insert(int v,int L,int R,int Co)
{
	if(t[v].a>R||t[v].b<L)return;
	if(t[v].a>=L&&t[v].b<=R){t[v].c=Co;return;}
	if(t[v].c>=0)
	{
		t[v*2].c=t[v*2+1].c=t[v].c;
		t[v].c=-1;
	}
	Insert(v*2,L,R,Co);
	Insert(v*2+1,L,R,Co);
}
void Find(int v)
{
	if(t[v].c==0)return;
	if(t[v].c>0){f[t[v].c]=1;return;}
	if(t[v].c==-1) {Find(v*2);Find(v*2+1);}
}
int main()
{
	cin>>ll>>rr>>n;
	Build(1,0,rr-ll-1);
	for(int i=1,br,bl;i<=n;i++)
	{
		cin>>bl>>br;
		Insert(1,bl-ll,br-ll-1,i);
	}
	Find(1);
	for(int i=1;i<=n;i++)ans+=f[i];
	cout<<ans;
	return 0;
}
/*
1 10 3
3 5
1 4
7 8
*/