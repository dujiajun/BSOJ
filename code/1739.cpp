#include<iostream>
#include<algorithm>
using namespace std;

struct line{int begin,end;};
bool cmp(line a,line b){return a.begin<b.begin;}

int main()
{
 	int n,count=0,left,right;
	long long sum=0;
 	cin>>n;
 	line ln[20001];
 	for(int i=1;i<=n;i++)cin>>ln[i].begin>>ln[i].end;
 	sort(ln+1,ln+n+1,cmp);
 	left=ln[1].begin;right=ln[1].end;
 	for(int i=2;i<=n;i++)
 	{
 		if(ln[i].begin>right){sum+=right-left;left=ln[i].begin;right=ln[i].end;continue;}
 		if(ln[i].end>=right&&ln[i].begin<=right){right=ln[i].end;continue;}
 	}
 	sum+=right-left;
 	cout<<sum;
	return 0;
}
