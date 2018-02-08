#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

priority_queue <int,vector<int>,greater<int> > c;
int main()
{
	int k,n,i,j;
	cin>>n>>k;
for(i=1;i<=n;i++)
	  {
	  	int j;
	  	cin>>j;
	  	c.push(j);
	  }
	for(i=1;i<=k;i++)
	  {
	  	 int j=c.top();
	  	 c.pop();
	  	 c.push(2*j);
	  }
	for(i=1;i<=n;i++)
	 {
	 	int j=c.top();
	 	cout<<j<<' ';
	 	c.pop();
	 }
	return 0;
}