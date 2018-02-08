#include<iostream>
#include<iomanip>
using namespace std;



int main()
{
	int c[15],i=0,A=0,B=0;
 	for(int j=1;j<=1000;j++)
 	{
 		int t=j,a=0,b=0;
	for(i=0;t>0;t/=2)
	{
		c[i]=t%2;
		if(c[i]==1)a++;
		if(c[i]==0)b++;
		i++;
	}
	if(a>b)A++;
	else B++;
 	}
 	cout<<A<<" "<<B;
	return 0;
}
