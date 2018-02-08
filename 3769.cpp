#include<iostream>
#include<iomanip>
using namespace std;
int t,n,a[10011]={0},b[10011]={0},c[10011]={0};
double f(double x)
{
	double maxx=-1<<29;
	for(int i=1;i<=n;i++)maxx=max(maxx,a[i]*x*x+b[i]*x+c[i]);
	return maxx;
}
double three(double l,double r)
{
	while(l+1e-10<r)
	{
		double mid=(l+r)/2;
		double midmid=(mid+r)/2;
		if(f(mid)>f(midmid))l=mid;
		else r=midmid;
	}
	cout<<fixed<<setprecision(4)<<f(l)<<endl;
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i],&b[i],&c[i]);
		three(0,1000);
	}
	return 0;
}
/*
2
1
2 0 0
2
2 0 0
2 -4 2
*/