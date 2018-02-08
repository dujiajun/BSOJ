#include<iostream>
#include<algorithm>
using namespace std;

struct line{int begin,end;};
bool cmp(line a,line b){return a.end<b.end;}

int main()
{
 	int n,count=1,s;
 	cin>>n;
 	line ln[1000];
 	for(int i=0;i<n;i++)cin>>ln[i].begin>>ln[i].end;
 	sort(ln,ln+n,cmp);
 	s=ln[0].end;
 	for(int i=1;i<n;i++)
	 if(ln[i].begin>=s){s=ln[i].end;count++;}
 	cout<<count;
	return 0;
}
