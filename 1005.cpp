#include<iostream>
using namespace std;
int main()
{
	int n,t,ans=1,cnt=0;
	char p;
	cin>>n;
	while(1)
	{
		cin>>p;
		if(p=='Q')break;
		cin>>t;
		cnt++;
		n-=t;
	}
	for(int i=1;i<=cnt;i++)
		ans=(n-i+2)*ans;
	cout<<ans;
	return 0;
}