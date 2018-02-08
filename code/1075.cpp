#include<iostream>
#include<cmath>
using namespace std;
double h,s1,v,l,k,t1,t2;int n,cnt=0;
int main()
{
	cin>>h>>s1>>v>>l>>k>>n;n--;
	t1=sqrt(h/5);t2=sqrt((h-k)/5);
	for(int i=n;i>=0;i--)if((s1-i-0.00001)/v>t1||t2>(s1-i+l+0.00001)/v)cnt++;
	cout<<n-cnt+1;
	return 0;
}