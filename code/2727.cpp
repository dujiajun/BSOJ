#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double ax,ay,bx,by,cx,cy,dx,dy,p,r,q;
double dis(double x1,double y1,double x2,double y2){return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));}
double cal(double p1,double p2) 
{  
	double xi=(bx-ax)*p1+ax,yi=(by-ay)*p1+ay;
   	double xj=(dx-cx)*p2+cx,yj=(dy-cy)*p2+cy;
   	double ans=dis(ax,ay,xi,yi)/p+dis(xi,yi,xj,yj)/r+dis(xj,yj,dx,dy)/q;
   	return ans;
}
double tb(double x)
{  
	double l=0,r=1,lm,rm;
   	while(l+1e-6<r) 
   	{  
	   	lm=(r-l)/3;rm=lm*2;
		lm+=l;rm+=l;
      	if(cal(x,lm)>cal(x,rm))l=lm;
		else r=rm;
   	}
   	return cal(x,r);
}
int main()
{  
	cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy>>p>>q>>r;
   	double l=0,r=1,lm,rm;
   	while(l+1e-6<r) 
   	{  
	   	lm=(r-l)/3;rm=lm*2;
		lm+=l;rm+=l;
   	   	if(tb(lm)>tb(rm))l=lm;
		else r=rm;
   	}
   	cout<<fixed<<setprecision(2)<<tb(r)<<endl;
   	return 0;
}
/*
0 0 0 100
100 0 100 100
2 2 1
*/