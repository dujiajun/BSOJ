#include<iostream>
#include<iomanip>
using namespace std;
int n,m,all=0,yes=0;
double maxx=0,a[1005]={0};
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	for(int i=1;i<n;i++)
	for(int j=i+1;j<=n;j++)
	{
		all++;
		if(int(m/a[i])*(a[j]-a[i])>0)yes++;
		maxx=max(maxx,int(m/a[i])*(a[j]-a[i]));
	}
	cout<<fixed<<setprecision(3)<<maxx<<endl<<(double)yes/all<<endl;
	return 0;
}
/*
10
5 7 6 8 5 1 2 3 4 5
100
*/
