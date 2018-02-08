#include<iostream>
#include<cstring>
using namespace std;
int n,m,a[5005]={0},b[5005]={0};
bool v[5005]={true};
int find(int x)
{
	if(a[x]==x)return x;
	a[x]=find(a[x]);
	return a[x];
}
void Union(int x,int y)
{
	int f1=find(x),f2=find(y);
	a[f1]=f2;
}
void solve()
{
	char ch;
	int x,y,ans=0;
	memset(v,true,sizeof(v));
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++)a[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>ch>>x>>y;
		if(ch=='F')Union(x,y);
		else 
		{
			if(b[x]==0)b[x]=y;else Union(b[x],y);
			if(b[y]==0)b[y]=x;else Union(b[y],x);
		}
	}
	for(int i=1;i<=n;i++)if(v[find(i)]){v[a[i]]=false;ans++;}
	cout<<ans<<endl;
}
int main()
{
	cin>>n>>m;
	solve();
	return 0;
}
/*
6
4
E 1 4
F 3 5
F 4 6
E 1 2
*/
