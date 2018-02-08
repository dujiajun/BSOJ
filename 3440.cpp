#include<iostream>
#include<cstdio>
using namespace std;
int n,m,q,ea[300005],eb[300005],w[300005]={0},a1[300005]={0},a2[300005]={0},fa[300005]={0},re[300005]={0};
bool h[300005]={0};
int getfa(int x) 
{
	if(fa[x]==x)return x;
	else return fa[x]=getfa(fa[x]);
}
void bing(int x,int y) 
{
	int f1=getfa(x),f2=getfa(y); 
	if(f1!=f2)fa[f1]=f2;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)scanf("%d%d",&ea[i],&eb[i]);
	cin>>q;
	for(int i=1;i<=q;i++) 
	{
		scanf("%d",&w[i]);
		if(w[i]==0){scanf("%d",&a1[i]);h[a1[i]]=true;}
		else scanf("%d%d",&a1[i],&a2[i]);
	}
	for(int i=1;i<=m;i++)if(!h[i])bing(ea[i],eb[i]);
	for(int i=q;i>=1;i--) 
	if(w[i]==0)bing(ea[a1[i]],eb[a1[i]]);
	else re[++re[0]]=(getfa(a1[i])==getfa(a2[i]));
	for(int i=re[0];i>=1;i--)
	if(re[i])cout<<"Yes"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
/*

*/