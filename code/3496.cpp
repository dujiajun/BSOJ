#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int n,a[20005];
map<int,int>pos[6];
bool cmp(int a,int b)
{
	int f=0;
	for(int i=1;i<=5;i++)f+=pos[i][a]<pos[i][b];
	return f>=3;
}
int main()
{
	cin>>n;
	for(int i=1;i<=5;i++)
	for(int j=1;j<=n;j++)
	{
		scanf("%d",&a[j]);
		pos[i][a[j]]=j;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)printf("%d\n",a[i]);
	return 0;
}