#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int a={0},m,n,sum=0,cnt=1;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		sum+=a;
		if(sum>m)
		{
			sum=a;
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}