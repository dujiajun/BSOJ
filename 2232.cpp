#include<iostream>
using namespace std;
int n,m,p,q,R,L,t[1000000*4+5]={0},sum=0;
void Insert(int v,int a,int b,int co)
{
	if(a>R||b<L)return;
	if(t[v]>0)return;
	if(L<=a&&R>=b&&t[v]!=-1){t[v]=co;sum+=b-a+1;return;}
	t[v]=-1;
	Insert(v*2,a,(a+b)/2,co);
	Insert(v*2+1,(a+b)/2+1,b,co);
}
void Out(int v,int a,int b)
{
	if(t[v]!=-1){for(int i=a;i<=b;i++)printf("%d\n",t[v]);return;}
	if(a==b)return;
	Out(v*2,a,(a+b)/2);
	Out(v*2+1,(a+b)/2+1,b);
}
int main()
{
	cin>>n>>m>>p>>q;
	for(int i=m;i>=1;i--)
	{
		L=(i*p+q)%n+1;R=(i*q+p)%n+1;
		if(L>R)swap(L,R);
		Insert(1,1,n,i);
		if(sum==n)break;
	}
	Out(1,1,n);
	return 0;
}