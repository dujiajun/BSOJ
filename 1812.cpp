#include<iostream>
using namespace std;
int l1,l2,a[5005]={0},b[5005]={0},f[5005][5005]={0},maxx=0;
int main()
{
	cin>>l1;
	for(int i=1;i<=l1;i++)cin>>a[i];
	cin>>l2;
	for(int j=1;j<=l2;j++)cin>>b[j];
	for(int i=1;i<=l1;i++)
	{
		maxx=0;
		for(int j=1;j<=l2;j++)
		{
			f[i][j]=f[i-1][j];
			if(a[i]>b[j]&&maxx<f[i-1][j])maxx=f[i-1][j];
			if(a[i]==b[j])f[i][j]=maxx+1;
		}
	}
	maxx=0;
	for(int i=1;i<=l2;i++)maxx=max(f[l1][i],maxx);
	cout<<maxx<<endl;
	return 0;
}