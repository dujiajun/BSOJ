#include<iostream>
#include<algorithm>
using namespace std;
struct g{int t,w;}a[505];
int m,n,hs[505]={0};
bool cmp(g g1,g g2){return g1.w>g2.w;}
int main()
{
 	cin>>m>>n;
 	for(int i=1;i<=n;i++)cin>>a[i].t;
 	for(int i=1;i<=n;i++){cin>>a[i].w;}
 	sort(a+1,a+n+1,cmp);
 	for(int i=1;i<=n;i++)
	{
		int j=a[i].t;
		while(hs[j]>0&&j>0)j--;
		if(j)hs[j]=1;
		else m-=a[i].w;
	}
 	cout<<m;
	return 0;
}
/*
10000
7
4 2 4 3 1 4 6
70 60 50 40 30 20 10
*/