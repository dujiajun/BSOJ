#include<iostream>
#include<map>
using namespace std;
map<int,int>cnt;int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=m;i++)
	{
		scanf("%d",&x);cnt[x]++;
		if(cnt[x]>m/2){cout<<x;return 0;}
	}
	printf("-1");
	return 0;
}