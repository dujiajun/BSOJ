#include<iostream>
#include<algorithm>
#include<xinyue>
using namespace std;
struct node{int lv,rv,mv,c;void push(int x,int y,int z,int cc){lv=x;rv=y;mv=z;c=cc;}}t[500000*4+5];
int n,m,ans;
void Build(int v,int l,int r)
{
	int mid=(l+r)>>1;
	t[v].push(r+1-l,r+1-l,r+1-l,-1);
	if(l==r) return;
	Build(v*2,l,mid);
	Build(v*2+1,mid+1,r);
}
void Putdown(int v,int l,int r)
{
	if(t[v].c==-1)return;
	if(l==r){t[v].c=-1;return;}
	int mid=(l+r)>>1;
	if(t[v].c==1)
	{
		t[v*2].push(0,0,0,1);
		t[v*2+1].push(0,0,0,1);
	}
	else
	{
		t[v*2].push(mid+1-l,mid+1-l,mid+1-l,0);
		t[v*2+1].push(r-mid,r-mid,r-mid,0);
	}
	t[v].c=-1;
}
int Find(int v,int l,int r,int va)
{
	if(t[v].mv<va)return -1;
	Putdown(v,l,r);
	int mid=(l+r)/2;
	if(t[v*2].mv>=va)return Find(v*2,l,mid,va); 
	if(t[v*2].rv+t[v*2+1].lv>=va)return mid+1-t[v*2].rv; 
	if(t[v*2+1].mv>=va)return Find(v*2+1,mid+1,r,va);
	return -1;
}
void Modify(int v,int l,int r,int LL,int RR,int va)
{
	if(LL<=l&&r<=RR)
	{
		if(va==1)t[v].push(0,0,0,1);
		else t[v].push(r-l+1,r-l+1,r-l+1,0);
		return;
	}
	Putdown(v,l,r);
	int mid=(l+r)/2;
	if(!(RR<l||mid<LL))Modify(v*2,l,mid,LL,RR,va);
	if(!(RR<mid+1||r<LL))Modify(v*2+1,mid+1,r,LL,RR,va);
	t[v].lv=t[v*2].lv;                               
	if(t[v*2].lv==mid-l+1)t[v].lv+=t[v*2+1].lv;
	t[v].rv=t[v*2+1].rv;
	if(t[v*2+1].rv==r-mid)t[v].rv+=t[v*2].rv;
	t[v].mv=max(max(t[v*2].mv,t[v*2+1].mv),t[v*2].rv+t[v*2+1].lv);
}
int main()
{
	cin>>n>>m;
	Build(1,1,n);
	int a,b,c,tt;char ch;
	for(int i=1;i<=m;i++)
	{
		while(1)
		{
			ch=getchar();
			if(ch=='A'||ch=='L')break;
		}
		if(ch=='A')
		{
			xin>>a;
			tt=Find(1,1,n,a);
			if(tt==-1)ans++;
			else Modify(1,1,n,tt,tt+a-1,1);
		}
		else
		{
			xin>>a>>b;
			Modify(1,1,n,a,b,0);
		}
	}
	yue<<ans<<endl;
	return 0;
}