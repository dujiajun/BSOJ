#include<iostream>
using namespace std;
int m,sum;
int main()
{
	cin>>m;
	for(int i=1;i<=m/2;i++)
	{
		sum=0;
		for(int j=i;sum<=m;j++)
		{
			sum+=j;
			if(sum==m)cout<<i<<" "<<j<<endl;
		}
	}
	return 0;
}