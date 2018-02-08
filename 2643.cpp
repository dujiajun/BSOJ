#include<iostream>
#include<algorithm>
using namespace std;
struct peo{int id,s,bj;}a[5005]={0};
int n,m,t=0;
bool cmp(peo c,peo d){return (c.s>d.s)||(c.s==d.s&&c.id<d.id);}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i].id>>a[i].s;
	m=m*1.5;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)if(a[i].s>=a[m].s){t++;a[i].bj=1;}
	cout<<a[m].s<<" "<<t<<endl;
	for(int i=1;i<=n;i++)if(a[i].bj)cout<<a[i].id<<" "<<a[i].s<<endl;
	return 0;
}
/*
6 3 
1000 90 
3239 88 
2390 95 
7231 84 
1005 95 
1001 88 
*/