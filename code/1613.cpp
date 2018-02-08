#include<iostream>
using namespace std;
int tree[101]={0},n,m,x,y,sum=0,root,maxx,maxroot;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){cin>>x>>y;tree[y]=x;}
	for(int i=1;i<=n;i++)
		if(tree[i]==0){root=i;break;}
	for(int i=1;i<=n;i++)
	{
		sum=0;
		for(int j=1;j<=n;j++)
			if(tree[j]==i)sum++;
		if(sum>maxx){maxx=sum;maxroot=i;}
	}
	cout<<root<<endl<<maxroot<<endl;
	for(int i=1;i<=n;i++)
		if(tree[i]==maxroot)cout<<i<<" ";
	return 0;
} 
/*
8 7
4 1
4 2
1 3
1 5
2 6
2 7
2 8
*/