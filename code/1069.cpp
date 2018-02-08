#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
 	int k=0,i=0;
 	double s=0;
 	cin>>k;
 	for(i=1;s<=k;i++)
 	{
 		s+=(double)1/i;
 	}
 	cout<<i-1;
	return 0;
}
