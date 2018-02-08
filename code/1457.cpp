#include<iostream>
#include<algorithm>
using namespace std;
struct na{string n,d;int a;}a[5005];
int n,tot=0,t=0;
bool cmp(na a1,na b1)
{
	if(a1.d.size()==b1.d.size())return a1.d<b1.d;
	else return a1.d.size()<b1.d.size();
}
void init()
{
	int i=1;
	while(cin>>a[i].a>>a[i].d>>a[i].n){tot+=a[i].a;i++;}
	n=i-1;
}
int main()
{
	init();
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		t+=a[i].a;
		if(t*2>=tot)
		{
			cout<<a[i].n;
			break;
		}
	}
	return 0;
}
/*
7 9289 JAPAN
5 8523 AMERICA
3 5184 CHINA
8 2213 BASHU
10 0 DDS
*/