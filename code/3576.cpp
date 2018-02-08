#include<iostream>
#include<queue>
#include<vector>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long> >q;
int n;
long long x,ans;
int main()
{
	cin>>n;
	q.push(1);
	for(int i=1;i<=n;i++)
	{
		x=q.top();
		q.pop();
		q.push(x*2);
		q.push(x*3);
		q.push(x*5);
		q.push(x*7);
		while(x==q.top())q.pop();
	}
	cout<<x<<endl;
	return 0;
}