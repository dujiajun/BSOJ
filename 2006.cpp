#include<iostream>
using namespace std;
int m,s,t,tm=0,l=0;
int main()
{
	cin>>m>>s>>t;
	for(int i=1;i<=t;i++)
	{
		if(m>=10){tm+=60;m-=10;}
		else m+=4;
		l=max(tm,l+17);
		if(l>=s){cout<<"Yes"<<endl<<i<<endl;return 0;}
	}
	cout<<"No"<<endl<<l<<endl;;
	return 0;
}