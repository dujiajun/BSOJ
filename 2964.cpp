#include<iostream> 
#include<cstdio> 
#include<queue> 
#include<algorithm> 
using namespace std; 
priority_queue<long long,vector<long long> >q; 
struct node{int d,p;}a[1000050]; 
bool cmp(const node& lhs,const node& rhs){return lhs.d<rhs.d;} 
int n; 
long long ans=0; 
long long now=1000000000ll; 
int main() 
{
	cin>>n; 
	for(int i=1;i<=n;i++)scanf("%d %d",&a[i].d,&a[i].p); 
	a[++n].d=0;a[n].p=0; 
	sort(a+1,a+n+1,cmp); 
	for(int i=n;i>=1;i--) 
	{ 
		while(now>a[i].d&&q.size()>0) 
		{
			now--;
			ans+=q.top();
			q.pop(); 
		} 
		now=a[i].d;
		q.push(a[i].p); 
	} 
	cout<<ans<<endl; 
	return 0;
 }