#include<iostream>
#include<algorithm>
using namespace std;
int n,m,t,mark[10001]={0},ans=0;
string names[10001];
int find(string s)
{
	int l=1,r=n,mid;
	while(l<=r)
	{
		mid=(r+l)/2;
		if(s==names[mid])return mid;
		if(s<names[mid])r=mid-1;
		if(s>names[mid])l=mid+1;
	}
}
int main()
{
 	cin>>n;
 	for(int i=1;i<=n;i++)cin>>names[i];
 	sort(names+1,names+n+1);t=find("JLY");
 	cin>>m;
 	for(int i=1;i<=m;i++)
 	{
 		ans=1;
 		for(int j=1;j<=n;j++)
 		{
 			int x;string nm;
 			cin>>x>>nm;
 			mark[find(nm)]+=x;
 		}
 		for(int j=1;j<=n;j++)if(mark[j]>mark[t])ans++;
 		cout<<ans<<endl;
 	}
 		
	return 0;
}
/*
3
JLY
BluePoint
WangFuLong
2
49 JLY
49 BluePoint
48 WangFuLong
80 BluePoint
85 WangFuLong
83 JLY
*/
