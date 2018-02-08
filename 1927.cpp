#include<iostream>
#include<iomanip>
using namespace std;
int n;
double ans,a,b;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		ans+=a*b/10.0;
	}
	cout<<fixed<<setprecision(2)<<ans<<endl;
	return 0;
}