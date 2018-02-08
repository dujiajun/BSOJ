#include<iostream>
using namespace std;
int n,s=2,cnt=1;
int main()
{
	cin>>n;
	while(s!=1)
	{
		if(s>n)s+=s-(n*2+1);
		else s+=s;
		cnt++;
	}
	cout<<cnt;
	return 0;
}