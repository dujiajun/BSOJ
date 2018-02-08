#include<iostream>
using namespace std;
int a[1005]={0},b[10005]={0},c[10005]={0},n,m,st=1,t=0,cnt=0;
int main()
{
	//freopen("translate.in","r",stdin);
	//freopen("translate.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(b[a[i]]==0)
		{
			if(t<m)
			{
				c[++t]=a[i];
				b[a[i]]=1;
			}
			else if(t==m)
			{
				b[c[st]]=0;
				c[st+t]=a[i];
				st++;
				b[a[i]]=1;
			}
			cnt++;
		}
		
	}
	cout<<cnt<<endl;
	return 0;
}
/*
5 7
2 0 1 5 4 2 1

2 10
8 824 11 78 11 78 11 78 8 264
*/