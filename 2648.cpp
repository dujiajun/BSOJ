#include<iostream>
using namespace std;
const int MAXN=200001;
struct tree{int a,b,c;}t[MAXN*4+5];
int ll,rr,n;
void Build(int v,int L,int R)
{
	t[v].a=L;t[v].b=R;t[v].c=0;
	if(L==R)return;
	int mid=(L+R)/2;
	Build(v*2,L,mid);
	Build(v*2+1,mid+1,R);
}
void Insert(int v,int L,int R)
{
	if(t[v].a>R||t[v].b<L||t[v].c==1)return;
	if(t[v].a>=L&&t[v].b<=R){t[v].c=1;return;}
	Insert(v*2,L,R);
	Insert(v*2+1,L,R);
}
int Ask(int v)
{
	if(t[v].c==1)return t[v].b-t[v].a+1;
	if(t[v].a==t[v].b)return 0;
	return Ask(v*2)+Ask(v*2+1);
}
int main()
{
	cin>>ll>>rr>>n;
	Build(1,0,rr-ll-1);
	for(int i=1,br,bl;i<=n;i++)
	{
		cin>>bl>>br;
		Insert(1,bl-ll,br-ll-1);
	}
	cout<<Ask(1);
	return 0;
}
/*
1 10 3
3 5
1 4
7 8
*/