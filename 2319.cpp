#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
const int INF=0x7fffffff/2;
int bw,bl,n,s[1005],w[1005];
double f[1005]={0};
void init()
{
	cin>>bw>>bl>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>s[i];
		f[i]=INF;
	}
}
void dp()
{
	f[0]=0.0;
	long long t,l;
	for(int i=1;i<=n;i++)
	{
		t=w[i],l=s[i];
		f[i]=f[i-1]+(bl*1.0)/l;
		for(int j=i-1;j>=0;j--)
		{
			if(t>bw)break;
			f[i]=min(f[i],f[j]+(bl*1.0)/l);
			t+=w[j];
			if(l>s[j])l=s[j];
		}
	}
	cout<<fixed<<setprecision(1)<<f[n]*60;
}
int main()
{
	init();
	dp();
	return 0;
}
/*
100 5 10
40 25
50 20
50 20
70 10
12 50
9 70
49 30
38 25
27 50
19 70
*/