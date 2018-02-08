#include<iostream>
using namespace std;
int n,k,q[1000005],t[1000005],vst[1000005];
void bfs()
{
	int l=1,r=1,x,nx;
	q[l]=n;t[l]=0;vst[n]=1;
	while(l<=r)
	{
		x=q[l];
		nx=x+1;
		if(0<=nx&&nx<=100000&&!vst[nx])
		{
			r++;
			q[r]=nx;
			t[nx]=t[x]+1;
			vst[nx]=1;
		}
		nx=x-1;
		if(0<=nx&&nx<=100000&&!vst[nx])
		{
			r++;
			q[r]=nx;
			t[nx]=t[x]+1;
			vst[nx]=1;
		}
		nx=x*2;
		if(0<=nx&&nx<=100000&&!vst[nx])
		{
			r++;
			q[r]=nx;
			t[nx]=t[x]+1;
			vst[nx]=1;
		}
		if(t[k])
		{
			cout<<t[k]<<endl;
			return;
		}
		l++;
	}
}
int main()
{
	cin>>n>>k;
	if(n==k)
	{
		cout<<0<<endl;
		return 0;
	}
	bfs();
	return 0;
}