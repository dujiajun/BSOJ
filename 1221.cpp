#include<iostream>
#include<cmath>
using namespace std;
const int n=30000;
int fa[n+5],h[n+5],b[n+5],t;
int getfa(int x)
{
	if(fa[x]==x) return x;
	int tmp=getfa(fa[x]);
	h[x]+=h[fa[x]];
	fa[x]=tmp;
	return fa[x];
}
char get_char()
{
	char ch;
	while(1)
	{
		ch=getchar();
		if(ch=='M'||ch=='C')return ch;
	}
}
int main()
{   
	cin>>t;
	int x,y;char ch;
	for(int i=1;i<=n;i++){fa[i]=i;b[i]=1;}
	while(t--)
	{   
		ch=get_char();
		scanf("%d%d",&x,&y);
		if(ch=='M') 
		{
			int f1=getfa(x),f2=getfa(y);
			fa[f1]=f2;
			h[f1]+=b[f2];
			b[f2]+=b[f1];
		}
		if(ch=='C')
		{
			int f1=getfa(x),f2=getfa(y);
			if(f1!=f2)printf("-1\n");
			else printf("%d\n",abs(h[x]-h[y])-1);
		} 
	}
	return 0;
}