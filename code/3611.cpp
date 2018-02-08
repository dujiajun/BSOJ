#include<iostream>
using namespace std;
int f(int x,int p)
{
	if(x==0)return 0;
	return f(x/p,p)+x/p;
}
int main()
{
	int n,p,t;
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&n,&p);
		printf("%d\n",f(2*n,p)-2*f(n,p));
		//cout<<<<endl;
	}
	return 0;
}