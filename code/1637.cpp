#include<iostream>
#include<algorithm>
using namespace std;
struct na{string n;int a,d;}a[5005];
int n,tot=0,t=0,tt;
bool cmp(na a1,na b1){return a1.d<b1.d;}
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
			cout<<a[i].n<<" ";
			t=0,tt=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)t+=abs(a[i].d-a[tt].d)*a[i].a;
	cout<<t;
	return 0;
}
/*
7 9289 Vladivostok
5 8523 Chabarovsk
3 5184 Irkutsk
8 2213 Yalutorovsk
10 0 Moscow
*/