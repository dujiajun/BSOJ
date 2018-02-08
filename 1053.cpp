#include<iostream>
#include<cstring>
using namespace std;
int n,l[60000]={0},r[60000]={0},a[60000]={0},t[60000]={0},maxx=-1,b[60000]={0};
void getit(int x[])
{
	memset(t,0,sizeof(t));
	for(int i=1;i<=n;i++)t[(x[i]-i+n)%n]++;
	for(int i=0;i<n;i++)maxx=max(t[i],maxx);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>l[i]>>r[i];
	for(int i=1;i<=n;i++)
	if((l[l[i]]!=i&&r[l[i]]!=i)||(l[r[i]]!=i&&r[r[i]]!=i)){cout<<-1<<endl;return 0;}
	a[1]=1;a[2]=r[1];
	for(int i=2;i<n;i++)
	if(a[i-1]==l[a[i]])a[i+1]=r[a[i]];else a[i+1]=l[a[i]];
	getit(a);
	for(int i=1;i<=n;i++)b[i]=a[n-i+1];
	getit(b);
	cout<<n-maxx<<endl;
	return 0;
}