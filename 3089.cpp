#include<iostream>
#include<iomanip>
using namespace std;
int n,x[1005],y[1005];
double ea=0,r=1<<29,dis;
int main()
{
 	cin>>n;
 	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
 	for(int i=1;i<=n;i++)
 	{
 		ea=0;
 		for(int j=1;j<=n;j++)
	    {
 			dis=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
		 	ea=max(dis,ea);
	    }
 		r=min(r,ea);
 	}
 	cout<<fixed<<setprecision(4)<<3.1415926535*r;
	return 0;
}
/*
3
0 1
-8 -4
-1 4
*/