#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
double a,b,d,m,q[100005],x,y;
int ans=0,maxx=0,n;
int main()
{
	cin>>a>>b>>d>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&x,&y);
		q[i]=a*x+b*y;
	}
	m=2*d*sqrt(a*a+b*b);
	sort(q+1,q+n+1);
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<n&&q[j+1]-q[i]<=m)j++;
		maxx=max(maxx,j-i+1);
	}
	cout<<maxx<<endl;
	return 0;
}
