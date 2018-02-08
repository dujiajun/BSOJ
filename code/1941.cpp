#include<iostream>
using namespace std;
struct F{int a,b,c;}w[10005];
struct heap{int f,n,v;}a[10005],tmp;
int n,m,num=0;
void heapdown()
{
	int i=1,j;
	while(i*2<=num)
	{
		j=i*2;
		if(a[j].v>a[j+1].v&&j<num)j++;
		if(a[j].v<a[i].v)swap(a[i],a[j]);else break;
		i=j;
	}
}
void heapup()
{
	int i=num;
	while(i>1&&a[i].v<a[i/2].v){swap(a[i],a[i/2]);i=i/2;}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i].a>>w[i].b>>w[i].c;
		tmp.v=w[i].a+w[i].b+w[i].c;
		tmp.f=i;tmp.n=1;
		a[++num]=tmp;
		heapup();
	}
	int f,j;
	for(int i=1;i<=m;i++)
	{
		cout<<a[1].v<<" ";
		tmp.f=f=a[1].f;tmp.n=j=a[1].n+1;
		tmp.v=w[f].a*j*j+w[f].b*j+w[f].c;
		a[1]=tmp;
		heapdown();
	} 
	return 0;
}