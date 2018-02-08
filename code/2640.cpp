#include<iostream>
#include<cstring>
using namespace std;
const int INF=1<<29,MAXN=100010;
struct edge{int to,next;}a[MAXN*5],b[MAXN*5];
int h[MAXN*2]={0},hs[MAXN*2]={0},v[MAXN]={0},cnt=0,mx[MAXN]={0},mn[MAXN]={0},n,m,vst[MAXN]={0},q[MAXN]={0};
void add(int x,int y)
{
    cnt++;
    a[cnt].to=y;a[cnt].next=h[x];h[x]=cnt;
    b[cnt].to=x;b[cnt].next=hs[y];hs[y]=cnt;
}
void spfa1()
{  
	int l=0,r=1;
   	mn[1]=v[1];
   	q[r]=1;vst[1]=1;
  	while(l<r)
   	{  
	   	l=(l+1)%MAXN;
      	int i=q[l];
      	for(int p=h[i];p;p=a[p].next)
      	{  
		  	int j=a[p].to;
         	if(!vst[j])
         	{  
            	vst[j]=1;
            	r=(r+1)%MAXN;
            	q[r]=j;
         	}
         	mn[j]=min(v[j],mn[i]);
      	}
   	}
}
void spfa2()
{  
	int l=0,r=1;
   	mx[1]=v[n];
   	q[r]=n;vst[n]=1;
   	while(l<r)
   	{  
	   	l=(l+1)%MAXN;
      	int i=q[l];
      	for(int p=hs[i];p;p=b[p].next)
      	{  
		  	int j=b[p].to;
         	if(!vst[j])
         	{  
            	vst[j]=1;
            	r=(r+1)%MAXN;
            	q[r]=j;
         	}
         	mx[j]=max(v[j],mx[i]);
      	}
   	}
}
int main()
{
	cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&v[i]);
    for(int i=1,x,y,z;i<=m;i++)
    {   
    	scanf("%d%d%d",&x,&y,&z);
        add(x,y);
        if(z==2)add(y,x);
    }
	spfa1();
	memset(vst,0,sizeof(vst));
	memset(q,0,sizeof(q));
	spfa2();
	int ans=0;
	for(int i=1;i<=n;i++)
  	if(mx[i]-mn[i]>ans)ans=mx[i]-mn[i];
	printf("%d",ans);
	return 0;
}
/*
5 5
4 3 6 5 1
1 2 1
1 4 1
2 3 2
3 5 1
4 5 2
*/