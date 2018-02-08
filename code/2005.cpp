#include<iostream>
#include<algorithm>
using namespace std;
int a[30000]={0};
int main()
{
 	int max,n,count=0;
 	cin>>max>>n;
 	int t;
 	for(int i=0;i<n;i++)
 	{cin>>t;a[i]=t;}
 	sort(a+0,a+n);
 	int i=0,j=n-1;
 	while(i<j)
 	{
		if(a[i]+a[j]<=max){i++;j--;}
		else j--;
		count++;
 	}
 	if(i==j)count++;
 	cout<<count;
	return 0;
}
