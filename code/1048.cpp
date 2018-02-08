#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
 	int l,n,count=0;
	 int L,r;
 	cin>>l>>n;
 	int ln[10001]={0};
 	for(int i=1;i<=n;i++)
	 {
	 	cin>>L>>r;
	 	for(int j=L;j<=r;j++)ln[j]=1;
	 }
 	for(int i=0;i<=l;i++)if(ln[i]==0)count++;
 	cout<<count;
	return 0;
}
