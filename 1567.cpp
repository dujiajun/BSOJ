#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

double fx(double a,double b,int flag)
{
	double answer;
	switch(flag)
	{
		case 1:
		answer=a+b;
		break;
	case 2:
		answer=a-b;
		break;
	case 3:
		answer=a*b;
		break;
	case 4:
		answer=a/(double)b;
		break;
	}
	return answer;
}
string f(int flag)
{
	switch(flag)
	{
		case 1:
		return "+";
		break;
	case 2:
		return "-";
		break;
	case 3:
		return "*";
		break;
	case 4:
		return "/";
		break;
	}
}

int main()
{
	int a[5],m,ans;
	for(int i=0;i<5;i++)cin>>a[i];
	cin>>m;
 	for(int i=1;i<=4;i++)
 	for(int j=1;j<=4;j++)
 	for(int k=1;k<=4;k++)
 	for(int w=1;w<=4;w++)
 	{
		ans=fx(fx(fx(fx(a[0],a[1],i),a[2],j),a[3],k),a[4],w);
		if(ans==m){cout<<a[0]<<f(i)<<a[1]<<f(j)<<a[2]<<f(k)<<a[3]<<f(w)<<a[4]<<"="<<ans;return 0;}
 	}
 	cout<<"no answer!";
 	
	return 0;
}
