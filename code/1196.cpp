#include<iostream>
using namespace std;
int a[105][2],n,x,b[105];
void out(int k,int way)
{
	if(way==1)cout<<k<<endl;
	if(a[k][0]!=0)out(a[k][0],way);
	if(way==2)cout<<k<<endl;
	if(a[k][1]!=0)out(a[k][1],way);
	if(way==3)cout<<k<<endl;
}
int main()
{
	cin>>n;
	int root=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x;cin>>a[x][0]>>a[x][1];
		b[a[x][0]]=1;b[a[x][1]]=1;
	}
	for(int i=1;i<=n;i++)
		if(b[i]==0){root=i;break;}
	out(root,2);	
	return 0;
}
/*
5
1 2 3
2 4 5
3 0 0
4 0 0
5 0 0
*/