#include<iostream>
#include<set>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
struct cow{int x,id;}a[50005];
int n,ans=1<<30,st=1,ed=1,in;
map<int,int>ids;
set<int>kis;
bool cmp(cow x,cow y){return x.x<y.x;}
int main()
{
	cin>>n;
 	for(int i=1;i<=n;i++)
 	{
	 	scanf("%d%d",&a[i].x,&a[i].id);
  		kis.insert(a[i].id);
  		ids[a[i].id]=0;
 	}
 	sort(a+1,a+n+1,cmp);
 	int all=kis.size();
  	while(1) 
  	{
	  	while(in!=all&&ed<=n)
   		{
		   	if(!ids[a[ed].id])in++;
    		ids[a[ed++].id]++;
   		}
   		if(ed==n+1&&in!=all)break;
   		while(ids[a[st].id]>1)ids[a[st++].id]--;
    	if(a[ed-1].x-a[st].x<ans)ans=a[ed-1].x-a[st].x;
    	ids[a[st++].id]--;
    	in--;
  	}
 	cout<<ans<<endl;
 	return 0;
}
/*
6
25 7
26 1
15 1
22 3
20 1
30 1
*/