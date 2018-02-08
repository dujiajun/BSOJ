#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,x,o=0,c[105];
long long t=10,k;
int main()
{
	cin>>n>>m>>k>>x;
	while(k)
	{
		c[++c[0]]=k%2;
		k/=2;
	}
	for(int i=c[0]-1;i>=1;i--)
	{
		t=(t*t)%n;
		if(c[i])t=(t*10)%n;
	}
	for(int i=1;i<=t;i++)o=(o+m)%n;
	cout<<(o+x)%n<<endl;
	return 0;
}