#include<iostream>
using namespace std;
int n,a[500]={0};
void flood(int root)
{
	cout<<root<<" ";
	for(int i=1;i<=n;i++)if(a[i]==root)flood(i);
}
int main()
{
	int root,x,y,i;
	cin>>n;
	for(int i=1;i<=n;i++){cin>>x>>y;a[x]=y;}
	for(int i=1;i<=n;i++)if(a[i]==0)root=i;
	flood(root);
	return 0;
}
/*
5
1 0
2 1
3 1
4 1
5 3
*/