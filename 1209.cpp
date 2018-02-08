#include<iostream>
using namespace std;
int n,f[101][10001];
void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		f[i][0]=1;int t=0;
		do
		{
			cin>>t;
			if(t==-1)break;
			for(int j=10000;j>=t;j--)
				f[i][j]=f[i][j]||f[i][j-t];
		}while(1);
	}
}
void dp()
{
	int fg=0;
	for(int j=10000;j>=1;j--)
	{
		int is=0;
		for(int i=1;i<=n;i++)
			if(!f[i][j]){is=1;break;}
		if(!is)
		{
			fg=1;
			cout<<j<<endl;
			break;
		}
	}
	if(!fg)cout<<0<<endl;
}
int main()
{
	init();
	dp();
	return 0;
} 
/*
2
2 1 -1
3 2 1 -1
*/