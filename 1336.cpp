#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,ans=0;
	while(cin>>n)
	{
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=8;j++)
			{
				int t=pow(5,j);
				if(i%t==0)ans++;
			}
		cout<<ans<<endl;
	}
	return 0;
}