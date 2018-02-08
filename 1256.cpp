#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
double a,b,c,d;
double fx(double x){return x*x*x*a+x*x*b+x*c+d;}
int main()
{
 	cin>>a>>b>>c>>d;
 	for(double i=-100;i<=100;i+=0.001)
 	{
 		if(fx(i)*fx(i+0.001)<0)
 		{
 			cout<<fixed<<setprecision(2)<<i<<" ";
 			i+=0.01;
 		}
 	}
	return 0;
}
