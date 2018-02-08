#include<iostream>
#include<iomanip>
using namespace std;
int n,inter[105]={0};
double f[105]={0},m[105]={0};
void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>inter[i];
}
void dp()
{
	f[0]=100;
	m[0]=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		m[i]=m[i-1];
		for(int j=0;j<i;j++)
		{
			f[i]=max(f[i],m[j]*100/inter[i]);
			m[i]=max(m[i],f[j]/100*inter[i]);
		}
	}
	cout<<fixed<<setprecision(2)<<max(f[n],m[n]*100/inter[n]);
}
int main()
{
	init();
	dp();
	return 0;
}
/*
5
400
300
500
300
250
*/