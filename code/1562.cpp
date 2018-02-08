#include<iostream>
#include<cstring>
#include<cstdio>
#include<iomanip>
using namespace std;
int main()
{
 	int n;
 	cin>>n;
 	int a[20][3]={0};
 	double result[20]={0};
 	for(int i=0;i<n;i++)
 	{
 		for(int j=0;j<3;j++)
 		{
 			cin>>a[i][j];
 			result[i]+=a[i][j];
 		}
 	}
 	for(int i=0;i<n;i++)
 	{
 		cout<<fixed<<setprecision(2)<<result[i]/3<<" ";
 	}
	return 0;
}
