#include<iostream>
using namespace std;
int main()
{
 	int n,maxx=0,minn=0x7fffffff;
 	cin>>n;
 	for(int i=1,x;i<=n;i++)
 	{
 		scanf("%d",&x);
 		maxx=max(maxx,x);
 		minn=min(minn,x);
 	}
 	cout<<maxx<<" "<<minn;
	return 0;
}