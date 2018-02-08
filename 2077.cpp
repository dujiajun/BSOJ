#include<iostream>
#include<algorithm>
using namespace std;
int n,cnt;
struct node{int a,b;}a[40005];
int gcd(int x,int y)
{
	if(y==0)return x;
	return gcd(y,x%y);
}
bool cmp(const node &x,const node &y){return x.a*y.b<y.a*x.b;}
int main()
{
	cin>>n;
	for(int i=0;i<=n;i++)
	for(int j=i;j<=n;j++)if(gcd(i,j)==1){a[++cnt].a=i;a[cnt].b=j;}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)cout<<a[i].a<<"/"<<a[i].b<<endl;
	return 0;
}