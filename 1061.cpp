#include<iostream>
using namespace std;
int main()
{
	int a=0,b=0,x=0,y=0,t=0,j[10001],k[10001];
	char ch;
	for(;ch!='E';)
	{
		if(ch=='W')a++;
		if(ch=='L')b++;
		if((a>=11||b>=11)&&(a-b>=2||b-a>=2)){cout<<a<<":"<<b<<endl;a=0;b=0;}
		if(ch=='W')x++;
		if(ch=='L')y++;
		if((x>=21||y>=21)&&(x-y>=2||y-x>=2)){t++;j[t]=x;k[t]=y;x=0;y=0;}
		cin>>ch;
	}
	cout<<a<<":"<<b<<endl<<endl;
	for(int i=1;i<=t;i++)cout<<j[i]<<":"<<k[i]<<endl;
	cout<<x<<":"<<y<<endl;
	return 0;
}
/*
WWWWWWWWWWWWWWWWWWWWWWLWE
*/