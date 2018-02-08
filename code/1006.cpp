#include<iostream>
using namespace std;
int a[205]={0},bj=0,x,y,cnt=0;
int main()
{
	while(cin>>x>>y)
	{
		a[y]+=x;
		if(y==0)cnt++;
		if(cnt==2)break;
	}
	for(int i=200;i>=0;i--)
		if(a[i]!=0)
		{
			if(bj==0)bj=1;
			else if(a[i]>0)cout<<"+";
			if(a[i]!=1)cout<<a[i];
			if(i!=0)
			{
				cout<<"x";
				if(i!=1)cout<<"^"<<i;;
			}
		}
	if(bj==0)cout<<0;
	return 0;
}