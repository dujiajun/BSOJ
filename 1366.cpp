#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int t;
const double eps=1e-8;
double h,D,H;
double cal(double x){return (h*D-H*x)/(D-x)+x;}
double three(double l,double r)
{
	while(l+eps<r)
	{
		double mid=(l+r)/2;
		double midmid=(mid+r)/2;
		if(cal(mid)>cal(midmid))r=midmid;
		else l=mid;
	}
	return l;
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>H>>h>>D;
		cout<<fixed<<setprecision(3)<<cal(three(0,h/H*D))<<endl;
	}
	return 0;	
}