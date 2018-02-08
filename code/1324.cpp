#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
 	int n;
 	cin>>n;
 	int t[1000];
 	int ti=0;
 	for(int i=0;i<n;i++)
 	{cin>>t[i];}
 	sort(t,t+n);
 	for(int i=1;i<n;i++)
 	{
 		t[i]=t[i]+t[i-1];
 		ti+=t[i];
 		sort(t+i,t+n);
 	}
 	cout<<ti;
	return 0;
}
