#include<iostream>
using namespace std;
struct tree{int num,son[1501];}t[1501];
int n,root=0,f[1501][2]={0};//f[i][0]not set f[i][1]set
void init()
{
	int k,r=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		r+=k;
		cin>>t[k].num;
		for(int j=0;j<t[k].num;j++)
		{
			cin>>t[k].son[j];
			root+=t[k].son[j];
		}
	}
	root=r-root;
}
void dp(int rt)
{
	
	f[rt][0]=0;
	f[rt][1]=1;
	if(t[rt].num==0)return;
	for(int i=0;i<t[rt].num;i++)
	{
		dp(t[rt].son[i]);
		f[rt][1]+=min(f[t[rt].son[i]][0],f[t[rt].son[i]][1]);
		f[rt][0]+=f[t[rt].son[i]][1];
	}
}
int main()
{
	init();
	dp(root);
	cout<<min(f[root][1],f[root][0]);
	return 0;
}
/*
5
3 3 1 4 2
1 1 0
2 0
0 0
4 0
*/ 