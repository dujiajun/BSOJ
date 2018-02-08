#include<iostream>
using namespace std;
void ext(long long a,long long b,long long &d,long long &x,long long &y)
{
	long long t;
	if(b==0){d=a;x=1;y=0;}
	else 
	{
		ext(b,a%b,d,x,y);
		t=x;x=y;y=t-(a/b)*y;
	}
}
int main()
{
	long long a,b,c=1,d,x,y;
	cin>>a>>b;
	ext(a,b,d,x,y);
	x=(x*(c/d))%(b/d);
	x=(x+(b/d))%(b/d);
	cout<<x;
	return 0;
}