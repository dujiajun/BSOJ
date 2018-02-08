#include<iostream>
#include<cstring>
#include<cstdio> 
using namespace std;
int main()
{
 	int n,t=1,num=1;
 	cin>>n;
 	while(t<=n)
 	{
		if(num%7==0||num%10==7)
		{
			printf("%d\n",num);
			t++;
		}
		num++;
 	}
	return 0;
}
