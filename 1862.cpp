#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct dd{int a,b;}a[50005];
int n,st,ed;
bool cmp(dd d1,dd d2){return d1.a<d2.a||d1.a==d2.a&&d1.b<d2.b;}
int main()
{
 	cin>>n;
 	for(int i=1,x,y;i<=n;i++)scanf("%d%d",&a[i].a,&a[i].b);
 	sort(a+1,a+n+1,cmp);
 	st=a[1].a,ed=a[1].b;
 	for(int i=2;i<=n;i++)
 	{
 		if(a[i].a<=ed)ed=max(a[i].b,ed);
 		else {printf("%d %d\n",st,ed);st=a[i].a;ed=a[i].b;}
 	}
 	printf("%d %d\n",st,ed);
	return 0;
}
/*
5
5 6
1 4
10 10
6 9
8 10
*/