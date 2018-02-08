#include<iostream>
using namespace std;
int tree[101]={0},ans[101],n,k,x,y,j=0,sum=0;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++){cin>>x>>y;tree[y]=x;}
	for(int i=1;i<=n;i++)
		if(tree[i]==0){ans[++j]=i;sum++;}
	cout<<sum<<endl;
	for(int i=1;i<=j;i++)cout<<ans[i]<<" ";
	return 0;
} 
/*
9 7
1 2
2 3
4 6
4 5
7 8
9 1 
9 4
*/