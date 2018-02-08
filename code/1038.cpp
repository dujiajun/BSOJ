#include<iostream>
#include<algorithm>
using namespace std;
struct per{string n,t;}a[1005];
int n;
bool cmp(per p1,per p2)
{
	if(p1.t.length()!=p2.t.length())return p1.t.length()>p2.t.length();
	if(p1.t!=p2.t)return p1.t>p2.t;
	return p1.n<p2.n;
} 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].n>>a[i].t;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)cout<<a[i].n<<endl;
	return 0;
}