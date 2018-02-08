#include<iostream>
#include<algorithm>
using namespace std;
int n,a,b,k[205],vst[205]={0};
struct w{int s,v;}q[1000];
void init()
{
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)cin>>k[i];
	if(a==b){cout<<0<<endl;exit(0);}
}
void solve()
{
	int h=1,t=1,tmp;
	q[h].s=a;
	q[h].v=0;
	vst[a]=1;
	while(h<=t)
	{
		tmp=q[h].s+k[q[h].s];
		if(tmp>=1&&tmp<=n&&vst[tmp]==0)
		{
			t++;
			vst[tmp]=1;
			q[t].s=tmp;
			q[t].v=q[h].v+1;
		}
		if(q[t].s==b){cout<<q[t].v<<endl;exit(0);}
		
		tmp=q[h].s-k[q[h].s];
		if(tmp>=1&&tmp<=n&&vst[tmp]==0)
		{
			t++;
			vst[tmp]=1;
			q[t].s=tmp;
			q[t].v=q[h].v+1;
		}
		if(q[t].s==b){cout<<q[t].v<<endl;exit(0);}
		h++;
	}
	cout<<-1<<endl;
}
int main()
{
	init();
	solve();
	return 0;
}