#include<iostream>
using namespace std;
int h[100005],ans=0,n;
int main() 
{
	cin>>n;h[0]=0;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&h[i]);
		if(h[i]>h[i-1])ans+=h[i]-h[i-1];
	}
	cout<<ans<<endl;
	return 0;
}