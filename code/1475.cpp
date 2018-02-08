#include<iostream>
#include<cmath>
using namespace std;
int n,t,tmp;
int main()
{
	cin>>n;
	t=sqrt(n);
	for(int i=2;i<=t;i++)
	if(n%i==0)
	{
		tmp++;
		if(tmp==2)
		{
			cout<<"It's not a MaoLaoDa number."<<endl;
			return 0;
		}
	}
	if(tmp==1)cout<<"It's a MaoLaoDa number."<<endl;
	else cout<<"It's not a MaoLaoDa number."<<endl;
	return 0;
}