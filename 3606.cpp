#include<iostream>
using namespace std;
int a,b;
int main()
{
	while(cin>>a>>b)
	{
		if(a==0&&b==0)break;
		a*=100;
		for(int i=0;i<=99;i++)
		if((a+i)%b==0)
		{
			if(i<10)cout<<0<<i<<" ";
			else cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}