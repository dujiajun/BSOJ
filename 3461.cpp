#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct du_water{int x,y;}a[100050]={0};
int n,d,du_Fmax[100005][30]={0},du_Fmin[100005][30]={0},maxx=0,minx=10000000;
inline bool du_cmp(du_water w1,du_water w2){return (w1.x<w2.x)||(w1.x==w2.x&&w1.y<w2.y);}
void du_st()//RMQ 
{
	int t=log2(n);
	for(int i=1;i<=n;i++){du_Fmax[i][0]=a[i].y;du_Fmin[i][0]=a[i].y;}
	for(int j=1;j<=t;j++)
	for(int i=1;i+(1<<j)-1<=n;i++)
	{
		du_Fmax[i][j]=max(du_Fmax[i][j-1],du_Fmax[i+(1<<(j-1))][j-1]);
		du_Fmin[i][j]=min(du_Fmin[i][j-1],du_Fmin[i+(1<<(j-1))][j-1]);
	}
}
inline int du_askmax(int l,int r)
{
	int t=log2(r-l+1);
	return du_Fmax[l][t]>du_Fmax[r+1-(1<<t)][t]?du_Fmax[l][t]:du_Fmax[r+1-(1<<t)][t];
}
inline int du_askmin(int l,int r)
{
	int t=log2(r-l+1);
	return du_Fmin[l][t]<du_Fmin[r+1-(1<<t)][t]?du_Fmin[l][t]:du_Fmin[r+1-(1<<t)][t];
}
int du_Find(int st,int lx)//二分查找以 st开始，满足 x<=lx 的最右点。 
{
	int l=st,r=n,mid,tp=0;
	while(l<r)
	{
		mid=(l+r)/2;
		if(mid==tp)break;//如果l,r没有变化，即认为已经找到最右点 
		if(a[mid].x<=lx)l=mid;
		else r=mid;
		tp=mid;
	}
	return l;
}
bool du_check(int x)//枚举第 i 点为左端点，x 为宽度能否满足区间（y最大值-y最小值 ）>= d 。 
{
	int t;
	for(int i=1;i<=n;i++)
	{
		t=du_Find(i,a[i].x+x);
		if(du_askmax(i,t)-du_askmin(i,t)>=d)return 1;
	}
	return 0;
}
int main()
{
	cin>>n>>d;//log2(1000000)=19.9,log2(100000)=16.6
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		maxx=maxx>a[i].x?maxx:a[i].x;
		minx=minx<a[i].x?minx:a[i].x;
	}
	sort(a+1,a+n+1,du_cmp);
	du_st();
	int l=1,r=maxx-minx,mid,bj=0;
	while(l<r)//二分答案，即花盆宽度。 
	{
		mid=(l+r)/2;
		if(du_check(mid)){r=mid;bj=1;}
		else l=mid+1;
	}
	if(bj)cout<<r<<endl;
	else cout<<-1<<endl;
	return 0;
}