#include<iostream>
#include<cstdio>
using namespace std;
int h[1000005]={0},n,x,y,minn=1<<29,maxx=-1<<29;
int main()
{
	cin>>n;
	while(n--)
	{
		cin>>x;
		while(x--)
		{
			scanf("%d",&y);
			minn=min(minn,y);maxx=max(maxx,y);
			h[y]++;
		}
		while(!h[maxx])maxx--;
		h[maxx]--;
		while(!h[minn])minn++;
		h[minn]--;
		printf("%d %d\n",maxx,minn);
	}
}