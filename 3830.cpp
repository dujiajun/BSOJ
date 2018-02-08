#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	int n,x,cnt=0,t,a;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		t=i;
		while(t!=0)
		{
			a=t%10;
			t=t/10;
			if(a==x)cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0; 
}